//
// Created by Vince on 11/1/2021.
//

#include "packet_compression.h"
#include "../../utility/log.h"
#include "../../constants.h"

std::function<int(int8_t**, int)>* dappf::data::packet::packet_compression::handle_compress;
std::function<int(int8_t**, int)>* dappf::data::packet::packet_compression::handle_decompress;

/**
 * Helper function for the public compress function. This function specifically
 * performs only the reduction of bytes using a lossless method. This function
 * compresses the packet's bytes with indexes between start and finish: [start, finish)
 * @param packet Array of bytes
 * @param start Where to begin compressing the packet
 * @param end Where to stop compressing the packet
 * @return The compressed packet
 */
std::vector<int8_t>* dappf::data::packet::packet_compression::compress(int8_t* packet, int start, int end){
    std::vector<int8_t>* compressed_bytes = new std::vector<int8_t>();

    for(int i = 0; i < start; i++){
        compressed_bytes->push_back(packet[i]);
    }

    for(int i = start; i < end; i++){
        int counter = 1;
        int value = packet[i];

        for(int j = (i + 1); j < end; j++){
            if(packet[j] != value) break;
            counter++;
        }

        i += (counter - 1);

        compressed_bytes->push_back(counter);
        compressed_bytes->push_back(value);
    }
    return compressed_bytes;
}

/**
 * Tries to reduce the number of bytes in the array of bytes. If the packet_compression
 * inflates the packet, the original array of bytes is returned with a flag byte.
 * A flag is inserted into the packet to signify if the packet was compressed.
 * @param packet Array of bytes
 * @param length Number of bytes in the array
 * @return New size of the array. This is always guaranteed to change. If the
 * array of bytes does not change, then the packet increases by 1 to contain
 * the change flag. Otherwise, the new size is equal to the compressed bytes + 1.
 */
int dappf::data::packet::packet_compression::compress(int8_t** packet, int length) {
    // if the only thing to compress is the address and op code, then don't compress
    if(dappf::constants::num_bytes_header >= length) return length;

    // apply lossless packet_compression starting after address and op code
    std::vector<int8_t>* compressed_bytes = dappf::data::packet::packet_compression::compress(*packet, dappf::constants::num_bytes_header + 1, length);

    if(compressed_bytes->size() >= length) {
        // the packet_compression actually inflated the packet, so don't use it.
        // note, this leaves the flag as 0 (false) so whoever receives this packet
        // knows to skip the decryption process
        compressed_bytes->clear();
        delete compressed_bytes;

    } else {
        // packet was successfully compressed so now we need to update the flag
        // and convert the vector into an array. also, the new packet is no longer
        // needed so we can delete it to prevent any memory leaks. everything we
        // need is inside the vector.
        //delete packet;

        // we're using the compressed bytes, so set the flag so the receiver knows
        // the bytes were compressed
        compressed_bytes->at(dappf::constants::pos_compression_flag) = 1;

        *packet = dappf::utility::array::to_array(compressed_bytes);

        length = compressed_bytes->size();
        compressed_bytes->clear();
        delete compressed_bytes;
    }

    return length;
}

/**
 * Tries to undo the packet compression done by dappf::data::packet::packet_compression::compress(int8_t**, int).
 * First checks to see if the flag has been set signifying if the packet was compressed. Flag = 1 if compressed,
 * otherwise 0. If compressed, then perform the associated decompression.
 * @param packet Array of bytes
 * @param length Number of bytes in the packet
 * @return Decompressed packet if the given packet was compressed, otherwise the original packet.
 */
int dappf::data::packet::packet_compression::decompress(int8_t** packet, int length) {
    // if the only things present are the address and op code or the flag
    // is 0 (false) then theres nothing to decompress.
    if(length <= dappf::constants::num_bytes_header || *(*packet + dappf::constants::pos_compression_flag) == 0) return length;
    //dappf::utility::log::cout_hex_array(*packet, length);

    // will hold our uncompressed bytes.
    std::vector<int8_t>* uncompressed_bytes = new std::vector<int8_t>();

    int8_t* p = *packet;

    // undo lossless packet_compression
    for(int i = 0; i < length; i += 2){
        int num_bytes = p[i];
        int8_t byte = p[i+1];

        for(int j = 0; j < num_bytes; j++){
            uncompressed_bytes->push_back(byte);
        }
    }

    // we no longer need packet. delete and update it.
    //delete packet;
    *packet = dappf::utility::array::to_array(uncompressed_bytes);
    // get the new length
    length = uncompressed_bytes->size();

    // free memory holding vector
    uncompressed_bytes->clear();
    delete uncompressed_bytes;

    return length;
}

void dappf::data::packet::packet_compression::set_compressor(std::function<int(int8_t **, int)>* handle) {
    handle_compress = handle;
}

std::function<int(int8_t **, int)> *dappf::data::packet::packet_compression::get_compressor() {
    return handle_compress;
}

void dappf::data::packet::packet_compression::set_decompressor(std::function<int(int8_t **, int)>* handle) {
    handle_decompress = handle;
}

std::function<int(int8_t **, int)> *dappf::data::packet::packet_compression::get_decompressor() {
    return handle_decompress;
}
