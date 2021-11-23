//
// Created by Kirill on 11/22/21.
//

#ifndef DAPPF_DAPPF_NETWORK_H
#define DAPPF_DAPPF_NETWORK_H


#include "net/connection.h"
#include "dappf.h"

namespace dappf {
    class DappfNetworkInterface {
    private:
        connection::network *net;
        Dappf *dappf;

        std::unordered_set<uint64_t> seen_map;

    public:
        void receive(int8_t *data, int32_t length);
    };
}

#endif //DAPPF_DAPPF_NETWORK_H
