//
// Created by Vincent Tan on 11/30/21.
//

#ifndef DAPPF_UNIT_TEST_CACHE_H
#define DAPPF_UNIT_TEST_CACHE_H

#include "unit_test.h"

namespace dappf::test {
    class unit_test_cache : unit_test {
    private:
        static bool test_insert();
        static bool test_delete();
        static bool test_policy();
        static bool test_get();
    public:
        static void test();
    };
}


#endif //DAPPF_UNIT_TEST_CACHE_H
