//
// Created by Vince on 10/16/2021.
//

#ifndef DAPPF_PACKET_WRITER_H
#define DAPPF_PACKET_WRITER_H

#include <cstddef>
#include <string>
#include <vector>

namespace dappf::meta {
    class packet_writer {
    private:
        std::vector<int8_t>* packet;
        int num_bytes;

    public:
        packet_writer();
        ~packet_writer();

        void encode_1(char);
        void encode_1(int8_t);
        void encode_2(short);
        void encode_4(int);
        void encode_8(long);
        void encode_string(std::string);

        int length();
        void remove_n(int n);
        void clear();

        int8_t* to_array();
    };
}


#endif //DAPPF_PACKET_WRITER_H
