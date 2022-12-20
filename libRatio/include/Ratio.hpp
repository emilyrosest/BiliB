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

        /// @brief set the numerator and denominator
        /// @param n : the new numerator
        /// @param d : the new denominator
        inline void setRatio(const T &n, const T &d) {m_n = n; m_d = d; reduce();};


        /// @brief transform the ratio into an irreducible fraction
        void reduce(){
            int pgcd = std::gcd((int)m_n, (int)m_d); 
            m_n /= pgcd;
            m_d /= pgcd;
        }

        /// @brief inverse the ratio
        /// @return the inversed ratio
        Ratio inverse() {
            return Ratio(m_d, m_n);
        }

        /// @brief devides the numerator by the denominator
        /// @return the remainder
        T remainder() {
            return m_n % m_d;
        }

// suppr??
        T sameDenominator(Ratio &r) {
            // T d = m_d * r.m_d;
            // this->m_n = m_n * r.m_d;
            // this->m_d = d;
            // r.m_n = r.m_n * m_d;
            // r.m_d = d;
            return m_d * r.m_d;
        }

        /// @brief the absolute value of a ratio
        /// @return the absolute value
        Ratio absolute() {
            return (m_n < static_cast<T>(0)) ? -*this : *this;
        }

        T floor() {
            return static_cast<T>(m_n / m_d);
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

        //A BESOIN DE CONVERT TO RATIO
        // Ratio operator%(const Ratio &r) const {
        //     Ratio result = this / r;
        //     return convertToRatio(result.remainder(), nb_iter);
        // }

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



        ////////////////////////////////////
        //ASSIGNMENT OPERATORS

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
        void operator+=(const Ratio &r) {
            //setRatio(m_n * r.m_d + r.m_n * m_d, m_d * r.m_d);
            *this = *this + r;
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

        ///////////////////////////////////
        //RELATIONAL OPERATORS

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



/// @brief convert float to ratio
/// @param x : the number to convert into a ratio number
/// @param nb_iter : the number of recursive calls
/// @return the ratio number
template<typename T, typename U = int>
Ratio<U> convertToRatio(const T &x, unsigned int nb_iter) {

    std::cout << "x = " << x << std::endl;

    //constexpr T ONE = static_cast<T>(1);
    constexpr T ZERO = static_cast<T>(0);

    if (x < ZERO){ 
        std::cout << "inf 0" << std::endl;
        return -convertToRatio(-x, nb_iter);
    }

    if (x == ZERO) {
        std::cout << "==0" << std::endl;
        return Ratio<U>();
    }

    if (nb_iter == 0){
        std::cout << "nbiter" << std::endl;
        return Ratio<U>();
    }

    if (x < static_cast<T>(1)) {
        std::cout << "x < 1" << std::endl;
        return convertToRatio(static_cast<T>(1) / static_cast<T>(x), nb_iter).inverse();
    }

    U q = static_cast<U>(x);
    std::cout << "q = " << q << std::endl;
    std::cout << "x - q = " << x - q << std::endl;
    return Ratio<U>(q, static_cast<T>(1)) + convertToRatio(x - q, nb_iter - 1);
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



/*
template<typename T, typename U = int>
Ratio<U> convertToRatio(const T &x, unsigned int nb_iter) {
    std::cout << x << std::endl;

    constexpr T ONE = static_cast<T>(1);
    constexpr T ZERO = static_cast<T>(0);

    if (x < static_cast<T>(0)){ // static_cast<T>(0) a la place de 0?
        std::cout << "inf 0" << std::endl;
        return -convertToRatio<U>(-x, nb_iter);
    }

    if (x == static_cast<T>(0)) {
        std::cout << "==0" << std::endl;
        return Ratio<U>();
    }

    if (nb_iter == 0){
        std::cout << "nbiter" << std::endl;
        return Ratio<U>();
    }

    if (x < static_cast<T>(1)) {
        //return Ratio<U>(static_cast<U>(1), static_cast<U>(1))/convertToRatio<U>(1/x, nb_iter);
        //return Ratio<U>(static_cast<U>(1), convertToRatio<U>(1/x, nb_iter));
        std::cout << "ici" << std::endl;
        std::cout << static_cast<T>(1)/static_cast<T>(x) << std::endl;

        //return Ratio<U>(static_cast<U>(1), static_cast<U>(1))/convertToRatio<U>(static_cast<T>(1)/static_cast<T>(x), nb_iter);
        return convertToRatio<U>(ONE / static_cast<T>(x), nb_iter).inverse2();
    }

    if (x >= static_cast<T>(1)) {
        int q = (int)x;
        std::cout << "derniere" << std::endl;
        std::cout << x << std::endl;
        std::cout << "q = " << q << std::endl;
        return Ratio<U>(q, static_cast<U>(1)) + convertToRatio<T>(static_cast<T>(x - q), nb_iter - 1);
    }
}*/