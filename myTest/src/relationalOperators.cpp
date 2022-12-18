#include <string>
#include <gtest/gtest.h>

#include "Ratio.hpp"

TEST (RatioOperators, EqualOperator) {
    Ratio ratio1(8, 5);
    Ratio ratio2(16, 10);
    ASSERT_EQ (ratio1 == ratio2, true);
}