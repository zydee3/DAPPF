//
// Created by Vince on 11/1/2021.
//

#include <iostream>
#include "Compression.h"
#include "../meta/log.h"

/**
 * Tries to reduce the number of bytes in the array of bytes. If the compression
 * inflates the packet, the original array of bytes is returned with a flag byte.
 * A flag is inserted into the packet to signify if the packet was compressed.
 * @param packet Array of bytes
 * @param length Number of bytes in the array
 * @return New size of the array. This is always guaranteed to change. If the
 * array of bytes does not change, then the packet increases by 1 to contain
 * the change flag. Otherwise, the new size is equal to the compressed bytes + 1.
 */
int dappf::data::Compression::compress(int8_t* packet, int length) {
    // if the only thing to compress is the address and op code, then don't compress
    if(pos_compressed_flag >= length) return length;

    // create the new packet
    int8_t* new_packet = new int8_t[++length];
    dappf::meta::log::cout_hex_array(new_packet, length);

    // insert the flag to determine if the bytes have been compressed
    dappf::utility::array::copy_over(packet, 0, pos_compressed_flag - 1, new_packet, 0);

    std::cout << "first" << std::endl;
    dappf::meta::log::cout_hex_array(new_packet, pos_compressed_flag - 1);

    new_packet[pos_compressed_flag] = 0;

    std::cout << "second" << std::endl;
    dappf::meta::log::cout_hex_array(new_packet, pos_compressed_flag);


    dappf::utility::array::copy_over(packet, pos_compressed_flag, length - 1, new_packet, pos_compressed_flag + 1);

    std::cout << "third" << std::endl;
    dappf::meta::log::cout_hex_array(new_packet, length);

    // apply lossless compression starting after address and op code
    std::vector<int8_t>* compressed_bytes = new std::vector<int8_t>();
    for(int i = pos_compressed_flag; i < length; i++){
        int counter = 1;
        int value = new_packet[i];

        for(int j = (i + 1); j < length; j++){
            if(new_packet[j] != value) break;
            counter++;
        }

        i += (counter - 1);

        compressed_bytes->push_back(counter);
        compressed_bytes->push_back(value);
    }

    std::cout << std::endl;

    // the compression actually inflated the packet, so don't use it.
    // note, this leaves the flag as 0 (false) so whoever receives this packet
    // knows to skip the decryption process
    if(compressed_bytes->size() >= length) return length;

    // packet was successfully compressed so now we need to update the flag
    // and convert the vector into an array. also, the new packet is no longer
    // needed so we can delete it to prevent any memory leaks. everything we
    // need is inside the vector.
    delete new_packet;

    // we're using the compressed bytes, so set the flag so the receiver knows.
    compressed_bytes->at(pos_compressed_flag) = 1;
    new_packet = dappf::utility::array::to_array(compressed_bytes);

    length = compressed_bytes->size();
    compressed_bytes->clear();
    delete compressed_bytes;

    // update param packet and now the packet is now smaller or equal
    // to it's previous size.
    packet = new_packet;
    return length;
}

int dappf::data::Compression::decompress(int8_t* packet, int length) {
    // if the only things present are the address and op code or the flag
    // is 0 (false) then theres nothing to decompress.
    if(length < pos_compressed_flag && packet[pos_compressed_flag] == 0) return length;

    // will hold our uncompressed bytes.
    std::vector<int8_t>* uncompressed_bytes = new std::vector<int8_t>();

    // undo lossless compression
    for(int i = 0; i < length; i += 2){
        int num_bytes = packet[i];
        int8_t byte = packet[i+1];

        for(int j = 0; j < num_bytes; j++){
            uncompressed_bytes->push_back(byte);
        }
    }

    // we no longer need packet. delete and update it.
    delete packet;
    packet = dappf::utility::array::to_array(uncompressed_bytes);

    // get the new length
    length = uncompressed_bytes->size();

    // free memory holding vector
    uncompressed_bytes->clear();
    delete uncompressed_bytes;

    return length;
}