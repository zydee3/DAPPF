//
// Created by Vince on 10/16/2021.
//

#include "dappf.h"

#include "net/connection.h"
#include <iostream>

dappf::connection::network dappf::initialize_node_new_network(uint16_t listen_port, void (*handler)(int8_t *, int32_t)) {
    return connection::start_network(listen_port, handler);
}

dappf::connection::network dappf::initialize_node_existing_network(std::string address, uint16_t connect_port, uint16_t listen_port, void (*handler)(int8_t *, int32_t)) {
    return connection::join_network(address, connect_port, listen_port, handler);
}

void dappf::send(connection::network net, meta::packet_writer packet) {
    connection::broadcast_message(net.connections, packet.to_array(), packet.length());
}
