//
// Created by Vincent Tan on 11/20/21.
//

#ifndef DAPPF_UNIT_TEST_H
#define DAPPF_UNIT_TEST_H

namespace dappf::test {

    class unit_test {
    public:
        enum test_result {
            no_test, failed, success
        };

        virtual test_result test_1();
        virtual test_result test_2();
        virtual test_result test_3();
    };
}


#endif //DAPPF_UNIT_TEST_H
