//
// Created by Vince on 11/1/2021.
//

#ifndef DAPPF_COMPRESSION_H
#define DAPPF_COMPRESSION_H


#include <cstdint>
#include <vector>
#include "../utility/array.h"

namespace dappf::data {
    class compression {

    protected:
        static const int pos_compressed_flag = 15;

        static void insert_flag(int8_t**, int, int);
        static std::vector<int8_t>* compress(int8_t*, int, int);

    public:
        static int compress(int8_t**, int);
        static int decompress(int8_t**, int);

    };
}


#endif //DAPPF_COMPRESSION_H
