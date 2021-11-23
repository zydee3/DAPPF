//
// Created by Vince on 10/16/2021.
//

#ifndef FRAMEWORK_DAAPF_HPP
#define FRAMEWORK_DAAPF_HPP


#include <cstdint>
#include <unordered_set>
#include "dappf_network.h"
#include "meta/packet_writer.h"

namespace dappf {
    class Dappf {
    private:
        DappfNetworkInterface interface;
        void (*on_data)(int8_t *, int32_t);

    public:
        Dappf(uint16_t listen_port, void (*handler)(int8_t *, int32_t));
        Dappf(std::string address, uint16_t connect_port, uint16_t listen_port, void (*handler)(int8_t *, int32_t));

        // i wish this weren't public to everyone
        void receive(int8_t *data, int32_t length);

        void broadcast(meta::packet_writer *packet);
        void send(meta::packet_writer *packet, std::string address, uint16_t target_port);
    };
}


#endif //FRAMEWORK_DAAPF_HPP
