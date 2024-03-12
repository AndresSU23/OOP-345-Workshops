/***********************************************************************
// Workshop 6 Part 2
// Module: Utilities
// File: Utilities.cpp
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


#include "Utilities.h"
#include "Student.h"
#include "Professor.h"
#include <sstream>

namespace seneca {

    Person* buildInstance(std::istream& in) {
        char tag, garbage;
        in >> tag;
        in >> garbage;
        if (tag == 's' || tag == 'S') {
            return new Student(in);
        }
        else if (tag == 'p' || tag == 'P') {
            return new Professor(in);
        }
        else if (tag == 'e' || tag == 'E') {
            return new Employee(in);
        }

        return nullptr;
    }
}
