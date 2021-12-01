//
// Created by aether on 11/29/21.
//

#include <cstdlib>
#include "message_counter.h"

/**
 * Getter for the singleton message counter
 * @return the message counter instance
 */
dappf::async_wrappers::MessageCounter &dappf::async_wrappers::MessageCounter::get() {
    static MessageCounter counter;
    return counter;
}

/**
 * Constructor for the message counter, initializes the semaphore
 */
dappf::async_wrappers::MessageCounter::MessageCounter() {
    lock = new sem_t;

    // 0 for shared between threads, not processes
    // 1 for semaphore value, so it's binary
    sem_init(lock, 0, 1);
}

/**
 * Atomically gets the current value of the counter, and increments it for future calls
 * @return the counter value
 */
uint16_t dappf::async_wrappers::MessageCounter::get_and_increment() {
    sem_wait(lock);
    uint16_t ans = counter;
    counter++;
    sem_post(lock);

    return ans;
}
