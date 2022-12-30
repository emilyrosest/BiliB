#include <iostream>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <cassert>


static unsigned int nbIter = 10;


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
        //////////////////////////////// CONSTRUCTORS AND DESTRUCTOR

        /// \brief default constructor (denominator = 0; numerator = 1)
        constexpr Ratio() : m_n(0), m_d(1) {}

        /// \brief constructor from the two integers of the ratio
        /// \param n : n is the numerator (it always carries the sign)
        /// \param d : d is the denominator
        constexpr Ratio(const T &n, const T &d) {
            if (d == 0) throw std::domain_error("denominator should not be zero");
            m_n = (d > static_cast<T>(0)) ? n : -n;
            m_d = abs(d);
            reduce();
        }

        /// \brief copy constructor
        /// \param ratio
        constexpr Ratio(const Ratio &ratio) : m_n(ratio.m_n), m_d(ratio.m_d) {}

        /// @brief constructor from a double
        /// @tparam U : the type of the given number
        /// @param x : the number to convert into a ratio number
        template <typename U>
        constexpr Ratio(const U &x) {
            Ratio<T> ratio = convertToRatio<U, T>(x, nbIter);
            if (ratio.m_d == static_cast<T>(0)) throw std::domain_error("denominator should not be zero");
            m_n = ratio.m_n;
            m_d = ratio.m_d;
        } 

        /// \brief destructor
        ~Ratio() = default;

        //////////////////////////////// FUNCTIONS

        /// @brief get the numerator of a ratio number
        /// @return the numerator
        inline constexpr T getNumerator() const { return m_n; };

        /// @brief get the denominator of a ratio number
        /// @return the denominator
        inline constexpr T getDenominator() const { return m_d; };

        /// @brief set the numerator of a ratio number
        /// @param n : the new numerator
        inline constexpr void setNumerator(const T &n) { m_n = n; reduce();};

        /// @brief set the denominator of a ratio number
        /// @param d : the new denominator
        inline constexpr void setDenominator(const T &d) { m_d = d; reduce();};

        /// @brief set the numerator and denominator
        /// @param n : the new numerator
        /// @param d : the new denominator
        inline constexpr void setRatio(const T &n, const T &d) {if (d == 0) throw std::string("denominator should not be zero"); m_n = n; m_d = d; reduce();};


        /// @brief transform the ratio into an irreducible fraction
        constexpr void reduce(){ 
            int pgcd = std::gcd((int)m_n, (int)m_d); 
            assert(pgcd != 0 && "gcd should not be zero");
            m_n /= pgcd;
            m_d /= pgcd;
        }

        /// @brief inverse the ratio
        /// @return the inversed ratio
        inline constexpr Ratio<T> inverse() { return Ratio<T>(m_d, m_n);};

        /// @brief devides the numerator by the denominator
        /// @return the remainder
        inline constexpr T remainder() { return m_n % m_d;};

        /// @brief the absolute value of a ratio
        /// @return the absolute value
        inline constexpr Ratio<T> absolute() { return (m_n < static_cast<T>(0)) ? -*this : *this;};

        /// @brief the integer part of a ratio
        /// @return the integer part
        inline constexpr T floor() { return static_cast<T>(m_n / m_d);};

        /// @brief convert ratio to number
        /// @tparam U : the type of the number wanted
        /// @return the number
        template <typename U = float>
        inline constexpr U convertToNumber() const{ return static_cast<U>(m_n) / static_cast<U>(m_d);}


        //////////////////////////////// ARITHMETIC OPERATORS

        /// @brief add 2 ratio
        /// @param r : ratio to add to the calling ratio
        /// @return the sum of the current ratio and the argument ratio
        inline constexpr Ratio<T> operator+(const Ratio<T> &r) const { return Ratio<T>(m_n * r.m_d + m_d * r.m_n, m_d * r.m_d);};

        /// @brief add a ratio and a number
        /// @tparam U : the type of the number
        /// @param value : the value to add to the ratio
        /// @return the sum of the current ratio and the argument number
        template <typename U>
        inline constexpr Ratio<T> operator+(const U &value) const { return *this + convertToRatio<U, T>(value, nbIter);}

        /// @brief subtract a ratio to the current ratio
        /// @param r : ratio to subtract to the calling ratio
        /// @return the subtraction of the current ratio and the argument ratio
        inline constexpr Ratio<T> operator-(const Ratio<T> &r) const { return Ratio<T>(m_n * r.m_d - m_d * r.m_n, m_d * r.m_d);};

        /// @brief subtract a number to the current ratio
        /// @tparam U : the type of the number
        /// @param value : the value to subtract to the ratio
        /// @return the subtraction of the current ratio and the argument number
        template <typename U>
        inline constexpr Ratio<T> operator-(const U &value) const { return *this - convertToRatio<U, T>(value, nbIter);} 

        /// @brief invert the ratio's sign
        /// @return the inverted ratio
        inline constexpr Ratio<T> operator-() const { return Ratio<T>(-m_n, m_d);};

        /// @brief divide the ratio by another ratio
        /// @param r : the denominator of the division
        /// @return the division of the current ratio and the argument ratio
        inline constexpr Ratio<T> operator/(const Ratio<T> &r) const { return Ratio<T>(m_n * r.m_d, m_d * r.m_n);};

        /// @brief divide a ratio by a number
        /// @tparam U : the type of the number
        /// @param value : the value to divide to the ratio
        /// @return the division of the current ratio by the argument number
        template <typename U>
        constexpr Ratio<T> operator/(const U &value) const { 
            Ratio<T> ratioValue = convertToRatio<U, T>(value, nbIter);
            if (ratioValue == Ratio()) throw std::string("denominator should not be zero");
            return *this / ratioValue;
        }

        /// @brief multiply the ratio by another ratio
        /// @param r : the ratio used to multiply
        /// @return the multiplication of the current ratio and the argument ratio
        inline constexpr Ratio<T> operator*(const Ratio<T> &r) const { return Ratio<T>(m_n * r.m_n, m_d * r.m_d);};

        /// @brief multiply the ratio by a value
        /// @param value : the value to multiply the ratio
        /// @return the multiplication of the current ratio and the given value
        template <typename U>
        inline constexpr Ratio<T> operator*(const U &value) const { return Ratio<T>(m_n * value, m_d);}

        /// @brief divide the ratio by another and gives the remainder
        /// @tparam U : the type of the remainder
        /// @param r : the ratio to divide
        /// @return the rational remainder of the division of 2 ratio
        template <typename U = float>
        inline constexpr Ratio<T> operator%(const Ratio<T> &r) const { return convertToRatio<U, T>((*this / r).remainder(), nbIter);}

        /// @brief increment the ratio by 1
        inline constexpr void operator++() { *this += Ratio<T>(static_cast<T>(1), static_cast<T>(1));};

        /// @brief decrement the ratio by 1
        inline constexpr void operator--() { *this -= Ratio<T>(static_cast<T>(1), static_cast<T>(1));};

        //////////////////////////////// ASSIGNMENT OPERATORS

        /// @brief assign a ratio to another
        /// @param r : the ratio to assign
        /// @return the ratio assigned
        constexpr Ratio<T> operator=(const Ratio<T> &r) {
            if (&r == this) return *this;
            m_n = r.m_n;
            m_d = r.m_d;
            return *this;
        }

        /// @brief assign a ratio to another from a value
        /// @tparam U : the type of the value
        /// @param value : the value to assign
        /// @return the ratio assigned
        template <typename U>
        inline constexpr Ratio<T> operator=(const U &value) { this = convertToRatio<U, T>(value, nbIter); return *this;}

        /// @brief add a ratio to the curent ratio
        /// @param r : the ratio to add
        inline void operator+=(const Ratio<T> &r) { *this = *this + r;}; //return un ratio?

        /// @brief add a value to the current ratio
        /// @tparam U : the type of the value
        /// @param value : the value to add
        template <typename U>
        inline constexpr void operator+=(const T &value) { *this += convertToRatio<U, T>(value, nbIter);}

        /// @brief subtract a ratio to the curent ratio
        /// @param r : the ratio to subtract
        inline constexpr void operator-=(const Ratio<T> &r) { *this = *this - r;};

        /// @brief subtract a value to the current ratio
        /// @tparam U : the type of the value
        /// @param value : the value to subtract
        template <typename U>
        inline constexpr void operator-=(const U &value) { *this -= convertToRatio<U, T>(value, nbIter);}

        /// @brief multiply a ratio to the curent ratio
        /// @param r : the ratio to multiply
        inline constexpr void operator*=(const Ratio<T> &r) { *this = *this * r;};

        /// @brief multiply a value to the current ratio
        /// @tparam U : the type of the value
        /// @param value : the value to multiply
        template <typename U>
        inline constexpr void operator*=(const U &value) { *this *= convertToRatio<U, T>(value, nbIter);}

        /// @brief divide a ratio to the current ratio
        /// @param r : the ratio to divide
        inline constexpr void operator/=(const Ratio<T> &r) { *this = *this / r;};

        /// @brief divide a value to the current ratio
        /// @tparam U : the type of the value
        /// @param value : the value to divide
        template <typename U>
        inline constexpr void operator/=(const U &value) { *this /= convertToRatio<U, T>(value, nbIter);}

        /// @brief assign the remainder of the current ratio and a ratio to the current ratio
        /// @param r : the ratio to divide to the current ratio to get the remainder
        inline constexpr void operator%=(const Ratio<T> &r) { *this = *this % r;};

        /// @brief assign the remainder of the current ratio and a value to the current ratio
        /// @tparam U : the type of the value
        /// @param value : the value to divide to the current ratio to get the remainder
        template <typename U>
        inline constexpr void operator%=(const U &value) { *this %= convertToRatio<U, T>(value, nbIter);}

        //////////////////////////////// RELATIONAL OPERATORS

        /// @brief comparison of 2 ratio
        /// @param r : the compared ratio
        /// @return true if the 2 ratio are equal, false if not
        inline constexpr bool operator==(const Ratio<T> &r) const { return (m_n == r.m_n && m_d == r.m_d);};

        /// @brief comparision of a ratio and a value
        /// @tparam U : the type of the value
        /// @param value : the compared value
        /// @return true if the ratio and the value are equal
        template <typename U>
        inline constexpr bool operator==(const U &value) const { return *this == convertToRatio<U, T>(value, nbIter);}

        /// @brief comparison of 2 ratio
        /// @param r : the compared ratio
        /// @return true if the 2 ratio are not equal
        inline constexpr bool operator!=(const Ratio<T> &r) const { return (m_n != r.m_n || m_d != r.m_d);};

        /// @brief comparision of a ratio and a value
        /// @tparam U : the type of the value
        /// @param value : the compared value
        /// @return true if the ratio and the value are not equal
        template <typename U>
        inline constexpr bool operator!=(const U &value) const { return *this != convertToRatio<U, T>(value, nbIter);}

        /// @brief comparison of 2 ratio
        /// @param r : the compared ratio
        /// @return true if the current ratio is greater than the given ratio
        inline constexpr bool operator>(const Ratio<T> &r) const { return (m_n * r.m_d > r.m_n * m_d);};

        /// @brief comparision of a ratio and a value
        /// @tparam U : the type of the value
        /// @param value : the compared value
        /// @return true if the current ratio is greater than the value
        template <typename U>
        inline constexpr bool operator>(const U &value) const { return *this > convertToRatio<U, T>(value, nbIter);}

        /// @brief comparison of 2 ratio
        /// @param r : the compared ratio
        /// @return true if the current ratio is less than the given ratio
        inline constexpr bool operator<(const Ratio<T> &r) const { return (m_n * r.m_d < r.m_n * m_d);};

        /// @brief comparision of a ratio and a value
        /// @tparam U : the type of the value
        /// @param value : the compared value
        /// @return true if the current ratio is less than the value
        template <typename U>
        inline constexpr bool operator<(const U &value) const { return *this < convertToRatio<U, T>(value, nbIter);}

        /// @brief comparison of 2 ratio
        /// @param r : the compared ratio
        /// @return true if the current ratio is greater than or equal to the given ratio
        inline constexpr bool operator>=(const Ratio<T> &r) const { return (m_n * r.m_d >= r.m_n * m_d);};

        /// @brief comparision of a ratio and a value
        /// @tparam U : the type of the value
        /// @param value : the compared value
        /// @return true if the current ratio is greater than or equal to the value
        template <typename U>
        inline constexpr bool operator>=(const U &value) const { return *this >= convertToRatio<U, T>(value, nbIter);}

        /// @brief comparison of 2 ratio
        /// @param r : the compared ratio
        /// @return true if the current ratio is less than or equal to the given ratio
        inline constexpr bool operator<=(const Ratio<T> &r) const { return (m_n * r.m_d <= r.m_n * m_d);};

        /// @brief comparision of a ratio and a value
        /// @tparam U : the type of the value
        /// @param value : the compared value
        /// @return true if the current ratio is less than or equal to the value
        template <typename U>
        inline constexpr bool operator<=(const U &value) const { return *this <= convertToRatio<U, T>(value, nbIter);}

};

