//
// Created by Vince, Anthony on 11/8/2021.
//

#include "task_pool.h"

std::mutex dappf::data::task_pool::task_pool::lock;
std::vector<dappf::data::task_pool::task*> dappf::data::task_pool::task_pool::pool;

/**
 * Inserts a task into the task pool. Acquires the lock while inserting to prevent any
 * race conditions.
 * @param timestamp
 * @param task
 */
void dappf::data::task_pool::task_pool::insert(long timestamp, std::function<void()> task) {
    lock.lock();
    pool.push_back(new dappf::data::task_pool::task(timestamp, task));
    lock.unlock();
}

/**
 * Goes through the task pool one by one and checks if the task
 * can be executed. If the task can be executed then it is removed
 * from the pool and executed. The process is then repeated for the next
 * task. We hold the lock while iterating through to find the task to
 * prevent race conditions.
 */
void dappf::data::task_pool::task_pool::execute() {
    dappf::data::task_pool::task* task = nullptr;

    lock.lock();
    std::vector<dappf::data::task_pool::task*>::iterator iterator = pool.begin();
    while(iterator != pool.end()){
        if((*iterator)->can_run()){
            task = *iterator;
            pool.erase(iterator);
            break;
        }
        iterator++;
    }
    lock.unlock();

    if(task != nullptr){
        task->run();
    }
}

/**
 * Helper function for running the execution of tasks within the task pool
 * forever by bounding the execute function inside a while(true) loop. We
 * are currently busy waiting, need to implement a semaphore or conditional
 * lock in the future
 */
void dappf::data::task_pool::task_pool::run() {
    while(true){
        dappf::data::task_pool::task_pool::execute();
    }
}

/**
 * Starts the thread which infinitely runs the task pool checker.
 */
void dappf::data::task_pool::task_pool::start() {
    std::thread inf_thread (run);
}





