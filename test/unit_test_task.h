//
// Created by Vincent Tan on 11/30/21.
//

#ifndef DAPPF_UNIT_TEST_TASK_H
#define DAPPF_UNIT_TEST_TASK_H

#include "../framework/utility/time.h"
#include "../framework/meta/task_pool/task.h"
#include "unit_test.h"


namespace dappf::test {
    class unit_test_task : unit_test {
    private:
        static bool test_can_run();
        static bool test_execute();
    public:
        static void test();
    };
}


#endif //DAPPF_UNIT_TEST_TASK_H