/// @brief overload the operator << for Ratio
/// @tparam T the type of the ratio
/// @param stream : input stream
/// @param ratio : the ratio to output
/// @return the output stream containing the ratio
template <typename T>
constexpr std::ostream& operator<< (std::ostream& stream, Ratio<T> ratio) {
    stream << ratio.getNumerator() << "/" << ratio.getDenominator();
    return stream;
}


/// @brief convert a floating number to a ratio
/// @tparam T : the floating type
/// @tparam U : the int type
/// @param x : the number to convert into a ratio number
/// @param nbIter : the number of recursive calls
/// @return the ratio number
template<typename U, typename T = int>
constexpr Ratio<T> convertToRatio(const U &x, unsigned int nbIter) {
    constexpr U ZERO = static_cast<U>(0);
    constexpr U ONE = static_cast<U>(1);

    if (x < ZERO){ 
        return -convertToRatio<U, T>(-x, nbIter);
    }
    if (x < 0.01) { //static_cast<U>(0.01)
        return Ratio<T>();
    }
    if (nbIter == 0){
        return Ratio<T>();
    }
    if (x < ONE) {
        return convertToRatio<U, T>(ONE / static_cast<U>(x), nbIter).inverse();
    }
    U q = static_cast<T>(x);
    return Ratio<T>(q, ONE) + convertToRatio<U, T>(x - q, nbIter - 1);
}

