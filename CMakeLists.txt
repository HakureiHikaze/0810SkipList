cmake_minimum_required(VERSION 3.27)
project(0810SkipList)
set(CMAKE_CXX_STANDARD 23)
aux_source_directory(./ dirRoot)
add_subdirectory(SkipList)
include_directories(${PROJECT_SOURCE_DIR}/SkipList)
link_libraries(SkipList)
add_executable(0810SkipList ${dirRoot}
        SkipList/SkipListNode.cpp
        SkipList/SkipListNode.h)
