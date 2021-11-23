//
// Created by Vince on 11/23/2021.
//

#include "string.h"

static std::vector<int8_t>* split_as_int8(std::string s, char delimiter){
    std::vector<int8_t>* values = new std::vector<int8_t>();

    char current_char;
    std::string value;
    int length = s.length();

    for(int i = 0; i < length; i++){
        current_char = s.at(i);
        if(current_char == delimiter || i == (length - 1)){
            if (i == (length - 1))
                value += current_char;
            values->push_back((int8_t) std::stoi(value));
            value = "";
        } else {
            value += current_char;
        }
    }

    return values;
}

static std::vector<int16_t>* split_as_int16(std::string, char delimiter){

}

static std::vector<int32_t>* split_as_int32(std::string, char delimiter){

}

static std::vector<int64_t>* split_as_int64(std::string, char delimiter){

}

static std::vector<std::string>* split_as_string(std::string, char delimiter){

}
