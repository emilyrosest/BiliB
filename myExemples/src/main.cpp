#include <iostream>
#include "Ratio.hpp"




int main()
{
    Ratio myRatio;

    int bidule = 0;
    bidule++;


    // std::cout << "salut a tous!!! " << std::endl << bidule << std::endl;

    // //CONSTRUCTEUR DEFAUT
    // std::cout << myRatio.getNumerator() << std::endl;

    
    // //2E CONSTRUCTEUR
    // int n = 2;
    // unsigned int d = 3;
    // Ratio myRatio2(n, d);
    // std::cout << myRatio2.getNumerator() << std::endl;
    // int x = myRatio2.getNumerator();
    // x++;
    // std::cout << x << std::endl;

    // Ratio myRatio3(4, 5);
    // std::cout << myRatio3.getNumerator() << std::endl;

    // //COPY CONSTRUCTEUR
    // Ratio myCopyRatio(myRatio2);
    // std::cout << myCopyRatio.getNumerator() << std::endl;

    // //Constructor from dfloat
    // Ratio fRatio(2.5);
    // std::cout << fRatio.getNumerator() << std::endl;
    // std::cout << fRatio.getDenominator() << std::endl;

    // std::cout << (fRatio*6.0).getNumerator() << std::endl;

    // Ratio ratio = convertToRatio<float>(3.2, nb_iter);
    // std::cout << ratio.getNumerator() << std::endl;
    // std::cout << ratio.getDenominator() << std::endl;

    Ratio ratio = convertToRatio(11.6, nb_iter); //9.6 = 48/5, 12.8 = 64/5, (7.5 = 45/6), (5.25=42/8), 11.6=58/5
    std::cout << ratio << std::endl;

    // Ratio ratio(2, 3);
    // std::cout << ratio.inverse2() << std::endl;

    return 0;
}