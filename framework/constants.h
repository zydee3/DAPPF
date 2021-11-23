//
// Created by Vince on 11/15/2021.
//

#ifndef DAPPF_CONSTANTS_H
#define DAPPF_CONSTANTS_H

#include <string>


namespace dappf::constants {
    // [4 bytes for ipv4] [2 bytes for port] [8 bytes for message id] [2 bytes for op code] [1 byte flag for compressed] [body]

    static const int num_bytes_address = 4;
    static const int num_bytes_port = 2;
    static const int num_bytes_message_id = 8;
    static const int num_bytes_op_code = 2;
    static const int num_bytes_compression_flag = 1;

    static const int pos_address = 0;
    static const int pos_port = pos_address + num_bytes_address;
    static const int pos_message_id = pos_port + num_bytes_port;
    static const int pos_op_code = pos_message_id + num_bytes_message_id;
    static const int pos_compression_flag = pos_op_code + num_bytes_op_code;

    static const int num_bytes_header = pos_compression_flag + num_bytes_compression_flag;

    static const char address_delimiter = ':';
}


#endif //DAPPF_CONSTANTS_H
