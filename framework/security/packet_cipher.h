//
// Created by Anthony on 10/28/2021.
//

#ifndef DAPPF_PACKET_CIPHER_H
#define DAPPF_PACKET_CIPHER_H

#include <string>
#include <vector>

namespace dappf::meta {
    class packet_cipher {
    private:
        //static void _encrypt(int8_t *);
        //static void _decrypt(int8_t *);

        static void encrypt(int8_t *, int32_t);
        static void decrypt(int8_t *, int32_t);

    public:
        //static void encrypt(std::vector<int8_t> *);

        auto get_encryptor() -> void(*)(int8_t*, int32_t);
        auto get_decryptor() -> void(*)(int8_t*, int32_t);
    };
}


#endif //DAPPF_PACKET_CIPHER_H
