/***********************************************************************
// Workshop 6 Part 2
// Module: Student
// File: Student.h
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
#ifndef SENECA_STUDENT_H
#define SENECA_STUDENT_H

#include "person.h"
#include <string>

namespace seneca {

    class Student : public Person {
    private:
        std::string m_id;
        std::string m_name;
        std::string m_age;
        std::string* m_courses;
        size_t m_count;

    public:
        Student(std::istream& in);
        virtual ~Student();
        std::string status() const;
        std::string name() const;
        std::string id() const;
        std::string age() const;
        void display(std::ostream& out) const;
    };
}

#endif // SENECA_STUDENT_H
