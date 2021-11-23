//
// Created by Vince on 11/6/2021.
//

#include "event_listeners.h"


// region on connection request

/**
 * Sets handler for handling connection requests.
 * @param handle Pointer to function that handles connection requests.
 * When invoked, the handler passes in a string parameter representing the ipv6
 * address of the requesting node.
 */
void dappf::meta::event_listeners::set_on_connection_request_event_listener(void(*handle)(std::string)){
    on_connection_request = handle;
}

/**
 * Returns handler for handling connection requests.
 * @return Pointer to function that handles connection requests.
 * When invoked, the handler passes in a string parameter representing the ipv6
 * address of the requesting node.
 */
auto dappf::meta::event_listeners::get_on_connection_request_event_listener() {
    return on_connection_request;
}

// endregion  on connection request

// region on connection established

/**
 * Sets handler for handling post-connection events.
 * @param handle Pointer to function that handles post-connection events.
 * When invoked, the handler passes in a string parameter representing the ipv6
 * address of the connected neighbor.
 */
void dappf::meta::event_listeners::set_on_connection_established_event_listener(void(*handle)(std::string, int)){
    on_connection_established = handle;
}

/**
 * Gets handler for handling post-connection events.
 * @return Pointer to function that handles post-connection events.
 * When invoked, the handler passes in a string parameter representing the ipv6
 * address of the connected neighbor.
 */
auto dappf::meta::event_listeners::get_on_connection_established_event_listener() {
    return on_connection_established;
}

// endregion

// region on connection dropped

/**
 * Sets handler for handling post-disconnection events.
 * @param handle Pointer to function that handles post-disconnection events.
 * When invoked, the handler passes in a string parameter representing the ipv6
 * address of the disconnected neighbor.
 */
void dappf::meta::event_listeners::set_on_connection_dropped_event_listener(void(*handle)(std::string, int)){
    on_connection_dropped = handle;
}

/**
 * Gets handler for handling post-disconnection events.
 * @param handle Pointer to function that handles post-disconnection events.
 * When invoked, the handler passes in a string parameter representing the ipv6
 * address of the disconnected neighbor.
 */
auto dappf::meta::event_listeners::get_on_connection_dropped_event_listener() {
    return on_connection_dropped;
}

// endregion

// region on packet received

/**
 * Sets handler for handing received packets from neighbors.
 * @param handle Pointer to function that handles received packets from neighbors.
 * When invoked, the handler passes in an instantiated packet reader which contains
 * the bytes received.
 */
void dappf::meta::event_listeners::set_on_packet_received_event_listener(void(*handle)(dappf::meta::packet_reader*)){
    on_packet_received = handle;
}

/**
 * Gets handler for handing received packets from neighbors.
 * @param handle Pointer to function that handles received packets from neighbors.
 * When invoked, the handler passes in an instantiated packet reader which contains
 * the bytes received.
 */
auto dappf::meta::event_listeners::get_on_packet_received_event_listener(){
    return on_packet_received;
}

// endregion

// region on packet send

/**
 * Sets handler for handing sent packets to neighbors.
 * @param handle Pointer to function that handles sent packets to neighbors.
 * When invoked, the handler passes in an instantiated packet writer which contains
 * the bytes written and sent.
 */
void dappf::meta::event_listeners::set_on_packet_sent_event_listener(void(*handle)(int8_t* packet, int length)){
    on_packet_sent = handle;
}

/**
 * Gets handler for handing sent packets to neighbors.
 * @param handle Pointer to function that handles sent packets to neighbors.
 * When invoked, the handler passes in an instantiated packet writer which contains
 * the bytes written and sent.
 */
auto dappf::meta::event_listeners::get_on_packet_sent_event_listener(){
    return on_packet_sent;
}

// endregion

// region on internal error

/**
 * Sets handler for handing internal errors.
 * @param handle Pointer to function that handles internal errors.
 * These are typically errors which are not critical and thus should
 * not crash or halt the entire program.
 */
void dappf::meta::event_listeners::set_on_internal_error_event_listener(void(*handle)(std::string)){
    on_internal_error = handle;
}

/**
 * Gets handler for handing internal errors.
 * @param handle Pointer to function that handles internal errors.
 * These are typically errors which are not critical and thus should
 * not crash or halt the entire program.
 */
auto dappf::meta::event_listeners::get_on_internal_error_event_listener(){
    return on_internal_error;
}

// endregion

// do packet validator

/**
 * Sets the handler for validating an incoming packet.
 * @param handle Pointer to function that validates packets.
 * When invoked, the handler accepts the array of bytes, the length of the array of bytes
 * and whats returned is true or false representing the state; true if valid, otherwise false.
 */
void dappf::meta::event_listeners::set_packet_validator(bool(*handle)(int8_t*, int)){
    packet_validator = handle;
}

/**
 * Gets the handler for validating an incoming packet.
 * @param handle Pointer to function that validates packets.
 * When invoked, the handler accepts the array of bytes, the length of the array of bytes
 * and whats returned is true or false representing the state; true if valid, otherwise false.
 */
auto dappf::meta::event_listeners::get_packet_validator(){
    return packet_validator;
}

