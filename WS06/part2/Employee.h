/***********************************************************************
// Workshop 6 Part 2
// Module: Employee
// File: Employee.h
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
#ifndef SENECA_EMPLOYEE_H
#define SENECA_EMPLOYEE_H

#include <iostream>
#include <string>
#include "Person.h"

namespace seneca {
    class Employee : public Person {
    private:
        std::string m_name;
        std::string m_age;
        std::string m_id;

    public:
        Employee(std::istream& in);
        virtual ~Employee() {};
        std::string status() const;
        std::string name() const;
        std::string id() const;
        std::string age() const;
        void display(std::ostream& out) const;
        
    };
    std::string trim(const std::string& str);
    bool isNumber(const std::string& str);
}

#endif // SENECA_EMPLOYEE_H
