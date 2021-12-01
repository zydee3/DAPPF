//
// Created by Vincent Tan on 11/29/21.
//

#ifndef DAPPF_UNIT_TEST_H
#define DAPPF_UNIT_TEST_H

#include <string>
#include "../framework/constants.h"
#include "../framework/utility/log.h"

namespace dappf::test {
    class unit_test {
    protected:
        static void display_test_result(std::string, bool);
    };
}


#endif //DAPPF_UNIT_TEST_H
