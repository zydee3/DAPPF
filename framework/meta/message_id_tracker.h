//
// Created by Kirill on 11/22/21.
//

#ifndef DAPPF_MESSAGE_ID_TRACKER_H
#define DAPPF_MESSAGE_ID_TRACKER_H

#include <unordered_set>

namespace dappf {
    class MessageIdTracker {
    private:
        std::unordered_set<uint64_t> seen_set;

    public:
        void insert(uint64_t id);
        bool contains(uint64_t);
    };
}

#endif //DAPPF_MESSAGE_ID_TRACKER_H