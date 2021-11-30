//
// Created by Vince on 11/23/2021.
//

#ifndef DAPPF_HANDLER_DIRECTOR_H
#define DAPPF_HANDLER_DIRECTOR_H

#include <iterator>
#include <map>
#include <stdexcept>
#include "handler.h"
#include "../event_listeners/on_internal_error.h"
#include "../../dappf.h"


namespace dappf::data::handlers {
    class handler_director {
    private:
        static std::map<int16_t, handler*> handlers;
        static bool check_state(std::string);
    public:
        static bool remove(int16_t);
        static bool put(int16_t, handler*);
        static handler* get(int16_t);
    };
}


#endif //DAPPF_HANDLER_DIRECTOR_H
