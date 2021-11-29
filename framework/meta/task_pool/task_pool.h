//
// Created by Vince on 11/23/2021.
//

#ifndef DAPPF_TASK_POOL_H
#define DAPPF_TASK_POOL_H

#include <vector>
#include <mutex>
#include <thread>
#include "task.h"


namespace dappf::meta::task_pool {
    class task_pool {
    private:
        static std::mutex lock;
        static std::vector<dappf::meta::task_pool::task*> pool;

    public:
        static void insert(long, std::function<void()>*);
        static void execute();
        [[noreturn]]static void run();
        static void start();
    };

}

#endif //DAPPF_TASK_POOL_H
