//
// Created by Anthony on 10/28/2021.
//

#ifndef DAPPF_PACKET_CIPHER_H
#define DAPPF_PACKET_CIPHER_H

#include <string>
#include <vector>
#include <functional>

namespace dappf::data::packet {
    class packet_cipher {
    private:
        static std::function<void(int8_t*, int32_t)> encryptor;
        static std::function<void(int8_t*, int32_t)> decryptor;
    public:
        static void encrypt(int8_t *, int32_t);
        static void decrypt(int8_t *, int32_t);

        static std::function<void(int8_t*, int32_t)> get_encryptor();
        static void set_encryptor(std::function<void(int8_t*, int32_t)>);

        static std::function<void(int8_t*, int32_t)> get_decryptor();
        static void set_decryptor(std::function<void(int8_t*, int32_t)>);
    };
}


#endif //DAPPF_PACKET_CIPHER_H
