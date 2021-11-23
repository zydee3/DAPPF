//
// Created by Kirill on 11/22/21.
//

#ifndef DAPPF_PACKET_PROCCESSING_H
#define DAPPF_PACKET_PROCCESSING_H

#include "packet_writer.h"
#include "packet_reader.h"

namespace dappf::meta::packet_processing {
    typedef struct {
        int8_t *data;
        int32_t length;
    } Message;

    Message *wrap(packet_writer *packet);
    packet_reader *unwrap(int8_t *data, int32_t length);
}

#endif //DAPPF_PACKET_PROCCESSING_H
