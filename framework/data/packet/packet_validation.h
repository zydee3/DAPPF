//
// Created by Garrett, Vincent on 11/9/2021.
//

#ifndef DAPPF_VALIDATOR_H
#define DAPPF_VALIDATOR_H


#include <cstdint>
#include <functional>
#include "../../constants.h"

namespace dappf::data::packet {
    class validation {
    private:
        bool is_valid_character(char);

    public:
        bool validate_packet(int8_t*, int);

    };
}


#endif //DAPPF_VALIDATOR_H