//
// Created by Vince on 10/16/2021.
//

#ifndef DAPPF_CONNECTION_H
#define DAPPF_CONNECTION_H

#include <string>
#include <vector>
#include <thread>

namespace dappf::connection {

    const int32_t BUFFER_SIZE = 8192; // 8 bytes

    /**
     * Puts both an address and a port number into the same struct for ease of organization
     * @param address the address of the connection
     * @param port the port number of the connection
     */
    typedef struct {
        std::string address;
        int connfd;
        std::thread *connection_thread;
    } conn;

    typedef struct {
        uint16_t listen_port;
        uint64_t message_counter;
        std::vector<conn> *connections;
        std::thread *thread_listening_for_incoming_connections;
    } network;

    network start_network(uint16_t listen_port, dappf::DappfNetworkInterface *app); // void (*handler)(int8_t *, int32_t)

    network join_network(std::string address, uint16_t connect_port, uint16_t listen_port, dappf::DappfNetworkInterface *app);

    void broadcast_message(std::vector<conn> *connections, int8_t* message, int32_t length);

    void leave_network(std::vector<conn> *connections);
};


#endif //DAPPF_CONNECTION_H
