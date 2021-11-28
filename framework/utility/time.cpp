//
// Created by Vince on 11/23/2021.
//

#include "time.h"

long dappf::utility::time::now() {
    auto time_since_epoch = std::chrono::system_clock::now().time_since_epoch();
    auto milliseconds_since_epoch = duration_cast<std::chrono::milliseconds>(time_since_epoch);
    return milliseconds_since_epoch.count();
}
