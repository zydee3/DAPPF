//
// Created by Vince on 10/16/2021.
//

#include "unit_test_packet.h"

void dappf::test::unit_test_packet::test() {
    test_encode_numbers();
    test_encode_string();
    test_decode_exception();
    test_validation_1();
    test_validation_2();
    test_compression_1();
    test_compression_2();
    test_compression_3();
    test_decompression();
    test_cipher();
    test_decipher();
}

/**
 * This Testing will encode numbers
 * @return True if result is correct, otherwise false.
 */
bool dappf::test::unit_test_packet::test_encode_numbers() {
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

    display_test_result("dappf::Testing::  unit_test_packet::    test_encode_numbers()", result);

    return result;
}

/**
 * This Testing will encode a string
 * @return True if result is correct, otherwise false
 */
bool dappf::test::unit_test_packet::test_encode_string() {
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

    display_test_result("dappf::Testing::  unit_test_packet::     test_encode_string()", result);

    return result;
}

/**
 * This Testing attempts to read more bytes from the buffer than available.
 * @return True if result is correct, otherwise false
 */
bool dappf::test::unit_test_packet::test_decode_exception() {
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
    display_test_result("dappf::Testing::  unit_test_packet::  test_decode_exception()", result);

    return result;
}

/**
 * Tests to see if packet validates a valid packet header.
 * @return True if result is correct, otherwise false
 */
bool dappf::test::unit_test_packet::test_validation_1() {
    bool expected_result = true;

    // create packet writer
    dappf::data::packet::packet_writer* writer = new dappf::data::packet::packet_writer();

    // get array of bytes from packet writer
    int8_t* packet = writer->to_array();

    bool result = dappf::data::packet::packet_validation::validate_packet(packet, writer->length());
    display_test_result("dappf::Testing::  unit_test_packet::      test_validation_1()", result);

    return result;
}

/**
 * Tests to see if packet validator correctly determines if
 * the packet is invalid.
 * @return True if result is correct, otherwise false
 */
bool dappf::test::unit_test_packet::test_validation_2() {
    int num_bytes_in_header = dappf::constants::num_bytes_header;
    int8_t* packet = new int8_t[num_bytes_in_header];
    for(int i = 0; i < num_bytes_in_header; i++){
        packet[i] = i % 9; // arbitrary values we know are valid
    }

    // insert an invalid value
    packet[2] = (int8_t)('}');
    bool result = dappf::data::packet::packet_validation::validate_packet(packet, num_bytes_in_header);
    display_test_result("dappf::Testing::  unit_test_packet::      test_validation_2()", !result);

    return !result;
}

/**
 * Tests if the default compression implementation compresses when applicable.
 * @return True if result is correct, otherwise false
 */
bool dappf::test::unit_test_packet::test_compression_1() {
    // create packet writer
    dappf::data::packet::packet_writer* writer = new dappf::data::packet::packet_writer();

    writer->encode_4(0);
    writer->encode_2(0);
    writer->encode_8(0);
    writer->encode_2(0);
    writer->encode_1(0);
    writer->encode_8(1);
    writer->encode_8(1);
    writer->encode_8(1);
    writer->encode_8(1);

    // get array of bytes from packet writer
    int8_t* packet = writer->to_array();
    int initial_length = writer->length();
    int compressed_length = dappf::data::packet::packet_compression::compress(&packet, initial_length);

    bool result = compressed_length <= initial_length;
    display_test_result("dappf::Testing::  unit_test_packet::     test_compression_1()", result);

    return result;
}

/**
 * Tests if the default compression implementation does not compress
 * the packet when the packet is unable to be compressed. For example,
 * when there is no body present in the packet.
 * @return True if result is correct, otherwise false
 */
bool dappf::test::unit_test_packet::test_compression_2() {
    std::string test_string = "sdlsdjflkjsdlfkjdlsfjldkjfldkjflksjdlf.nvnmvksdvn.,nvkn.n.dfn";
    // create packet writer
    dappf::data::packet::packet_writer* writer = new dappf::data::packet::packet_writer();
    writer->encode_string(test_string);

    // get array of bytes from packet writer
    int8_t* packet = writer->to_array();

    int compressed_length = dappf::data::packet::packet_compression::compress(&packet, writer->length());

    bool result = compressed_length == writer->length();
    display_test_result("dappf::Testing::  unit_test_packet::     test_compression_2()", result);

    return result;
}

