//
// Created by Kirill on 11/22/21.
//

#include <cstring>
#include "../data/compression.h"
#include "packet_proccessing.h"
#include "../security/packet_cipher.h"

dappf::meta::packet_processing::Message *dappf::meta::packet_processing::wrap(meta::packet_writer *packet) {
    int8_t *data = packet->to_array();
    int32_t length = packet->length();

    // encrypt
    security::packet_cipher cipher;
    cipher.get_encryptor()(data, length);

    // add metadata
    int8_t *data_full = new int8_t[length+14]; // unique message counter (10), body length (4)

    std::memcpy(data_full, &net.listen_port, 2);
    std::memcpy(data_full+2, &net.message_counter, 8);
    std::memcpy(data_full+10, &length, 4);
    std::memcpy(data_full+14, data, length);

    delete data;

    // compress
    int8_t **data_loc = &data_full;

    data::compression compressor;
    length = compressor.compress(data_loc, length);

    data_full = *data_loc;

    return new Message {data_full, length};
}

dappf::meta::packet_reader *dappf::meta::packet_processing::unwrap(int8_t *data, int32_t length) {

}
