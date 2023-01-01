#include <iostream>
#include "Ratio.hpp"


int main()
{
    //////////////////// CONSTRUCTORS
    
    Ratio<int> myRatio0;
    Ratio<int> myRatio1(78, 44);
    Ratio<int> myRatio2(myRatio1);
    Ratio<int> myRatio3(-15.25895);

    std::cout << "myRatio0 = " << myRatio0 << std::endl;
    std::cout << "myRatio1 = " << myRatio1 << std::endl;
    std::cout << "myRatio2 = " << myRatio2 << std::endl << std::endl;

    //////////////////// GETTERS AND SETTERS

    myRatio2.setNumerator(48);
    std::cout << "myRatio2 = " << myRatio2 << std::endl;
    std::cout << "myRatio3 = " << myRatio3.getNumerator() << "/" << myRatio3.getDenominator() << std::endl << std::endl;

    //////////////////// FUNCTIONS

    std::cout << "1/myRatio1 = " << myRatio1.inverse() << std::endl;
    std::cout << "42 = " << Ratio(42, 5).remainder() << " [5]" << std::endl;
    std::cout << "|myRatio3| = " << myRatio3.absolute() << std::endl;
    std::cout << "myRatio3 integer part = " << myRatio3.floor() << std::endl;
    std::cout << myRatio2 << " = " << myRatio2.convertToNumber<float>() << std::endl;
    std::cout << "12.56 = " << convertToRatio<double, int>(12.56, nbIter) << std::endl << std::endl;

    //////////////////// ARITHMETIC OPERATORS

    Ratio myRatio4 = myRatio1 + myRatio2;
    Ratio myRatio5 = myRatio4 - 6.123;
    Ratio myRatio6 = - myRatio5;
    Ratio myRatio7 = 23 / myRatio6;
    Ratio myRatio8 = myRatio7 * -0.21;
    Ratio myRatio9 = myRatio8 % myRatio7;
    ++myRatio9;

    std::cout << "myRatio4 = " << myRatio4 << std::endl;
    std::cout << "myRatio5 = " << myRatio5 << std::endl;
    std::cout << "myRatio6 = " << myRatio6 << std::endl;
    std::cout << "myRatio7 = " << myRatio7 << std::endl;
    std::cout << "myRatio8 = " << myRatio8 << std::endl;
    std::cout << "myRatio9 = " << myRatio9 << std::endl << std::endl;

    //////////////////// ASSIGNMENT OPERATORS

    Ratio myRatio10 = myRatio1;
    float myValue1 = 58.2;

    myRatio10 *= myRatio0;
    myRatio10 += 20;
    myValue1 += myRatio10;
    myRatio10 -= myRatio2;
    myRatio10 /= myValue1;
    myValue1 /= myRatio2;
    myRatio10 %= myRatio2;

    std::cout << "myRatio10 = " << myRatio10 << std::endl;
    std::cout << "myValue1 = " << myValue1 << std::endl << std::endl;

    //////////////////// RELATIONAL OPERATORS

    Ratio myRatio11(48, 12);
    Ratio myRatio12(4);
    int myValue2 = 4;

    (myRatio11 == myRatio12) ? std::cout << "myRatio11 == myRatio12" << std::endl : std::cout << "myRatio11 != myRatio12" << std::endl;
    (myValue2 == myRatio12) ? std::cout << "myValue2 == myRatio12" << std::endl : std::cout << "myValue2 != myRatio12" << std::endl;
    (myRatio11 != 4.1) ? std::cout << "myRatio11 != 4.1" << std::endl : std::cout << "myRatio11 == 4.1" << std::endl;
    (myRatio11 > 4.1) ? std::cout << "myRatio11 > 4.1" << std::endl : std::cout << "myRatio11 <= 4.1" << std::endl;
    (myRatio11 <= Ratio(355, 175)) ? std::cout << "myRatio11 <= " << Ratio(355, 175) << std::endl : std::cout << "myRatio11 > " << Ratio(355, 175) << std::endl;
    (myValue2 + 29.7 < myRatio12) ? std::cout << myValue2 + 29.7 << " < myRatio12" << std::endl : std::cout << myValue2 + 29.7 << " >= myRatio12" << std::endl;

    Ratio myRatio13 = myRatio11 + myRatio12 + Ratio(myValue2) + myRatio1;
    Ratio myRatio14 = addition(myRatio11, myRatio12, Ratio(myValue2), myRatio1);
    (myRatio13 == myRatio14) ? std::cout << "myRatio13 == myRatio14" << std::endl : std::cout << "myRatio13 != myRatio14" << std::endl << std::endl;

    //////////////////// MIN & MAX

    std::cout << "min : " << min(myRatio0, myRatio1, myRatio2, myRatio3, myRatio4, myRatio5, myRatio6, myRatio7, myRatio8, myRatio9, myRatio10, myRatio11, myRatio12, myRatio13, myRatio14) << std::endl;
    std::cout << "max : " << max(myRatio0, myRatio1, myRatio2, myRatio3, myRatio4, myRatio5, myRatio6, myRatio7, myRatio8, myRatio9, myRatio10, myRatio11, myRatio12, myRatio13, myRatio14) << std::endl << std::endl;

    //////////////////// MATHS FUNCTIONS
    
    std::cout << "exp(0) = " << (-Ratio()).exp() << std::endl;
    std::cout << "exp(-1) = " << (-Ratio(1)).exp() << std::endl;
    std::cout << "exp(10) = " << Ratio(10).exp() << std::endl;

    std::cout << "log(1) = " << Ratio(1).log() << std::endl;
    std::cout << "log(10) = " << Ratio(10).log() << std::endl;

    std::cout << "2² = " << Ratio(4, 2).pow(2) << std::endl;
    std::cout << "5³ = " << Ratio(25, 5).pow(3) << std::endl;

    std::cout << "sqrt(25) = " << Ratio(125, 5).sqrt() << std::endl;

    std::cout << "cos(PI) = " << Ratio(M_PI).cos() << std::endl;
    std::cout << "sin(PI) = " << Ratio(M_PI).sin() << std::endl;
    std::cout << "tan(PI) = " << Ratio(M_PI).tan() << std::endl << std::endl;
    
    return 0;
}