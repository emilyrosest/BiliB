#include <iostream>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <cassert>


static unsigned int nbIter = 10;


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
            if (d == 0) throw std::string("denominator should not be zero");
            m_n = (d > static_cast<T>(0)) ? n : -n;
            m_d = abs(d);
            reduce();
        }

        /// \brief copy constructor
        /// \param ratio
        Ratio(const Ratio &ratio) : m_n(ratio.m_n), m_d(ratio.m_d) {}

        /// @brief constructor from a double
        /// @tparam U : the type of the given number
        /// @param x : the number to convert into a ratio number
        template <typename U = float>
        Ratio(const U &x) : m_n(convertToRatio<U>(x, nbIter).getNumerator()), m_d(convertToRatio<U>(x, nbIter).getDenominator()) {}

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

        /// @brief set the numerator and denominator
        /// @param n : the new numerator
        /// @param d : the new denominator
        inline void setRatio(const T &n, const T &d) {m_n = n; m_d = d; reduce();};


        /// @brief transform the ratio into an irreducible fraction
        void reduce(){ 
            int pgcd = std::gcd((int)m_n, (int)m_d); 
            assert(pgcd != 0 && "gcd should not be zero");
            m_n /= pgcd;
            m_d /= pgcd;
        }

        /// @brief inverse the ratio
        /// @return the inversed ratio
        Ratio<T> inverse() {
            return Ratio<T>(m_d, m_n);
        }

        /// @brief devides the numerator by the denominator
        /// @return the remainder
        T remainder() {
            return m_n % m_d;
        }

        /// @brief the absolute value of a ratio
        /// @return the absolute value
        Ratio absolute() {
            return (m_n < static_cast<T>(0)) ? -*this : *this;
        }

        /// @brief the integer part of a ratio
        /// @return the integer part
        T floor() {
            return static_cast<T>(m_n / m_d);
        }

        /// @brief convert ratio to number
        /// @tparam U : the type of the number wanted
        /// @return the number
        template <typename U = float>
        U convertToNumber() const{
            return static_cast<U>(m_n) / static_cast<U>(m_d);
        }


        //////////////////////////////// ARITHMETIC OPERATORS

        /// @brief add 2 ratio
        /// @param r ratio to add to the calling ratio
        /// @return the sum of the current ratio and the argument ratio
        inline Ratio operator+(const Ratio &r) const { return Ratio(m_n * r.m_d + m_d * r.m_n, m_d * r.m_d);};

        //ratio + autre type, ratio+ratio , ratio+T, T+ratio

        /// @brief subtract a ratio to the current ratio
        /// @param r ratio to subtract to the calling ratio
        /// @return the subtraction of the current ratio and the argument ratio
        inline Ratio operator-(const Ratio &r) const { return Ratio(m_n * r.m_d - m_d * r.m_n, m_d * r.m_d);};

        /// @brief invert the ratio's sign
        /// @return the inverted ratio
        inline Ratio operator-() const { return Ratio(-m_n, m_d);};

        /// @brief divide the ratio by another ratio
        /// @param r the denominator of the division
        /// @return the division of the current ratio and the argument ratio
        inline Ratio operator/(const Ratio &r) const { return Ratio(m_n * r.m_d, m_d * r.m_n);};

        /// @brief multiply the ratio by another ratio
        /// @param r the ratio used to multiply
        /// @return the multiplication of the current ratio and the argument ratio
        inline Ratio operator*(const Ratio &r) const { return Ratio(m_n * r.m_n, m_d * r.m_d);};

        /// @brief multiply the ratio by a value
        /// @param value the value to multiply the ratio
        /// @return the multiplication of the current ratio and the given value
        inline Ratio operator*(const T &value) const { return Ratio(m_n * value, m_d);};

        /// @brief divide the ratio by another and gives the remainder
        /// @tparam U : the type of the remainder
        /// @param r : the ratio to divide
        /// @return the rational remainder of the division of 2 ratio
        template <typename U = float>
        inline Ratio operator%(const Ratio &r) const { return convertToRatio<U>((*this / r).remainder(), nbIter);}

        /// @brief increment the ratio by 1
        void operator++() { 
            Ratio one(static_cast<T>(1), static_cast<T>(1));
            *this += one;
        }

        /// @brief decrement the ratio by 1
        void operator--() {
            Ratio one(static_cast<T>(1), static_cast<T>(1));
            *this -= one;
        }

        //////////////////////////////// ASSIGNMENT OPERATORS

        /// @brief assign a ratio to another
        /// @param r the ratio to assign
        /// @return the ratio assigned
        Ratio operator=(const Ratio &r) {
            if (&r == this) return *this;
            m_n = r.m_n;
            m_d = r.m_d;
            return *this;
        }

        /// @brief add a ratio to the curent ratio
        /// @param r : the ratio to add
        void operator+=(const Ratio &r) { //mettre en ratio
            //setRatio(m_n * r.m_d + r.m_n * m_d, m_d * r.m_d);
            *this = *this + r; //return le ratio??
        }

        /// @brief subtract a ratio to the curent ratio
        /// @param r : the ratio to subtract
        void operator-=(const Ratio &r) {
            *this = *this - r;
        }

        /// @brief multiply a ratio to the curent ratio
        /// @param r : the ratio to multiply
        void operator*=(const Ratio &r) {
            *this = *this * r;
        }

        /// @brief divide a ratio to the curent ratio
        /// @param r : the ratio to divide
        void operator/=(const Ratio &r) {
            *this = *this / r;
        }

        // void operator%=(const Ratio &r) {
        //     *this = *this % r;
        // }

        //////////////////////////////// RELATIONAL OPERATORS

        /// @brief comparison of 2 ratio
        /// @param r the compared ratio
        /// @return true if the 2 ratio are equal, false if not
        bool operator==(const Ratio &r) const {
            return (m_n == r.m_n && m_d == r.m_d);
        }

        /// @brief comparison of 2 ratio
        /// @param r : the compared ratio
        /// @return true if the 2 ratio are not equal
        bool operator!=(const Ratio &r) const {
            return (m_n != r.m_n || m_d != r.m_d);
        }

        /// @brief comparison of 2 ratio
        /// @param r : the compared ratio
        /// @return true if the current ratio is greater than the given ratio
        bool operator>(const Ratio &r) const {
            return (m_n * r.m_d > r.m_n * m_d);
        }

        /// @brief comparison of 2 ratio
        /// @param r : the compared ratio
        /// @return true if the current ratio is less than the given ratio
        bool operator<(const Ratio &r) const {
            return (m_n * r.m_d < r.m_n * m_d);
        }

        /// @brief comparison of 2 ratio
        /// @param r : the compared ratio
        /// @return true if the current ratio is greater than or equal to the given ratio
        bool operator>=(const Ratio &r) const {
            return (m_n * r.m_d >= r.m_n * m_d);
        }

        /// @brief comparison of 2 ratio
        /// @param r : the compared ratio
        /// @return true if the current ratio is less than or equal to the given ratio
        bool operator<=(const Ratio &r) const {
            return (m_n * r.m_d <= r.m_n * m_d);
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


/// @brief convert a floating number to a ratio
/// @tparam T : the floating type
/// @tparam U : the int type
/// @param x : the number to convert into a ratio number
/// @param nbIter : the number of recursive calls
/// @return the ratio number
template<typename T, typename U = int>
Ratio<U> convertToRatio(const T &x, unsigned int nbIter) {

    constexpr T ZERO = static_cast<T>(0);
    constexpr T ONE = static_cast<T>(1);

    if (x < ZERO){ 
        return -convertToRatio(-x, nbIter);
    }

    if (x < static_cast<T>(0.01)) {
        return Ratio<U>();
    }

    if (nbIter == 0){
        return Ratio<U>();
    }

    if (x < ONE) {
        return convertToRatio(ONE / static_cast<T>(x), nbIter).inverse();
    }

    U q = static_cast<U>(x);
    return Ratio<U>(q, ONE) + convertToRatio(x - q, nbIter - 1);
}


template <typename T, typename U>
Ratio<T> operator*(const U value, const Ratio<T> &r) {
    return r * value;
}


template <typename T>
Ratio<T> product(Ratio<T> first) {
            return first;
}
template <typename T, typename ... Args>
Ratio<T> product(const Ratio<T> &ratio, const Args ... args) {
    return ratio * product(args...);
}


template <typename T>
Ratio<T> addition(Ratio<T> first) {
            return first;
}
template <typename T, typename ... Args>
Ratio<T> addition(const Ratio<T> &ratio, const Args ... args) {
    return ratio + addition(args...);
}


template <typename T>
Ratio<T> subtraction(Ratio<T> first) {
            return - first;
}
template <typename T, typename ... Args>
Ratio<T> subtraction(const Ratio<T> &ratio, const Args ... args) {
    return ratio - subtraction(args...);
}



// #endif




//assert(d != 0 && "denominator should not be zero"); //exception mieux