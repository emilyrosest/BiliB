cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(BiliB)

# add myLib
message(STATUS "myLib cmake part ..." )
add_subdirectory(libRatio INTERFACE)
include_directories(${CMAKE_SOURCE_DIR}/libRatio/include) # important : other projects call by this cmake will know this include directory

# add myCode
message(STATUS "myExemples cmake part ..." )
add_subdirectory(myExemples)

# add google test
message(STATUS "google test cmake part ..." )
add_subdirectory(googletest-main)

# add myTest
message(STATUS "myTest cmake part ..." )
add_subdirectory(myTest)
