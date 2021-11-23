#include <iostream>
#include <cmath>
#include <signal.h>
#include "../framework/dappf.h"
#include "../framework/data/Compression.h"
#include "../framework/security/packet_cipher.h"
#include "../framework/meta/event_listeners.h"

void interrupt_handler(int s) {
    std::cout << "terminating" << std::endl;
    exit(1);
}

uint16_t strtouint16(char number[]) {
    char *last;
    long num = strtol(number, &last, 10);
    if (num <= 0 || num > UINT16_MAX || *last != '\0') {
        return 0;
    }
    return num;
}

void receive(dappf::meta::packet_reader *reader) {
    std::cout << reader->decode_string(reader->remaining()) << std::endl;
}

[[noreturn]] int main(int argc, char **argv) {
    dappf::meta::packet_writer *packet = new dappf::meta::packet_writer; // this works when it's here, but not just before the while loop TODO: figure it out
    dappf::Dappf *dappf_handle;

    dappf::meta::event_listeners::set_on_packet_received_event_listener(receive);

    if (argc == 2) {
        uint16_t listen_port = strtouint16(argv[1]);

        dappf_handle = new dappf::Dappf(listen_port);
    } else {
        std::string address(argv[1]);
        uint16_t connect_port = strtouint16(argv[2]);
        uint16_t listen_port = strtouint16(argv[3]);

        dappf_handle = new dappf::Dappf(address, connect_port, listen_port);
    }

    // setup the signal handler so that we can quit gracefully
    struct sigaction sigint_handler;

    sigint_handler.sa_handler = interrupt_handler;
    sigemptyset(&sigint_handler.sa_mask);
    sigint_handler.sa_flags = 0;

    sigaction(SIGINT, &sigint_handler, NULL);

    // keep reading in from console and sending through the network
    std::string message;
    while (true) {
        std::cin >> message;

        try {
            packet->encode_string(message);
            dappf_handle->broadcast(packet);
            packet->clear();
        } catch (std::runtime_error e) {
            std::cout << e.what() << std::endl;
        } catch (...) {
            std::cout << "An error occurred!" << std::endl;
        }
    }
}
