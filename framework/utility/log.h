//
// Created by Vince on 10/16/2021.
//

#ifndef DAPPF_LOG_H
#define DAPPF_LOG_H

#include <iostream>
#include <string>

namespace dappf::utility {
    class log {
    public:
        static void info(std::string);
        static void cout_hex(int32_t n);
        static void cout_hex_array(int8_t *a, int32_t length);
    };
}

#endif //DAPPF_LOG_H
