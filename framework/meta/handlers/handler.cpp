//
// Created by Vince on 11/20/2021.
//

#include "handler.h"

/**
 * Super constructor to any class which implements this handler
 * @param _ipv4 Ipv4 address of target, nullptr if none / internal use. Ipv4 is an array
 * of 4 numbers [aaa,bbb,ccc,ddd] such that the ipv4 constructed is aaa.bbb.ccc.ddd
 * @param _packet The packet to be sent and/or constructed, nullptr if unneeded.
 */
dappf::meta::handlers::handler::handler(int8_t* _ipv4, int8_t* _packet, long _timestamp) {
    ipv4 = _ipv4;
    packet = _packet;
    timestamp = _timestamp;
}

/**
 * Super deconstructor to any class which implements this handler
 */
dappf::meta::handlers::handler::~handler() {
    delete ipv4;
    delete packet;
}

/**
 * Used by other super methods when a class implementing this handler does not
 * implement their own methods for handling the associated member function.
 * @param error Error message to be outputted.
 */
void dappf::meta::handlers::handler::throw_unhandled_exception(std::string error) {
    if(dappf::constants::throw_exceptions) {
        throw std::runtime_error(error);
    }

    auto listener = dappf::meta::event_listeners::on_internal_error::get();
    if(listener != nullptr){
        (*listener)(error);
    }
}

/**
 * Super function for process. Only throws an error when the class implementing
 * this class does not implement / override this member function.
 *
 * The use of this function is to process any required information needed
 * for the handling part of the instruction set.
 *
 * @return False for not processed
 */
bool dappf::meta::handlers::handler::process() {
    throw_unhandled_exception("handler::process unhandled");
    return false;
}

/**
 * Super function for handle. Only throws an error when the class implementing
 * this class does not implement / override this member function.
 *
 * The use of this function is to handle the designated set of instructions
 * after process has been called.
 *
 * @return False for not handled
 */
bool dappf::meta::handlers::handler::handle() {
    throw_unhandled_exception("handler::handle unhandled");
    return false;
}

/**
 * Super function for delay. Only throws an error when the class implementing
 * this class does not implement / override this member function.
 *
 * The use of this function is to handle any task necessary for when this task
 * gets potentially delayed. A point of delay can be when not enough threads
 * are available in the task pool to execute this handler and thus we invoke
 * a set of instructions to be completed while waiting for the handle to be
 * completed.
 *
 * @return
 */
bool dappf::meta::handlers::handler::delay() {
    throw_unhandled_exception("handler::delay unhandled");
    return false;
}


