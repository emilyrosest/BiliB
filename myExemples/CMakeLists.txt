cmake_minimum_required(VERSION 3.13)

project(samples)


add_executable(samples src/main.cpp)
target_link_libraries(samples PRIVATE Ratio)

# compilation flags
target_compile_features(samples PRIVATE cxx_std_20) # use at least c++ 20
if (MSVC)
    target_compile_options(samples PRIVATE /W3)
else()
    target_compile_options(samples PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()

