#include <string>
#include <gtest/gtest.h>

#include "Ratio.hpp"


TEST (Constructors, default) {
    Ratio ratio;
    EXPECT_EQ (ratio.getNumerator(), 0);
    EXPECT_EQ (ratio.getDenominator(), 1);
}

TEST (Constructors, fromIntegers) {
    Ratio ratio(9, 5);
    ASSERT_EQ (ratio.getNumerator(), 9);
    ASSERT_EQ (ratio.getDenominator(), 5);
}

TEST (Constructors, byCopy) {
    Ratio ratio1(6, 7);
    Ratio ratio2(ratio1);
    ASSERT_EQ (ratio2.getNumerator(), 6);
    ASSERT_EQ (ratio2.getDenominator(), 7);
}

TEST (Constructors, fromRealNumber) {
    Ratio ratio(-4.5);
    ASSERT_EQ (ratio.getNumerator(), -9);
    ASSERT_EQ (ratio.getDenominator(), 2);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
