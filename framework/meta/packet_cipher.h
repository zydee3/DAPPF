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

    public:
        //static void encrypt(std::vector<int8_t> *);
        static void encrypt(int8_t *, int32_t size);
        static void decrypt(int8_t *, int32_t size);
    };
}


#endif //DAPPF_PACKET_CIPHER_H
