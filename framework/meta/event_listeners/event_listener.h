//
// Created by Vince on 11/6/2021.
//

#ifndef DAPPF_EVENT_LISTENER_H
#define DAPPF_EVENT_LISTENER_H


#include <cstdint>
#include <iostream>
#include <functional>
#include "../../data/packet/packet_writer.h"
#include "../../data/packet/packet_reader.h"

#include "../../utility/log.h"


namespace dappf::meta::event_listeners {
    class event_listener {

    private:

    public:

        //bool(*packet_validator)(int8_t*, int) = nullptr;
        //void set_packet_validator(bool(*)(int8_t*, int));
        //auto get_packet_validator();

    // packet compressor
    // packet encryptor
    };
}



#endif //DAPPF_EVENT_LISTENER_H
