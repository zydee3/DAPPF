//
// Created by Vincent Tan on 11/28/21.
//

#include "on_internal_error.h"

std::function<void(std::string)>* dappf::meta::event_listeners::on_internal_error::handle;

void dappf::meta::event_listeners::on_internal_error::set(std::function<void(std::string)>* _handle) {
    _handle = handle;
}

std::function<void(std::string)> *dappf::meta::event_listeners::on_internal_error::get() {
    return handle;
}
