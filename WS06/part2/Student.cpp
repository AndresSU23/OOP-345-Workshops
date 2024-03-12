/***********************************************************************
// Workshop 6 Part 2
// Module: Student
// File: Student.cpp
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

#include "Student.h"
#include "Employee.h"
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <iomanip>



namespace seneca {

    Student::Student(std::istream& in) : m_count(0), m_courses(nullptr) {
        try {
            std::string name, age, id, noCourses;
            std::getline(in >> std::ws, name, ',');
            std::getline(in >> std::ws, age, ',');
            if (!isNumber(age)) {
                throw std::invalid_argument(name + "++Invalid record!\n");
            }

            std::getline(in >> std::ws, id, ',');

            if (id.empty() || id[0] != 'S') {
                throw std::invalid_argument(name + "++Invalid record!\n");
            }

            std::getline(in >> std::ws, noCourses, ',');
            if (!isNumber(noCourses)) {
                throw std::invalid_argument(name + "++Invalid record!\n");
            }

            m_count = std::stoi(noCourses);
            m_courses = new std::string[m_count];
            std::string test;
            for (size_t i = 0; i < m_count; ++i) {
                char ch;
                while (in.get(ch)) {
                    if (ch == '\n' || ch == ',') {
                        break;
                    }
                    m_courses[i] += ch;
                }
                m_courses[i] = trim(m_courses[i]);
            }

            id = trim(id);
            name = trim(name);
            age = trim(age);
            
            m_name = name;
            m_age = age;
            m_id = id;
        }
        catch (const std::invalid_argument& er) {
            std::string flush;
            std::getline(in, flush);
            std::cout << er.what();
        }
    }

    Student::~Student() {
        delete[] m_courses;
    }

    std::string Student::status() const {
        return "Student";
    }

    std::string Student::name() const {
        return m_name;
    }

    std::string Student::id() const {
        return m_id;
    }

    std::string Student::age() const {
        return m_age;
    }

    void Student::display(std::ostream& out) const {
        out << "| " << std::left << std::setw(9) << status() << " | "
            << std::setw(9) << m_id << " | "
            << std::setw(20) << m_name << " | "
            << std::setw(3) << m_age << " |";
        for (size_t i = 0; i < m_count; ++i) {
            out << m_courses[i];
            if (i < m_count - 1)
                out << ", ";
        }
    }
}
