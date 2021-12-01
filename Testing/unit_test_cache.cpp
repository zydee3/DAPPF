//
// Created by Vincent Tan on 11/30/21.
//

#include "unit_test_cache.h"

void dappf::test::unit_test_cache::test() {
    test_insert();
    test_get();
    test_delete();
    test_policy();
}

bool dappf::test::unit_test_cache::test_get() {
    bool result;
    display_test_result("dappf::Testing::  unit_test_cache::                test_get()", result);
    return false;
}

bool dappf::test::unit_test_cache::test_policy() {
    bool result;
    display_test_result("dappf::Testing::  unit_test_cache::             test_policy()", result);
    return false;
}

bool dappf::test::unit_test_cache::test_delete() {
    bool result;
    display_test_result("dappf::Testing::  unit_test_cache::             test_delete()", result);
    return false;
}

bool dappf::test::unit_test_cache::test_insert() {
    bool result;
    display_test_result("dappf::Testing::  unit_test_cache::             test_insert()", result);
    return false;
}
