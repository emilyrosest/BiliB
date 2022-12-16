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


// int main(int argc, char **argv) {
//   ::testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }
