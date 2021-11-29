//
// Created by Vince on 11/23/2021.
//

#include "time.h"

long dappf::utility::time::now() {
    auto time_since_epoch = std::chrono::system_clock::now().time_since_epoch();
    auto milliseconds_since_epoch = duration_cast<std::chrono::milliseconds>(time_since_epoch);
    return milliseconds_since_epoch.count();
}

long dappf::utility::time::to_milliseconds(int seconds) {
    return seconds * 1000;
}

long dappf::utility::time::to_milliseconds(int minutes, int seconds) {
    return (minutes * 60000) + dappf::utility::time::to_milliseconds(seconds);
}

long dappf::utility::time::to_milliseconds(int hours, int minutes, int seconds) {
    return (hours * 3600000) + dappf::utility::time::to_milliseconds(minutes, seconds);
}

long dappf::utility::time::to_milliseconds(int days, int hours, int minutes, int seconds) {
    return (days * 86400000) + dappf::utility::time::to_milliseconds(hours, minutes, seconds);
}