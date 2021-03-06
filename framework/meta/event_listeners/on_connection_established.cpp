//
// Created by Vincent Tan on 11/24/21.
//

#include "on_connection_established.h"

std::function<void(std::string)> dappf::data::event_listeners::on_connection_established::handle;

void dappf::data::event_listeners::on_connection_established::set(std::function<void(std::string)> _handle) {
    handle = _handle;
}

std::function<void(std::string)> dappf::data::event_listeners::on_connection_established::get() {
    return handle;
}
