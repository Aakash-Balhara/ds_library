cmake_minimum_required(VERSION 3.10)

project(ds_library)

set(CMAKE_EXE_LINKER_FLAGS "-mconsole")
include_directories(include)

add_executable(ds_library 
    main.cpp
    tests/vector.cpp
    tests/forwardList.cpp
    tests/stack.cpp
    tests/queue.cpp
    tests/list.cpp
)