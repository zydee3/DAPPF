//
// Created by Vince on 11/6/2021.
//

#include <iostream>
#include "unit_test_compression.h"
#include "../data/compression.h"
#include "../meta/packet_writer.h"
#include "../utility/log.h"

void dappf::test::unit_test_compression::unit_test_compression(){
    dappf::meta::packet_writer* writer = new dappf::meta::packet_writer();
    writer->encode_1(22);
    writer->encode_2(32000);
    writer->encode_4(2000000);
    writer->encode_8(5000000);

    // creating the array of bytes
    int8_t* packet = writer->to_array();
    std::cout << "Original: " << std::endl;
    dappf::meta::log::cout_hex_array(packet, writer->length());

    // compress the array of bytes
    std::cout << std::endl << "Compressed: " << std::endl;
    int length = dappf::data::compression::compress(&packet, writer->length());
    dappf::meta::log::cout_hex_array(packet, length);

    // decompress the array of bytes
    std::cout << std::endl << "Decompressed: " << std::endl;
    length = dappf::data::compression::decompress(&packet, length);

    dappf::meta::log::cout_hex_array(packet, length);
}