//
// Created by Anthony on 10/28/2021.
//

#include "packet_cipher.h"

#include <algorithm>    // std::for_each
#include <stdexcept>

#define BIT_SHIFT 3


/*
 * BEGIN FOREIGN CODE
 *
 * Author: Peter A. Bigot (GitHub user pabigot)
 * URL: https://gist.github.com/pabigot/7550454
 *
 * Purpose: Creative way to implement circular shift in C++
 *          without unintended behavior.
 */

/* See http://blog.regehr.org/archives/1063
 */
#include <type_traits>
#include <cstdint>
#include <limits>
#include <typeinfo>

#ifndef ARGTYPE
#define ARGTYPE uint32_t
#endif /* ARGTYPE */

using argtype = ARGTYPE;

template <typename T>
T
rotl (T v, unsigned int b)
{
    static_assert(std::is_integral<T>::value, "rotate of non-integral type");
    static_assert(! std::is_signed<T>::value, "rotate of signed type");
    constexpr unsigned int num_bits {std::numeric_limits<T>::digits};
    static_assert(0 == (num_bits & (num_bits - 1)), "rotate value bit length not power of two");
    constexpr unsigned int count_mask {num_bits - 1};
    const unsigned int mb {b & count_mask};
    using promoted_type = typename std::common_type<int, T>::type;
    using unsigned_promoted_type = typename std::make_unsigned<promoted_type>::type;
    return ((unsigned_promoted_type{v} << mb)
            | (unsigned_promoted_type{v} >> (-mb & count_mask)));
}

template <typename T>
T
rotr (T v, unsigned int b)
{
    static_assert(std::is_integral<T>::value, "rotate of non-integral type");
    static_assert(! std::is_signed<T>::value, "rotate of signed type");
    constexpr unsigned int num_bits {std::numeric_limits<T>::digits};
    static_assert(0 == (num_bits & (num_bits - 1)), "rotate value bit length not power of two");
    constexpr unsigned int count_mask {num_bits - 1};
    const unsigned int mb {b & count_mask};
    using promoted_type = typename std::common_type<int, T>::type;
    using unsigned_promoted_type = typename std::make_unsigned<promoted_type>::type;
    return ((unsigned_promoted_type{v} >> mb)
            | (unsigned_promoted_type{v} << (-mb & count_mask)));
}

argtype
rotl32d (argtype v,
         unsigned int b)
{
    return rotl(v, b);
}

argtype
rotr32d (argtype v,
         unsigned int b)
{
    return rotr(v, b);
}
/*
 * END FOREIGN CODE
 */

// Deprecated for now. Might need commented functions in future
///**
// * Encrypts the contents of a packet using Caesar's cipher
// * @param packet is the packet to be encrypted
// */
//void dappf::meta::packet_cipher::encrypt(std::vector<int8_t> *packet) {
//    std::for_each(packet->begin(), packet->end(), _encrypt);
//}
//
///**
// * Helper function for packet_cipher::encrypt()
// * @param current_byte is the byte to be encrypted
// */
//void dappf::meta::packet_cipher::_encrypt(int8_t *current_byte) {
//    *current_byte = *current_byte << BIT_SHIFT;
//}

/**
 * Encrypts the contents of a packet using Caesar's cipher
 * @param array is the array of bytes to be encrypted
 * @param length is the length of the array
 */
void dappf::security::packet_cipher::encrypt(int8_t *array, int32_t length) {
    std::string error_null = "[packet_cipher] attempting to encrypt null data.";
    std::string error_size = "[packet_cipher] attempting to read an invalid amount of bytes.";
    if (array == nullptr)
        throw std::logic_error(error_null);
    else if (length < 1)
        throw std::logic_error(error_size);

    for (int32_t i=0; i < length; i++) {
        array[i] = rotl32d(array[i], BIT_SHIFT);
    }
}

/**
 * Decrypts the contents of a packet using Caesar's cipher
 * @param array is the array of bytes to be decrypted
 * @param length is the length of the array
 */
void dappf::security::packet_cipher::decrypt(int8_t *array, int32_t length) {
    std::string error_null = "[packet_cipher] attempting to decrypt null data.";
    std::string error_size = "[packet_cipher] attempting to read an invalid amount of bytes.";
    if (array == nullptr)
        throw std::logic_error(error_null);
    else if (length < 1)
        throw std::logic_error(error_size);

    for (int32_t i=0; i < length; i++) {
        array[i] = rotr32d(array[i], BIT_SHIFT);
    }
}
//
///**
// * Helper function for packet_cipher::decrypt()
// * @param current_byte is the byte to be decrypted
// */
//void dappf::meta::packet_cipher::_decrypt(int8_t *current_byte) {
//    *current_byte = *current_byte >> BIT_SHIFT;
//}

auto dappf::security::packet_cipher::get_encryptor() -> void(*)(int8_t *, int32_t){
    return &dappf::security::packet_cipher::encrypt;
}

auto dappf::security::packet_cipher::get_decryptor() -> void(*)(int8_t *, int32_t){
    return &dappf::security::packet_cipher::decrypt;
}
