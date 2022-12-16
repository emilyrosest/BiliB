#include <string>
#include <gtest/gtest.h>

#include "Ratio.hpp"


TEST (RatioFunction, convertToRatio) {
    Ratio ratio = convertToRatio<float>(3.2, nb_iter);
    EXPECT_EQ (ratio.getNumerator(), 16);
    EXPECT_EQ (ratio.getDenominator(), 5);
}