//
// Created by Vince on 11/22/2021.
//

#include "../framework/meta/packet_reader.h"

/**
 * Demonstrating usage of dappf::meta::packet_reader
 * @param packet an array of bytes
 * @param packet_length number of bytes in the packet
 *
 * Note: Assume packet is an array of zero filled bytes with length 35
 */
void example_usage_packet_reader(int8_t* packet, int packet_length){

    // assume packet_length = 35
    // instantiate a new packet reader
    dappf::meta::packet_reader* reader = new dappf::meta::packet_reader(packet, packet_length);

    // read 1 byte, 34 readable bytes remain
    char c = reader->decode_1();

    // read 2 bytes, 32 readable bytes remain
    short num_1 = reader->decode_2();

    // read 4 bytes, 28 readable bytes remain
    int num_2 = reader->decode_4();

    // read 8 bytes, 20 readable bytes remain
    int num_3 = reader->decode_8();

    // read 20 bytes, 0 readable bytes remain
    std::string s = reader->decode_string(20);

    // read 4 bytes, exception thrown since no readable bytes present
    int num_4 = reader->decode_4();

    // get the original packet being interfaced
    int8_t* original_packet = reader->get_packet();

    // dispose of the packet
    ~original_packet();

    // dispose of the packet writer
    ~reader;
}
