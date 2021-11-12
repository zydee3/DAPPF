//
// Created by Vince on 10/16/2021.
//

#ifndef FRAMEWORK_DAAPF_HPP
#define FRAMEWORK_DAAPF_HPP


#include <cstdint>
#include "net/connection.h"
#include "meta/packet_writer.h"

namespace dappf {
    connection::network initialize_node_new_network(uint16_t listen_port, void (*handler)(int8_t *, int32_t));
    connection::network initialize_node_existing_network(std::string address, uint16_t connect_port, uint16_t listen_port, void (*handler)(int8_t *, int32_t));

    void send(connection::network net, meta::packet_writer packet);
}


#endif //FRAMEWORK_DAAPF_HPP
