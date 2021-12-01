//
// Created by Vincent Tan on 11/24/21.
//

#ifndef DAPPF_ON_PACKET_RECEIVED_H
#define DAPPF_ON_PACKET_RECEIVED_H

#include <functional>
#include "../../data/packet/packet_reader.h"
#include "event_listener.h"

namespace dappf::data::event_listeners {
    class on_packet_received : event_listener {

    private:
        static std::function<void(dappf::data::packet::packet_reader *)> handle;
    public:
        static void set(std::function<void(dappf::data::packet::packet_reader *)>);
        static std::function<void(dappf::data::packet::packet_reader *)> get();
    };
}


#endif //DAPPF_ON_PACKET_RECEIVED_H
