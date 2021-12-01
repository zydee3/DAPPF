//
// Created by Kirill on 11/22/21.
//

#include <cstring>
#include "packet_validation.h"
#include "packet_compression.h"
#include "packet_processing.h"
#include "packet_cipher.h"

#include "../../meta/event_listeners/on_packet_received.h"
#include "../../dappf.h"
#include "../../meta/async_wrappers/message_id_tracker.h"

/**
 * Prepares a packet for broadcasting over the network by filling in header information, encrypting, and compressing
 * @param packet the packet to prepare
 * @param listen_port port of the source
 * @param counter message counter
 * @return the prepared data (array and length)
 */
dappf::data::packet::processing::Message *dappf::data::packet::processing::wrap_broadcast(data::packet::packet_writer *packet, int16_t listen_port, int64_t counter) {
    int8_t *data = packet->to_array();
    int32_t length = packet->length();

    // encrypt
    auto encryptor = packet_cipher::get_encryptor();
    if (encryptor) encryptor(data+dappf::constants::num_bytes_header, length); // we're not encrypting the header

    // add metadata
    // [4 bytes for ipv4] [2 bytes for port] [8 bytes for message id] [2 bytes for op code] [1 byte flag for compressed] [body]

    // port and address
    std::memset(data+dappf::constants::pos_address, 0, dappf::constants::num_bytes_address); // zero fill, this is broadcast
    std::memset(data+dappf::constants::pos_port, 0, dappf::constants::num_bytes_port); // zero fill, this is broadcast

    // message id (encodes address (kinda) and port)
    std::memset(data+dappf::constants::pos_message_id, 0, 4);
    *((uint16_t *) (data+dappf::constants::pos_message_id+4)) = listen_port;
    //std::memcpy(data+dappf::constants::pos_message_id+4, &listen_port, 2);
    *((uint16_t *) (data+dappf::constants::pos_message_id+6)) = counter;
    //std::memcpy(data+dappf::constants::pos_message_id+6, &counter, 2);

    // compress
    int8_t **data_loc = &data;

    auto compressor = packet_compression::get_compressor();
    if (compressor) length = compressor(data_loc, length);

    data = *data_loc;

    return new Message {data, length};
}

/**
 * Prepares a packet for sending to a particular target over the network by filling in header information, encrypting, and compressing
 * @param packet the packet to prepare
 * @param listen_port port of the source
 * @param counter message counter
 * @return the prepared data (array and length)
 */
dappf::data::packet::processing::Message *dappf::data::packet::processing::wrap_targeted(data::packet::packet_writer *packet, int16_t listen_port, int64_t counter) {
    // TODO: see if the duplicated code can be made not duplicate

    int8_t *data = packet->to_array();
    int32_t length = packet->length();

    // encrypt
    auto encryptor = packet_cipher::get_encryptor();
    if (encryptor) encryptor(data+dappf::constants::num_bytes_header, length-dappf::constants::num_bytes_header); // we're not encrypting the header

    // add metadata
    // [4 bytes for ipv4] [2 bytes for port] [8 bytes for message id] [2 bytes for op code] [1 byte flag for compressed] [body]

    // port and address
    std::memset(data+dappf::constants::pos_address, 0, dappf::constants::num_bytes_address); // zero fill, because address isn't really known
    std::memcpy(data+dappf::constants::pos_port, &listen_port, dappf::constants::num_bytes_port);

    // message id (encodes address (kinda) and port)
    std::memset(data+dappf::constants::pos_message_id, 0, 4);
    *((uint16_t *) (data+dappf::constants::pos_message_id+4)) = listen_port;
    //std::memcpy(data+dappf::constants::pos_message_id+4, &listen_port, 2);
    *((uint16_t *) (data+dappf::constants::pos_message_id+6)) = counter;
    //std::memcpy(data+dappf::constants::pos_message_id+6, &counter, 2);

    // compress
    int8_t **data_loc = &data;

    auto compressor = packet_compression::get_compressor();
    if (compressor) length = compressor(data_loc, length);

    data = *data_loc;

    return new Message {data, length};
}

/**
 * Takes apart a received packet by decompressing and decrypting
 * @param data the received data
 * @param length the length of the array that holds the data
 * @return the prepared data (array and length)
 */
dappf::data::packet::packet_reader *dappf::data::packet::processing::unwrap(int8_t *data, int32_t length) {
    // decompress
    int8_t **data_loc = &data;

    auto decompressor = packet_compression::get_decompressor();
    if (decompressor) length = decompressor(data_loc, length);

    data = *data_loc;

    int8_t *body = data+dappf::constants::num_bytes_header;
    int32_t body_length = length-dappf::constants::num_bytes_header;

    // decrypt
    auto decryptor = packet_cipher::get_decryptor();
    if (decryptor) decryptor(body, body_length); // the header is not encrypted

    return new packet_reader(body, body_length);
}

/**
 * Helper method that interprets a packet and determines whether it needs to be rebroadcast
 * @param data the received packet
 * @return whether the packet needs to be rebroadcast
 */
bool need_rebroadcast(int8_t *data) {
    int marker_length = dappf::constants::num_bytes_address + dappf::constants::num_bytes_port;

    int8_t zero[marker_length];
    std::memset(zero, 0, marker_length);
    return std::memcmp(data, zero, marker_length) == 0;
}

/**
 * Extracts the message id part of the header of the packet
 * @param data the received packet
 * @return the message id
 */
uint64_t dappf::data::packet::processing::extract_message_id(int8_t *data) {
    int8_t *loc = data+dappf::constants::pos_message_id;
    uint64_t *loc_casted = (uint64_t *) loc;
    uint64_t ans = *loc_casted;

    return ans;
    return *((uint64_t *) data+dappf::constants::pos_message_id);/*

    uint64_t id = 0;
    std::memcpy(&id, data+dappf::constants::pos_message_id, dappf::constants::num_bytes_message_id);
    return id;*/
}

/**
 * Extracts the op code part of the header of the packet
 * @param data the received packet
 * @return the op code
 */
uint16_t dappf::data::packet::processing::extract_op_code(int8_t *data) {
    int8_t *loc = data+dappf::constants::pos_op_code;
    uint16_t *loc_casted = (uint16_t *) loc;

    return *loc_casted;/*

    uint64_t id = 0;
    std::memcpy(&id, data+dappf::constants::pos_message_id, dappf::constants::num_bytes_message_id);
    return id;*/
}

/**
 * The method to be called when the net layer receives a packet - performs checks as needed, and
 * @param data
 * @param length
 */
void dappf::data::packet::processing::receive(int8_t *data, int32_t length) {
    if (packet_validation::validate_packet(data, length)) {
        uint64_t id = extract_message_id(data);
        if (dappf::async_wrappers::MessageIdTracker::get().contains(id)) return;

        dappf::async_wrappers::MessageIdTracker::get().insert(id);

        if (need_rebroadcast(data)) {
            dappf::broadcast(data, length);
        }

        auto on_packet_received = dappf::data::event_listeners::on_packet_received::get();
        if (on_packet_received) on_packet_received(unwrap(data, length));
    }
}
