//
// Created by Vince on 10/16/2021.
//

#include "unit_test_packet.h"

void dappf::test::unit_test_packet::test() {
    test_1(); // This test will encode numbers
    test_2(); // This test will encode a string
    test_3(); // This test attempts to read more bytes from the buffer than available.
}

/**
 * This test will encode numbers
 * @return True if result is correct, otherwise false.
 */
bool dappf::test::unit_test_packet::test_1() {
    // creating a writer
    int8_t b = 22;
    int16_t s = 32000;
    int32_t i = 2000000;
    int64_t l = 5000000;

    dappf::data::packet::packet_writer* writer = new dappf::data::packet::packet_writer();
    writer->encode_1(b);
    writer->encode_2(s);
    writer->encode_4(i);
    writer->encode_8(l);

    // creating the array of bytes
    int8_t* packet = writer->to_array();

    // creating a reader
    dappf::data::packet::packet_reader* reader = new dappf::data::packet::packet_reader(packet, writer->length());

    // consume bytes from the header
    std::string header_bytes = reader->decode_string(dappf::constants::num_bytes_header);

    bool result = reader->decode_1() == b
                && reader->decode_2() == s
                && reader->decode_4() == i
                && reader->decode_8() == l;

    display_test_result("dappf::test::unit_test_packet::test_1()", result);

    return result;
}

/**
 * This test will encode a string
 * @return True if result is correct, otherwise false
 */
bool dappf::test::unit_test_packet::test_2() {
    std::string test_string = "this is a random message";

    // create a writer
    dappf::data::packet::packet_writer* writer = new dappf::data::packet::packet_writer();
    writer->encode_string(test_string);

    // creating the array of bytes
    int8_t* packet = writer->to_array();

    // creating a reader
    dappf::data::packet::packet_reader* reader = new dappf::data::packet::packet_reader(packet, writer->length());

    // consume bytes from the header
    std::string header_bytes = reader->decode_string(dappf::constants::num_bytes_header);

    std::string decoded_string = reader->decode_string(test_string.length());

    bool result = test_string == decoded_string;

    display_test_result("dappf::test::unit_test_packet::test_2()", result);

    return result;
}

/**
 * This test attempts to read more bytes from the buffer than available.
 * @return True if result is correct, otherwise false
 */
bool dappf::test::unit_test_packet::test_3() {
    int32_t num_1 = 1000;
    int32_t num_2 = 9999;

    dappf::data::packet::packet_writer* writer = new dappf::data::packet::packet_writer();
    writer->encode_4(num_1);
    writer->encode_4(num_2);
    int8_t* packet = writer->to_array();

    // creating a reader
    dappf::data::packet::packet_reader* reader = new dappf::data::packet::packet_reader(packet, writer->length());

    // consume bytes from the header
    std::string header_bytes = reader->decode_string(dappf::constants::num_bytes_header);

    int32_t result_1 = reader->decode_4();
    int32_t result_2 = reader->decode_4();

    bool was_exception_thrown = false;

    try {
        reader->decode_1();
    } catch (std::exception& e){
        was_exception_thrown = true;
    }

    bool result = was_exception_thrown && result_1 == num_1 && result_2 == num_2;
    display_test_result("dappf::test::unit_test_packet::test_3()", result);
    return result;
}

bool dappf::test::unit_test_packet::test_4() {
    return false;
}

bool dappf::test::unit_test_packet::test_5() {
    return false;
}

bool dappf::test::unit_test_packet::test_6() {
    return false;
}


