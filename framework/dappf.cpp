//
// Created by Vince on 10/16/2021.
//

#include <functional>
#include <iostream>
#include "dappf.h"

#include "data/packet/packet_compression.h"
#include "data/packet/packet_processing.h"

dappf::Dappf::Dappf(uint16_t listen_port) {
    local_port = listen_port;

    net = connection::start_network(listen_port);
    internal_state = state::running;
}

dappf::Dappf::Dappf(std::string address, uint16_t connect_port, uint16_t listen_port) {
    local_port = listen_port;

    net = connection::join_network(address, connect_port, listen_port);
    internal_state = state::running;
}

void dappf::Dappf::broadcast(meta::packet::packet_writer *packet) {
    meta::packet::processing::Message *message = meta::packet::processing::wrap_broadcast(packet, net.listen_port, dappf::async_wrappers::message_counter.get_and_increment());

    connection::broadcast_message(net.connections, message->data, message->length);

    delete message->data;
    delete message;
}

void dappf::Dappf::send(meta::packet::packet_writer *packet, std::string address, uint16_t target_port) {
    meta::packet::processing::Message *message = meta::packet::processing::wrap_targeted(packet, net.listen_port, dappf::async_wrappers::message_counter.get_and_increment());

    connection::broadcast_message(net.connections, message->data, message->length);

    delete message->data;
    delete message;
}
