cmake_minimum_required(VERSION 3.5)
project(cpp_test LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR on)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

include_directories(third-party/include)

set(serial_SRCS third-party/src/serial.cc third-party/include/serial/serial.h
    third-party/include/serial/v8stdint.h third-party/src/impl/list_ports/list_ports_linux.cc)
list(APPEND serial_SRCS third-party/src/impl/unix.cc)

add_library(serial ${serial_SRCS})
target_link_libraries(serial rt)

add_executable(cpp_test main.cpp)
target_link_libraries(cpp_test serial ncurses SDL2)
