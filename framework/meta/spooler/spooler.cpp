//
// Created by Vincent Tan, Gar on 11/27/21.
//

#include "spooler.h"

/**
 * Fetches a handler from the handler_director. If the handler_director does not have
 * a handler to the associated key, then nullptr is returned and we throw an
 * error where appropriate
 * @param key value associated to handler which acts as the handler id
 * @return handler if present in handler_director, otherwise nullptr
 */
dappf::data::handlers::handler* dappf::data::spooler::spooler::fetch_handler(int key) {
    auto handler = dappf::data::handlers::handler_director::get(key);

    std::string error = "spooler::fetch_handler: unhandled op code";

    if(handler == nullptr) {
        if (dappf::constants::throw_exceptions) {
            throw std::runtime_error(error);
        }

        auto listener = dappf::data::event_listeners::on_internal_error::get();
        if(listener != nullptr){
            listener(error);
        }
    }

    return handler;
}

/**
 * Using the predictor, we fetch handlers which could be needed in the future
 * and pre-process the data such that the data is available for when the
 * handle request does come in. The predictor returns a vector of values which
 * is associated to a handler. For each value in the vector, we fetch the
 * handler. If the handler is present and valid, we pre-process it and cache
 * the handler. If the pre-process fails, we don't cache the handler and an
 * exception is thrown where appropriate.
 * @param source Requester, generally an Ipv4
 * @param value op code
 */
void dappf::data::spooler::spooler::spool(std::string source, int value) {
    if(!dappf::constants::use_spooler){
        return;
    }

    auto predictor = dappf::data::spooler::predictor::get();
    if(predictor == nullptr) {
        return;
    }

    std::vector<int> to_spool = predictor(value);
    for(int i = 0; i < to_spool.size(); i++){
        int key = to_spool[i];
        dappf::data::handlers::handler* handler = fetch_handler(key);
        if(handler == nullptr){
            continue;
        }

        if(!handler->process()){
            auto listener = dappf::data::event_listeners::on_internal_error::get();
            if(listener != nullptr){
                listener("unable to process handler");
            }
            continue;
        }

        std::string id = source + std::to_string(value);

        // todo: uncomment this when shishir finishes the cache
        // dappf::data::storage::cache::put(id, handler);
    }
}


