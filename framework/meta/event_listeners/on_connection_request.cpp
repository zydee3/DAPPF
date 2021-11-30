//
// Created by Vincent Tan on 11/24/21.
//

#include "on_connection_request.h"

std::function<void(std::string)>* dappf::data::event_listeners::on_connection_request::handle;

void dappf::data::event_listeners::on_connection_request::set(std::function<void(std::string)>* _handle) {
    handle = _handle;
}

std::function<void(std::string)> *dappf::data::event_listeners::on_connection_request::get() {
    return handle;
}