/**
 * Tests if the compression properly sets the flag.
 * @return True if result is correct, otherwise false
 */
bool dappf::test::unit_test_packet::test_compression_3() {
    // using test_compression_2, we know this packet cannot be compressed, thus we see
    // can check if the flag = 0

    std::string test_string = "sdlsdjflkjsdlfkjdlsfjldkjfldkjflksjdlf.nvnmvksdvn.,nvkn.n.dfn";
    // create packet writer
    dappf::data::packet::packet_writer* writer = new dappf::data::packet::packet_writer();
    writer->encode_string(test_string);

    // get array of bytes from packet writer
    int8_t* packet = writer->to_array();

    int compressed_length = dappf::data::packet::packet_compression::compress(&packet, writer->length());
    bool result = packet[dappf::constants::pos_compression_flag] == 0;
    display_test_result("dappf::Testing::  unit_test_packet::     test_compression_3()", result);

    return result;
}


/**
 * Tests if the array can be properly decompressed
 * @return True if result is correct, otherwise false
 */
bool dappf::test::unit_test_packet::test_decompression() {
    // using test_compression_1, we know that packet was successfully
    // compressed. now we check if it can be decompressed.

    // create packet writer
    dappf::data::packet::packet_writer* writer = new dappf::data::packet::packet_writer();

    writer->encode_4(0);
    writer->encode_2(0);
    writer->encode_8(0);
    writer->encode_2(0);
    writer->encode_1(0);
    writer->encode_8(1);
    writer->encode_8(1);
    writer->encode_8(1);
    writer->encode_8(1);

    // get array of bytes from packet writer
    int8_t* packet = writer->to_array();
    int initial_length = writer->length();
    int compressed_length = dappf::data::packet::packet_compression::compress(&packet, initial_length);
    int final_length = dappf::data::packet::packet_compression::decompress(&packet, compressed_length);
    bool result = compressed_length <= initial_length && initial_length == final_length + dappf::constants::num_bytes_header;
    display_test_result("dappf::Testing::  unit_test_packet::     test_decompression()", result);

    return result;
}

/**
 * Tests to see if the encrypted packet data is different than the original packet data.
 * @return True if result is correct, otherwise false
 */
bool dappf::test::unit_test_packet::test_cipher() {
    // create packet writer
    dappf::data::packet::packet_writer* writer = new dappf::data::packet::packet_writer();
    for(int i = 0; i < 9; i++){
        writer->encode_1(i); // arbitrary value
    }

    // get array of bytes from packet writer
    int8_t* packet = writer->to_array();
    int8_t* copy = writer->to_array();
    dappf::data::packet::packet_cipher::encrypt(packet, writer->length());

    bool all_elements_same = true;

    for(int i = 0; i < writer->length(); i++){
        if(copy[i] != packet[i]){
            all_elements_same = false;
            break;
        }
    }

    display_test_result("dappf::Testing::  unit_test_packet::            test_cipher()", !all_elements_same);

    return !all_elements_same;
}

/**
 * Tests to see if a packet data persist once it has been both encrypted and decrypted.
 * @return True if result is correct, otherwise false
 */
bool dappf::test::unit_test_packet::test_decipher() {
    // using test_cipher, we know the packet was encrypted
    // so we can just decrypt it and compare to the original packet

    // create packet writer
    dappf::data::packet::packet_writer* writer = new dappf::data::packet::packet_writer();
    for(int i = 0; i < 9; i++){
        writer->encode_1(i); // arbitrary value
    }

    // get array of bytes from packet writer
    int8_t* packet = writer->to_array();
    int8_t* copy = writer->to_array();
    dappf::data::packet::packet_cipher::encrypt(packet, writer->length());
    dappf::data::packet::packet_cipher::decrypt(packet, writer->length());

    bool all_elements_same = true;
    for(int i = 0; i < writer->length(); i++){
        if(copy[i] != packet[i]){
            all_elements_same = false;
            break;
        }
    }

    display_test_result("dappf::Testing::  unit_test_packet::          test_decipher()", all_elements_same);

    return all_elements_same;
}



