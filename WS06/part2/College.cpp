/***********************************************************************
// Workshop 6 Part 2
// Module: College
// File: College.cpp
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
#include "College.h"
#include <iomanip>
#include <iostream>

namespace seneca {

    College& College::operator+=(Person* thePerson) {
        m_persons.push_back(thePerson);
        return *this;
    }

    College::~College() {
        for (auto& person : m_persons) {
            delete person;
        }
    }

    void College::display(std::ostream& out) const {
        static int testNum = 1;
        
        out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
        out << "|                                        Test #" << testNum++ << " Persons in the college!                                               |" << std::endl;
        out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
        for (auto person = m_persons.begin(); person != m_persons.end(); person++)
        {
            if (!(*person)->id().empty()) {
                (*person)->display(out);
                out << std::endl;
            }
        }
        out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
        out << "|                                        Test #" << testNum++ << " Persons in the college!                                               |" << std::endl;
        out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
        for (const auto& person : m_persons) {
            if (!person->id().empty()) {
                out << "| " << std::left << std::setw(10) << person->status() << " | "
                    << std::setw(10) << person->id() << " | "
                    << std::setw(20) << person->name() << " | "
                    << std::setw(3) << person->age() << " |" << std::endl;
            }
        }
        out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
    }
}