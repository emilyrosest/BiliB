#include <string>
#include <gtest/gtest.h>

#include "Ratio.hpp"

TEST (RatioOperators, EqualOperator) {
    Ratio ratio1(8, 5);
    Ratio ratio2(16, 10);
    ASSERT_EQ (ratio1 == ratio2, true);
}

TEST (RatioOperators, notEqualOperator) {
    Ratio ratio1(8, 5);
    Ratio ratio2(18, 10);
    ASSERT_EQ (ratio1 != ratio2, true);
}

TEST (RatioOperators, greaterOperator) {
    Ratio ratio1(7, 4);
    Ratio ratio2(2, 7);
    ASSERT_EQ (ratio1 > ratio2, true);
    ASSERT_EQ (ratio2 > ratio1, false);
}

TEST (RatioOperators, lessOperator) {
    Ratio ratio1(1, 3);
    Ratio ratio2(4, 5);
    ASSERT_EQ (ratio1 < ratio2, true);
    ASSERT_EQ (ratio2 < ratio1, false);
}

TEST (RatioOperators, greaterOrEqual) {
    Ratio ratio1(7, 4);
    Ratio ratio2(14, 8);
    ASSERT_EQ (ratio1 >= ratio2, true);
    ASSERT_EQ (ratio2 >= ratio1, true);
}

TEST (RatioOperators, lessOrEqual) {
    Ratio ratio1(1, 4);
    Ratio ratio2(4, 3);
    ASSERT_EQ (ratio1 <= ratio2, true);
    ASSERT_EQ (ratio2 <= ratio1, false);
}