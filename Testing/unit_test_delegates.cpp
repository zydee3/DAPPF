//
// Created by Vincent Tan on 11/30/21.
//

#include "unit_test_delegates.h"

void dappf::test::unit_test_delegates::test() {
    test_if_settable();
    test_if_callable();
}

bool dappf::test::unit_test_delegates::test_if_settable() {
    bool test_1 = dappf::data::event_listeners::on_internal_error::get() == nullptr;

    dappf::data::event_listeners::on_internal_error::set(*[](std::string error){
        std::cout << error << std::endl;
    });

    bool test_2 = dappf::data::event_listeners::on_internal_error::get() == nullptr;;

    bool result = test_1 && test_2;
    display_test_result("dappf::Testing::  unit_test_delegates::    test_if_settable()", result);
    return result;
}

bool dappf::test::unit_test_delegates::test_if_callable() {
    std::string ipv4 = "1.1.1.1";
    std::string initial_value = dappf::test::input_output::unit_test_delegates_test_if_callable_value;

    std::function<void(std::string)> listener = dappf::data::event_listeners::on_connection_request::get();
    bool test_1 = listener == nullptr;

    dappf::data::event_listeners::on_connection_request::set(*[](std::string ipv4){
        dappf::test::input_output::unit_test_delegates_test_if_callable_value = ipv4;
    });

    listener = dappf::data::event_listeners::on_connection_request::get();
    listener(ipv4);
    bool test_2 = initial_value != dappf::test::input_output::unit_test_delegates_test_if_callable_value;

    bool result = test_1 && test_2;
    display_test_result("dappf::Testing::  unit_test_delegates::    test_if_callable()", result);
    return result;
}
