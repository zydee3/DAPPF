//
// Created by Anthony on 11/8/2021.
//

#include "task_pool.h"

/**
 * Adds a task to the task pool queue
 * @return the uid of the task
 */
int dappf::net::task_pool::enqueue() {
    task_queue.insert(task(0, 0));
}

/**
 * Removes a task from the task pool queue
 * (only should be used if task is manually ended)
 * @uid the unique id of the task to be removed
 */
void dappf::net::task_pool::dequeue(int uid) {
    task_queue.erase(std::remove_if(task_queue.begin(), task_queue.end(),
                                    [&](const task t)-> bool { return t.uid == uid; }));
}