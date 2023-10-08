cmake_minimum_required(VERSION 3.5)
project(cpp_test LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR on)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

include_directories(third-party/include third-party/include/imgui third-party/include/imgui/impl)

set(imgui_SRCS 
    third-party/include/imgui/imconfig.h 
    third-party/include/imgui/imgui_internal.h
    third-party/include/imgui/imstb_rectpack.h
    third-party/include/imgui/imstb_textedit.h
    third-party/include/imgui/imstb_truetype.h
    third-party/src/imgui.cpp
    third-party/src/imgui_demo.cpp
    third-party/src/imgui_draw.cpp
    third-party/src/imgui_widgets.cpp
    third-party/src/imgui_tables.cpp

    third-party/include/imgui/impl/imgui_impl_opengl3.h
    third-party/include/imgui/impl/imgui_impl_glfw.h
    third-party/include/imgui/impl/imgui_impl_opengl3_loader.h
    third-party/src/impl/imgui_impl_opengl3.cpp
    third-party/src/impl/imgui_impl_glfw.cpp
    )

set(serial_SRCS 
    third-party/src/serial.cc 
    third-party/include/serial/serial.h
    third-party/include/serial/v8stdint.h 
    third-party/src/impl/list_ports/list_ports_linux.cc
    third-party/src/impl/unix.cc
    )

add_library(serial ${serial_SRCS})
add_library(imgui ${imgui_SRCS})

add_executable(cpp_test main.cpp ${serial_SRCS} ${imgui_SRCS})
target_link_libraries(cpp_test serial imgui glfw GL)
target_include_directories(cpp_test PUBLIC third-party/include/serial third-party/include/imgui third-party/include/imgui/backends)
