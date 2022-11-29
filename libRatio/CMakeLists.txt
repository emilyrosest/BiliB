cmake_minimum_required(VERSION 3.13)

project(libRatio LANGUAGES C CXX)

file(GLOB_RECURSE source_files src/*.cpp)
file(GLOB_RECURSE header_files include/*.hpp)
# add_executable(libRatio src/Ratio.cpp include/Ratio.hpp)

# Doxygen
find_package(Doxygen OPTIONAL_COMPONENTS QUIET)
if(DOXYGEN_FOUND)
    add_subdirectory(doc)
else()
    message(WARNING "Doxygen not found, skip dococumentation")
endif()

add_library(libRatio ${source_files} ${header_files})

target_compile_features(libRatio PRIVATE cxx_std_17) 
target_compile_options(libRatio PRIVATE -Wall -O2)

target_include_directories(libRatio PRIVATE "include")

install(FILES ${header_files} DESTINATION /usr/local/include/libRatio)
install(TARGETS libRatio
        RUNTIME DESTINATION /usr/local/lib
        LIBRARY DESTINATION /usr/local/lib
        ARCHIVE DESTINATION /usr/local/lib)