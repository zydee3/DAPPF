//
// Created by Vincent Tan on 11/29/21.
//

#include "unit_test.h"

void dappf::test::unit_test::display_test_result(std::string test_name, bool success) {
    std::string test_result = (success ? "SUCCESS" : "FAILED");
    std::string message = "TEST " + test_name + "       " + test_result;
    dappf::utility::log::info(message);
}
