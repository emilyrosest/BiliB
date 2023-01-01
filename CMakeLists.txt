cmake_minimum_required(VERSION 3.13)

project(BiliB)

# add libRatio
message(STATUS "libRatio cmake part ..." )
add_subdirectory(libRatio INTERFACE)
include_directories(${CMAKE_SOURCE_DIR}/libRatio/include)

# add examples
message(STATUS "examples cmake part ..." )
add_subdirectory(examples)

# add google test
message(STATUS "google test cmake part ..." )
add_subdirectory(googletest-main)

# add tests
message(STATUS "tests cmake part ..." )
add_subdirectory(tests)
