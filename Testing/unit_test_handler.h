//
// Created by Vincent Tan on 11/29/21.
//

#ifndef DAPPF_UNIT_TEST_HANDLER_H
#define DAPPF_UNIT_TEST_HANDLER_H

#include "../framework/meta/handlers/handler.h"
#include "unit_test.h"


namespace dappf::test {
    class unit_test_handler : unit_test {
    private:

    public:
        static void test();
    };
}

#endif //DAPPF_UNIT_TEST_HANDLER_H
