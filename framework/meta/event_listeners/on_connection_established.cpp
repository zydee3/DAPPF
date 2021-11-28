//
// Created by Vincent Tan on 11/24/21.
//

#include "on_connection_established.h"

void dappf::meta::event_listeners::on_connection_established::set(std::function<void(std::string, int)>* _handle) {
    handle = _handle;
}

std::function<void(std::string, int)> *dappf::meta::event_listeners::on_connection_established::get() {
    return handle;
}
