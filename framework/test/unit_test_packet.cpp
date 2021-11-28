//
// Created by Vince on 10/16/2021.
//

#include "unit_test_packet.h"
#include "../data/packet/packet_reader.h"
#include "../data/packet/packet_writer.h"
#include "../utility/log.h"

#include <iostream>

void dappf::test::unit_test_packet::test() {
    std::string test_message = "hello world!";

    // creating a writer
    dappf::meta::packet::packet_writer* writer = new dappf::meta::packet::packet_writer();
    writer->encode_1(22);
    writer->encode_2(32000);
    writer->encode_4(2000000);
    writer->encode_8(5000000);

    // creating the array of bytes
    int8_t* packet = writer->to_array();
    dappf::utility::log::cout_hex_array(packet, writer->length());

    // creating a reader
    dappf::meta::packet::packet_reader* reader = new dappf::meta::packet::packet_reader(packet, writer->length());
    std::cout << (uint32_t) reader->decode_1() << std::endl;
    std::cout << reader->decode_2() << std::endl;
    std::cout << reader->decode_4() << std::endl;
    std::cout << reader->decode_8() << std::endl;
}
