//
// Created by Vincent Tan on 11/24/21.
//

#include "on_packet_received.h"

void
dappf::meta::event_listeners::on_packet_received::set(std::function<void(dappf::meta::packet::packet_reader *)>* _handle) {
    handle = _handle;
}

std::function<void(dappf::meta::packet::packet_reader *)> *dappf::meta::event_listeners::on_packet_received::get() {
    return handle;
}
