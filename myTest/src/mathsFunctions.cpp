#include <string>
#include <gtest/gtest.h>
#include <math.h>

#include "Ratio.hpp"


TEST (mathsFunctions, exp) {
    Ratio ratio(6, 2);
    long double error = ratio.exp().convertToNumber() - std::exp(3);
    ASSERT_EQ (std::abs(error) < 0.000001, true);

    Ratio ratio0;
    ASSERT_EQ (ratio0.exp().convertToNumber(), 1);

    Ratio ratio1(1);
    ASSERT_EQ (ratio1.exp(), Ratio(std::exp(1)));
}

TEST (mathsFunctions, log) {
    Ratio ratio(14, 5);
    long double error = ratio.log().convertToNumber() - log(2.8);
    ASSERT_EQ (std::abs(error) < 0.000001, true);
}

TEST (mathsFunctions, pow) {
    Ratio ratio(32, 5);
    long double error = ratio.pow(3).convertToNumber() - pow(6.4, 3);
    ASSERT_EQ (std::abs(error) < 0.0001, true);
}

TEST (mathsFunctions, sqrt) {
    Ratio ratio(125, 5);
    ASSERT_EQ (ratio.sqrt().convertToNumber(), 5);
}

TEST (mathsFunction, cosSinTan) {
    Ratio ratio(45, 6);
    long double errorCos = ratio.cos().convertToNumber() - cos(7.5);
    long double errorSin = ratio.sin().convertToNumber() - sin(7.5);
    long double errorTan = ratio.tan().convertToNumber() - tan(7.5);
    ASSERT_EQ (std::abs(errorCos) < 0.000001, true);
    ASSERT_EQ (std::abs(errorSin) < 0.000001, true);
    ASSERT_EQ (std::abs(errorTan) < 0.000001, true);
}