//
// Created by Vince on 10/16/2021.
//

#include "packet_writer.h"
#include "log.h"


dappf::meta::packet_writer::packet_writer() {
    packet = new std::vector<int8_t>();
    num_bytes = 0;
}

dappf::meta::packet_writer::~packet_writer() {
    delete packet;
}

void dappf::meta::packet_writer::encode_1(char c){
    packet->push_back(c);
    num_bytes++;
}

void dappf::meta::packet_writer::encode_1(int8_t n) {
    packet->push_back(n);
    num_bytes++;
}

void dappf::meta::packet_writer::encode_2(short n) {
    packet->push_back(n & 0xFF);
    packet->push_back((n & 0xFF) >> 8);
    num_bytes += 2;
}

void dappf::meta::packet_writer::encode_4(int n) {
    for(int i = 0; i < 4; i++){
        packet->push_back((n & 0xFF) >> (i * 8));
        num_bytes++;
    }
}

void dappf::meta::packet_writer::encode_8(long n) {
    for(int i = 0; i < 8; i++){
        packet->push_back((n & 0xFF) >> (i * 8));
        num_bytes++;
    }
}

void dappf::meta::packet_writer::encode_string(std::string s) {
    for(int i = 0; i < s.length(); i++){
        packet->push_back(s.at(i));
        num_bytes++;
    }
}

int dappf::meta::packet_writer::length() {
    return num_bytes;
}

void dappf::meta::packet_writer::remove_n(int n) {
    for(int i = 0; i < std::min(n, num_bytes); i++){
        packet->pop_back();
        num_bytes--;
    }
}

void dappf::meta::packet_writer::clear() {
    packet->clear();
    num_bytes = 0;
}

int8_t* dappf::meta::packet_writer::to_array() {
    int8_t* array = new int8_t[num_bytes];
    for(int i = 0; i < num_bytes; i++){
        array[i] = packet->at(i);
    }
    return array;
}