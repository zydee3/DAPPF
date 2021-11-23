//
// Created by Kirill on 11/22/21.
//

#include <cstdint>
#include "message_id_tracker.h"

void dappf::MessageIdTracker::insert(uint64_t id) {
    seen_set.insert(id);
}

bool dappf::MessageIdTracker::contains(uint64_t id) {
    return seen_set.contains(id);
}
