#include <string>
#include <gtest/gtest.h>

#include "Ratio.hpp"

/////////////////// =

TEST (AssignmentOperators, equal) {
    Ratio ratio1(7, 4);
    Ratio ratio2 = ratio1;
    ASSERT_EQ (ratio1.getNumerator(), ratio2.getNumerator());
    ASSERT_EQ (ratio1.getDenominator(), ratio2.getDenominator());
}

TEST (AssignmentOperators, equalValue) {
    float value = 12.8;
    Ratio ratio = value;
    ASSERT_EQ (ratio.getNumerator(), 64);
    ASSERT_EQ (ratio.getDenominator(), 5);
}

// TEST (AssignmentOperators, valueEqual) {
//     int value = 76;
//     Ratio ratio(86, 20);
//     value = ratio;
//     ASSERT_EQ (value, 80);
// }

/////////////////// +=

TEST (AssignmentOperators, plus) {
    Ratio ratio1(4, 3);
    Ratio ratio2(10, 6);
    ratio1 += ratio2;
    ASSERT_EQ (ratio1.getNumerator(), 3);
    ASSERT_EQ (ratio1.getDenominator(), 1);
}

TEST (AssignmentOperators, plusValue) {
    Ratio ratio(10, 6);
    float value = 7.5;
    ratio += value;
    ASSERT_EQ (ratio.getNumerator(), 55);
    ASSERT_EQ (ratio.getDenominator(), 6);
}

TEST (AssignmentOperators, valuePlus) {
    int value = 17;
    Ratio ratio(23, 2);
    value += ratio;
    ASSERT_EQ (value, 28);
}

/////////////////// -=

TEST (AssignmentOperators, minus) {
    Ratio ratio1(4, 3);
    Ratio ratio2(10, 6);
    ratio1 -= ratio2;
    ASSERT_EQ (ratio1.getNumerator(), -1);
    ASSERT_EQ (ratio1.getDenominator(), 3);
}

TEST (AssignmentOperators, minusValue) {
    Ratio ratio(4.);
    float value = 5.25;
    ratio -= value;
    ASSERT_EQ (ratio.getNumerator(), -5);
    ASSERT_EQ (ratio.getDenominator(), 4);
}

TEST (AssignmentOperators, valueMinus) {
    float value = 14.2;
    Ratio ratio(23, 2);
    value -= ratio;
    ASSERT_EQ (abs(value - 2.7) < 0.0001, true);
}

/////////////////// *=

TEST (AssignmentOperators, multiply) {
    Ratio ratio1(2, 3);
    Ratio ratio2(10, 6);
    ratio1 *= ratio2;
    ASSERT_EQ (ratio1.getNumerator(), 10);
    ASSERT_EQ (ratio1.getDenominator(), 9);
}

TEST (AssignmentOperators, multiplyValue) {
    Ratio ratio(2, 4);
    float value = 11.6;
    ratio *= value;
    ASSERT_EQ (ratio.getNumerator(), 29);
    ASSERT_EQ (ratio.getDenominator(), 5);
}

TEST (AssignmentOperators, valueMultiply) {
    int value = 5;
    Ratio ratio(30, 10);
    value *= ratio;
    ASSERT_EQ (value, 15);
}

/////////////////// /=

TEST (AssignmentOperators, divide) {
    Ratio ratio1(2, 3);
    Ratio ratio2(4, 5);
    ratio1 /= ratio2;
    ASSERT_EQ (ratio1.getNumerator(), 5);
    ASSERT_EQ (ratio1.getDenominator(), 6);
}

TEST (AssignmentOperators, divideValue) {
    Ratio ratio(7, 11);
    float value = 5.;
    ratio /= value;
    ASSERT_EQ (ratio.getNumerator(), 7);
    ASSERT_EQ (ratio.getDenominator(), 55);
}

TEST (AssignmentOperators, valueDivide) {
    float value = 2.5;
    Ratio ratio(5, 7);
    value /= ratio;
    ASSERT_EQ (value, 3.5);
}

/////////////////// %=

TEST (AssignmentOperators, modulo) {
    Ratio ratio1(5, 7);
    Ratio ratio2(6, 4);
    ratio1 %= ratio2;
    ASSERT_EQ (ratio1.getNumerator(), 10);
    ASSERT_EQ (ratio1.getDenominator(), 1);
}

TEST (AssignmentOperators, moduloValue) {
    Ratio ratio(2, 10);
    float value = 9.;
    ratio %= value;
    ASSERT_EQ (ratio.getNumerator(), 1);
    ASSERT_EQ (ratio.getDenominator(), 1);
}

TEST (AssignmentOperators, valueModulo) {
    int value = 10;
    Ratio ratio(14, 2);
    value %= ratio;
    ASSERT_EQ (value, 3);
}