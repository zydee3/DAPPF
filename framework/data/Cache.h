//
// Created by Vince on 10/17/2021.
//

#ifndef DAPPF_CACHE_H
#define DAPPF_CACHE_H

#include <mutex>
#include <map>
#include <string>
#include "./meta/CacheEntry.h"

namespace dappf::data::meta {
    class Cache {
    private:
        int update_interval;
        std::mutex *cache_lock;
        std::map<std::string, CacheEntry*>* cache_entries;

    public:
        Cache();
        ~Cache();

        void update_cache();

        bool exists(std::string);
        int8_t* get(std::string);
        bool put(std::string, int8_t*);
    };
}



#endif //DAPPF_CACHE_H
