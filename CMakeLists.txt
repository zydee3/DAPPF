project(Dappf)
set(CMAKE_CXX_STANDARD 20)
cmake_minimum_required(VERSION 3.19)

# create library
add_library(
        lib SHARED # <target> <LINK_PRIVATE | LINK_PUBLIC>

        # files to be compiled
        framework/dappf.h framework/dappf.cpp
        framework/meta/packet_writer.cpp framework/meta/packet_writer.h
        framework/meta/log.h framework/meta/log.cpp)

# link entry point to project
add_executable(Dappf environment/main.cpp framework/net/connection.cpp framework/net/connection.h)

# link framework to project
target_link_libraries(Dappf lib)