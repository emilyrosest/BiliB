cmake_minimum_required(VERSION 3.13)

enable_testing()

add_executable(tests src/constructors.cpp src/arithmeticOperators.cpp src/functions.cpp src/assignmentOperators.cpp src/relationalOperators.cpp src/variadicsFunctions.cpp src/mathsFunctions.cpp)
target_link_libraries(tests gtest Ratio)
target_compile_features(tests PRIVATE cxx_std_20)

add_test(NAME tests
    COMMAND tests)



