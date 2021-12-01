//
// Created by Vincent Tan on 11/30/21.
//

#include "unit_test_task.h"

void dappf::test::unit_test_task::test() {
    test_can_run();
    test_execute();
}

/**
 * Tests to see if two tasks, one with a timestamp > now and timestamp < now,
 * are correctly evaluated in dappf::data::task_pool::task.can_run() as
 * false and true respectively.
 * @return True if result is correct, otherwise false
 */
bool dappf::test::unit_test_task::test_can_run() {
    long now = dappf::utility::time::now();
    long future = now + dappf::utility::time::to_milliseconds(1, 0, 0);

    dappf::data::task_pool::task task_1 = dappf::data::task_pool::task(now, nullptr);
    dappf::data::task_pool::task task_2 = dappf::data::task_pool::task(future, nullptr);
    bool result = task_1.can_run() && !task_2.can_run();

    display_test_result("dappf::Testing::  unit_test_task::             test_can_run()", result);

    return result;

}

static int testing = 0;

/**
 * Tests to see if the callback is executed properly when invoked
 * through the provided function
 * @return True if result is correct, otherwise false
 */
bool dappf::test::unit_test_task::test_execute() {
    long now = dappf::utility::time::now();
    int default_value = 50;
    dappf::test::input_output::unit_test_task_test_execute_value = default_value;

    dappf::data::task_pool::task* task = new dappf::data::task_pool::task(now, *[](){
        dappf::test::input_output::unit_test_task_test_execute_value++;
    });

    if(task->can_run()){
        task->run();
    }

    bool result = dappf::test::input_output::unit_test_task_test_execute_value != default_value;
    display_test_result("dappf::Testing::  unit_test_task::             test_execute()", result);
    return result;
}