//////////////////////////////// ARITHMETIC OPERATORS

/// @brief add a ratio and a number
/// @tparam U : the type of the number
/// @tparam T : the type of the ratio
/// @param value : the value to add to the ratio
/// @param r : the ratio
/// @return the sum of the ratio and the number
template <typename T, typename U>
inline constexpr Ratio<T> operator+(const U &value, const Ratio<T> &r) { return convertToRatio<U, T>(value, nbIter) + r;}

/// @brief subtract a ratio to a number
/// @tparam U : the type of the number
/// @tparam T : the type of the ratio
/// @param value : the value to subtract the ratio
/// @param r : the ratio
/// @return the subtraction of the ratio to the number
template <typename T, typename U>
inline constexpr Ratio<T> operator-(const U &value, const Ratio<T> &r) { return convertToRatio<U, T>(value, nbIter) - r;}

/// @brief divide a ratio by a number
/// @tparam U : the type of the number
/// @param value : the value to divide to the ratio
/// @return the division of the current ratio by the argument number
template <typename T, typename U>
constexpr Ratio<T> operator/(const U &value, const Ratio<T> &r) { 
    if (r == Ratio<T>()) throw std::string("denominator should not be zero");
    return convertToRatio<U, T>(value, nbIter) / r;
} 

/// @brief multiply a value by a ratio
/// @tparam T : the type of the ratio
/// @tparam U : the type of the value
/// @param value : the value to multiply
/// @param r : the ratio to multiply
/// @return the multiplication of the value by the ratio
template <typename T, typename U>
inline constexpr Ratio<T> operator*(const U &value, const Ratio<T> &r) { return r * value;}

