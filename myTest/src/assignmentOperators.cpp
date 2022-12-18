#include <string>
#include <gtest/gtest.h>

#include "Ratio.hpp"


TEST (RatioOperators, equalAssignment) {
    Ratio ratio1(7, 4);
    Ratio ratio2 = ratio1;
    ASSERT_EQ (ratio1.getNumerator(), ratio2.getNumerator());
    ASSERT_EQ (ratio1.getDenominator(), ratio2.getDenominator());
}

// TEST (RatioOperators, plusAssignment) {
//     Ratio ratio1(4, 3);
//     Ratio ratio2(10, 6);
//     ratio1 += ratio2;
//     ASSERT_EQ (ratio1.getNumerator(), 3);
//     ASSERT_EQ (ratio1.getDenominator(), 1);
// }