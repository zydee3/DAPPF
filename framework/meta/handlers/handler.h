//
// Created by Vince on 11/20/2021.
//

#ifndef DAPPF_HANDLER_H
#define DAPPF_HANDLER_H


#include <cstdint>
#include <exception>
#include "../../constants.h"
#include "../event_listeners/on_internal_error.h"

namespace dappf::meta::handlers {

    class handler {
    private:
        long timestamp;
        int8_t* ipv4 = nullptr;
        int8_t* packet = nullptr;

        void throw_unhandled_exception(std::string);

    public:
        handler(int8_t *ipv4, int8_t *packet, long);
        virtual ~handler();
        virtual bool process();
        virtual bool handle();
        virtual bool delay();

    };
}


#endif //DAPPF_HANDLER_H
