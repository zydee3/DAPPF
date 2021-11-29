//
// Created by Vincent Tan on 11/28/21.
//

#ifndef DAPPF_ON_PACKET_SENT_H
#define DAPPF_ON_PACKET_SENT_H

#include <functional>
#include "../../data/packet/packet_reader.h"
#include "event_listener.h"

namespace dappf::meta::event_listeners {
    class on_packet_sent : event_listener {

    private:
        static std::function<void(int8_t*, int)>* handle;
    public:
        static void set(std::function<void(int8_t*, int)>*);
        static std::function<void(int8_t*, int)>* get();
    };
}


#endif //DAPPF_ON_PACKET_SENT_H
