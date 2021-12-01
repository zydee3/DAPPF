//
// Created by Vincent Tan on 11/30/21.
//

#include "unit_test_task.h"

void dappf::test::unit_test_task::test() {
    test_can_run();
    test_execute();
}

bool dappf::test::unit_test_task::test_can_run() {
    long now = dappf::utility::time::now();
    long future = now + dappf::utility::time::to_milliseconds(1000, 1000, 1000);

    std::cout << now - future << " " << dappf::utility::time::to_milliseconds(1, 0, 0) << std::endl;

    dappf::data::task_pool::task task_1 = dappf::data::task_pool::task(now, nullptr);
    dappf::data::task_pool::task task_2 = dappf::data::task_pool::task(future, nullptr);
    bool result = task_1.can_run() && !task_2.can_run();

    std::cout << task_1.can_run() << " " <<  task_2.can_run();
    display_test_result("dappf::test::unit_test_task::test_can_run()", result);

    return result;

}
bool dappf::test::unit_test_task::test_execute() {
    long now = dappf::utility::time::now();

//    dappf::data::task_pool::task task_1 = dappf::data::task_pool::task(now, *[](){
//
//    });

    bool result;
    display_test_result("dappf::test::unit_test_task::test_execute()", result);
    return false;
}
