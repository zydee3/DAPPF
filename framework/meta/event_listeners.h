//
// Created by Vince on 11/6/2021.
//

#ifndef DAPPF_EVENT_LISTENERS_H
#define DAPPF_EVENT_LISTENERS_H


#include <cstdint>

namespace dappf::meta::event_listeners {

    // connection listeners
    void(*on_connection_request)();
    void(*on_connection_established)();
    void(*on_connection_dropped)();

    // packet listeners
    void(*on_packet_received)(int8_t*, bool(*function)(int8_t*));
    void(*on_packet_send)(int8_t*);

    // handlers
    void(*validate_packet)(int8_t*);
}


#endif //DAPPF_EVENT_LISTENERS_H
