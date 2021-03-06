//
// Created by Vince on 10/16/2021.
//

#ifndef DAPPF_PACKET_WRITER_H
#define DAPPF_PACKET_WRITER_H

#include <string>
#include <vector>
#include <stdexcept>
#include "../../constants.h"
#include "../../utility/array.h"
#include "../../utility/string.h"


namespace dappf::data   ::packet {
    class packet_writer {
    private:
        std::vector<int8_t>* packet;

    public:
        packet_writer();
        ~packet_writer();

        void encode_1(int8_t);
        void encode_2(int16_t);
        void encode_4(int32_t);
        void encode_8(int64_t);
        void encode_string(std::string);

        int32_t length();
        void remove_n(int32_t n);
        void clear();

        int8_t* to_array();
    };
}


#endif //DAPPF_PACKET_WRITER_H
