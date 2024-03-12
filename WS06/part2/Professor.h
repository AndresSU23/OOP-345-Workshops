/***********************************************************************
// Workshop 6 Part 2
// Module: Professor
// File: Professor.h
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


#pragma once
#ifndef SENECA_PROFESSOR_H
#define SENECA_PROFESSOR_H

#include "employee.h"
#include <string>

namespace seneca {

    class Professor : public Employee {
    private:
        std::string m_department;

    public:
        Professor(std::istream& in);
        void display(std::ostream& out) const;
        std::string status() const;
        std::string department() const;
    };
}

#endif // SENECA_PROFESSOR_H
