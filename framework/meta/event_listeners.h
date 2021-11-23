//
// Created by Vince on 11/6/2021.
//

#ifndef DAPPF_EVENT_LISTENERS_H
#define DAPPF_EVENT_LISTENERS_H


#include <cstdint>
#include <iostream>
#include "packet_writer.h"
#include "packet_reader.h"

#include "../utility/log.h"


namespace dappf::meta {
    class event_listeners {

    private:
        void(*on_connection_request)(std::string s);
        void(*on_connection_established)(std::string, int);
        void(*on_connection_dropped)(std::string, int);
        void(*on_packet_received)(dappf::meta::packet_reader*);
        void(*on_packet_sent)(int8_t*, int);
        void(*on_internal_error)(std::string);

    public:
        static void set_test(std::function<void(std::string)>);
        void set_on_connection_request_event_listener(void(*)(std::string));
        auto get_on_connection_request_event_listener();

        void set_on_connection_established_event_listener(void(*)(std::string, int));
        auto get_on_connection_established_event_listener();

        void set_on_connection_dropped_event_listener(void(*)(std::string, int));
        auto get_on_connection_dropped_event_listener();

        void set_on_packet_received_event_listener(void(*)(dappf::meta::packet_reader*));
        auto get_on_packet_received_event_listener();

        void set_on_packet_sent_event_listener(void(*)(int8_t*, int));
        auto get_on_packet_sent_event_listener();

        void set_on_internal_error_event_listener(void(*)(std::string));
        auto get_on_internal_error_event_listener();

        bool(*packet_validator)(int8_t*, int) = nullptr;
        void set_packet_validator(bool(*)(int8_t*, int));
        auto get_packet_validator();

    // packet compressor
    // packet encryptor
    };
}



#endif //DAPPF_EVENT_LISTENERS_H
