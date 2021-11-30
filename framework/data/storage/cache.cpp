//
// Created by Vince on 10/17/2021.
//

#include "cache.h"
#include "doublylinkedlist.h"

//bool dappf::data::cache::exists(std::string key) {
//    // std::list<std::pair<std::string, int8_t**>>::iterator it;
//    // for(it=entries.begin(); it!=entries.end(); ++it) {
//    //     if(it->first == key) {
//    //         return true;
//    //     }
//    // }
//    if(cache_map.find(key) == cache_map.end()){
//        return false;
//    }
//    else{
//        return true;
//    }
//}
//
//void dappf::data::cache::set_cache_policy(std::function<void()>* policy){
//    cache_policy = policy;
//}
//
//std::function<void()>* dappf::data::cache::get_cache_policy(){
//    return cache_policy;
//}
//
//dappf::meta::handler* dappf::data::cache::lru_get(std::string key){
//    if(cache_map.find(key) != cache_map.end()){
//        entries->move_to_head(cache_map[key]);
//        return cache_map[key]->value;
//    }
//    return nullptr;
//}
//
//void dappf::data::cache::lru_put(std::string key, dappf::meta::handler* value){
//    if(cache_map.find(key) != cache_map.end()){
//        cache_map[key]->value = value;
//        entries->move_to_head(cache_map[key]);
//        return;
//    }
//    if(size == capacity){
//        std::string tail_key = entries->get_tail()->key;
//        cache_map.erase(tail_key);
//        entries->remove_tail();
//        size--;
//    }
//    Node* entry = entries->insert(key,value);
//    cache_map[key] = entry;
//    size++;
//}