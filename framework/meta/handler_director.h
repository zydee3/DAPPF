//
// Created by Vince on 11/23/2021.
//

#ifndef DAPPF_HANDLER_DIRECTOR_H
#define DAPPF_HANDLER_DIRECTOR_H

#include <iterator>
#include <map>
#include <stdexcept>
#include "handler.h"
#include "event_listeners.h"
#include "../dappf.h"


namespace dappf::meta {
    class handler_director {
    private:
        std::map<int16_t, handler*>* handlers = new std::map<int16_t, handler*>();

    public:
        bool check_state(std::string);
        bool remove(int16_t);
        bool put(int16_t, handler*);
        handler* get(int16_t);
    };
}


#endif //DAPPF_HANDLER_DIRECTOR_H
