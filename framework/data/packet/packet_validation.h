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
        std::function<bool(int8_t*, int)>* handle;

    public:
        bool validate_packet(int8_t*, int);

        void set(std::function<bool(int8_t*, int)>*);
        std::function<bool(int8_t*, int)>* get();

    };
}


#endif //DAPPF_VALIDATOR_H