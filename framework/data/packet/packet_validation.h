//
// Created by Garrett, Vincent on 11/9/2021.
//

#ifndef DAPPF_VALIDATOR_H
#define DAPPF_VALIDATOR_H


#include <cstdint>
#include "../../constants.h"

namespace dappf::data::packet {
    class validation {
    private:
        bool is_valid_character(char);

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