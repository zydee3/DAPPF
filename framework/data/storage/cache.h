//
// Created by Vince on 10/17/2021.
//

#ifndef DAPPF_CACHE_H
#define DAPPF_CACHE_H

#include <list>
#include <mutex>
#include <string>
#include <utility>
#include <map>


#include "../../meta/handlers/handler.h"
#include "doublylinkedlist.h"

namespace dappf::data::storage {
    class cache {
    private:
//        int update_interval;
//        int capacity, size;
//        std::mutex *lock;
//        // std::list<std::pair<std::string, int8_t**>> entries;
//        // std::vector<std::pair<std::string,int>> lfu_entries;
//        DoublyLinkedList *entries;
//        map<std::string,Node*> cache_map;
//        static std::function<void()>* cache_policy;

    public:
//        cache(int capacity){
//            this->capacity = capacity;
//            size = 0;
//            entries = new DoublyLinkedList();
//        }
//        ~cache();
//
//        void update();
//
//        bool exists(std::string);
//        // std::pair<std::string, int8_t**>* get(std::string);
//        dappf::data::storage::handler* lru_get(std::string);
//        dappf::meta::handlers::handler* lfu_get(std::string);
//        // bool put(std::string, int8_t*);
//        void lru_put(std::string, dappf::meta::handler*);
//        void lfu_put(std::string, dappf::meta::handler*);
//        static void set_cache_policy(std::function<void()>*);
//        static std::function<void()>* get_cache_policy();
    };
}


#endif //DAPPF_CACHE_H
