//
// Created by Vincent Tan on 11/28/21.
//

#ifndef DAPPF_PREDICTOR_H
#define DAPPF_PREDICTOR_H

#include <iostream>
#include <iterator>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>

#include "../../constants.h"

namespace dappf::data::spooler {
    class predictor {

    private:

        int max_lookback = 3;
        int max_previous = 500;
        int min_threshold = 3 / max_previous;

        // holds every value received in sequential order
        // max size is max_previous
        std::vector<int> previous_values;

        // holds values to decrement occurrences when a value is deleted.holds
        // max size is max_lookback
        std::vector<int> lookback_values;

        // key: associates key to list of sequential values after
        // value: list of numbers that come after the key which maintains LRU order.
        // each element is a pair, left being value, right being occurrence
        std::map<int, std::vector<std::pair<int, int>>> references;

        std::pair<int, int> get_new_pair_entry(int value);
        std::vector<std::pair<int, int>> get_new_vector_entry(int initial_value);
        void increment(int key, int value);
        void decrement(int key, int value);
        void associate(int value);
        void unassociate(int value);
        void move();

        static std::function<std::vector<int>(int)>* handle;

    public:

        void insert(int value);
        std::vector<int> predict(int key);

        static std::function<std::vector<int>(int)>* get();
        static void set(std::function<std::vector<int>(int)>*);

    };
}

#endif //DAPPF_PREDICTOR_H
