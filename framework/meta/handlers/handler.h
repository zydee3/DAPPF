//
// Created by Vince on 11/20/2021.
//

#ifndef DAPPF_HANDLER_H
#define DAPPF_HANDLER_H


#include <cstdint>

namespace dappf::meta {

    class handler {
    private:
        long timestamp;
        int num_times_repeated;
        int8_t* ipv4 = nullptr;
        int8_t* packet = nullptr;

    public:

        handler(int8_t *ipv4, int8_t *packet);
        virtual ~handler();
        virtual bool process();
        virtual bool handle();

    };
}


#endif //DAPPF_HANDLER_H
