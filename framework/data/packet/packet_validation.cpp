#include "packet_validation.h"

/**
 * Checks if the char is a valid char present inside the packet header
 * @param c Char to be tested
 * @return True if char c is valid, otherwise false
 */
bool dappf::data::packet::validation::is_valid_character(char c) {

    int lower_bound = (int) '0';
    int upper_bound = (int) '9';
    return c >= lower_bound && c <= upper_bound;

//    switch(c){
//        case ':':
//        case '.':
//            return true;
//        default:
//            return false;
//    }
}

/**
 * Checks to see if the packet header is valid by iterating through the
 * packet header element by element and checking if the byte is a valid
 * byte to be contained in the packet header
 * @param packet Array of bytes
 * @param length Number of elements in packet
 * @return True if the entire packet header contains only valid characters, otherwise false
 */
bool dappf::data::packet::validation::validate_packet(int8_t* packet, int length){

    const int num_bytes_header = dappf::constants::num_bytes_header;
    if(length < num_bytes_header){
        return false;
    }

    for(int i = 0; i < num_bytes_header; i++){
        if(!dappf::data::packet::validation::is_valid_character((char) (*(packet + i)))){
            return false;
        }
    }

  return true;
}

