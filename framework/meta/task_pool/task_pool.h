//
// Created by Vince on 11/23/2021.
//

#ifndef DAPPF_TASK_POOL_H
#define DAPPF_TASK_POOL_H

#include <vector>
#include "task.h"

namespace dappf::meta::task_pool {
    class task_pool {
    private:
        std::vector<dappf::meta::task_pool::task> pool;
    public:
        void insert(long, std::function<void()>);

    };

}

#endif //DAPPF_TASK_POOL_H
