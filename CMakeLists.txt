project(Dappf)
set(CMAKE_CXX_STANDARD 20)
cmake_minimum_required(VERSION 3.19)

# create library
add_library(
        lib SHARED # <target> <LINK_PRIVATE | LINK_PUBLIC>

        # files to be compiled
        framework/dappf.cpp framework/dappf.h
        framework/meta/packet_writer.cpp framework/meta/packet_writer.h
        framework/meta/packet_reader.cpp framework/meta/packet_reader.h
        framework/meta/log.cpp framework/meta/log.h
        framework/test/unit_test_packet.cpp framework/test/unit_test_packet.h framework/meta/packet_cipher.cpp framework/meta/packet_cipher.h framework/test/unit_test_cipher.cpp framework/test/unit_test_cipher.h)

# link entry point to project
add_executable(Dappf environment/main.cpp framework/net/connection.cpp framework/net/connection.h)

# link framework to project
target_link_libraries(Dappf lib)