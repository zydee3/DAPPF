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

void dappf::connection::join_network() {
    /* at the moment, can't quite do that
     * some ideas:
     *
     * have a central server keeping track of nodes' existences, ask it for a node and try connecting until one connects
     * + straightforward
     * - goes against the whole purpose
     *
     * have each node know its neighbor ahead of time, and connect to that one every time
     * + also simple
     * - what if that node is down?
     * - how does the first node join the network?
     *
     * shout out to the whole internet that you want to connect to the network
     * - malicious agents can pretend to be the network
     * - how do we even do that
     *
     * have each node in the network shout out periodically that it exists
     * - malicious agents can join the network
     * - again how does one do this
     *
     * if anyone has any ideas on how to make this work please do let me know
     */
}

/**
    Creates a socket for listening for connections.
    Throws error if anything goes wrong.
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
 * Enters an non-busy infinite loop of accepting connections and adding them to a list
 * Call this from a dedicated thread - never exits unless an error occurs
 * @param connections pointer to a list of connections which will get added to
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
};

void dappf::connection::establish(std::string address, int port) {
    std::cout << "establishing a connection to " << address << " on port " << port << std::endl;
}
