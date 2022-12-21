#include <string>
#include <gtest/gtest.h>

#include "Ratio.hpp"


TEST (RatioVariadic, product) {
    Ratio ratio1(1, 2);
    Ratio ratio2(3, 2);
    Ratio ratio3(7, 3);
    Ratio result = product<int>(ratio1, ratio2, ratio3);
    ASSERT_EQ (result.getNumerator(), 7);
    ASSERT_EQ (result.getDenominator(), 4);
}

TEST (RatioVariadic, addition) {
    Ratio ratio1(1, 2);
    Ratio ratio2(7, 6);
    Ratio ratio3(8, 3);
    Ratio result = addition<int>(ratio1, ratio2, ratio3);
    ASSERT_EQ (result.getNumerator(), 13);
    ASSERT_EQ (result.getDenominator(), 3);
}

TEST (RatioVariadic, subtraction) {
    Ratio ratio1(10, 6);
    Ratio ratio2(7, 3);
    Ratio ratio3(9, 2);
    Ratio result = subtraction<int>(ratio1, ratio2, ratio3);
    ASSERT_EQ (result.getNumerator(), -31);
    ASSERT_EQ (result.getDenominator(), 6);
}