#include <string>
#include <gtest/gtest.h>

#include "Ratio.hpp"


TEST (VariadicFunctions, product) {
    Ratio ratio1(1, 2);
    Ratio ratio2(3, 2);
    Ratio ratio3(7, 3);
    Ratio result = product<int>(ratio1, ratio2, ratio3);
    ASSERT_EQ (result.getNumerator(), 7);
    ASSERT_EQ (result.getDenominator(), 4);
}

TEST (VariadicFunctions, addition) {
    Ratio ratio1(1, 2);
    Ratio ratio2(7, 6);
    Ratio ratio3(8, 3);
    Ratio result = addition<int>(ratio1, ratio2, ratio3);
    ASSERT_EQ (result.getNumerator(), 13);
    ASSERT_EQ (result.getDenominator(), 3);
}

TEST (VariadicFunctions, subtraction) {
    Ratio ratio1(10, 6);
    Ratio ratio2(7, 3);
    Ratio ratio3(9, 2);
    Ratio result = subtraction<int>(ratio1, ratio2, ratio3);
    ASSERT_EQ (result.getNumerator(), -31);
    ASSERT_EQ (result.getDenominator(), 6);
}

TEST (VariadicFunctions, minimum) {
    Ratio ratio1(7, 4);
    Ratio ratio2(9.);
    Ratio ratio3(1, 3);
    Ratio ratio4(99, 5);
    Ratio ratio5(-7, 4);
    ASSERT_EQ (min(ratio1, ratio2, ratio3, ratio4, ratio5), ratio5);
}

TEST (VariadicFunctions, maximum) {
    Ratio ratio1(4, 4);
    Ratio ratio2(-487, -400);
    Ratio ratio3(7, -3);
    Ratio ratio4(7.);
    Ratio ratio5(-8, 5);
    Ratio ratio6(7);
    ASSERT_EQ (max(ratio1, ratio2, ratio3, ratio4, ratio5, ratio6), ratio4);
    ASSERT_EQ (max(ratio1, ratio2, ratio3, ratio4, ratio5, ratio6), ratio6);
}