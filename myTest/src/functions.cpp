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