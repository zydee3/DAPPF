//
// Created by Vince on 11/23/2021.
//

#include "task.h"

dappf::meta::task_pool::task::task(long _timestamp, std::function<void()>* _handle) {
    timestamp = _timestamp;
    handle = _handle;
}

bool dappf::meta::task_pool::task::can_run() {
    return dappf::utility::time::now() >= timestamp;
}

void dappf::meta::task_pool::task::run() {
    if(handle != nullptr){
        (*handle)();
    }
}
