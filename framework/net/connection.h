//
// Created by Vince on 10/16/2021.
//

#ifndef DAPPF_CONNECTION_H
#define DAPPF_CONNECTION_H

#include <string>
#include <vector>

namespace dappf::connection {

    /**
     * Puts both an address and a port number into the same struct for ease of organization
     * @param address the address of the connection
     * @param port the port number of the connection
     */
    typedef struct {
        std::string address;
        int connfd;
    } conn;

    void join_network();

    [[noreturn]] void listen_for_connections(std::vector<conn> *connections, uint16_t port);

    void establish(std::string address, int port);

};


#endif //DAPPF_CONNECTION_H
