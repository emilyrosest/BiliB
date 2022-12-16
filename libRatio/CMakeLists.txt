cmake_minimum_required(VERSION 3.13)

project(Ratio LANGUAGES C CXX)

file(GLOB_RECURSE source_files src/*.cpp)
file(GLOB_RECURSE header_files include/*.hpp)

find_package(Doxygen OPTIONAL_COMPONENTS QUIET)
if(DOXYGEN_FOUND)
	add_subdirectory(doc)
else()
	message(WARNING "Doxygen not found, skip documentation")
endif()

add_library(Ratio ${source_files} ${header_files})

# compilation flags
target_compile_features(Ratio PRIVATE cxx_std_20) # use at least c++ 20
if (MSVC)
    target_compile_options(Ratio PRIVATE /W3)
else()
    target_compile_options(Ratio PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors)
endif()

target_include_directories(Ratio PRIVATE "include")

install(FILES ${header_files} DESTINATION /usr/local/include/Ratio)
install(TARGETS Ratio
        RUNTIME DESTINATION /usr/local/lib
        LIBRARY DESTINATION /usr/local/lib
        ARCHIVE DESTINATION /usr/local/lib)


