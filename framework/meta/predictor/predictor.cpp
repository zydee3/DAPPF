//
// Created by Vincent Tan on 11/28/21.
//

#include "predictor.h"

/**
 * Returns
 * @param value
 * @return
 */
std::pair<int, int> dappf::meta::predictor::predictor::get_new_pair_entry(int value) {
    std::pair<int, int> new_pair_entry;
    new_pair_entry.first = value;
    new_pair_entry.second = 1;
    return new_pair_entry;
}

std::vector<std::pair<int, int>> dappf::meta::predictor::predictor::get_new_vector_entry(int initial_value) {
    std::vector<std::pair<int, int>> new_vector_entry;
    new_vector_entry.push_back(get_new_pair_entry(initial_value));
    return new_vector_entry;
}

void dappf::meta::predictor::predictor::increment(int key, int value) {
    std::map<int, std::vector<std::pair<int, int>>>::iterator map_entry = references.find(key);

    if (map_entry == references.end()) {
        references.insert({key, get_new_vector_entry(value)});
    } else {
        std::vector<std::pair<int, int>> value_vector = (*map_entry).second;
        std::vector<std::pair<int, int>>::iterator itr = value_vector.begin();

        while (itr != value_vector.end()) {
            std::pair<int, int> &entry = *itr;
            if (entry.first == value) {
                entry.second++;
                value_vector.erase(itr);
                value_vector.push_back(*itr);
                break;
            }

            itr++;
        }

        std::pair<int, int> new_pair_entry = get_new_pair_entry(value);
        value_vector.push_back(new_pair_entry);

        if (value_vector.size() >= max_lookback) {
            value_vector.erase(value_vector.begin());
        }
    }
}

void dappf::meta::predictor::predictor::decrement(int key, int value) {
    std::map<int, std::vector<std::pair<int, int>>>::iterator map_entry = references.find(key);
    std::vector<std::pair<int, int>> value_vector = (*map_entry).second;

    for (std::vector<std::pair<int, int>>::iterator itr = value_vector.begin(); itr != value_vector.end(); itr++) {
        if ((*itr).first == value) {
            std::pair<int, int> &entry = *itr;
            entry.second++;

            if ((*itr).second <= 0) {
                value_vector.erase(itr);
            }

            break;
        }
    }
}

// step 2.  associate z to i, j, k by 2a or 2b.
void dappf::meta::predictor::predictor::associate(int value) {
    int upper_bound = previous_values.size();
    int lower_bound = std::max(0, upper_bound - max_lookback);

    for (int i = lower_bound; i < upper_bound; i++) {
        increment(previous_values[i], value);
    }
}

void dappf::meta::predictor::predictor::unassociate(int value) {
    for (int i = 0; i < lookback_values.size(); i++) {
        decrement(lookback_values[i], value);
    }
}

void dappf::meta::predictor::predictor::move() {
    lookback_values.push_back(previous_values[0]);
    previous_values.erase(previous_values.begin());
    if (lookback_values.size() >= max_lookback) {
        lookback_values.erase(lookback_values.begin());
    }
}

/** Pseudo Code For Insert
 * [lookback_values] [ previous_values ] (value)
 * [ a b c         ] [ y x x x x i j k ] (z)
 *
 *
 * INSERT z INTO previous_values
 * FOR EACH element IN [i, j, k]: (ASSOCIATE)
 *     IF references CONTAINS element THEN:
 *         LET v BE value AT element IN references
 *         LET p BE std::pair WHERE pair.first == value IN v
 *         IF p EXISTS THEN:
 *             INCREMENT p.second
 *         ELSE:
 *             p = std::pair(value, 1)
 *             INSERT p INTO v
 *             LET l BE length OF v
 *             IF l >= max_lookback THEN:
 *                 REMOVE first element OF V
 *     ELSE:
 *         LET v BE std::vector OF integers
 *         LET p = std::pair(value, 1)
 *         INSERT p INTO v
 *         INSERT v INTO references AS std::pair(element, v)
 *
 * REMOVE y FROM previous_values
 * FOR EACH element IN [a, b, c]: (UNASSOCIATE)
 *     LET v BE value AT element IN lookback_values
 *     LET p BE std::pair WHERE pair.first == y IN v
 *     DECREMENT p.second
 *     IF p.second == 0 THEN:
 *         REMOVE p FROM v
 * INSERT y INTO lookback_values
 * Let l BE length OF lookback_values
 * IF l >= max_lookback THEN:
 *     REMOVE a
 **/

/**
 *
 * @param value
 */
void dappf::meta::predictor::predictor::insert(int value) {
    if(!dappf::constants::use_spooler){
        return;
    }

    previous_values.push_back(value);
    associate(value);

    if (previous_values.size() < max_previous) {
        unassociate(previous_values[0]);
        move();
    }
}

std::vector<int> dappf::meta::predictor::predictor::predict(int key) {
    std::vector<int> predictions;

    if(dappf::constants::use_spooler) {
        std::map<int, std::vector<std::pair<int, int>>>::iterator map_entry = references.find(key);

        if (map_entry != references.end()) {
            const int total_size = previous_values.size();
            std::vector<std::pair<int, int>> value_vector = (*map_entry).second;
            for (int i = 0; i < value_vector.size(); i++) {
                std::pair<int, int> current = value_vector[i];

                double score = current.second / (1.0 * total_size);

                if (score >= min_threshold) {
                    predictions.push_back(current.first);
                }
            }
        }
    }

    return predictions;
}

void dappf::meta::predictor::predictor::set(std::function<std::vector<int>(int)>* _handle) {
    handle = _handle;
}

std::function<std::vector<int>(int)> *dappf::meta::predictor::predictor::get() {
    return handle;
}