//////////////////////////////// ASSIGNMENT OPERATORS

// template <typename T, typename U>
// inline constexpr U operator=(U &value, const Ratio<T> &r) { value = r.convertToNumber(); return value;}

/// @brief add a ratio to the value
/// @tparam T : the type of the ratio
/// @tparam U : the type of the value
/// @param value : the value to add the ratio to
/// @param r : the ratio to add to the value
template <typename T, typename U>
inline constexpr void operator+=(U &value, const Ratio<T> &r) { value = value + r.convertToNumber();}

/// @brief subtract a ratio to the value
/// @tparam T : the type of the ratio
/// @tparam U : the type of the value
/// @param value : the value to subtract the ratio to
/// @param r : the ratio to subtract to the value
template <typename T, typename U>
inline constexpr void operator-=(U &value, const Ratio<T> &r) { value = value - r.convertToNumber();}

/// @brief multiply a ratio to the value
/// @tparam T : the type of the ratio
/// @tparam U : the type of the value
/// @param value : the value to multiply the ratio to
/// @param r : the ratio to multiply to the value
template <typename T, typename U>
inline constexpr void operator*=(U &value, const Ratio<T> &r) { value = value * r.convertToNumber();}

/// @brief divide a ratio to the value
/// @tparam T : the type of the ratio
/// @tparam U : the type of the value
/// @param value : the value to divide the ratio to
/// @param r : the ratio to divide to the value
template <typename T, typename U>
inline constexpr void operator/=(U &value, const Ratio<T> &r) { value = value / r.convertToNumber();}

