//
// Created by Anthony on 11/8/2021.
//

#include "task_pool.h"

/**
 * Generates a thread-safe uid
 * ---------------------------
 * Based on code from:
 * ---------------------------
 * @return the uid
 */
int dappf::net::task_pool::generate_uid() {
    // @todo
}

/**
 * Adds a task to the task queue
 * @return the uid of the task
 */
int dappf::net::task_pool::enqueue() {
    int uid = generate_uid();
    task_queue.insert(task(uid, 0));
    return uid;
}

/**
 * Removes a task from the task queue
 * (only should be used if task is manually ended)
 * @uid the unique id of the task to be removed
 */
void dappf::net::task_pool::dequeue(int uid) {
    task_queue.erase(std::remove_if(task_queue.begin(), task_queue.end(),
                                    [&](const task t)-> bool { return t.uid == uid; }));
}


/**
 * Adds a task to the task pool
 * @return the uid of the task
 */
int add() {
    return -1; //@todo
}

/**
 * Removes a task to the task pool
 * @return 0 if the task was successfully removed
 *        -1 if the task was not found in the task pool
 */
int remove() {
    return -1; //@todo
}