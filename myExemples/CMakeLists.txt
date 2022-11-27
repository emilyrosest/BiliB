cmake_minimum_required(VERSION 3.13)

project(myExemples)

add_executable(myExemples src/main.cpp)
target_link_libraries(myExemples PRIVATE libRatio)
target_compile_features(myExemples PRIVATE cxx_std_11) 
target_compile_options(myExemples PRIVATE -Wall -O2)
