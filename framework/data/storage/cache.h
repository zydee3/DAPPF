//
// Created by Vince on 10/17/2021.
//

#ifndef DAPPF_CACHE_H
#define DAPPF_CACHE_H

#include <list>
#include <mutex>
#include <string>
#include <utility>

namespace dappf::data {
    class cache {
    private:
        int update_interval;
        std::mutex *lock;
        std::list<std::pair<std::string, int8_t**>> entries;

    public:
        cache();
        ~cache();

        void update();

        bool exists(std::string);
        std::pair<std::string, int8_t**>* get(std::string);
        bool put(std::string, int8_t*);
    };
}


#endif //DAPPF_CACHE_H
