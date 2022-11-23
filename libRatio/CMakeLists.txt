cmake_minimum_required(VERSION 3.13)

project(libRatio)

add_executable(libRatio src/Ratio.cpp include/Ratio.hpp)

target_compile_features(libRatio PRIVATE cxx_std_11) 
target_compile_options(libRatio PRIVATE -Wall -O2)   