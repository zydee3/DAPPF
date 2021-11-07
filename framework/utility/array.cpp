//
// Created by Vince on 11/6/2021.
//

#include "array.h"

/**
 * Copies a specified range from the reference (ref) array to the target array.
 * @param ref Reference array being copied from
 * @param ref_start Where to start the copying
 * @param ref_end Where to stop the copying
 * @param target Where the elements will be copied to
 * @param target_start Where the elements will begin being copied to
 */
void dappf::utility::array::copy_over(int8_t* ref, int ref_start, int ref_end, int8_t* target, int target_start) {
    for(int i = 0; i < (ref_end - ref_start); i++) {
        (target[target_start + i] = ref[ref_start + i]);
    }
}

#include <iostream>
/**
 * Converts a vector to an array
 * @param ref Reference vector to be converted to an array
 * @return int8_t* with the same elements as ref
 */
int8_t* dappf::utility::array::to_array(std::vector<int8_t>* ref){
    int8_t* array = new int8_t[ref->size()];
    for(int i = 0; i < ref->size(); i++) {
        array[i] = ref->at(i);
    }
    return array;
}

/**
 * Creates a copy from the reference (ref) array
 * @param ref Reference array being copied from
 * @param length Length of the reference array
 * @return copy of reference
 */
int8_t* dappf::utility::array::copy(int8_t* ref, int length){
    int8_t* array = new int8_t[length];
    for(int i = 0; i < length; i++) {
        array[i] = ref[i];
    }
    return array;
}

