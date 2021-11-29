//
// Created by Vince on 11/15/2021.
//

#ifndef DAPPF_CONSTANTS_H
#define DAPPF_CONSTANTS_H

#include <string>


namespace dappf::constants {
    // [4 bytes for ipv4] [2 bytes for port] [8 bytes for message id] [2 bytes for op code] [1 byte flag for compressed] [body]
    
    static int num_bytes_address = 4;
    static int num_bytes_port = 2;
    static int num_bytes_message_id = 8;
    static int num_bytes_op_code = 2;
    static int num_bytes_compression_flag = 1;

    static int pos_address = 0;
    static int pos_port = pos_address + num_bytes_address;
    static int pos_message_id = pos_port + num_bytes_port;
    static int pos_op_code = pos_message_id + num_bytes_message_id;
    static int pos_compression_flag = pos_op_code + num_bytes_op_code;

    static int num_bytes_header = pos_compression_flag + num_bytes_compression_flag;

    static char address_delimiter = ':';

    static bool throw_exceptions = false;
    static bool use_spooler = false;
}


#endif //DAPPF_CONSTANTS_H
