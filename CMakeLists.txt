cmake_minimum_required(VERSION 3.13)

project(BiliB)


# specify the system
message(VERBOSE "CMAKE_VERSION           : " ${CMAKE_VERSION})
message(VERBOSE "CMAKE_SYSTEM_NAME       : " ${CMAKE_SYSTEM_NAME})
message(VERBOSE "CMAKE_SYSTEM            : " ${CMAKE_SYSTEM})
message(VERBOSE "CMAKE_SYSTEM_PROCESSOR  : " ${CMAKE_SYSTEM_PROCESSOR} "\n")

# specify the directories
message(VERBOSE "CMAKE_BINARY_DIR        : " ${CMAKE_BINARY_DIR})
message(VERBOSE "CMAKE_SOURCE_DIR        : " ${CMAKE_SOURCE_DIR})
message(VERBOSE "CMAKE_HOME_DIRECTORY    : " ${CMAKE_HOME_DIRECTORY})
message(VERBOSE "PROJECT_BINARY_DIR      : " ${PROJECT_BINARY_DIR})
message(VERBOSE "PROJECT_SOURCE_DIR      : " ${PROJECT_SOURCE_DIR} "\n")

# compile flags
message(VERBOSE "CMAKE_CXX_FLAGS         : " ${CMAKE_CXX_FLAG})
message(VERBOSE "CMAKE_CXX_FLAGS_DEBUG   : " ${CMAKE_CXX_FLAGS_DEBUG})
message(VERBOSE "CMAKE_CXX_FLAGS_RELEASE : " ${CMAKE_CXX_FLAGS_RELEASE})
message(VERBOSE "CMAKE_CXX_COMPILER      : " ${CMAKE_CXX_COMPILER} "\n")


# not clear to me, but vscode can't work fine without
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# (optional) add a "output" directory in the project binary directory
file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/output)

# (optional) put the binary files in this directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)


message(STATUS "libRatio cmake part ...")
add_subdirectory(libRatio INTERFACE)
include_directories(${CMAKE_SOURCE_DIR}/libRatio/include)

message(STATUS "myExemples cmake part ...")
add_subdirectory(myExemples)

find_package(GTest OPTIONAL_COMPONENTS)
if(GTEST_FOUND)
	message(STATUS "myTest cmake part ..." )
	add_subdirectory(myTest)
elseif()
	message(WARNING "google test not found, skipping myTest ..." )
endif()