#include "Ratio.hpp"
#include <iostream>

Ratio::Ratio() : m_n(0), m_d(1) {
}


double Ratio::getNum() {
    return m_n;
}