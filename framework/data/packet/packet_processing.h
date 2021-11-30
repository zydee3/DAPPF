//
// Created by Kirill on 11/22/21.
//

#ifndef DAPPF_PACKET_PROCESSING_H
#define DAPPF_PACKET_PROCESSING_H

#include "packet_writer.h"
#include "packet_reader.h"

namespace dappf::meta::packet::processing {
    typedef struct {
        int8_t *data;
        int32_t length;
    } Message;

    Message *wrap_broadcast(packet_writer *packet, int16_t listen_port, int64_t counter);
    Message *wrap_targeted(packet_writer *packet, int16_t listen_port, int64_t counter);
    packet_reader *unwrap(int8_t *data, int32_t length);

    void receive(int8_t *data, int32_t length);
}

#endif //DAPPF_PACKET_PROCESSING_H
