//
// Created by Vince on 10/16/2021.
//

#ifndef FRAMEWORK_DAAPF_HPP
#define FRAMEWORK_DAAPF_HPP


#include <cstdint>
#include <unordered_set>
#include "meta/packet_writer.h"
#include "net/connection.h"
#include "meta/message_id_tracker.h"

namespace dappf {
    class Dappf {
    private:
        connection::network net;
        MessageIdTracker tracker;

    public:
        Dappf(uint16_t listen_port);
        Dappf(std::string address, uint16_t connect_port, uint16_t listen_port);

        void broadcast(meta::packet_writer *packet);
        void send(meta::packet_writer *packet, std::string address, uint16_t target_port);
    };
}



#endif //FRAMEWORK_DAAPF_HPP
