#include <string>
#include <gtest/gtest.h>

#include "Ratio.hpp"


TEST (RatioArithmetic, plus) {
    Ratio ratio1(5, 3);
    Ratio ratio2(8, 6);
    Ratio result = ratio1 + ratio2;
    ASSERT_EQ (result.getNumerator(), 3);
    ASSERT_EQ (result.getDenominator(), 1);
}

TEST (RatioArithmetic, minus) {
    Ratio ratio1(5, 3);
    Ratio ratio2(8, 6);
    Ratio result = ratio1 - ratio2;
    ASSERT_EQ (result.getNumerator(), 1);
    ASSERT_EQ (result.getDenominator(), 3);
}

TEST (RatioArithmetic, unaryMinus) {
    Ratio ratio1(5, 3);
    Ratio result = - ratio1;
    ASSERT_EQ (result.getNumerator(), -5);
    ASSERT_EQ (result.getDenominator(), 3);
}

TEST (RatioArithmetic, divide) {
    Ratio ratio1(6, 3); 
    Ratio ratio2(8, 5);
    Ratio result = ratio1/ratio2;
    ASSERT_EQ (result.getNumerator(), 5);
    ASSERT_EQ (result.getDenominator(), 4);
}

TEST (RatioArithmetic, multiply) {
    Ratio ratio1(6, 3); 
    Ratio ratio2(8, 5);
    Ratio result = ratio1*ratio2;
    ASSERT_EQ (result.getNumerator(), 16);
    ASSERT_EQ (result.getDenominator(), 5);
}

TEST (RatioArithmetic, multiply_value) {
    Ratio ratio1(8, 5);
    int value = 3;
    Ratio result = ratio1*value;
    ASSERT_EQ (result.getNumerator(), 24);
    ASSERT_EQ (result.getDenominator(), 5);
}


// int main(int argc, char **argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }
