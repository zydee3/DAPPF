//
// Created by Kirill on 11/22/21.
//

#ifndef DAPPF_MESSAGE_ID_TRACKER_H
#define DAPPF_MESSAGE_ID_TRACKER_H

#include <semaphore.h>
#include <unordered_set>

namespace dappf::async_wrappers {
    class MessageIdTracker {
    private:
        sem_t* lock;
        std::unordered_set<uint64_t> seen_set;

        MessageIdTracker();

    public:
        static MessageIdTracker &get();

        void insert(uint64_t id);
        bool contains(uint64_t);
    };
}

#endif //DAPPF_MESSAGE_ID_TRACKER_H
