//
// Created by Vince on 10/16/2021.
//

#include <cstring>
#include <functional>
#include <iostream>
#include "dappf.h"

#include "data/compression.h"
#include "security/packet_cipher.h"
#include "meta/packet_proccessing.h"

dappf::Dappf::Dappf(uint16_t listen_port) {
    net = connection::start_network(listen_port);
}

dappf::Dappf::Dappf(std::string address, uint16_t connect_port, uint16_t listen_port) {
    net = connection::join_network(address, connect_port, listen_port);
}

void dappf::Dappf::broadcast(meta::packet_writer *packet) {
    meta::packet_processing::Message *message = meta::packet_processing::wrap(packet);

    connection::broadcast_message(net.connections, message->data, message->length);

    delete message->data;
    delete message;
}

void dappf::Dappf::send(meta::packet_writer *packet, std::string address, uint16_t target_port) {
    meta::packet_processing::Message *message = meta::packet_processing::wrap(packet);

    connection::broadcast_message(net.connections, message->data, message->length);

    delete message->data;
    delete message;
}
