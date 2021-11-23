//
// Created by Kirill on 11/22/21.
//

#include <cstring>
#include "packet_preproccessing.h"

dappf::meta::packet_preprocessing::Message *dappf::meta::packet_preprocessing::wrap(meta::packet_writer *packet) {
    int8_t *data = packet->to_array();
    int32_t length = packet->length();

    // encrypt
    /*meta::packet_cipher cipher;
    cipher.get_encryptor()(data, length);*/

    // add metadata
    int8_t *data_full = new int8_t[length+14]; // unique message counter (10), body length (4)

    std::memcpy(data_full, &net.listen_port, 2);
    std::memcpy(data_full+2, &net.message_counter, 8);
    std::memcpy(data_full+10, &length, 4);
    std::memcpy(data_full+14, data, length);

    delete data;

    // compress
    int8_t **data_loc = &data_full;

    data::Compression compressor;
    length = compressor.compress(data_loc, length);

    data_full = *data_loc;
}

dappf::meta::packet_reader *dappf::meta::packet_preprocessing::unwrap(dappf::meta::packet_preprocessing::Message *message) {

}
