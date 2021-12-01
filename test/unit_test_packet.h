//
// Created by Vince on 10/16/2021.
//

#ifndef DAPPF_UNIT_TEST_PACKET_H
#define DAPPF_UNIT_TEST_PACKET_H

#include <iostream>
#include <iomanip>
#include "unit_test.h"
#include "../framework/constants.h"
#include "../framework/utility/log.h"
#include "../framework/data/packet/packet_reader.h"
#include "../framework/data/packet/packet_writer.h"
#include "../framework/data/packet/packet_validation.h"
#include "../framework/data/packet/packet_compression.h"
#include "../framework/data/packet/packet_cipher.h"
#include "../framework/utility/log.h"


namespace dappf::test {
    class unit_test_packet : unit_test {
    private:
        static bool test_encode_numbers();
        static bool test_encode_string();
        static bool test_decode_exception();
        static bool test_validation_1();
        static bool test_validation_2();
        static bool test_compression_1();
        static bool test_compression_2();
        static bool test_compression_3();
        static bool test_decompression();
        static bool test_cipher();
        static bool test_decipher();
    public:
        static void test();
    };
}


#endif //DAPPF_UNIT_TEST_PACKET_H
