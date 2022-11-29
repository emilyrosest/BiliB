cmake_minimum_required(VERSION 3.13)

project(myTest)

enable_testing()

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(myTest src/test.cpp)
target_link_libraries(myTest libRatio GTest::GTest GTest::Main)
#target_link_libraries(myTest gtest libRatio)
target_compile_features(myTest PRIVATE cxx_std_14)

add_test(NAME myTest
    COMMAND myTest)


#gtest_discover_tests(myTest)
