//
// Created by Anthony on 11/8/2021.
//

#ifndef DAPPF_TASK_POOL_H
#define DAPPF_TASK_POOL_H

#include <set>

namespace dappf::net {
    /**
     * A task that has been received and needs to be delivered
     * @var function is a pointer to the function that should be executed
     *      when the task is delivered
     * @var uid is a unique id that is used to identify a specific task
     * @var priority is the priority of the task in the priority queue
     * @var time is the time that the task should be delivered
     */
    struct task {
        void *function;
        int uid;
        int priority; //@todo
        int time; //@todo

        /**
         * Used to compare the priority of two tasks
         * @param t is the task that is being compared to this task
         * @return true if this < t,
         *         false if this >= t
         */
        bool operator<(const task& t) const {
            return (this->priority < t.priority);
        }

        // Constructor
        task(int uid, int priority) {
            this->uid = uid;
            this->priority = priority;
        }
    };

    /**
     * Task pool
     */
    class task_pool {
    private:
        std::set<dappf::net::task> task_queue;

        int generate_uid();
        int enqueue();
        void dequeue(int uid);
    public:
        int add(); //@todo
        int remove(); //@todo
    };
}

#endif //DAPPF_TASK_POOL_H
