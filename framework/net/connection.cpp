//
// Created by Vince on 10/16/2021.
//

#include "connection.h"
#include <iostream>
#include <string>

#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <cstring>

/**
   Creates a socket for connecting to a server running on the same
   computer, listening on the specified port number.  Returns the
   socket file descriptor on success. On failure, throws error.
   @param address the target's address
   @param port the target's port
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
    Creates a socket for listening for connections.
    Throws error if anything goes wrong.
    @param port the port on which the socket should be opened
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
 * Attempts to join the network given the address and port of some node in that network
 * @param address the target node's address
 * @param port the target node's port
 * @return the file descriptor of the connection
 */
int dappf::connection::join_network(std::string address, uint16_t port) {
    // in order for a node to connect, it must already have the address/port of a node in the network
    // how it obtains that will be outside the framework's responsibilities

    return create_client_socket(address, port);
}

/**
 * Enters an non-busy infinite loop of accepting connections and adding them to a list
 * Call this from a dedicated thread - never exits unless an error occurs
 * @param connections pointer to a list of connections which will get added to
 * @param port the port on which to listen for incoming connections
 */
[[noreturn]] void dappf::connection::listen_for_connections(std::vector<conn> *connections, uint16_t port) {
    int listenfd = create_listen_socket(port);

    while (true) {
        int connfd = accept(listenfd, NULL, NULL);
        if (connfd < 0) {
            // couldn't accept connection, but not fatal, just print a message to console for now
            std::cout << "tried to accept connection, but failed" << std::endl;
        }

        // how to get the connection's address?
        connections->push_back(conn {"", connfd});
    }
}
