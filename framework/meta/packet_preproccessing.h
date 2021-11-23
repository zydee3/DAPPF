//
// Created by Kirill on 11/22/21.
//

#ifndef DAPPF_PACKET_PREPROCCESSING_H
#define DAPPF_PACKET_PREPROCCESSING_H

#include "packet_writer.h"
#include "packet_reader.h"

namespace dappf::meta::packet_preprocessing {
    typedef struct {
        int8_t *data;
        int32_t length;
    } Message;

    Message *wrap(packet_writer *packet);
    packet_reader *unwrap(Message *message);
}

#endif //DAPPF_PACKET_PREPROCCESSING_H
