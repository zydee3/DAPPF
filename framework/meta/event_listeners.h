//
// Created by Vince on 11/6/2021.
//

#ifndef DAPPF_EVENT_LISTENERS_H
#define DAPPF_EVENT_LISTENERS_H


#include <cstdint>
#include "packet_writer.h"
#include "packet_reader.h"

namespace dappf::meta::event_listeners {

    // on connection request
    // @param _1: ipv6 address of the requesting node.
    void(*on_connection_request)(std::string);
    void set_on_connection_request_event_listener(void(*)(std::string));
    auto get_on_connection_request_event_listener();

    // on connection established
    // // @param _1: ipv6 address of the connected neighbor.
    void(*on_connection_established)(std::string);
    void set_on_connection_established_event_listener(void(*)(std::string));
    auto get_on_connection_established_event_listener();

    // on connection dropped:
    // Invoked automatically when a connection with a neighbor is dropped.
    // @param _1: ipv6 address of the disconnected neighbor.
    void(*on_connection_dropped)(std::string);
    void set_on_connection_dropped_event_listener(void(*)(std::string));
    auto get_on_connection_dropped_event_listener();

    // on packet received:
    // Invoked automatically when the a packet is received from neighbors.
    // @param _1: packet_reader object containing message from neighbors.
    void(*on_packet_received)(dappf::meta::packet_reader*);
    void set_on_packet_received_event_listener(void(*)(dappf::meta::packet_reader*));
    auto get_on_packet_received_event_listener();

    // on packet sent
    void(*on_packet_sent)(dappf::meta::packet_writer*);
    void set_on_packet_sent_event_listener(void(*)(dappf::meta::packet_writer*));
    auto get_on_packet_sent_event_listener();

    // packet validator // need to move this elsewhere since its not an event listener
    bool(*packet_validator)(int8_t*, int);
    void set_packet_validator(bool(*)(int8_t*, int));
    auto get_packet_validator();

    // packet compressor
    // packet encryptor
}



#endif //DAPPF_EVENT_LISTENERS_H
