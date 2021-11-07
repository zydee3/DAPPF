//
// Created by Anthony on 11/1/2021.
//

#include "unit_test_cipher.h"
#include "../meta/packet_reader.h"
#include "../meta/packet_writer.h"
#include "../meta/log.h"
#include "../security/packet_cipher.h"

#include <iostream>

void dappf::test::unit_test_cipher::test() {
    // Creates a writer
    dappf::meta::packet_writer *writer = new dappf::meta::packet_writer();
    writer->encode_1(22);
    writer->encode_2(32000);

    // Creates an array of bytes
    int8_t *packet = writer->to_array();
    dappf::meta::log::cout_hex_array(packet, writer->length()); // Prints the original packet

    // Encrypts the array
    dappf::meta::packet_cipher::encrypt(packet, writer->length());

    // Creates a reader (on the encrypted packet)
    dappf::meta::packet_reader *reader_en = new dappf::meta::packet_reader(packet, writer->length());
    std::cout << (uint32_t) reader_en->decode_1() << std::endl;
    std::cout << reader_en->decode_2() << std::endl;

    // Decrypts the array
    dappf::meta::packet_cipher::decrypt(packet, writer->length());

    // Creates a reader (on the decrypted packet)
    dappf::meta::packet_reader *reader_de = new dappf::meta::packet_reader(packet, writer->length());
    std::cout << (uint32_t) reader_de->decode_1() << std::endl;
    std::cout << reader_de->decode_2() << std::endl;
}
