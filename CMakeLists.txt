cmake_minimum_required(VERSION 3.17)
project(spbu_2020_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
    library/commonUtils/numericOperations.c
    library/commonUtils/stack.c
)
add_library(library ${SOURCE_LIB})

add_executable(hw2.1 homework_2/hw2.1/main.c)
add_executable(hw2.3 homework_2/hw2.3/main.c)
target_link_libraries(hw2.3 library)
add_executable(hw2.5 homework_2/hw2.5/main.c)
target_link_libraries(hw2.5 library)
