//
// Created by Vincent Tan on 11/28/21.
//

#include "on_packet_sent.h"

std::function<void(int8_t*, int)>* dappf::meta::event_listeners::on_packet_sent::handle;

void dappf::meta::event_listeners::on_packet_sent::set(std::function<void(int8_t *, int)>* _handle) {
    handle = _handle;
}

std::function<void(int8_t *, int)> *dappf::meta::event_listeners::on_packet_sent::get() {
    return handle;
}
