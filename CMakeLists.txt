cmake_minimum_required(VERSION 3.17)
project(spbu_2020_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
    library/commonUtils/numericOperations.c
    library/commonUtils/stack.c
    library/commonUtils/list.c
    library/commonUtils/cyclicList.c
    library/commonUtils/heap.c
    library/commonUtils/arrayOperations.c
    library/commonUtils/mysorts.c
    library/commonUtils/binaryOperations.c
    library/commonUtils/BST.c
)
add_library(library ${SOURCE_LIB})

add_executable(hw1.1 homework_1/hw1.1/main.c)
add_executable(hw1.2 homework_1/hw1.2/main.c)
target_link_libraries(hw1.2 library)
add_executable(hw1.3 homework_1/hw1.3/main.c)
add_executable(hw1.4 homework_1/hw1.4/main.c)
add_executable(hw1.5 homework_1/hw1.5/main.c)
target_link_libraries(hw1.5 library)

add_executable(hw2.1 homework_2/hw2.1/main.c)
add_executable(hw2.2 homework_2/hw2.2/main.c)
add_executable(hw2.3 homework_2/hw2.3/main.c)
target_link_libraries(hw2.3 library)
add_executable(hw2.4 homework_2/hw2.4/main.c)
target_link_libraries(hw2.4 library)
add_executable(hw2.5 homework_2/hw2.5/main.c)
target_link_libraries(hw2.5 library)
add_executable(hw4.1 homework_4/hw4.1/main.c)
target_link_libraries(hw4.1 library)

add_executable(hw3.1 homework_3/hw3.1/main.c)
target_link_libraries(hw3.1 library)
add_executable(hw3.2 homework_3/hw3.2/main.c)
target_link_libraries(hw3.2 library)
add_executable(hw4.2 homework_4/hw4.2/main.c)
target_link_libraries(hw4.2 library)
add_executable(hw5.1 homework_5/hw5.1/main.c)
target_link_libraries(hw5.1 library)
