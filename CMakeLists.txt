cmake_minimum_required(VERSION 3.15)
project(igen3)

set(CMAKE_CXX_STANDARD 17)

add_executable(igen3 main.cpp)

# Third party
target_sources(igen3
        PRIVATE
        lib/easylogging++.h lib/easylogging++.cc)
target_include_directories(igen3
        PRIVATE
        lib/)

add_subdirectory(lib/fmt)
target_link_libraries(igen3 fmt)

# KCommon
target_include_directories(igen3
        PRIVATE
        lib/kcommon)
