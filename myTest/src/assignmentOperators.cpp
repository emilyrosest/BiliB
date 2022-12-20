#include <string>
#include <gtest/gtest.h>

#include "Ratio.hpp"


TEST (RatioOperators, equalAssignment) {
    Ratio ratio1(7, 4);
    Ratio ratio2 = ratio1;
    ASSERT_EQ (ratio1.getNumerator(), ratio2.getNumerator());
    ASSERT_EQ (ratio1.getDenominator(), ratio2.getDenominator());
}

TEST (RatioOperators, plusAssignment) {
    Ratio ratio1(4, 3);
    Ratio ratio2(10, 6);
    ratio1 += ratio2;
    ASSERT_EQ (ratio1.getNumerator(), 3);
    ASSERT_EQ (ratio1.getDenominator(), 1);
}

TEST (RatioOperators, minusAssignment) {
    Ratio ratio1(4, 3);
    Ratio ratio2(10, 6);
    ratio1 -= ratio2;
    ASSERT_EQ (ratio1.getNumerator(), -1);
    ASSERT_EQ (ratio1.getDenominator(), 3);
}

TEST (RatioOperators, multiplyAssignment) {
    Ratio ratio1(2, 3);
    Ratio ratio2(10, 6);
    ratio1 *= ratio2;
    ASSERT_EQ (ratio1.getNumerator(), 10);
    ASSERT_EQ (ratio1.getDenominator(), 9);
}

TEST (RatioOperators, divideAssignment) {
    Ratio ratio1(2, 3);
    Ratio ratio2(4, 5);
    ratio1 /= ratio2;
    ASSERT_EQ (ratio1.getNumerator(), 5);
    ASSERT_EQ (ratio1.getDenominator(), 6);
}