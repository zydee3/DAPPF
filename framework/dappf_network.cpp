#include "dappf_network.h"

void dappf::DappfNetwork::receive(int8_t *data, int32_t length) {
    // check metadata
    uint64_t *key = (uint64_t *) data+2;
    if (seen_map.contains(*key)) return;
    seen_map.insert(*key);

    // decompress
    /*int8_t **data_loc = &data;

    dappf::data::Compression compressor;
    length = compressor.decompress(data_loc, length);

    data = *data_loc;*/

    // decrypt
    /*dappf::meta::packet_cipher cipher;
    cipher.get_decryptor()(data, length);*/

    dappf::meta::event_listeners::get_on_packet_received_event_listener()(data+14, length);
}
