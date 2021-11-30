//
// Created by aether on 11/29/21.
//

#ifndef DAPPF_MESSAGE_COUNTER_H
#define DAPPF_MESSAGE_COUNTER_H

#include <semaphore.h>
#include <cstdint>

namespace dappf::async_wrappers {
    class MessageCounter {
    private:
        sem_t* lock;
        uint16_t counter;

    public:
        MessageCounter();
        uint16_t get_and_increment();
    };
}

#endif //DAPPF_MESSAGE_COUNTER_H
