//
// Created by Vincent Tan on 11/30/21.
//

#include "run_test_global.h"

const void dappf::test::run_test_global::run() {
    dappf::test::unit_test_packet::test();
    dappf::test::unit_test_task::test();
    dappf::test::unit_test_delegates::test();
    dappf::test::unit_test_cache::test();
    dappf::test::unit_test_spool::test();

}
