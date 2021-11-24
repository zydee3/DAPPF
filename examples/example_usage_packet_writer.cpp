//
// Created by Vince on 11/22/2021.
//

#include "../framework/data/packet/packet_writer.h"

void example_usage_packet_reader(){
    // instantiate a new packet writer
    // packet = []
    dappf::meta::packet_writer* writer = new dappf::meta::packet_writer();

    // write a byte (1 byte) to the packet
    // packet = [05]
    writer->encode(5);

    // write a short (2 bytes) to the packet
    // packet = [05 2B 02]
    writer->encode_2(555);

    // write an integer (4 bytes) to the packet
    // packet = [05 2B 02 03 D9 00 00]
    writer->encode_4(55555);

    // write a long (8 bytes) to the packet
    // packet = [05 2B 02 03 D9 00 00 E3 08 B1 59 81 00 00 00]
    writer->encode_8(555555555555);

    // write a string to the packet
    // packet = [05 2B 02 03 D9 00 00 E3 08 B1 59 81 00 00 00 68 65 6C 6C 6F 20 77 6F 72 6C 64 21]
    writer->encode_string("hello world!");

    // array = [05 2B 02 03 D9 00 00 E3 08 B1 59 81 00 00 00 68 65 6C 6C 6F 20 77 6F 72 6C 64 21]
    int8_t* packet = writer->to_array();

    // dispose of the array
    ~packet();

    // dispose of the packet writer
    ~writer;
}
