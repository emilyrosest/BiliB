#include "Ratio.hpp"
#include <iostream>

Ratio::Ratio() : m_n((int)0), m_d((unsigned int)1) {
}

Ratio::Ratio(const int &n, const unsigned int &d) : m_n(n), m_d(d) {
}

Ratio::Ratio(const Ratio &ratio) : m_n(ratio.m_n), m_d(ratio.m_d) {
}


int Ratio::getNum() const {
    return m_n;
}

