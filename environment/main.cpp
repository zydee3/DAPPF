#include <iostream>
#include <cmath>
#include <signal.h>
#include "../framework/dappf.h"
#include "../framework/meta/log.h"

void interrupt_handler(int s) {
    std::cout << "terminating" << std::endl;
    exit(1);
}

[[noreturn]] int main() {
    std::string first_str;
    std::cout << "First node? " << std::flush;
    std::cin >> first_str;

    bool first = first_str == "y";

    dappf::connection::network net;

    if (first) {
        uint16_t listen_port;
        std::cout << "This node's port: " << std::flush;
        std::cin >> listen_port;

        net = dappf::initialize_node_new_network(listen_port, dappf::meta::log::cout_hex_array);
    } else {
        std::string address;
        uint16_t connect_port;
        std::cout << "Existing node address: " << std::flush;
        std::cin >> address;
        std::cout << "Existing node port: " << std::flush;
        std::cin >> connect_port;

        uint16_t listen_port;
        std::cout << "This node's port: " << std::flush;
        std::cin >> listen_port;

        net = dappf::initialize_node_existing_network(address, connect_port, listen_port, dappf::meta::log::cout_hex_array);
    }

    // setup the signal handler so that we can quit gracefully
    struct sigaction sigIntHandler;

    sigIntHandler.sa_handler = interrupt_handler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;

    sigaction(SIGINT, &sigIntHandler, NULL);

    // keep reading in from console and sending through the network
    std::string message;
    while (true) {
        std::cin >> message;

        try {
            dappf::meta::packet_writer packet;
            packet.encode_string(message);

            dappf::send(net, packet);
        } catch (std::runtime_error e) {
            std::cout << e.what() << std::endl;
        } catch (...) {
            std::cout << "An error occurred!" << std::endl;
        }
    }
}