/// @brief assign the remainder of the value and the ratio to the value
/// @tparam T : the type of the ratio
/// @tparam U : the type of the value
/// @param value : the value to divide the ratio to 
/// @param r : the ratio to divide to the value to get the remainder
template <typename T, typename U>
inline constexpr void operator%=(U &value, const Ratio<T> &r) { value = value % static_cast<T>(r.convertToNumber());}

//////////////////////////////// RELATIONAL OPERATORS

/// @brief comparision of a value and a ratio
/// @tparam T : the type of the ratio
/// @tparam U : the type of the value
/// @param value : the value to compare
/// @param r : the compared ratio
/// @return true if the value and the ratio are equal
template <typename T, typename U>
inline constexpr bool operator==(const U &value, const Ratio<T> &r) { return convertToRatio<U, T>(value, nbIter) == r;}

/// @brief comparision of a value and a ratio
/// @tparam T : the type of the ratio
/// @tparam U : the type of the value
/// @param value : the value to compare
/// @param r : the compared ratio
/// @return true if the value and the ratio are not equal
template <typename T, typename U>
inline constexpr bool operator!=(const U &value, const Ratio<T> &r) { return convertToRatio<U, T>(value, nbIter) != r;}

/// @brief comparision of a value and a ratio
/// @tparam T : the type of the ratio
/// @tparam U : the type of the value
/// @param value : the value to compare
/// @param r : the compared ratio
/// @return true if the value is greater than the ratio
template <typename T, typename U>
inline constexpr bool operator>(const U &value, const Ratio<T> &r) { return convertToRatio<U, T>(value, nbIter) > r;}

/// @brief comparision of a value and a ratio
/// @tparam T : the type of the ratio
/// @tparam U : the type of the value
/// @param value : the value to compare
/// @param r : the compared ratio
/// @return true if the value is less than the ratio
template <typename T, typename U>
inline constexpr bool operator<(const U &value, const Ratio<T> &r) { return convertToRatio<U, T>(value, nbIter) < r;}

/// @brief comparision of a value and a ratio
/// @tparam T : the type of the ratio
/// @tparam U : the type of the value
/// @param value : the value to compare
/// @param r : the compared ratio
/// @return true if the value is greater than or equal to the ratio
template <typename T, typename U>
inline constexpr bool operator>=(const U &value, const Ratio<T> &r) { return convertToRatio<U, T>(value, nbIter) >= r;}

