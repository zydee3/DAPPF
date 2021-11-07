project(Dappf)
set(CMAKE_CXX_STANDARD 20)
cmake_minimum_required(VERSION 3.19)

# create library
add_library(
        lib SHARED # <target> <LINK_PRIVATE | LINK_PUBLIC>

        # files to be compiled
        framework/dappf.h
        framework/dappf.cpp

        framework/meta/packet_writer.h
        framework/meta/packet_writer.cpp

        framework/meta/packet_reader.h
        framework/meta/packet_reader.cpp

        framework/meta/log.h
        framework/meta/log.cpp

        framework/test/unit_test_packet.h
        framework/test/unit_test_packet.cpp

        framework/data/Cache.h
        framework/data/Cache.cpp

        framework/data/meta/CacheEntry.h
        framework/data/meta/CacheEntry.cpp

        framework/data/Compression.h
        framework/data/Compression.cpp

        framework/test/unit_test_compression.h
        framework/test/unit_test_compression.cpp

        framework/net/connection.h
        framework/net/connection.cpp

        framework/utility/tree.h
        framework/utility/tree.cpp

        framework/utility/tree_node.h
        framework/utility/tree_node.cpp

        framework/utility/array.h
        framework/utility/array.cpp

        framework/meta/event_listeners.h
        framework/meta/event_listeners.cpp

        framework/security/packet_cipher.h
        framework/security/packet_cipher.cpp
        framework/meta/Exception.cpp framework/meta/Exception.h)

# link entry point to project
add_executable(Dappf environment/main.cpp)

# link framework to project
target_link_libraries(Dappf lib)