#include <iostream>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <cassert>


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
            assert(d != 0 && "denominator should not be zero");
            m_n = (d > static_cast<T>(0)) ? n : -n;
            m_d = abs(d);
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


        /// @brief get the numerator of a ratio number
        /// @return the numerator
        inline T getNumerator() const { return m_n; };

        /// @brief get the denominator of a ratio number
        /// @return the denominator
        inline T getDenominator() const { return m_d; };

        /// @brief set the numerator of a ratio number
        /// @param n : the new numerator
        inline void setNumerator(const T &n) { m_n = n; reduce();};

        /// @brief set the denominator of a ratio number
        /// @param d : the new denominator
        inline void setDenominator(const T &d) { m_d = d; reduce();};


        /// @brief transform the ratio into an irreducible fraction
        void reduce(){
            int pgcd = std::gcd((int)m_n, (int)m_d); 
            m_n /= pgcd;
            m_d /= pgcd;
        }

        /// @brief inverse the ratio
        void inverse() {
            T num = m_n;
            m_n = m_d;
            m_d = num;
        }

        /// @brief devides the numerator by the denominator
        /// @return the remainder
        T remainder() {
            return m_n % m_d;
        }

        // /// @brief convert ratio to number
        // /// @return the normal number
        // template <typename U>
        // U convertToNumber();


        ////////////////////////////////
        //ARITHMETIC OPERATORS

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

        // Ratio operator%(const Ratio &r) const {
        //     Ratio result = this / r;
        //     return result.remainder();
        // }

        // Ratio operator++() const {
        //     this +=
        // }



        ////////////////////////////////////
        //ASSIGNMENT OPERATORS

        /// @brief assign a ratio to another
        /// @param r the ratio to assign
        /// @return the ratio assigned
        Ratio operator=(const Ratio &r) const {
            if (&r == this) return *this;

            m_n = r.m_n;
            m_d = r.m_d;

            return *this;
        }

        // Ratio operator+=(const Ratio &r) const {
        //     *m_n = m_n * r.m_d + m_d * r.m_n;
        //     *m_d = m_d * r.m_d;
        //     reduce();

        //     return *this;
        // }



        ///////////////////////////////////
        //RELATIONAL OPERATORS

        /// @brief comparison of 2 ratio
        /// @param r the compared ratio
        /// @return true if the 2 ratio are equal, false if not
        bool operator==(const Ratio &r) const {
            return (m_n == r.m_n && m_d == r.m_d);
        }


        


};

/// @brief overload the operator << for Ratio
/// @tparam T the type of the ratio
/// @param stream input stream
/// @param ratio the ratio to output
/// @return the output stream containing the ratio
template <typename T>
std::ostream& operator<< (std::ostream& stream, Ratio<T> ratio) {
    stream << ratio.getNumerator() << "/" << ratio.getDenominator();
    return stream;
}



/// @brief convert float to ratio
/// @param x : the number to convert into a ratio number
/// @param nb_iter : the number of recursive calls
/// @return the ratio number
template<typename T, typename U = int>
Ratio<U> convertToRatio(const T &x, unsigned int nb_iter) {
    if (x < 0) // static_cast<T>(0) a la place de 0?
        return -convertToRatio<U>(-x, nb_iter);

    if (x == 0)
        return Ratio<U>();

    if (nb_iter == 0)
        return Ratio<U>();

    if (x < 1)
        return Ratio<U>(1, 1)/convertToRatio<U>(1/x, nb_iter);

    if (x > 1) {
        int q = (int)x;
        std::cout << q << std::endl;
        return Ratio<U>(q, 1) + convertToRatio<U>(x - q, nb_iter - 1);
    }
}


template <typename T, typename U>
Ratio<T> operator*(const U value, const Ratio<T> &r) {
    return r * value;
}

// #endif

