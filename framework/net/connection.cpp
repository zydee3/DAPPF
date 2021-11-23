//
// Created by Vince on 10/16/2021.
//

#include "connection.h"
#include <iostream>
#include <string>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>

//int32_t dappf::connection::BUFFER_SIZE = 8192; // 8 bytes

/**
 * Creates a socket for connecting to a server, listening on the specified port number.
 * Returns the socket file descriptor on success. On failure, throws error.
 * @param address the target's address
 * @param port the target's port
 * @return the file descriptor for the socket
 */
int create_client_socket(std::string address, uint16_t port) {
    int clientfd = socket(AF_INET, SOCK_STREAM, 0);
    if (clientfd < 0) {
        throw std::runtime_error("couldn't open socket");
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof addr);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(address.c_str());
    addr.sin_port = htons(port);
    if (connect(clientfd, (struct sockaddr*) &addr, sizeof addr)) {
        throw std::runtime_error("couldn't connect to target");
    }
    return clientfd;
}

/**
 * Creates a socket for listening for connections.
 * Throws error if anything goes wrong.
 * @param port the port on which the socket should be opened
 * @return the file descriptor for the socket
 */
int create_listen_socket(uint16_t port) {
    struct sockaddr_in addr;
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        throw std::runtime_error("couldn't open socket");
    }

    int dummy = 1;
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &dummy, sizeof(int)) < 0) {
        throw std::runtime_error("couldn't set socket options");
    }

    std::memset(&addr, 0, sizeof addr);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htons(INADDR_ANY);
    addr.sin_port = htons(port);
    if (bind(listenfd, (struct sockaddr*)&addr, sizeof addr) < 0) {
        throw std::runtime_error("couldn't bind port");
    }

    if (listen(listenfd, 500) < 0) {
        throw std::runtime_error("couldn't listen to socket");
    }

    return listenfd;
}

/**
 * Listens for data coming from a connection, and calls the provided function when data is received
 * @param connection the connection to listen to
 * @param handler the function that should be called when data is received
 */
void listen_connection(int connfd, dappf::DappfNetworkInterface *app) {
    int8_t *buffer = (int8_t *) malloc(dappf::connection::BUFFER_SIZE);

    while (true) {
        int32_t length_read_in = read(connfd, buffer, dappf::connection::BUFFER_SIZE);
        if (length_read_in == 0) break;

        app->receive(buffer, length_read_in);
    }
}

/**
 * Adds the new connection to the list, and creates a new thread which will listen to the connection for data
 * @param connections the list of active connections to add to
 * @param address the address of the new connection
 * @param connfd the file descriptor of the new connection
 * @param handler the function that should be called when data is received
 */
void add_connection(std::vector<dappf::connection::conn> *connections, std::string address, int connfd, dappf::DappfNetworkInterface *app) {
    std::thread *thread = new std::thread(listen_connection, connfd, app);
    connections->push_back(dappf::connection::conn { address, connfd, thread });
}

/**
 * Enters a non-busy infinite loop of accepting connections and adding them to a list
 * Call this from a dedicated thread - never exits unless an error occurs
 * @param connections pointer to a list of connections which will get added to
 * @param port the port on which to listen for incoming connections
 * @param handler the function that should be called when data is received
 */
[[noreturn]] void listen_for_connections(std::vector<dappf::connection::conn> *connections, uint16_t port, dappf::DappfNetworkInterface *app) {
    int listenfd = create_listen_socket(port);

    while (true) {
        // just for getting the address of the incoming connection
        sockaddr incoming_address;
        socklen_t address_length = sizeof incoming_address;
        std::memset(&incoming_address, 0, address_length);

        int connfd = accept(listenfd, &incoming_address, &address_length);
        if (connfd < 0) {
            // not fatal, so just print, no error throwing
            std::cerr << "tried to accept connection, but failed" << std::endl;
        } else {
            // extracting address
            sockaddr_in *addr_in = (sockaddr_in *) &incoming_address;
            std::string address(inet_ntoa(addr_in->sin_addr));

            add_connection(connections, address, connfd, app);
        }
    }
}

dappf::connection::network dappf::connection::start_network(uint16_t listen_port, DappfNetworkInterface *app) {
    std::vector<conn> *connections = new std::vector<conn>;
    std::thread *thread_listening_for_incoming_connections = new std::thread(listen_for_connections, connections, listen_port, app);

    return network { listen_port, 0, connections, thread_listening_for_incoming_connections };
}

/**
 * Attempts to join the network given the address and connect_port of some node in that network
 * @param address the target node's address
 * @param connect_port the target node's port
 * @param listen_port the port on which the current node should listen for incoming connections
 * @param handler the function that should be called when data is received
 * @return the list of active connections, initialized with a single element
 */
dappf::connection::network dappf::connection::join_network(std::string address, uint16_t connect_port, uint16_t listen_port, DappfNetworkInterface *app) {
    // in order for a node to connect, it must already have the address/connect_port of a node in the network
    // how it obtains that will be outside the framework's responsibilities

    network net = start_network(listen_port, app);

    int clientfd = create_client_socket(address, connect_port);
    add_connection(net.connections, address, clientfd, app);

    return net;
}

/**
 * Sends a message to all connections
 * @param connections the list of connections to send the message to
 * @param message the message to send
 * @param length the length of the message
 */
void dappf::connection::broadcast_message(std::vector<conn> *connections, int8_t* message, int32_t length) {
    for (conn connection : *connections) {
        write(connection.connfd, message, length);
    }
}

/**
 * Closes all connections, then frees the storage memory
 * @param connections the list of active connections to close and free
 */
void dappf::connection::leave_network(std::vector<conn> *connections) {
    for (conn connection : *connections) {
        close(connection.connfd);
        delete connection.connection_thread;
    }

    free(connections);
}
