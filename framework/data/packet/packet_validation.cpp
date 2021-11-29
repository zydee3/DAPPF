#include "packet_validation.h"

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

bool dappf::data::packet::validation::handle(int8_t* packet, int length){

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


