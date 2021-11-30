//
// Created by Vince on 11/1/2021.
//

#ifndef DAPPF_PACKET_COMPRESSION_H
#define DAPPF_PACKET_COMPRESSION_H

#include <functional>
#include <cstdint>
#include <vector>
#include "../../utility/array.h"

namespace dappf::data::packet {
    class packet_compression {

    protected:
        static std::vector<int8_t>* compress(int8_t*, int, int);
        static std::function<int(int8_t**, int)>* handle_compress;
        static std::function<int(int8_t**, int)>* handle_decompress;
    public:
        static int compress(int8_t**, int);
        static int decompress(int8_t**, int);

        static void set_compressor(std::function<int(int8_t**, int)>*);
        static std::function<int(int8_t**, int)>* get_compressor();

        static void set_decompressor(std::function<int(int8_t**, int)>*);
        static std::function<int(int8_t**, int)>* get_decompressor();
    };
}


#endif //DAPPF_PACKET_COMPRESSION_H
