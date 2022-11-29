#include <iostream>
#include "Ratio.hpp"




int main()
{
    Ratio myRatio;

    int bidule = 0;
    bidule++;


    std::cout << "salut a tous!!! " << std::endl << bidule << std::endl;

    //CONSTRUCTEUR DEFAUT
    std::cout << myRatio.getNumerator() << std::endl;

    
    //2E CONSTRUCTEUR
    int n = 2;
    unsigned int d = 3;
    Ratio myRatio2(n, d);
    std::cout << myRatio2.getNumerator() << std::endl;
    int x = myRatio2.getNumerator();
    x++;
    std::cout << x << std::endl;

    Ratio myRatio3(4, 5);
    std::cout << myRatio3.getNumerator() << std::endl;

    //COPY CONSTRUCTEUR
    Ratio myCopyRatio(myRatio2);
    std::cout << myCopyRatio.getNumerator() << std::endl;


    return 0;
}