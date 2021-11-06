//
// Created by Vince on 11/6/2021.
//

#ifndef DAPPF_ARRAY_H
#define DAPPF_ARRAY_H


#include <cstdint>
#include <vector>

namespace dappf::utility::array {
    void copy_over(int8_t*, int, int, int8_t*, int);
    int8_t* to_array(std::vector<int8_t>*);
    int8_t* copy(int8_t*, int);
}

#endif //DAPPF_ARRAY_H
