#include <iostream>
#include <cstdlib>
#include <fstream>


// #ifdef __LIBRATIO__HPP
// #define __LIBRATIO__HPP

// Doxygen menu
/// \version 0.1
/// \mainpage
/// \tableofcontents
/// \section introduction_sec What for?
/// BiliB is a super tool.
/// \section install_bigsec How to install
/// \subsection dependencies_sec Dependecies
/// \li nothing
/// \li Doxygen (if you want the documentation)
/// \subsection install_sec Install with cmake (Linux / Mac)
/// \li go to main dir
/// \li mkdir build
/// \li cd build
/// \li cmake ..
/// \li make
/// \li if Doxygen installed: make html
/// \li The documentation is located in :
///     - [path to build]/doc/doc-doxygen/html/index.html or 
///     - or [path to build]/INTERFACE/doc/doc-doxygen/html/index.html
/// \li euh ça marche bien du coup ou pas ??


/// \class Ratio
/// \brief class defining a number written as a ratio between two integers

class Ratio {
    
    private :

        int m_n;
        unsigned int m_d;

    public:

        /// \brief default constructor (denominator = 0; numerator = 1)
        Ratio();

        /// \brief constructor from the two integers of the ratio
        /// \param n : n is the numerator
        /// \param d : d is the denominator
        Ratio(const int &n, const unsigned int &d);

        /// \brief constructor from a double
        /// \param x : the number to convert into a ratio number
        Ratio(const double &x);

        /// \brief copy constructor
        /// \param ratio
        Ratio(const Ratio &ratio);

        /// \brief destructor
        ~Ratio() = default;



        /// @brief convert float to ratio
        /// @param x : the number to convert into a ratio number
        /// @param nb_iter : the number of recursive calls
        /// @return the ratio number
        Ratio convertToRatio(const double &x, unsigned int nb_iter);

        /// @brief get the numerator of a ratio number
        /// @return the numerator
        int getNumerator() const;

        /// @brief get the denominator of a ratio number
        /// @return the denominator
        int getDenominator() const;

        /// @brief set the numerator of a ratio number
        /// @param n : the new numerator
        void setNumerator(const int &n);

        /// @brief set the denominator of a ratio number
        /// @param d : the new denominator
        void setDenominator(const unsigned int &d);


        void reduce();


        Ratio operator+(const Ratio &r) const;

        Ratio operator/(const Ratio &r) const;

};

// #endif