//
// Created by Vince on 10/16/2021.
//

#include "packet_writer.h"

/**
 * Constructor; can be overloaded as long as packet is initialized.
 */
dappf::data::packet::packet_writer::packet_writer() {
    packet = new std::vector<int8_t>();
    encode_4(0); // ipv4 address
    encode_2(0); // port
    encode_8(0); // message id
    encode_2(0); // op code
    encode_1(0); // packet_compression flag
}

/**
 * Destructor; necessary to release memory in packet and the collection itself.
 */
dappf::data::packet::packet_writer::~packet_writer() {
    packet->clear();
    delete packet;
}

/**
 * Writes a single byte to the packet.
 * @param n byte to be encoded.
 */
void dappf::data::packet::packet_writer::encode_1(int8_t n) {
    packet->push_back(n);
}

/**
 * Converts a int16_t into two bytes and writes the bytes to the packet.
 * @param n int16_t to be encoded.
 */
void dappf::data::packet::packet_writer::encode_2(int16_t n) {
    packet->push_back((int8_t) n);
    packet->push_back((int8_t)(n >> 8));
}

/**
 * Converts a int32_t into four bytes and writes the bytes to the packet.
 * @param n int32_t to be encoded.
 */
void dappf::data::packet::packet_writer::encode_4(int32_t n) {
    for(int32_t i = 0; i < 4; i++)
        packet->push_back((int8_t) (n >> (i * 8)));
}

/**
 * Converts a int64_t into eight bytes and writes the bytes to the packet.
 * @param n int64_t to be encoded.
 */
void dappf::data::packet::packet_writer::encode_8(int64_t n) {
    for(int32_t i = 0; i < 8; i++)
        packet->push_back(n >> (i * 8));
}

/**
 * Writes the provided string into the buffer by iterating character by character
 * and inserting at each iteration.
 * @param s String to be encoded.
 */
void dappf::data::packet::packet_writer::encode_string(std::string s) {
    for(int32_t i = 0; i < s.length(); i++)
        packet->push_back(s.at(i));
}

/**
 * Determines the number of bytes currently written to the packet.
 * @return The number of bytes current written to the packet.
 */
int32_t dappf::data::packet::packet_writer::length() {
    return packet->size();
}

/**
 * Removes the last n bytes written in the packet. If the number of bytes
 * to be removed is more than what is present, the packet is cleared instead.
 * @param n The number of bytes to removed.
 */
void dappf::data::packet::packet_writer::remove_n(int32_t n) {
    if(n >= packet->size()) {
        packet->clear();
    } else {
        for (int32_t i = 0; i < packet->size(); i++) {
            packet->pop_back();
        }
    }
}

/**
 * Removes all written bytes in the packet.
 */
void dappf::data::packet::packet_writer::clear() {
    packet->clear();
}

/**
 * Converts the packet to an array of bytes (int8_t).
 * @return Array of bytes (int8_t)
 */
int8_t* dappf::data::packet::packet_writer::to_array() {
    return dappf::utility::array::to_array(packet);
}