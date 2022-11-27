cmake_minimum_required(VERSION 3.13)


enable_testing()

find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(myTest src/test.cpp)
target_link_libraries(myTest PUBLIC libRatio GTest::GTest GTest::Main)
target_compile_features(myTest PRIVATE cxx_std_14)

gtest_discover_tests(myTest)
