//
// Created by Vince on 10/16/2021.
//

#include <cstring>
#include "dappf.h"

#include "data/Compression.h"
#include "security/packet_cipher.h"
#include "net/connection.h"

/*void receive(int8_t *data_full, int32_t length) {
    // decompress
    int8_t **data_loc = &data_full;

    dappf::data::Compression compressor;
    compressor.decompress(data_loc, length);

    data_full = *data_loc;

    // decrypt
    dappf::meta::packet_cipher cipher;
    cipher.get_decryptor()(data_full, length);


}*/

void dappf::Dappf::receive(int8_t *data, int32_t length) {
    // check metadata
    uint64_t *key = (uint64_t *) data+2;
    if (seen_map.contains(*key)) return;
    seen_map.insert(*key);

    // decompress
    /*int8_t **data_loc = &data;

    dappf::data::Compression compressor;
    length = compressor.decompress(data_loc, length);

    data = *data_loc;*/

    // decrypt
    /*dappf::meta::packet_cipher cipher;
    cipher.get_decryptor()(data, length);*/

    on_data(data+14, length);
}

dappf::Dappf::Dappf(uint16_t listen_port, void (*handler)(int8_t *, int32_t)) {
    on_data = handler;
    net = connection::start_network(listen_port, receive);
}

dappf::Dappf::Dappf(std::string address, uint16_t connect_port, uint16_t listen_port, void (*handler)(int8_t *, int32_t)) {
    on_data = handler;
    net = connection::join_network(address, connect_port, listen_port, receive);
}

void dappf::Dappf::broadcast(meta::packet_writer *packet) {
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
    /*int8_t **data_loc = &data_full;

    data::Compression compressor;
    length = compressor.compress(data_loc, length);

    data_full = *data_loc;*/

    // send
    connection::broadcast_message(net.connections, data_full, length);

    delete[] data_full;
}

void dappf::Dappf::send(meta::packet_writer *packet, std::string address, uint16_t target_port) {
    int8_t *data = packet->to_array();
    int32_t length = packet->length();

    // encrypt
    meta::packet_cipher cipher;
    cipher.get_encryptor()(data, length);

    // add metadata
    int8_t *data_full = new int8_t[length+12]; // ipv4 (4), port (4), body length (4)


    // compress
    int8_t **data_loc = &data;

    data::Compression compressor;
    compressor.compress(data_loc, length);

    data = *data_loc;

    // send
    connection::broadcast_message(net.connections, data, length);

    delete data;
}
