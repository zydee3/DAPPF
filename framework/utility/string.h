//
// Created by Vince on 11/23/2021.
//

#ifndef DAPPF_STRING_H
#define DAPPF_STRING_H

#include <string>
#include <vector>

namespace dappf::utility::string {

    static std::vector<int8_t>* split_as_int8(std::string, char);
    static std::vector<int16_t>* split_as_int16(std::string, char);
    static std::vector<int32_t>* split_as_int32(std::string, char);
    static std::vector<int64_t>* split_as_int64(std::string, char);
    static std::vector<std::string>* split_as_string(std::string, char);

}


#endif //DAPPF_STRING_H
