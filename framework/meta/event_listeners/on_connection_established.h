//
// Created by Vincent Tan on 11/24/21.
//

#ifndef DAPPF_ON_CONNECTION_ESTABLISHED_H
#define DAPPF_ON_CONNECTION_ESTABLISHED_H

#include <string>
#include <functional>
#include "event_listener.h"

namespace dappf::data::event_listeners {
    class on_connection_established : event_listener {
    private:
        static std::function<void(std::string, int)>* handle;
    public:
        static void set(std::function<void(std::string, int)>*);
        static std::function<void(std::string, int)>* get();
    };
}


#endif //DAPPF_ON_CONNECTION_ESTABLISHED_H
