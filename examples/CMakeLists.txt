cmake_minimum_required(VERSION 3.13)

project(examples)


add_executable(examples src/main.cpp)
target_link_libraries(examples PRIVATE Ratio)

# compilation flags
target_compile_features(examples PRIVATE cxx_std_20) # use at least c++ 20
if (MSVC)
    target_compile_options(examples PRIVATE /W3)
else()
    target_compile_options(examples PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()

