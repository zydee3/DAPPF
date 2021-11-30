//
// Created by Vince on 10/16/2021.
//

#ifndef FRAMEWORK_DAAPF_HPP
#define FRAMEWORK_DAAPF_HPP


#include <cstdint>
#include <unordered_set>
#include "data/packet/packet_writer.h"
#include "net/connection.h"
#include "meta/async_wrappers/message_id_tracker.h"
#include "meta/async_wrappers/message_counter.h"

namespace dappf {
    enum state {
        stopped,
        running,
        paused,
    };

    static state internal_state = state::stopped;
    static uint16_t local_port;

    class Dappf {
    private:
        connection::network net;

    public:
        Dappf(uint16_t listen_port);
        Dappf(std::string address, uint16_t connect_port, uint16_t listen_port);

        void broadcast(meta::packet::packet_writer *packet);
        void send(meta::packet::packet_writer *packet, std::string address, uint16_t target_port);
    };
}



#endif //FRAMEWORK_DAAPF_HPP
