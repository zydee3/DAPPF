//
// Created by Vince on 11/6/2021.
//

#ifndef DAPPF_EVENT_LISTENERS_H
#define DAPPF_EVENT_LISTENERS_H


#include <cstdint>
#include <iostream>
#include <functional>
#include "packet_writer.h"
#include "packet_reader.h"

#include "../utility/log.h"


namespace dappf::meta {
    class event_listeners {

    private:
        static std::function<void(std::string)>* on_connection_request;
        static std::function<void(std::string, int)>* on_connection_established;
        static std::function<void(std::string, int)>* on_connection_dropped;
        static std::function<void(dappf::meta::packet_reader*)>* on_packet_received;
        static std::function<void(int8_t*, int)>* on_packet_sent;
        static std::function<void(std::string)>* on_internal_error;

    public:
        static void set_on_connection_request_event_listener(std::function<void(std::string)>*);
        static std::function<void(std::string)>* get_on_connection_request_event_listener();

        static void set_on_connection_established_event_listener(std::function<void(std::string, int)>*);
        static std::function<void(std::string, int)>* get_on_connection_established_event_listener();

        static void set_on_connection_dropped_event_listener(std::function<void(std::string, int)>*);
        static std::function<void(std::string, int)>* get_on_connection_dropped_event_listener();

        static void set_on_packet_received_event_listener(std::function<void(dappf::meta::packet_reader*)>*);
        static std::function<void(dappf::meta::packet_reader*)>* get_on_packet_received_event_listener();

        static void set_on_packet_sent_event_listener(std::function<void(int8_t*, int)>*);
        static std::function<void(int8_t*, int)>* get_on_packet_sent_event_listener();

        static void set_on_internal_error_event_listener(std::function<void(std::string)>*);
        static std::function<void(std::string)>* get_on_internal_error_event_listener();

        bool(*packet_validator)(int8_t*, int) = nullptr;
        void set_packet_validator(bool(*)(int8_t*, int));
        auto get_packet_validator();

    // packet compressor
    // packet encryptor
    };
}



#endif //DAPPF_EVENT_LISTENERS_H
