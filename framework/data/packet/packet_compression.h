//
// Created by Vince on 11/1/2021.
//

#ifndef DAPPF_PACKET_COMPRESSION_H
#define DAPPF_PACKET_COMPRESSION_H


#include <cstdint>
#include <vector>
#include "../../utility/array.h"

namespace dappf::data::packet {
    class packet_compression {

    protected:
        static std::vector<int8_t>* compress(int8_t*, int, int);

    public:
        static int compress(int8_t**, int);
        static int decompress(int8_t**, int);

    };
}


#endif //DAPPF_PACKET_COMPRESSION_H
