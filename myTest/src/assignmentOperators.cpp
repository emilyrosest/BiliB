#include <string>
#include <gtest/gtest.h>

#include "Ratio.hpp"

/////////////////// =

TEST (RatioOperators, equalAssignment) {
    Ratio ratio1(7, 4);
    Ratio ratio2 = ratio1;
    ASSERT_EQ (ratio1.getNumerator(), ratio2.getNumerator());
    ASSERT_EQ (ratio1.getDenominator(), ratio2.getDenominator());
}

TEST (RatioOperators, equalAssignementValue) {
    float value = 12.8;
    Ratio ratio = value;
    ASSERT_EQ (ratio.getNumerator(), 64);
    ASSERT_EQ (ratio.getDenominator(), 5);
}

// TEST (RatioOperators, valueEqualAssignment) {
//     int value = 76;
//     Ratio ratio(86, 20);
//     value = ratio;
//     ASSERT_EQ (value, 80);
// }

/////////////////// +=

TEST (RatioOperators, plusAssignment) {
    Ratio ratio1(4, 3);
    Ratio ratio2(10, 6);
    ratio1 += ratio2;
    ASSERT_EQ (ratio1.getNumerator(), 3);
    ASSERT_EQ (ratio1.getDenominator(), 1);
}

TEST (RatioOperators, plusAssignmentValue) {
    Ratio ratio(10, 6);
    float value = 7.5;
    ratio += value;
    ASSERT_EQ (ratio.getNumerator(), 55);
    ASSERT_EQ (ratio.getDenominator(), 6);
}

TEST (RatioOperators, valuePlusAssignment) {
    int value = 17;
    Ratio ratio(23, 2);
    value += ratio;
    ASSERT_EQ (value, 28);
}

/////////////////// -=

TEST (RatioOperators, minusAssignment) {
    Ratio ratio1(4, 3);
    Ratio ratio2(10, 6);
    ratio1 -= ratio2;
    ASSERT_EQ (ratio1.getNumerator(), -1);
    ASSERT_EQ (ratio1.getDenominator(), 3);
}

TEST (RatioOperators, minusAssignmentValue) {
    Ratio ratio(4.);
    float value = 5.25;
    ratio -= value;
    ASSERT_EQ (ratio.getNumerator(), -5);
    ASSERT_EQ (ratio.getDenominator(), 4);
}

TEST (RatioOperators, valueMinusAssignment) {
    float value = 14.2;
    Ratio ratio(23, 2);
    value -= ratio;
    ASSERT_EQ (abs(value - 2.7) < 0.0001, true);
}

/////////////////// *=

TEST (RatioOperators, multiplyAssignment) {
    Ratio ratio1(2, 3);
    Ratio ratio2(10, 6);
    ratio1 *= ratio2;
    ASSERT_EQ (ratio1.getNumerator(), 10);
    ASSERT_EQ (ratio1.getDenominator(), 9);
}

TEST (RatioOperators, multiplyAssignmentValue) {
    Ratio ratio(2, 4);
    float value = 11.6;
    ratio *= value;
    ASSERT_EQ (ratio.getNumerator(), 29);
    ASSERT_EQ (ratio.getDenominator(), 5);
}

TEST (RatioOperators, valueMultiplyAssignment) {
    int value = 5;
    Ratio ratio(30, 10);
    value *= ratio;
    ASSERT_EQ (value, 15);
}

/////////////////// /=

TEST (RatioOperators, divideAssignment) {
    Ratio ratio1(2, 3);
    Ratio ratio2(4, 5);
    ratio1 /= ratio2;
    ASSERT_EQ (ratio1.getNumerator(), 5);
    ASSERT_EQ (ratio1.getDenominator(), 6);
}

TEST (RatioOperators, divideAssignmentValue) {
    Ratio ratio(7, 11);
    float value = 5.;
    ratio /= value;
    ASSERT_EQ (ratio.getNumerator(), 7);
    ASSERT_EQ (ratio.getDenominator(), 55);
}

TEST (RatioOperators, valueDivideAssignment) {
    float value = 2.5;
    Ratio ratio(5, 7);
    value /= ratio;
    ASSERT_EQ (value, 3.5);
}

/////////////////// %=

TEST (RatioOperators, moduloAssignment) {
    Ratio ratio1(5, 7);
    Ratio ratio2(6, 4);
    ratio1 %= ratio2;
    ASSERT_EQ (ratio1.getNumerator(), 10);
    ASSERT_EQ (ratio1.getDenominator(), 1);
}

TEST (RatioOperators, moduloAssignmentValue) {
    Ratio ratio(2, 10);
    float value = 9.;
    ratio %= value;
    ASSERT_EQ (ratio.getNumerator(), 1);
    ASSERT_EQ (ratio.getDenominator(), 1);
}

TEST (RatioOperators, valueModuloAssignment) {
    int value = 10;
    Ratio ratio(14, 2);
    value %= ratio;
    ASSERT_EQ (value, 3);
}