//
// Created by Vince on 10/16/2021.
//

#ifndef DAPPF_UNIT_TEST_PACKET_H
#define DAPPF_UNIT_TEST_PACKET_H

#include <iostream>
#include <iomanip>
#include "unit_test.h"
#include "../utility/log.h"
#include "../data/packet/packet_reader.h"
#include "../data/packet/packet_writer.h"
#include "../utility/log.h"


namespace dappf::test {
    class unit_test_packet : unit_test {
    private:
        static bool test_1();
        static bool test_2();
        static bool test_3();
        static bool test_4();
        static bool test_5();
        static bool test_6();
    public:
        static void test();
    };
}


#endif //DAPPF_UNIT_TEST_PACKET_H
