//
// Created by Vince on 10/16/2021.
//

#ifndef DAPPF_PACKET_READER_H
#define DAPPF_PACKET_READER_H

#include <string>

namespace dappf::meta::packet {
    class packet_reader {
    private:
        int32_t length;
        int32_t position;
        int8_t* packet;
        std::string invalid_read_size_error = "[packet_reader] attempting to read more bytes than available.";

        void check_and_shift(int);

    public:
        packet_reader(int8_t*, int32_t);
        ~packet_reader();

        int8_t decode_1();
        int16_t decode_2();
        int32_t decode_4();
        int64_t decode_8();
        std::string decode_string(int32_t);
        int32_t remaining();

        int8_t* get_packet();
    };
}


#endif //DAPPF_PACKET_READER_H
