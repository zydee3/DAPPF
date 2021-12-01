//
// Created by Vincent Tan on 11/30/21.
//

#ifndef DAPPF_RUN_TEST_GLOBAL_H
#define DAPPF_RUN_TEST_GLOBAL_H

#include "unit_test_handler.h"
#include "unit_test_packet.h"
#include "unit_test_task.h"
#include "unit_test_delegates.h"
#include "unit_test_cache.h"
#include "unit_test_spool.h"

namespace dappf::test {
    class run_test_global {
    public:
        static const bool do_tests = false;
        static const void run();
    };
}


#endif //DAPPF_RUN_TEST_GLOBAL_H
