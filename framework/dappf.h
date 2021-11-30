//
// Created by Vince on 10/16/2021.
//

#ifndef FRAMEWORK_DAAPF_HPP
#define FRAMEWORK_DAAPF_HPP


#include <cstdint>
#include "data/packet/packet_writer.h"
#include "net/connection.h"

namespace dappf {
    enum state {
        stopped,
        running,
        paused,
    };

    static state internal_state = state::stopped;
    static uint16_t local_port;

    static connection::network net;

    void init(uint16_t listen_port);
    void init(std::string address, uint16_t connect_port, uint16_t listen_port);

    void broadcast(data::packet::packet_writer *packet);
    void broadcast(int8_t *data, int32_t length);
    void send(data::packet::packet_writer *packet, std::string address, uint16_t target_port);
}



#endif //FRAMEWORK_DAAPF_HPP
