//
// Created by Vince on 10/16/2021.
//

#include "packet_writer.h"

dappf::meta::packet_writer::packet_writer() {
    packet = new std::vector<int8_t>();
}

dappf::meta::packet_writer::~packet_writer() {
    packet->clear();
    delete packet;
}

void dappf::meta::packet_writer::encode_1(int8_t n) {
    packet->push_back(n);
}

void dappf::meta::packet_writer::encode_2(int16_t n) {
    packet->push_back((int8_t) n);
    packet->push_back((int8_t)(n >> 8));
}

void dappf::meta::packet_writer::encode_4(int32_t n) {
    for(int32_t i = 0; i < 4; i++)
        packet->push_back((int8_t) (n >> (i * 8)));
}

void dappf::meta::packet_writer::encode_8(int64_t n) {
    for(int32_t i = 0; i < 8; i++)
        packet->push_back(n >> (i * 8));
}

void dappf::meta::packet_writer::encode_string(std::string s) {
    for(int32_t i = 0; i < s.length(); i++)
        packet->push_back(s.at(i));
}

int32_t dappf::meta::packet_writer::length() {
    return packet->size();
}

void dappf::meta::packet_writer::remove_n(int32_t n) {
    for(int32_t i = 0; i < std::min(n, (int32_t) packet->size()); i++){
        packet->pop_back();
    }
}

void dappf::meta::packet_writer::clear() {
    packet->clear();
}

int8_t* dappf::meta::packet_writer::to_array() {
    int32_t num_bytes = packet->size();
    int8_t* array = new int8_t[num_bytes];
    for(int32_t i = 0; i < num_bytes; i++){
        array[i] = packet->at(i);
    }
    return array;
}