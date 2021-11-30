//
// Created by aether on 11/29/21.
//

#include <cstdlib>
#include "message_counter.h"

dappf::async_wrappers::MessageCounter::MessageCounter() {
    lock = (sem_t *) malloc(sizeof(sem_t));

    // 0 for shared between threads, not processes
    // 1 for semaphore value, so it's binary
    sem_init(lock, 0, 1);
}

uint16_t dappf::async_wrappers::MessageCounter::get_and_increment() {
    sem_wait(lock);
    uint16_t ans = counter;
    counter++;
    sem_post(lock);

    return ans;
}
