//
// Created by Vince on 11/23/2021.
//

#ifndef DAPPF_TIME_H
#define DAPPF_TIME_H

#include <chrono>
#include <ctime>

namespace dappf::utility {
    class time {
    public:
        static long now();
        static long to_milliseconds(int);
        static long to_milliseconds(int, int);
        static long to_milliseconds(int, int, int);
        static long to_milliseconds(int, int, int, int);
    };
}


#endif //DAPPF_TIME_H
