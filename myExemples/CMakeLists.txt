cmake_minimum_required(VERSION 3.13)

project(myExemples)

add_executable(myExemples src/test.cpp)

target_compile_features(myExemples PRIVATE cxx_std_11) 
target_compile_options(myExemples PRIVATE -Wall -O2)