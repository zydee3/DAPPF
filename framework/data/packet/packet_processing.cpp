//
// Created by Kirill on 11/22/21.
//

#include <cstring>
#include "packet_validation.h"
#include "packet_compression.h"
#include "packet_processing.h"
#include "packet_cipher.h"

dappf::meta::packet::processing::Message *dappf::meta::packet::processing::wrap_broadcast(packet_writer *packet, int16_t listen_port, int64_t counter) {
    int8_t *data = packet->to_array();
    int32_t length = packet->length();

    // encrypt
    data::packet::packet_cipher cipher;
    cipher.get_encryptor()(data, length);

    // add metadata
    // [4 bytes for ipv4] [2 bytes for port] [8 bytes for message id] [2 bytes for op code] [1 byte flag for compressed] [body]
    int8_t *data_full = new int8_t[length + dappf::constants::num_bytes_header];

    // port and address
    std::memset(data_full+dappf::constants::pos_address, 0, dappf::constants::num_bytes_address); // zero fill, this is broadcast
    std::memset(data_full+dappf::constants::pos_port, 0, dappf::constants::num_bytes_port); // zero fill, this is broadcast

    // message id (encodes address (kinda) and port)
    std::memset(data_full+dappf::constants::pos_message_id, 0, 4);
    std::memcpy(data_full+dappf::constants::pos_message_id+4, &listen_port, 2);
    std::memcpy(data_full+dappf::constants::pos_message_id+6, &counter, 2);

    std::memcpy(data_full+dappf::constants::num_bytes_header, data, length);

    delete data;

    // compress
    int8_t **data_loc = &data_full;

    data::packet::packet_compression compressor;
    length = compressor.compress(data_loc, length);

    data_full = *data_loc;

    return new Message {data_full, length};
}

dappf::meta::packet::processing::Message *dappf::meta::packet::processing::wrap_targeted(packet_writer *packet, int16_t listen_port, int64_t counter) {
    // TODO: see if the duplicated code can be made not duplicate

    int8_t *data = packet->to_array();
    int32_t length = packet->length();

    // encrypt
    data::packet::packet_cipher cipher;
    cipher.get_encryptor()(data, length);

    // add metadata
    // [4 bytes for ipv4] [2 bytes for port] [8 bytes for message id] [2 bytes for op code] [1 byte flag for compressed] [body]
    int8_t *data_full = new int8_t[length + dappf::constants::num_bytes_header];

    // port and address
    std::memset(data_full+dappf::constants::pos_address, 0, dappf::constants::num_bytes_address); // zero fill, because address isn't really known
    std::memcpy(data_full+dappf::constants::pos_port, &listen_port, dappf::constants::num_bytes_port);

    // message id (encodes address (kinda) and port)
    std::memset(data_full+dappf::constants::pos_message_id, 0, 4);
    std::memcpy(data_full+dappf::constants::pos_message_id+4, &listen_port, 2);
    std::memcpy(data_full+dappf::constants::pos_message_id+6, &counter, 2);

    std::memcpy(data_full+dappf::constants::num_bytes_header, data, length);

    delete data;

    // compress
    int8_t **data_loc = &data_full;

    data::packet::packet_compression compressor;
    length = compressor.compress(data_loc, length);

    data_full = *data_loc;

    return new Message {data_full, length};
}

dappf::meta::packet::packet_reader *dappf::meta::packet::processing::unwrap(int8_t *data, int32_t length) {

    //
}

bool need_rebroadcast(int8_t *data, int32_t length) {
    int marker_length = dappf::constants::num_bytes_address + dappf::constants::num_bytes_port;

    int8_t zero[marker_length];
    std::memset(zero, 0, marker_length);
    return std::memcmp(data, zero, marker_length) == 0;
}

void dappf::meta::packet::processing::receive(int8_t *data, int32_t length) {
    // check if we need to rebroadcast
    dappf::data::packet::validation::get();
}
