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
    ratio.inverse();
    ASSERT_EQ (ratio.getNumerator(), 7);
    ASSERT_EQ (ratio.getDenominator(), 6);
}

TEST (RatioFunctions, remainderFunction) {
    Ratio ratio(9, 4);
    ASSERT_EQ (ratio.remainder(), 1);
    Ratio ratio2(8, 4);
    ASSERT_EQ (ratio2.remainder(), 0);
}


// TEST (RatioFunction, convertToRatio) {
//     Ratio ratio = convertToRatio<float>(3.2, nb_iter);
//     EXPECT_EQ (ratio.getNumerator(), 16);
//     EXPECT_EQ (ratio.getDenominator(), 5);
// }


// TEST (RatioFunctions, RatioToFloat) {
//     Ratio ratio(2, 4);
//     ASSERT_EQ (ratio.convertRatioToFloat(), 0.5);
// }
