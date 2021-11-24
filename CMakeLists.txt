project(Dappf)
set(CMAKE_CXX_STANDARD 20)
cmake_minimum_required(VERSION 3.19)

# create library
add_library(
        lib SHARED # <target> <LINK_PRIVATE | LINK_PUBLIC>

        # files to be compiled
        framework/dappf.h
        framework/dappf.cpp

        framework/data/packet/packet_writer.h
        framework/data/packet/packet_writer.cpp

        framework/data/packet/packet_reader.h
        framework/data/packet/packet_reader.cpp

        framework/utility/log.h
        framework/utility/log.cpp

        framework/test/unit_test_packet.h
        framework/test/unit_test_packet.cpp

        framework/data/storage/cache.h
        framework/data/storage/cache.cpp

        framework/data/packet/packet_compression.h
        framework/data/packet/packet_compression.cpp

        framework/test/unit_test_compression.h
        framework/test/unit_test_compression.cpp

        framework/net/connection.h
        framework/net/connection.cpp

        framework/utility/tree.h
        framework/utility/tree.cpp

        framework/utility/meta/tree_node.h
        framework/utility/meta/tree_node.cpp

        framework/utility/array.h
        framework/utility/array.cpp

        framework/meta/event_listeners/event_listeners.h
        framework/meta/event_listeners/event_listeners.cpp

        framework/data/packet/packet_cipher.h
        framework/data/packet/packet_cipher.cpp
        framework/meta/task_pool/task_pool.cpp framework/meta/task_pool/task_pool.h

        framework/data/storage/cache.h
        framework/data/storage/cache.cpp

        framework/constants.h
        framework/constants.cpp

        framework/meta/handlers/handler.h
        framework/meta/handlers/handler.cpp

        framework/utility/string.h
        framework/utility/string.cpp

        framework/meta/handlers/handler_director.h
        framework/meta/handlers/handler_director.cpp framework/meta/task_pool/task.cpp framework/meta/task_pool/task.h framework/utility/time.cpp framework/utility/time.h

        framework/security/local_contract.cpp framework/security/local_contract.h framework/security/remote_contract.cpp framework/security/remote_contract.h)

# link entry point to project
add_executable(Dappf environment/main.cpp)

# link framework to project
target_link_libraries(Dappf lib)