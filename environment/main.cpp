#include <iostream>

#include "../framework/dappf.h"
#include "../framework/net/connection.h"
#include "../framework/meta/packet_writer.h"
#include "../framework/meta/log.h"

int main() {

    dappf::meta::packet_writer* writer = new dappf::meta::packet_writer();
    writer->encode_1('c');
    writer->encode_2(2);
    writer->encode_4(4);
    writer->encode_8(8);
    writer->encode_string("hello");

    int8_t* packet = writer->to_array();
    dappf::meta::log::write_hex_array(packet, writer->length());

    return 0;
}
