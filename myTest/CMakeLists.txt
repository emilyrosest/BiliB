cmake_minimum_required(VERSION 3.13)

enable_testing()

add_executable(myUnitTests src/constructors.cpp src/arithmeticOperators.cpp src/functions.cpp src/assignmentOperators.cpp src/relationalOperators.cpp src/variadicsFunctions.cpp src/mathsFunctions.cpp)
target_link_libraries(myUnitTests gtest Ratio)
target_compile_features(myUnitTests PRIVATE cxx_std_20)

add_test(NAME myUnitTests
    COMMAND myUnitTests)



