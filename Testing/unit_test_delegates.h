//
// Created by Vincent Tan on 11/30/21.
//

#ifndef DAPPF_UNIT_TEST_DELEGATES_H
#define DAPPF_UNIT_TEST_DELEGATES_H

#include "unit_test.h"
#include <functional>
#include "../framework/meta/event_listeners/on_connection_request.h";
#include "../framework/meta/event_listeners/on_internal_error.h"
#include "input_output.h"

namespace dappf::test {
    class unit_test_delegates : unit_test {
    private:
        static bool test_if_settable();
        static bool test_if_callable();
    public:
        static void test();
    };
}

#endif //DAPPF_UNIT_TEST_DELEGATES_H
