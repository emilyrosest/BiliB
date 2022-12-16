#include "Ratio.hpp"
#include <iostream>
#include <numeric>

Ratio::Ratio() : m_n((int)0), m_d((unsigned int)1) {
}

Ratio::Ratio(const int &n, const unsigned int &d) {
    m_n = n;
    m_d = d;
    reduce();
}

Ratio::Ratio(const Ratio &ratio) : m_n(ratio.m_n), m_d(ratio.m_d) {
}


Ratio::Ratio(const double &x) : m_n(convertFloatToRatio(x, nb_iter).m_n), m_d(convertFloatToRatio(x, nb_iter).m_d) {
}




Ratio Ratio::convertFloatToRatio(const double &x, unsigned int nb_iter) {
    if (x < 0) {
        return -convertFloatToRatio(-x, nb_iter);
    }

    if (x == 0) {
        return Ratio();
    }

    if (nb_iter == 0) {
        return Ratio();
    }

    if (x < 1) {
        return Ratio(1, 1)/convertFloatToRatio(1/x, nb_iter);
    }

    if (x > 1) {
        int q = (int)x; //peut etre pas une bonne chose d'apres matteo
        return Ratio(q, 1) + convertFloatToRatio(x - q, nb_iter - 1);
    }
}

float Ratio::convertRatioToFloat() {
    return float(m_n) / float(m_d);
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


Ratio Ratio::operator-(const Ratio &r) const {
    Ratio result;
    result.m_n = this->m_n * r.m_d - this->m_d * r.m_n;
    result.m_d = this->m_d * r.m_d;
    result.reduce();

    return result;
}

Ratio Ratio::operator-() const {
    Ratio result;
    result.m_n = -(this->m_n);
    result.m_d = this->m_d;

    return result;
}

Ratio Ratio::operator/(const Ratio &r) const {
    Ratio result;
    result.m_n = this->m_n * r.m_d;
    result.m_d = this->m_d * r.m_n;
    result.reduce();

    return result;
}

Ratio Ratio::operator*(const Ratio &r) const {
    Ratio result;
    result.m_n = this->m_n * r.m_n;
    result.m_d = this->m_d * r.m_d;
    result.reduce();

    return result;
}

Ratio Ratio::operator*(const double &value) const {
    Ratio result;
    result.m_n = this->m_n * value;
    result.m_d = this->m_d;
    result.reduce();

    return result;
}

// Ratio Ratio::operator*(const double &value, const Ratio &ratio) const {

// }