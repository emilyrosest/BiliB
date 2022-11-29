#include "Ratio.hpp"
#include <iostream>
#include <numeric>

Ratio::Ratio() : m_n((int)0), m_d((unsigned int)1) {
}

Ratio::Ratio(const int &n, const unsigned int &d) : m_n(n), m_d(d) {
}

Ratio::Ratio(const Ratio &ratio) : m_n(ratio.m_n), m_d(ratio.m_d) {
}


Ratio::Ratio(const double &x) {

}




int Ratio::getNumerator() const {
    return m_n;
}

int Ratio::getDenominator() const {
    return m_d;
}

void Ratio::setNumerator(const int &n) {
    m_n = n;
}

void Ratio::setDenominator(const unsigned int &d) {
    m_d = d;
}


void Ratio::reduce() {
    int pgcd = std::gcd(m_n, m_d); 

    m_n /= pgcd;
    m_d /= pgcd;
}


Ratio Ratio::operator+(const Ratio &r) const {
    Ratio result;
    result.m_n = this->m_n * r.m_d + this->m_d * r.m_n;
    result.m_d = this->m_d * r.m_d;
    result.reduce();

    return result;
}

Ratio Ratio::operator/(const Ratio &r) const {
    Ratio result;
    result.m_n = this->m_n * r.m_d;
    result.m_d = this->m_d * r.m_n;
    result.reduce();

    return result;
}


Ratio Ratio::convertToRatio(const double &x, unsigned int nb_iter) {
    Ratio result;

    if (x == 0) {
        result.m_n = 0;
        result.m_d = 1;
        return result;
    }

    if (nb_iter == 0) {
        result.m_n = 0;
        result.m_d = 1;
        return result;
    }

    if (x < 1) {
        return Ratio(1, 1)/convertToRatio(1/x, nb_iter);
    }

    if (x > 1) {
        //return Ratio(1, 1)/convertToRatio(1/x, nb_iter);
    }
}