//
// Created by Vince on 11/23/2021.
//

#include "task.h"

dappf::meta::task_pool::task::task(long, std::function<void()>) {

}

dappf::meta::task_pool::task::~task() {

}

bool dappf::meta::task_pool::task::can_run() {
    return false;
}

void dappf::meta::task_pool::task::run() {

}
