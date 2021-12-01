#include <iostream>
#include <cmath>
#include <signal.h>
#include "../framework/dappf.h"
#include "../framework/data/packet/packet_writer.h"
#include "../framework/data/packet/packet_reader.h"
#include "../framework/meta/event_listeners/on_packet_received.h"
#include "../framework/meta/event_listeners/on_packet_sent.h"
#include "../framework/meta/event_listeners/on_connection_request.h"
#include "../framework/meta/event_listeners/on_connection_established.h"
#include "../framework/meta/event_listeners/on_connection_dropped.h"
#include "../framework/utility/log.h"
#include "../test/run_test_global.h"

void interrupt_handler(int s) {
    std::cout << "interrupted" << std::endl;
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

void receive(dappf::data::packet::packet_reader *reader) {
    std::cout << reader->decode_string(reader->remaining()) << std::endl;
}

void unit_test_master(){

}

int main(int argc, char **argv) {
    if(dappf::test::run_test_global::do_tests){
        dappf::test::run_test_global::run();
        return 0;
    }

    // set all the listeners/delegates
    dappf::data::event_listeners::on_packet_received::set(receive);

    dappf::data::event_listeners::on_packet_sent::set([](int8_t *data, int32_t length) {
        std::cout << "packet sent! here it is: " << std::flush;
        dappf::utility::log::cout_hex_array(data, length);
    });

    dappf::data::event_listeners::on_internal_error::set([](std::string error) {
        std::cout << "An internal ERROR occurred, and the listener caught wind of it! here it is: " << error << std::endl;
    });

    dappf::data::event_listeners::on_connection_request::set([](std::string ip) {
        std::cout << "A node is REQUESTING TO CONNECT, from this ip: " << ip << std::endl;
    });

    dappf::data::event_listeners::on_connection_established::set([](std::string ip) {
        std::cout << "A node is has CONNECTED, from this ip: " << ip << std::endl;
    });

    dappf::data::event_listeners::on_connection_dropped::set([](std::string ip) {
        std::cout << "A connection with a node DROPPED, from this ip: " << ip << std::endl;
    });

    if (argc == 2) {
        uint16_t listen_port = strtouint16(argv[1]);

        dappf::init(listen_port);
    } else {
        std::string address(argv[1]);
        uint16_t connect_port = strtouint16(argv[2]);
        uint16_t listen_port = strtouint16(argv[3]);

        dappf::init(address, connect_port, listen_port);
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
            dappf::data::packet::packet_writer *packet = new dappf::data::packet::packet_writer;
            packet->encode_string(message);
            dappf::broadcast(packet);
            packet->clear();
            delete packet;
        } catch (std::runtime_error e) {
            std::cout << e.what() << std::endl;
        } catch (...) {
            std::cout << "An error occurred!" << std::endl;
        }
    }

    return 0;
}
