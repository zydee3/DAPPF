//
// Created by Garrett on 11/9/2021.
//

#ifndef DAPPF_VALIDATOR_H
#define DAPPF_VALIDATOR_H


#include <cstdint>

namespace dappf::data {
    class validator {

    protected:
        static const int pos_compressed_flag = 7;

        // static void insert_flag(int8_t**, int, int);
        // static std::vector<int8_t>* compress(int8_t*, int, int);

    public:
        bool handle(int8_t*, int);
        // static int decompress(int8_t*, int);

    };
}


#endif //DAPPF_VALIDATOR_H