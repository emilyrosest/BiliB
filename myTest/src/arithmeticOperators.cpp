#include <string>
#include <gtest/gtest.h>

#include "Ratio.hpp"

/////////////////// PLUS

TEST (ArithmeticOperators, plus) {
    Ratio ratio1(5, 3);
    Ratio ratio2(8, 6);
    Ratio result = ratio1 + ratio2;
    ASSERT_EQ (result.getNumerator(), 3);
    ASSERT_EQ (result.getDenominator(), 1);
}

TEST (ArithmeticOperators, plusValue) {
    Ratio ratio(5, 3);
    int value = 2;
    Ratio result = ratio + value;
    ASSERT_EQ (result.getNumerator(), 11);
    ASSERT_EQ (result.getDenominator(), 3);
}

TEST (ArithmeticOperators, valuePlus) {
    Ratio ratio(5, 3);
    double value = 1.75;
    Ratio result = value + ratio;
    ASSERT_EQ (result.getNumerator(), 41);
    ASSERT_EQ (result.getDenominator(), 12);
}

/////////////////// MINUS

TEST (ArithmeticOperators, minus) {
    Ratio ratio1(5, 3);
    Ratio ratio2(8, 6);
    Ratio result = ratio1 - ratio2;
    ASSERT_EQ (result.getNumerator(), 1);
    ASSERT_EQ (result.getDenominator(), 3);
}

TEST (ArithmeticOperators, minusValue) {
    Ratio ratio(3, 5);
    float value = 3.2;
    Ratio result = ratio - value;
    ASSERT_EQ (result.getNumerator(), -13);
    ASSERT_EQ (result.getDenominator(), 5);
}

TEST (ArithmeticOperators, valueMinus) {
    Ratio ratio(3, 5);
    float value = 3.2;
    Ratio result = value - ratio;
    ASSERT_EQ (result.getNumerator(), 13);
    ASSERT_EQ (result.getDenominator(), 5);

    Ratio ratio2(3, 5);
    int value2 = 3;
    Ratio result2 = value2 - ratio2;
    ASSERT_EQ (result2.getNumerator(), 12);
    ASSERT_EQ (result2.getDenominator(), 5);
}

TEST (ArithmeticOperators, unaryMinus) {
    Ratio ratio1(5, 3);
    Ratio result = - ratio1;
    ASSERT_EQ (result.getNumerator(), -5);
    ASSERT_EQ (result.getDenominator(), 3);
}

/////////////////// DIVIDE

TEST (ArithmeticOperators, divide) {
    Ratio ratio1(6, 3); 
    Ratio ratio2(8, 5);
    Ratio result = ratio1/ratio2;
    ASSERT_EQ (result.getNumerator(), 5);
    ASSERT_EQ (result.getDenominator(), 4);
}

TEST (ArithmeticOperators, divideValue) {
    Ratio ratio(6, 3); 
    double value = 1.6;
    Ratio result = ratio/value;
    ASSERT_EQ (result.getNumerator(), 5);
    ASSERT_EQ (result.getDenominator(), 4);
}

TEST (ArithmeticOperators, valueDivide) {
    float value = 2.;
    Ratio ratio(6, 3); 
    Ratio result = value / ratio;
    ASSERT_EQ (result.getNumerator(), 1);
    ASSERT_EQ (result.getDenominator(), 1);
}

/////////////////// MULTIPLY

TEST (ArithmeticOperators, multiply) {
    Ratio ratio1(6, 3); 
    Ratio ratio2(8, 5);
    Ratio result = ratio1*ratio2;
    ASSERT_EQ (result.getNumerator(), 16);
    ASSERT_EQ (result.getDenominator(), 5);
}

TEST (ArithmeticOperators, multiplyValue) {
    Ratio ratio(8, 5);
    int value = 3;
    Ratio result = ratio * value;
    ASSERT_EQ (result.getNumerator(), 24);
    ASSERT_EQ (result.getDenominator(), 5);
}

TEST (ArithmeticOperators, valueMultiply) {
    int value = 5;
    Ratio ratio(4, 3);
    Ratio result = value * ratio;
    ASSERT_EQ (result.getNumerator(), 20);
    ASSERT_EQ (result.getDenominator(), 3);
}

/////////////////// MODULO

TEST (ArithmeticOperators, modulo) {
    Ratio ratio1(5, 2);
    Ratio ratio2(4, 3);
    Ratio result = ratio1 % ratio2;
    ASSERT_EQ (result.getNumerator(), 7);
    ASSERT_EQ (result.getDenominator(), 1);
}

/////////////////// INCREMENT & DECREMENT

TEST (ArithmeticOperators, increment) {
    Ratio ratio(2, 3);
    ++ratio;
    ASSERT_EQ (ratio.getNumerator(), 5);
    ASSERT_EQ (ratio.getDenominator(), 3);
}

TEST (ArithmeticOperators, decrement) {
    Ratio ratio(2, 3);
    --ratio;
    ASSERT_EQ (ratio.getNumerator(), -1);
    ASSERT_EQ (ratio.getDenominator(), 3);
}