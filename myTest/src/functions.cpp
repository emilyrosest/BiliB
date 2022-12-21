#include <string>
#include <gtest/gtest.h>

#include "Ratio.hpp"


TEST (RatioFunctions, reduceFunction) {
    Ratio ratio(9, 3);
    ASSERT_EQ (ratio.getNumerator(), 3);
    ASSERT_EQ (ratio.getDenominator(), 1);
}

TEST (RatioFunctions, inverseFunction) {
    Ratio ratio(6, 7);
    Ratio inversedRatio = ratio.inverse();
    ASSERT_EQ (inversedRatio.getNumerator(), 7);
    ASSERT_EQ (inversedRatio.getDenominator(), 6);
}

TEST (RatioFunctions, remainderFunction) {
    Ratio ratio(9, 4);
    ASSERT_EQ (ratio.remainder(), 1);
    Ratio ratio2(8, 4);
    ASSERT_EQ (ratio2.remainder(), 0);
}

TEST (RatioFunctions, absolute) {
    Ratio ratio(-4, 7);
    Ratio absoluteRatio = ratio.absolute();
    ASSERT_EQ (absoluteRatio.getNumerator(), 4);
    ASSERT_EQ (absoluteRatio.getDenominator(), 7);

    Ratio absoluteRatio2 = (-ratio).absolute();
    ASSERT_EQ (absoluteRatio2.getNumerator(), 4);
    ASSERT_EQ (absoluteRatio2.getDenominator(), 7);
}

TEST (RatioFunctions, floor) {
    Ratio ratio(45, 6);
    ASSERT_EQ (ratio.floor(), 7);
}

TEST (RatioFunction, convertToRatio) {
    Ratio ratio = convertToRatio<float>(3.2, nbIter);
    EXPECT_EQ (ratio.getNumerator(), 16);
    EXPECT_EQ (ratio.getDenominator(), 5);
}

TEST (RatioFunctions, convertToNumber) {
    Ratio ratio(5, 2);
    ASSERT_EQ (ratio.convertToNumber(), 2.5);
}

