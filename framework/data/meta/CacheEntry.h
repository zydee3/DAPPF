//
// Created by Vince on 10/17/2021.
//

#ifndef DAPPF_CACHEENTRY_H
#define DAPPF_CACHEENTRY_H


#include <cstdint>
#include <string>

class CacheEntry {
private:
    std::string target_address;
    std::string timestamp;
    int8_t* packet;

public:
    CacheEntry();
    ~CacheEntry();
    std::string get_target_address();
    std::string get_timestamp();
    int8_t* get_packet();

};


#endif //DAPPF_CACHEENTRY_H
