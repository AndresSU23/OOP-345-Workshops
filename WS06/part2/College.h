/***********************************************************************
// Workshop 6 Part 2
// Module: College
// File: College.h
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
#ifndef SENECA_COLLEGE_H
#define SENECA_COLLEGE_H

#include "Employee.h"
#include <iostream>
#include <vector>
#include <list>

namespace seneca {

    class College {
    private:
        std::vector<Person*> m_persons;

    public:
        College() = default;
        College(const College&) = delete; // Disable copy constructor
        College& operator=(const College&) = delete; // Disable assignment operator
        ~College();

        College& operator+=(Person* thePerson);
        void display(std::ostream& out) const;

        template<typename T>
        void select(const T& test, std::list<const Person*>& persons) {
            for (const auto& person : m_persons) {
                if (test(person)) {
                    persons.push_back(person);
                }
            }
        }
    };
}

#endif // SENECA_COLLEGE_H
