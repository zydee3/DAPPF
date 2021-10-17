//
// Created by Vince on 10/16/2021.
//

#include "log.h"
#include <iostream>
#include <iomanip>
#include <vector>

void dappf::meta::log::write_hex(int32_t n) {
    std::cout << std::hex << std::setfill('0') << std::setw(2) << n << " " << std::dec;
}

void dappf::meta::log::write_hex_array(int8_t* a, int32_t length) {
    for(int32_t i = 0; i < length; i++){
        write_hex((int32_t) (0xFF & *(a + i)));
    }
    std::cout << std::endl;
}