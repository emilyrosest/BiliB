#include <random>
#include <string>
#include <algorithm>
#include <limits>

#include <gtest/gtest.h>

#include "Ratio.hpp"



/////////////////////////////////////////////////////
// constructors

TEST (RatioConstructor, defaultContructor) {
    Ratio ratio;
    EXPECT_EQ (ratio.getNumerator(), 0);
    EXPECT_EQ (ratio.getDenominator(), 1);
}


TEST (RatioConstructor, intergersConstructor) {
    Ratio ratio(9, 5);
    ASSERT_EQ (ratio.getNumerator(), 9);
    ASSERT_EQ (ratio.getDenominator(), 5);
}


// TEST (RatioFunctions, reduceFonction) {

// }


//reduce
//constructeur avec n et d, le refaire pour qu'il reduce



// TEST (RatioConstructor, copyConstructor) {
//     const size_t maxSize = 100000;  //???? prendre cette taille?
// 	std::default_random_engine generator(0);
// 	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
// 	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
// 	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

//     for(int run=0; run<100; ++run) {

//         Ratio ratio1(gen(), gen());
//     }
// }

//converttoratio