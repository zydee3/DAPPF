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
        //static void _encrypt(int8_t *);
        //static void _decrypt(int8_t *);

        static void encrypt(int8_t *, int32_t);
        static void decrypt(int8_t *, int32_t);

    public:

        auto get_encryptor() -> std::function<void(int8_t*, int32_t)>;
        auto get_decryptor() -> std::function<void(int8_t*, int32_t)>;
    };
}


#endif //DAPPF_PACKET_CIPHER_H
