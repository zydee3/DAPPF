//
// Created by Vince on 10/16/2021.
//

#ifndef DAPPF_LOG_H
#define DAPPF_LOG_H

#include<iostream>

namespace dappf::meta {
    class log {
    public:
        static void write_hex(int32_t);
        static void write_hex_array(int8_t*, int32_t);
    };
}


#endif //DAPPF_LOG_H
