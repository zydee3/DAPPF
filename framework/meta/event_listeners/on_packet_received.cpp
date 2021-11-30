//
// Created by Vincent Tan on 11/24/21.
//

#include "on_packet_received.h"

std::function<void(dappf::data::packet::packet_reader *)> *dappf::data::event_listeners::on_packet_received::handle;

void dappf::data::event_listeners::on_packet_received::set(std::function<void(dappf::data::packet::packet_reader *)>* _handle) {
    handle = _handle;
}

std::function<void(dappf::data::packet::packet_reader *)> *dappf::data::event_listeners::on_packet_received::get() {
    return handle;
}
