//
// Created by Vince on 10/16/2021.
//

#include "packet_reader.h"
#include <stdexcept>
#include <iostream>

dappf::meta::packet_reader::packet_reader(int8_t* a, int32_t length) {
    position = 0;
    packet = a;
    this->length = length;
}

dappf::meta::packet_reader::~packet_reader() {
    delete packet;
}

void dappf::meta::packet_reader::check_and_shift(int32_t num_bytes) {
    std::string error = invalid_read_size_error + "attempt: " + std::to_string(num_bytes) + ", actual: " + std::to_string(remaining());
    if(position + num_bytes > length)
        throw std::logic_error(error);

    position += num_bytes;
}

int8_t dappf::meta::packet_reader::decode_1() {
    check_and_shift(1);
    return (0xff & packet[position - 1]);
}

int16_t dappf::meta::packet_reader::decode_2() {
    int32_t num_bytes = 2;
    check_and_shift(num_bytes);
    int32_t value = 0;
    for(int32_t i = num_bytes; i > 0; i--)
        value |= (0xff & packet[position - i]) << ((num_bytes - i) * 8);
    return value;
}

int32_t dappf::meta::packet_reader::decode_4() {
    int32_t num_bytes = 4;
    check_and_shift(num_bytes);
    int32_t value = 0;
    for(int32_t i = num_bytes; i > 0; i--)
        value |= (0xff & packet[position - i]) << ((num_bytes - i) * 8);
    return value;
}

int64_t dappf::meta::packet_reader::decode_8() {
    int32_t num_bytes = 8;
    check_and_shift(num_bytes);
    int64_t value = 0;
    for(int32_t i = num_bytes; i > 0; i--)
        value |= (0xff & packet[position - i]) << ((num_bytes - i) * 8);
    return value;
}

std::string dappf::meta::packet_reader::decode_string(int32_t num_chars) {
    check_and_shift(num_chars);

    std::string value = "";
    for(int32_t i = position; i < position+num_chars; i++){
        value.push_back(packet[i]);
    }

    return value;
}

int32_t dappf::meta::packet_reader::remaining() {
    return length - position;
}
