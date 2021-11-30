//
// Created by Vincent Tan on 11/24/21.
//

#ifndef DAPPF_ON_CONNECTION_DROPPED_H
#define DAPPF_ON_CONNECTION_DROPPED_H

#include <functional>
#include <string>
#include "event_listener.h"

namespace dappf::data::event_listeners {
    class on_connection_dropped : event_listener {
    private:
        static std::function<void(std::string)>* handle;
    public:
        static void set(std::function<void(std::string)>*);
        static std::function<void(std::string)>* get();
    };
}


#endif //DAPPF_ON_CONNECTION_DROPPED_H
