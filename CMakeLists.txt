cmake_minimum_required(VERSION 3.15)
project(igen3)

set(CMAKE_CXX_STANDARD 17)

# === Main code ======================================

add_executable(igen3
        main.cpp
        runner/Runner.cpp runner/Runner.h lib/kcommon/ktypes.h igen/Domain.cpp igen/Domain.h igen/IgenOpts.cpp igen/IgenOpts.h runner/SimpleRunner.cpp runner/SimpleRunner.h igen/Igen.cpp igen/Igen.h lib/kcommon/klog.h)

target_include_directories(igen3 PRIVATE /)

# === Third party ======================================
target_include_directories(igen3
        PRIVATE
        lib/misc)

add_subdirectory(lib/fmt)
target_link_libraries(igen3 PRIVATE fmt)

set(REPROCXX ON)
add_subdirectory(lib/reproc)
target_link_libraries(igen3 PRIVATE reprocxx)

add_subdirectory(lib/dynamic_bitset)
target_link_libraries(igen3 PRIVATE dynamic_bitset::dynamic_bitset)

add_subdirectory(lib/hopscotch-map)
target_link_libraries(igen3 PRIVATE tsl::hopscotch_map)

add_subdirectory(lib/glog)
target_link_libraries(igen3 PRIVATE glog::glog)
# === KCommon ==========================================
target_include_directories(igen3
        PRIVATE
        lib/kcommon)
