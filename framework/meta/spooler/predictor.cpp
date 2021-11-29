//
// Created by Vincent Tan on 11/28/21.
//

#include "predictor.h"

/**
 * Returns a new pair with a value being parameter value and an occurrence being 1
 * @param value Value of pair.left
 * @return pair (value, 1)
 */
std::pair<int, int> dappf::meta::spooler::predictor::get_new_pair_entry(int value) {
    std::pair<int, int> new_pair_entry;
    new_pair_entry.first = value;
    new_pair_entry.second = 1;
    return new_pair_entry;
}

/**
 * Returns a new vector with an initial element where vector[0] is set to
 * a new pair with value being the parameter initial_value and the occurrence being 1
 * @param initial_value Value of vector[0].left
 * @return vector {pair (initial_value, 1) }
 */
std::vector<std::pair<int, int>> dappf::meta::spooler::predictor::get_new_vector_entry(int initial_value) {
    std::vector<std::pair<int, int>> new_vector_entry;
    new_vector_entry.push_back(get_new_pair_entry(initial_value));
    return new_vector_entry;
}

/**
 * Increments the number of occurrences of value in key. If the key doesn't exist, insert
 * a new entry with the key and a new vector with the default value of the parameter value.
 * If the key exists, then increment the occurrence of value, or insert it if the occurrence
 * counter does not exist. If the number of values exceeds the max lookback (max allowed
 * occurrences), then the least recently used value is removed.
 * @param key
 * @param value
 */
void dappf::meta::spooler::predictor::increment(int key, int value) {
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

/**
 * Decrements the number of occurrences of value in key. If the number of
 * occurrences reaches 0, that occurrence is removed instead.
 * @param key The value which the parameter value is being associated to
 * @param value The value which key is being associated with.
 */
void dappf::meta::spooler::predictor::decrement(int key, int value) {
    std::map<int, std::vector<std::pair<int, int>>>::iterator map_entry = references.find(key);
    std::vector<std::pair<int, int>> value_vector = (*map_entry).second;

    for (std::vector<std::pair<int, int>>::iterator itr = value_vector.begin(); itr != value_vector.end(); itr++) {
        if ((*itr).first == value) {
            std::pair<int, int> &entry = *itr;
            entry.second--;

            if ((*itr).second <= 0) {
                value_vector.erase(itr);
            }

            break;
        }
    }
}

/**
 * Associates the newest element to the last k (most recent) elements
 * of the previously seen elements by incrementing the occurrence of
 * value in the last k elements.
 * @param value Newly inserted value into previously seen values vector
 */
void dappf::meta::spooler::predictor::associate(int value) {
    int upper_bound = previous_values.size();
    int lower_bound = std::max(0, upper_bound - max_lookback);

    for (int i = lower_bound; i < upper_bound; i++) {
        increment(previous_values[i], value);
    }
}

/**
 * Unassociates the oldest element in the previously seen elements
 * by decrementing the occurrence in the vector of lookback values
 * @param value
 */
void dappf::meta::spooler::predictor::unassociate(int value) {
    for (int i = 0; i < lookback_values.size(); i++) {
        decrement(lookback_values[i], value);
    }
}

/**
 * Moves the oldest element from the previously seen elements E
 * to the vector of lookback values. This is so we can unassociate
 * E from the k-range of numbers prior.
 */
void dappf::meta::spooler::predictor::move() {
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
 * Required for dappf::meta::spooler::predictor::predict(int) to work. Inserts a
 * value into a list of previously seen values. See pseudo code above current function
 * or the documentation for dappf::meta::spooler::predictor::predict(int) for an in
 * depth look at how the process works for inserting and predicting
 * @param value
 */
void dappf::meta::spooler::predictor::insert(int value) {
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

/**
 * This predict only works given a set of data accumulated by values inserted
 * through dappf::meta::spooler::predictor::insert(int). Using a k-range (lookback),
 * the predictor determines a value which represents how likely a future number is to
 * appear given the history. Everytime a value is inserted, the k values before the current
 * value are associated to the current value. This association is used to determine the
 * likelihood mentioned. A max size on the number of previous values can be set (default is
 * 500). Once the max size has been reached, the first element of our list of previous values
 * (the oldest value) is removed and de-associated to the k-elements before it. This ensures
 * local min and maxes in fluctuation of predictions are accounted for.
 * @param key
 * @return
 */
std::vector<int> dappf::meta::spooler::predictor::predict(int key) {
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

/**
 * Sets function pointer to handle for predicting potential future values
 * @return dappf::meta::spooler::predictor::handle
 */
void dappf::meta::spooler::predictor::set(std::function<std::vector<int>(int)>* _handle) {
    handle = _handle;
}

/**
 * Returns function pointer to handle for predicting potential future values
 * @return dappf::meta::spooler::predictor::handle
 */
std::function<std::vector<int>(int)>* dappf::meta::spooler::predictor::get() {
    return handle;
}




