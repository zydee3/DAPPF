//
// Created by Vince on 11/23/2021.
//

#ifndef DAPPF_TASK_H
#define DAPPF_TASK_H

#include <functional>

namespace dappf::meta::task_pool {
    class task {
    private:
        int iterations;
        long time_interval;
        long time_initialized;
        const std::function<void()> t;

        static long get_current_time();

    public:
        task(long, std::function<void()>);
        ~task();
        bool can_run();
        void run();
    };
}


#endif //DAPPF_TASK_H
