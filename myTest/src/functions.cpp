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

TEST (RatioFunctions, sameDenominator) {
    Ratio ratio1(5, 3);
    Ratio ratio2(2, 4);
    // ratio1.sameDenominator(ratio2);
    // ASSERT_EQ (ratio1.getNumerator(), 10);
    // ASSERT_EQ (ratio1.getDenominator(), 6);
    // ASSERT_EQ (ratio2.getNumerator(), 3);
    // ASSERT_EQ (ratio2.getDenominator(), 6);
    // ASSERT_EQ (ratio1.getDenominator(), ratio2.getDenominator());
    ASSERT_EQ (ratio1.sameDenominator(ratio2), 6);

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
