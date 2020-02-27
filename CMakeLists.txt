cmake_minimum_required(VERSION 3.15)
project(igen3)

set(CMAKE_CXX_STANDARD 17)

# === Main code ======================================

add_executable(igen3
        main.cpp
        runner/Runner.cpp runner/Runner.h lib/kcommon/ktypes.h igen/DomainFile.cpp igen/DomainFile.h igen/IgenOpts.cpp igen/IgenOpts.h runner/SimpleRunner.cpp runner/SimpleRunner.h igen/Igen.cpp igen/Igen.h)

target_include_directories(igen3 PRIVATE /)

# === Third party ======================================
target_sources(igen3
        PRIVATE
        lib/misc/easylogging++.h lib/misc/easylogging++.cc)
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

add_subdirectory(lib/hopscotch-map)
target_link_libraries(igen3 PRIVATE tsl::hopscotch_map)
# === KCommon ==========================================
target_include_directories(igen3
        PRIVATE
        lib/kcommon)
