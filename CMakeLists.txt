cmake_minimum_required(VERSION 3.8)
project(ServerRM)

set(CMAKE_CXX_STANDARD 11)

find_package (Threads)

set(SOURCE_FILES main.cpp Core/MainServer.cpp Core/MainServer.h Core/memoryManager.cpp Core/memoryManager.h Core/ServerHA.cpp Core/ServerHA.h
         Structures/rmRef_h.cpp Structures/Node.h Structures/Node.cpp Structures/LinkedList.h Structures/LinkedList.cpp Structures/rmRef_h.h)
add_executable(ServerRM ${SOURCE_FILES})
target_link_libraries (ServerRM ${CMAKE_THREAD_LIBS_INIT})