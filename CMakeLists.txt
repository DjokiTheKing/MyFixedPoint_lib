cmake_minimum_required(VERSION 3.13)
project(MyFixedPoint_lib C CXX ASM)

add_library(MyFixedPoint_lib STATIC
    ${CMAKE_CURRENT_LIST_DIR}/headers/MyFixedPoint.h
    ${CMAKE_CURRENT_LIST_DIR}/headers/MyFixedPoint.hpp
)

target_include_directories(MyFixedPoint_lib PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/headers
)

target_link_libraries(MyFixedPoint_lib PUBLIC 
        pico_stdlib
        pico_float
        pico_bootrom
        pico_bit_ops
)
