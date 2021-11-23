//
// Created by Vince on 11/23/2021.
//

#include "handler_director.h"

/**
 * Removes a handler associated by the op_code.
 * @param op_code op_code to be removed
 * @return true if an associated op_code existed, otherwise false
 */
bool dappf::meta::handler_director::remove(int16_t op_code) {
    return handlers->erase(op_code) == 1;
}

/**
 * Inserts a handler associated by the op_code. op_codes must be unique, however multiple
 * op_codes can contain the same instance of the same handler.
 * @param op_code value representing the op_code
 * @param handler instance of handler associated to the op_code
 * @return true  if previous instance of op_code was overwritten,
 *         false if op_code was inserted without overwriting a previous instance.
 */
bool dappf::meta::handler_director::put(int16_t op_code, dappf::meta::handler* handler) {
    if (dappf::internal_state != dappf::state::stopped) {
        dappf::meta::event_listeners::get_on_internal_error_event_listener()()
        throw std::logic_error("Attempting to modify (put) handler on non-stopped internal state.");
    }

    bool replaced = handlers->find(op_code) != handlers->end();
    handlers->insert({op_code, handler});
    return replaced;
}

/**
 * Returns the handler associated to the given op_code if it exists
 * @param op_code op code associated to the desired handler
 * @return handler associated to the op code
 */
dappf::meta::handler *dappf::meta::handler_director::get(int16_t op_code) {
    if (dappf::internal_state != dappf::state::stopped) {
        throw std::logic_error("Attempting to modify (put) handler on non-stopped internal state.");
    }

    std::map<int16_t, handler*>::iterator iterator = handlers->find(op_code);
    if(iterator == handlers->end()) {
        return nullptr;
    } else {
        return iterator->second;
    }
}
