//
// Created by Vince on 10/16/2021.
//

#ifndef FRAMEWORK_DAAPF_HPP
#define FRAMEWORK_DAAPF_HPP


#include <cstdint>

namespace dappf {

    enum state {
        stopped,
        running,
        paused,
    };

    static state internal_state = state::stopped;
}



#endif //FRAMEWORK_DAAPF_HPP
