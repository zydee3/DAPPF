//
// Created by Vince on 10/16/2021.
//

#include <functional>
#include <iostream>
#include "dappf.h"

#include "data/packet/packet_compression.h"
#include "data/packet/packet_processing.h"
#include "meta/async_wrappers/message_id_tracker.h"
#include "meta/async_wrappers/message_counter.h"

void dappf::init(uint16_t listen_port) {
    local_port = listen_port;

    net = connection::start_network(listen_port);
    internal_state = state::running;
}

void dappf::init(std::string address, uint16_t connect_port, uint16_t listen_port) {
    local_port = listen_port;

    net = connection::join_network(address, connect_port, listen_port);
    internal_state = state::running;
}

void dappf::broadcast(data::packet::packet_writer *packet) {
    data::packet::processing::Message *message = data::packet::processing::wrap_broadcast(
            packet,
            net.listen_port,
            dappf::async_wrappers::MessageCounter::get().get_and_increment()
    );

    broadcast(message->data, message->length);

    delete message->data;
    delete message;
}

void dappf::broadcast(int8_t *data, int32_t length) {
    int64_t id = data::packet::processing::extract_message_id(data);
    async_wrappers::MessageIdTracker::get().insert(id);
    connection::broadcast_message(net.connections, data, length);
}

void dappf::send(data::packet::packet_writer *packet, std::string address, uint16_t target_port) {
    data::packet::processing::Message *message = data::packet::processing::wrap_targeted(
            packet,
            net.listen_port,
            dappf::async_wrappers::MessageCounter::get().get_and_increment()
    );

    connection::broadcast_message(net.connections, message->data, message->length);

    delete message->data;
    delete message;
}
