//
// Created by Vince, Anthony on 11/23/2021.
//

#ifndef DAPPF_TASK_H
#define DAPPF_TASK_H

#include <functional>
#include "../../utility/time.h"

namespace dappf::data::task_pool {
    class task {
    private:
        long timestamp;
        std::function<void()>* handle;

    public:
        task(long, std::function<void()>*);
        bool can_run();
        void run();
    };
}


#endif //DAPPF_TASK_H