/// @brief comparision of a value and a ratio
/// @tparam T : the type of the ratio
/// @tparam U : the type of the value
/// @param value : the value to compare
/// @param r : the compared ratio
/// @return true if the value is less than or equal to the ratio
template <typename T, typename U>
inline constexpr bool operator<=(const U &value, const Ratio<T> &r) { return convertToRatio<U, T>(value, nbIter) <= r;}

//////////////////////////////// VARIADICS FUNCTIONS

/// @brief stopping condition of variadics function to multiply several ratio
/// @tparam T : the type of the ratio
/// @param first : the first ratio in the list
/// @return the result of the multiplication
template <typename T>
constexpr Ratio<T> product(Ratio<T> first) {
    return first;
}
/// @brief variadics function to multiply several ratio
/// @tparam T : the type of the ratio
/// @tparam ...Args : the other arguments
/// @param ratio : the ratio to multiply to the others
/// @param ...args : the second part of the list
/// @return the result of the multiplication
template <typename T, typename ... Args>
constexpr Ratio<T> product(const Ratio<T> &ratio, const Args ... args) {
    return ratio * product(args...);
}

/// @brief stopping condition of variadics function to add several ratio
/// @tparam T : the type of the ratio
/// @param first : the first ratio in the list
/// @return the result of the addition
template <typename T>
constexpr Ratio<T> addition(Ratio<T> first) {
    return first;
}
/// @brief variadics function to add several ratio
/// @tparam T : the type of the ratio
/// @tparam ...Args : the other arguments
/// @param ratio : the ratio to add to the others
/// @param ...args : the second part of the list
/// @return the result of the addition
template <typename T, typename ... Args>
constexpr Ratio<T> addition(const Ratio<T> &ratio, const Args ... args) {
    return ratio + addition(args...);
}

/// @brief stopping condition of variadics function to subtract several ratio
/// @tparam T : the type of the ratio
/// @param first : the first ratio in the list
/// @return the result of the subtraction
template <typename T>
constexpr Ratio<T> subtraction(Ratio<T> first) {
    return - first;
}
/// @brief variadics function to subtract several ratio
/// @tparam T : the type of the ratio
/// @tparam ...Args : the other arguments
/// @param ratio : the ratio to subtract to the others
/// @param ...args : the second part of the list
/// @return the result of the subtraction
template <typename T, typename ... Args>
constexpr Ratio<T> subtraction(const Ratio<T> &ratio, const Args ... args) {
    return ratio - subtraction(args...);
}

/// @brief stopping condition of variadics function to get the minimum of several ratio
/// @tparam T : the type of the ratio
/// @param first : the first ratio in the list
/// @param last : the second ratio to compare to the first
/// @return the minimum of the ratio
template <typename T>
constexpr Ratio<T> min(Ratio<T> first, Ratio<T> last) {
    if (first < last) {
        return first;
    }
    return last;
}
/// @brief variadics function to get the minimum of several ratio
/// @tparam T : the type of the ratio
/// @tparam ...Args : the other arguments
/// @param ratio : the ratio to compare to the others
/// @param ...args : the second part of the list
/// @return the minimum of the ratio
template <typename T, typename ... Args>
constexpr Ratio<T> min(const Ratio<T> &ratio, const Args ... args) {
    if (ratio < min(args...)) {
        return ratio;
    }
    return min(args...);
}

/// @brief stopping condition of variadics function to get the maximum of several ratio
/// @tparam T : the type of the ratio
/// @param first : the first ratio in the list
/// @param last : the second ratio to compare to the first
/// @return the maximum of the ratio
template <typename T>
constexpr Ratio<T> max(Ratio<T> first, Ratio<T> last) {
    if (first > last) {
        return first;
    }
    return last;
}
/// @brief variadics function to get the maximum of several ratio
/// @tparam T : the type of the ratio
/// @tparam ...Args : the other arguments
/// @param ratio : the ratio to compare to the others
/// @param ...args : the second part of the list
/// @return the maximum of the ratio
template <typename T, typename ... Args>
constexpr Ratio<T> max(const Ratio<T> &ratio, const Args ... args) {
    if (ratio > max(args...)) {
        return ratio;
    }
    return max(args...);
}
