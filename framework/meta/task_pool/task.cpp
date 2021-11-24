//
// Created by Vince on 11/23/2021.
//

#include "task.h"

dappf::meta::task::task(long timestamp, std::function<void()> handler) : timestamp(timestamp), t(handler) {}

dappf::meta::task::~task(){

}
