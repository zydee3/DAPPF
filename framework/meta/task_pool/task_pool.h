//
// Created by Vince on 11/23/2021.
//

#ifndef DAPPF_TASK_POOL_H
#define DAPPF_TASK_POOL_H

#include <vector>
#include "task.h"

namespace dappf::meta {
    class task_pool {
    private:
        std::vector<dappf::meta::task> pool;
    public:
        void insert(long, std::function<void()>);

    };

}

#endif //DAPPF_TASK_POOL_H
