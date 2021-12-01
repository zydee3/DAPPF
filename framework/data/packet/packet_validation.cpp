#include "packet_validation.h"
#include <iostream>

/**
 * Checks if the char is a valid char present inside the packet header
 * @param c Char to be tested
 * @return True if char c is valid, otherwise false
 */
bool dappf::data::packet::packet_validation::is_valid_character(char c) {

    int lower_bound = (int) '0';
    int upper_bound = (int) '9';

    return lower_bound <= c && c <= upper_bound;

//    switch(c){
//        case ':':
//        case '.':
//            return true;
//        default:
//            return false;
//    }
}

/**
 * Checks whether a received packet is valid - the only distinguishing mark we can rely on, however, is the length
 * @param packet Array of bytes
 * @param length Number of elements in packet
 * @return True if the entire packet header contains enough characters to include at least the header
 */
bool dappf::data::packet::packet_validation::validate_packet(int8_t* packet, int length) {
    return length >= dappf::constants::num_bytes_header;

    const int num_bytes_header = dappf::constants::num_bytes_header;
    if (length < num_bytes_header) {
        return false;
    }

    // check ipv4 fields
    for (int i = 0; i < dappf::constants::num_bytes_address; i++) {
        int current_field = (*(packet + i));
        if (current_field < 0 || current_field > 9) {
            return false;
        }
    }

    // check the port is within 0 and 32767
    int pos_port = dappf::constants::pos_port;
    short port = packet[pos_port] | packet[pos_port + 1] << 8;
    if (port < 0) {
        return false;
    }

    for (int i = dappf::constants::pos_message_id;
         i < dappf::constants::pos_compression_flag + dappf::constants::num_bytes_compression_flag; i++) {
        int current_field = (*(packet + i));
        if (current_field < 0 || current_field > 9) {
            return false;
        }

        return true;
    }
}
