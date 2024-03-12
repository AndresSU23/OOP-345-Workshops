/***********************************************************************
// Workshop 6 Part 2
// Module: Professor
// File: Professor.cpp
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


#include "Professor.h"

namespace seneca {

    Professor::Professor(std::istream& in) : Employee(in) {
        std::getline(in >> std::ws, m_department, '\n');
        m_department = trim(m_department);
    }

    void Professor::display(std::ostream& out) const {
        Employee::display(out);
        out << m_department << "| " << status();
    }

    std::string Professor::status() const {
        return "Professor";
    }

    std::string Professor::department() const {
        return m_department;
    }
}
