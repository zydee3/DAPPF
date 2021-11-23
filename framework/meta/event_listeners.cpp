//
// Created by Vince on 11/6/2021.
//

#include "event_listeners.h"



// region on connection request

/**
 * Invoked by default when a connection request is made to establish a new connection.
 * @param address Ipv4 address of the requesting node.
 */
void dappf::meta::event_listeners::default_on_connection_request(std::string address){
    std::cout << "A connection request has been made from " << address << ".";
}

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
 * Invoked by default when a new connection has been establish.
 * @param address Ipv4 address of the requesting node.
 * @param port port the new connection is established on
 */
void dappf::meta::event_listeners::default_on_connection_established(std::string address, int port){
    std::cout << "A connection has been made with " << address << ":" << port << ".";
}

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

void dappf::meta::event_listeners::default_on_connection_dropped(std::string address, int port){
    std::cout << "A connection has been dropped with " << address << ":" << port << std::endl;
}

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

void dappf::meta::event_listeners::default_on_packet_received(dappf::meta::packet_reader* reader){
    std::cout << "Packet Received: ";
    dappf::utility::log::cout_hex_array(reader->get_packet(), reader->remaining());
}

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

void dappf::meta::event_listeners::default_on_packet_sent_event(int8_t* packet, int length){
    std::cout << "Packet Sent: ";
    dappf::utility::log::cout_hex_array(packet, length);
}

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

void dappf::meta::event_listeners::default_on_internal_error(std::string error){
    std::cout << "Internal error: " << error << std::endl;
}
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

