cmake_minimum_required(VERSION 3.13)

project(BiliB)

# add libRatio
message(STATUS "libRatio cmake part ..." )
add_subdirectory(libRatio INTERFACE)
include_directories(${CMAKE_SOURCE_DIR}/libRatio/include)

# add myExemples
message(STATUS "myExemples cmake part ..." )
add_subdirectory(myExemples)

# add google test
message(STATUS "google test cmake part ..." )
add_subdirectory(googletest-main)

# add myTest
message(STATUS "myTest cmake part ..." )
add_subdirectory(myTest)
