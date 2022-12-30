#include <string>
#include <gtest/gtest.h>
#include <cmath>

#include "Ratio.hpp"

/////////////////// ==

TEST (relationalOperators, equal) {
    Ratio ratio1(8, 5);
    Ratio ratio2(16, 10);
    ASSERT_EQ (ratio1 == ratio2, true);
}

TEST (relationalOperators, equalValue) {
    Ratio ratio(16, 5);
    double value = 3.2;
    ASSERT_EQ (ratio == value, true);
}

TEST (relationalOperators, valueEqual) {
    float value = 5.5;
    Ratio ratio(10, 1);
    ASSERT_EQ (value == ratio, false);
}

/////////////////// !=

TEST (relationalOperators, notEqual) {
    Ratio ratio1(8, 5);
    Ratio ratio2(18, 10);
    ASSERT_EQ (ratio1 != ratio2, true);
}

TEST (relationalOperators, notEqualValue) {
    Ratio ratio(8, 5);
    float value = 7.6;
    ASSERT_EQ (ratio != value, true);
}

TEST (relationalOperators, valueNotEqual) {
    float value = 1.6;
    Ratio ratio(8, 5);
    ASSERT_EQ (value != ratio, false);
}

/////////////////// >

TEST (relationalOperators, greater) {
    Ratio ratio1(7, 4);
    Ratio ratio2(2, 7);
    ASSERT_EQ (ratio1 > ratio2, true);
    ASSERT_EQ (ratio2 > ratio1, false);
}

TEST (relationalOperators, greaterValue) {
    Ratio ratio(9, 2);
    float value = 10.9;
    ASSERT_EQ (ratio > value, false);
}

TEST (relationalOperators, valueGreater) {
    float value = 2.;
    Ratio ratio(2, 7);
    ASSERT_EQ (value > ratio, true);
}

/////////////////// <

TEST (relationalOperators, less) {
    Ratio ratio1(1, 3);
    Ratio ratio2(4, 5);
    ASSERT_EQ (ratio1 < ratio2, true);
    ASSERT_EQ (ratio2 < ratio1, false);
}

TEST (relationalOperators, lessValue) {
    Ratio ratio(1, 4);
    float value = 0.25;
    ASSERT_EQ (ratio < value, false);
}

TEST (relationalOperators, valueLess) {
    float value = 0.25;
    Ratio ratio(1, 3);
    ASSERT_EQ (value < ratio, true);
}

/////////////////// >=

TEST (relationalOperators, greaterOrEqual) {
    Ratio ratio1(7, 4);
    Ratio ratio2(14, 8);
    ASSERT_EQ (ratio1 >= ratio2, true);
    ASSERT_EQ (ratio2 >= ratio1, true);
}

TEST (relationalOperators, greaterOrEqualValue) {
    Ratio ratio(7, 9);
    float value = -8.9;
    ASSERT_EQ (ratio >= value, true);
}

TEST (relationalOperators, valueGreaterOrEqual) {
    float value = 2.5;
    Ratio ratio(5, 2);
    ASSERT_EQ (value >= ratio, true);
}

/////////////////// <=

TEST (relationalOperators, lessOrEqual) {
    Ratio ratio1(1, 4);
    Ratio ratio2(4, 3);
    ASSERT_EQ (ratio1 <= ratio2, true);
    ASSERT_EQ (ratio2 <= ratio1, false);
}

TEST (relationalOperators, lessOrEqualValue) {
    Ratio ratio(18, 11);
    float value = 100.7;
    ASSERT_EQ (ratio <= value, true);
}

TEST (relationalOperators, valueLessOrEqual) {
    float value = 1.3;
    Ratio ratio(45, 44);
    ASSERT_EQ (value <= ratio, false);
}

