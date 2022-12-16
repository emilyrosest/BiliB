cmake_minimum_required(VERSION 3.13)

# give a name to the project
project(samples)

# find Ratio
# if build as standalone project, find the lib by yourself ...
# if build transitively 


add_executable(samples src/main.cpp)                # file to compile and name of the app
target_link_libraries(samples PRIVATE Ratio)      # lib dependency

# compilation flags
target_compile_features(samples PRIVATE cxx_std_20) # use at least c++ 20
if (MSVC)
    target_compile_options(samples PRIVATE /W3)
else()
    target_compile_options(samples PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()

