cmake_minimum_required(VERSION 3.13)


enable_testing()

#find_package(GTest REQUIRED)
#include(GoogleTest)

add_executable(myTest src/test.cpp)
target_link_libraries(myTest PUBLIC libRatio googletest)
target_compile_features(myTest PRIVATE cxx_std_14)

add_test(NAME myUnitTests
    COMMAND myUnitTests)

#gtest_discover_tests(myTest)
