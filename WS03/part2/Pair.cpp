/***********************************************************************
// Workshop 3 Part 2
// Module: Pair
// File: Pair.cpp
// Version 1.0
// Author
// Description
//	Name      : David Andres Sanchez Umbarila
//	Student ID: 140273228
//	Email     : dasanchez-umbarila@myseneca.ca
//
//	I have done all the coding by myself and only copied the code
//	 that my professor provided to complete my workshops and
//	 assignments.
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
***********************************************************************/

#include "Pair.h"
#include <iomanip>

namespace seneca {

    bool Pair::operator==(const Pair& other) const {
        return m_key == other.m_key;
    }


    std::ostream& operator<<(std::ostream& os, const Pair& pair) {
        os << std::right << std::setw(20) << pair.getKey() << ": " << pair.getValue();
        return os;
    }
}
