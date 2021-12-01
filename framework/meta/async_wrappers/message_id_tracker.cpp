//
// Created by Kirill on 11/22/21.
//

#include <cstdint>
#include "message_id_tracker.h"

dappf::async_wrappers::MessageIdTracker &dappf::async_wrappers::MessageIdTracker::get() {
    static MessageIdTracker tracker;
    return tracker;
}

dappf::async_wrappers::MessageIdTracker::MessageIdTracker() {
    lock = new sem_t;

    // 0 for shared between threads, not processes
    // 1 for semaphore value, so it's binary
    sem_init(lock, 0, 1);
}

void dappf::async_wrappers::MessageIdTracker::insert(uint64_t id) {
    sem_wait(lock);
    seen_set.insert(id);
    sem_post(lock);
}

bool dappf::async_wrappers::MessageIdTracker::contains(uint64_t id) {
    sem_wait(lock);
    bool ans = seen_set.contains(id);
    sem_post(lock);

    return ans;
}
