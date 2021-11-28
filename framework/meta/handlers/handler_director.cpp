//
// Created by Vince on 11/23/2021.
//

#include "handler_director.h"

bool dappf::meta::handlers::handler_director::check_state(std::string source) {
    if (dappf::internal_state != dappf::state::stopped) {
        auto handler = dappf::meta::event_listeners::on_internal_error::get();
        if(handler != nullptr){
            (*handler)("Attempting to modify (" + source + ") handler on non-stopped internal state.");
        }

        return false;
    }

    return true;
}

/**
 * Removes a handler associated by the op_code.
 * @param op_code op_code to be removed
 * @return true if an associated op_code existed, otherwise false
 */
bool dappf::meta::handlers::handler_director::remove(int16_t op_code) {
    return dappf::meta::handlers::handler_director::check_state("remove") && handlers->erase(op_code) == 1;
}

/**
 * Inserts a handler associated by the op_code. op_codes must be unique, however multiple
 * op_codes can contain the same instance of the same handler.
 * @param op_code value representing the op_code
 * @param handler instance of handler associated to the op_code
 * @return true  if previous instance of op_code was overwritten,
 *         false if op_code was inserted without overwriting a previous instance.
 */
bool dappf::meta::handlers::handler_director::put(int16_t op_code, dappf::meta::handlers::handler* handler) {
    if(dappf::meta::handlers::handler_director::check_state("remove")) {
        bool replaced = handlers->find(op_code) != handlers->end();
        handlers->insert({op_code, handler});
        return replaced;
    }

    return false;
}

/**
 * Returns the handler associated to the given op_code if it exists
 * @param op_code op code associated to the desired handler
 * @return handler associated to the op code
 */
dappf::meta::handlers::handler *dappf::meta::handlers::handler_director::get(int16_t op_code) {
    std::map<int16_t, handler*>::iterator iterator = handlers->find(op_code);
    if(iterator == handlers->end()) {
        return nullptr;
    } else {
        return iterator->second;
    }
}


