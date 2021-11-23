//
// Created by Vince on 10/16/2021.
//

#include "log.h"
#include <iostream>
#include <iomanip>

/**
 * Converts a byte into a hexadecimal and prints it out. Its important to convert
 * the byte to an int as printing out a single byte and/or int8_t will result in the
 * char representation being printed out.
 * @param n byte to be printed as a hexadecimal.
 */
void dappf::utility::log::cout_hex(int32_t n) {
    std::cout << std::hex << std::setfill('0') << std::setw(2) << n << " " << std::dec;
}

/**
 * Writes each byte (int8_t) as a hexadecimal and prints it out. The result
 * is a packet where each value is a hexadecimal.
 * @param a array of bytes (int8_t) to be printed.
 * @param length number of elements inside provided array of bytes (int8_t).
 */
void dappf::utility::log::cout_hex_array(int8_t* a, int32_t length) {
    for(int32_t i = 0; i < length; i++){
        cout_hex((int32_t) (0xFF & *(a + i)));
    }
    std::cout << std::endl;
}