//
// Created by Vince on 10/16/2021.
//

#include <cstring>
#include <functional>
#include <iostream>
#include "dappf.h"

#include "data/Compression.h"
#include "security/packet_cipher.h"

dappf::Dappf::Dappf(uint16_t listen_port) {
    net = connection::start_network(listen_port);
}

dappf::Dappf::Dappf(std::string address, uint16_t connect_port, uint16_t listen_port) {
    net = connection::join_network(address, connect_port, listen_port);
}

void dappf::Dappf::broadcast(meta::packet_writer *packet) {
    int8_t *data = packet->to_array();
    int32_t length = packet->length();

    // encrypt
    /*meta::packet_cipher cipher;
    cipher.get_encryptor()(data, length);*/

    // add metadata
    /*int8_t *data_full = new int8_t[length+14]; // unique message counter (10), body length (4)

    std::memcpy(data_full, &net.listen_port, 2);
    std::memcpy(data_full+2, &net.message_counter, 8);
    std::memcpy(data_full+10, &length, 4);
    std::memcpy(data_full+14, data, length);

    delete data;*/

    // compress
    /*int8_t **data_loc = &data_full;

    data::Compression compressor;
    length = compressor.compress(data_loc, length);

    data_full = *data_loc;*/

    // send
    connection::broadcast_message(net.connections, data, length);

    delete data;
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
