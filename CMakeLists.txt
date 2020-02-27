cmake_minimum_required(VERSION 3.15)
project(igen3)

set(CMAKE_CXX_STANDARD 17)

# === Main code ======================================

add_executable(igen3
        main.cpp
        Executor.cpp Executor.h)

# === Third party ======================================
target_sources(igen3
        PRIVATE
        lib/easylogging++.h lib/easylogging++.cc)
target_include_directories(igen3
        PRIVATE
        lib/)

add_subdirectory(lib/fmt)
target_link_libraries(igen3 PRIVATE fmt)

set(REPROCXX ON)
add_subdirectory(lib/reproc)
target_link_libraries(igen3 PRIVATE reprocxx)

add_subdirectory(lib/dynamic_bitset)
target_link_libraries(igen3 PRIVATE dynamic_bitset)
# === KCommon ==========================================
target_include_directories(igen3
        PRIVATE
        lib/kcommon)
