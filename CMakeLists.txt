project(Dappf C CXX)
set(CMAKE_CXX_STANDARD 20)
cmake_minimum_required(VERSION 3.19)

# create library
add_library(
        lib SHARED # <target> <LINK_PRIVATE | LINK_PUBLIC>

        # files to be compiled
        framework/dappf.h
        framework/dappf.cpp

        framework/meta/async_wrappers/message_counter.h
        framework/meta/async_wrappers/message_counter.cpp

        framework/meta/async_wrappers/message_id_tracker.h
        framework/meta/async_wrappers/message_id_tracker.cpp

        framework/data/packet/packet_writer.h
        framework/data/packet/packet_writer.cpp

        framework/data/packet/packet_reader.h
        framework/data/packet/packet_reader.cpp

        framework/utility/log.h
        framework/utility/log.cpp

        test/unit_test_packet.h
        test/unit_test_packet.cpp

        framework/data/storage/cache.h
        framework/data/storage/cache.cpp

        framework/data/packet/packet_compression.h
        framework/data/packet/packet_compression.cpp

        framework/data/packet/packet_processing.h
        framework/data/packet/packet_processing.cpp

        framework/net/connection.h
        framework/net/connection.cpp

        framework/utility/array.h
        framework/utility/array.cpp

        framework/meta/event_listeners/event_listener.h
        framework/meta/event_listeners/event_listener.cpp

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
        framework/meta/handlers/handler_director.cpp

        framework/meta/task_pool/task.cpp
        framework/meta/task_pool/task.h

        framework/utility/time.cpp
        framework/utility/time.h

        framework/security/local_contract.cpp
        framework/security/local_contract.h

        framework/security/remote_contract.cpp
        framework/security/remote_contract.h

        framework/meta/event_listeners/on_connection_request.cpp
        framework/meta/event_listeners/on_connection_request.h

        framework/meta/event_listeners/on_connection_established.cpp
        framework/meta/event_listeners/on_connection_established.h

        framework/meta/event_listeners/on_connection_dropped.cpp
        framework/meta/event_listeners/on_connection_dropped.h

        framework/meta/event_listeners/on_packet_received.cpp
        framework/meta/event_listeners/on_packet_received.h

        framework/meta/event_listeners/on_packet_sent.cpp
        framework/meta/event_listeners/on_packet_sent.h

        framework/meta/event_listeners/on_internal_error.cpp
        framework/meta/event_listeners/on_internal_error.h

        framework/data/packet/packet_validation.cpp
        framework/data/packet/packet_validation.h

        framework/meta/spooler/predictor.cpp
        framework/meta/spooler/predictor.h

        framework/meta/spooler/spooler.cpp
        framework/meta/spooler/spooler.h

        test/unit_test.cpp
        test/unit_test.h

        test/unit_test_handler.cpp
        test/unit_test_handler.h

        test/unit_test_task.cpp
        test/unit_test_task.h
        test/run_test_global.cpp test/run_test_global.h)

# link entry point to project
add_executable(Dappf environment/main.cpp)

# for the threading capability
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries (Dappf ${CMAKE_THREAD_LIBS_INIT})

# link framework to project
target_link_libraries(Dappf lib)
