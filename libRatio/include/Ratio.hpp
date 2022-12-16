#include <iostream>
#include <cstdlib>
#include <fstream>
#include <numeric>


static unsigned int nb_iter = 10;


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



template <class T = int>
class Ratio {
    
    private :

        T m_n;
        T m_d;

    public:

        /// \brief default constructor (denominator = 0; numerator = 1)
        Ratio() : m_n(0), m_d(1) {}

        /// \brief constructor from the two integers of the ratio
        /// \param n : n is the numerator
        /// \param d : d is the denominator
        Ratio(const T &n, const T &d) {
            // à faire : vérifier si le dénominateur est négatif
            // si c'est le cas, mettre le numérateur négatif
            m_n = n;
            m_d = d;
            reduce();
        }

        /// \brief copy constructor
        /// \param ratio
        Ratio(const Ratio &ratio) : m_n(ratio.m_n), m_d(ratio.m_d) {}

        // /// \brief constructor from a double
        // /// \param x : the number to convert into a ratio number
        // Ratio(const T &x) : m_n(convertToRatio(x, nb_iter).m_n), m_d(convertToRatio(x, nb_iter).m_d) {}

        /// \brief destructor
        ~Ratio() = default;


        /// @brief convert ratio to number
        /// @return the normal number
        template <typename U>
        U convertToNumber();

        /// @brief get the numerator of a ratio number
        /// @return the numerator
        inline T getNumerator() const { return m_n; };

        /// @brief get the denominator of a ratio number
        /// @return the denominator
        inline T getDenominator() const { return m_d; };

        /// @brief set the numerator of a ratio number
        /// @param n : the new numerator
        inline void setNumerator(const T &n) { m_n = n; };

        /// @brief set the denominator of a ratio number
        /// @param d : the new denominator
        inline void setDenominator(const T &d) { m_d = d; };

        /// @brief transform the ratio into an irreducible fraction
        void reduce(){
            int pgcd = std::gcd((int)m_n, (int)m_d); 
            m_n /= pgcd;
            m_d /= pgcd;
        }

        /// @brief add 2 ratio
        /// @param r ratio to add to the calling ratio
        /// @return the sum of the current ratio and the argument ratio
        Ratio operator+(const Ratio &r) const {
            Ratio result;
            result.m_n = this->m_n * r.m_d + this->m_d * r.m_n;
            result.m_d = this->m_d * r.m_d;
            result.reduce();

            return result;
        }

        /// @brief subtract a ratio to the current ratio
        /// @param r ratio to subtract to the calling ratio
        /// @return the subtraction of the current ratio and the argument ratio
        Ratio operator-(const Ratio &r) const {
            Ratio result;
            result.m_n = this->m_n * r.m_d - this->m_d * r.m_n;
            result.m_d = this->m_d * r.m_d;
            result.reduce();

            return result;
        }

        /// @brief invert the ratio's sign
        /// @return the inverted ratio
        Ratio operator-() const {
            Ratio result;
            result.m_n = -(this->m_n);
            result.m_d = this->m_d;

            return result;
        }

        /// @brief divide the ratio by another ratio
        /// @param r the denominator of the division
        /// @return the division of the current ratio and the argument ratio
        Ratio operator/(const Ratio &r) const {
            Ratio result;
            result.m_n = this->m_n * r.m_d;
            result.m_d = this->m_d * r.m_n;
            result.reduce();

            return result;
        }

        /// @brief multiply the ratio by another ratio
        /// @param r the ratio used to multiply
        /// @return the multiplication of the current ratio and the argument ratio
        Ratio operator*(const Ratio &r) const {
            Ratio result;
            result.m_n = this->m_n * r.m_n;
            result.m_d = this->m_d * r.m_d;
            result.reduce();

            return result;
        }

        /// @brief multiply the ratio by a value
        /// @param value the value to multiply the ratio
        /// @return the multiplication of the current ratio and the given value
        Ratio operator*(const T &value) const {
            Ratio result;
            result.m_n = this->m_n * value;
            result.m_d = this->m_d;
            result.reduce();

            return result;
        }


};

/// @brief convert float to ratio
/// @param x : the number to convert into a ratio number
/// @param nb_iter : the number of recursive calls
/// @return the ratio number
template<typename T, typename U = int>
Ratio<U> convertToRatio(const T &x, unsigned int nb_iter) {
    if (x < 0)
        return -convertToRatio<T>(-x, nb_iter);

    if (x == 0)
        return Ratio<U>();

    if (nb_iter == 0)
        return Ratio<U>();

    if (x < 1)
        return Ratio<U>(1, 1)/convertToRatio<T>(1/x, nb_iter);

    if (x > 1) {
        int q = (int)x;
        return Ratio<U>(q, 1) + convertToRatio<T>(x - q, nb_iter - 1);
    }
}


// faire la multiplication dans le sens value * ratio
// Ratio<T> T::operator*(const Ratio &r) {
//     return r*T;
// }

// #endif

