//
// Created by Vince on 10/16/2021.
//

#include "packet_reader.h"
#include <stdexcept>

/**
 * Packet reader constructor. If overloaded, the present two parameters a and length
 * must be present otherwise the reader cannot run as intended.
 * @param a The bytes to be read.
 * @param length The number of bytes that are present inside of parameter a.
 */
dappf::meta::packet_reader::packet_reader(int8_t* a, int32_t length) {
    position = 0;
    packet = a;
    this->length = length;
}

/**
 * Destructor to release the buffer holding the array of bytes.
 */
dappf::meta::packet_reader::~packet_reader() {
    delete packet;
}

/**
 * Checks if the packet has enough bytes to be consumed. If not, an exception is throw.
 * Otherwise, the position is moved forward by the number of bytes to be consumed.
 * @param num_bytes The number of bytes to be consumed.
 */
void dappf::meta::packet_reader::check_and_shift(int32_t num_bytes) {
    std::string error = invalid_read_size_error + "attempt: " + std::to_string(num_bytes) + ", actual: " + std::to_string(remaining());
    if(position + num_bytes > length)
        throw std::logic_error(error);

    position += num_bytes;
}

/**
 * Reads and consumes a single byte from the packet.
 * @return Byte consumed as an int8_t.
 */
int8_t dappf::meta::packet_reader::decode_1() {
    check_and_shift(1);
    return (0xff & packet[position - 1]);
}

/**
 * Reads and consumes two bytes from the packet.
 * @return Two bytes consumed as an int16_t.
 */
int16_t dappf::meta::packet_reader::decode_2() {
    int32_t num_bytes = 2;
    check_and_shift(num_bytes);
    int32_t value = 0;
    for(int32_t i = num_bytes; i > 0; i--)
        value |= (0xff & packet[position - i]) << ((num_bytes - i) * 8);
    return value;
}

/**
 * Reads and consumes 4 bytes from the packet.
 * @return Four bytes consumed as an int32_t.
 */
int32_t dappf::meta::packet_reader::decode_4() {
    int32_t num_bytes = 4;
    check_and_shift(num_bytes);
    int32_t value = 0;
    for(int32_t i = num_bytes; i > 0; i--)
        value |= (0xff & packet[position - i]) << ((num_bytes - i) * 8);
    return value;
}

/**
 * Reads and consumes 8 bytes from the packet.
 * @return Eight bytes consumed as an int64_t.
 */
int64_t dappf::meta::packet_reader::decode_8() {
    int32_t num_bytes = 8;
    check_and_shift(num_bytes);
    int64_t value = 0;
    for(int32_t i = num_bytes; i > 0; i--)
        value |= (0xff & packet[position - i]) << ((num_bytes - i) * 8);
    return value;
}

/**
 * Reads a specified number of bytes from the buffer. Each byte read is appended
 * to a string and the string is returned once the specified number of bytes are consumed.
 * @param num_chars
 * @return
 */
std::string dappf::meta::packet_reader::decode_string(int32_t num_chars) {
    check_and_shift(num_chars);

    std::string value = "";
    for(int32_t i = position; i < position+num_chars; i++){
        value.push_back(packet[i]);
    }

    return value;
}

/**
 * The number of bytes remaining that can be read and consumed.
 * @return Number of bytes remaining that can be read and consumed.
 */
int32_t dappf::meta::packet_reader::remaining() {
    return length - position;
}

/**
 * Returns the original packet being interfaced.
 * @return packet
 */
int8_t* dappf::meta::packet_reader::get_packet(){
    return packet;
}
