//
// Created by Vincent Tan on 11/30/21.
//

#include "unit_test_spool.h"

void dappf::test::unit_test_spool::test() {
    dappf::data::spooler::predictor* p = new dappf::data::spooler::predictor();
    for(int i = 0; i < 100; i++) {
        p->insert(i);
        for(int j = 0; j < 5; j++){
            p->insert(0);
        }
    }

    std::vector<int> predictions = p->predict(1);
    bool result = predictions.size() > 0;
    display_test_result("dappf::Testing::  unit_test_spool::                    test()", result);
}
