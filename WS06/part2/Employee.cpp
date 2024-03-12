/***********************************************************************
// Workshop 6 Part 2
// Module: Employee
// File: Employee.cpp
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

#include "Employee.h"
#include <sstream>
#include <stdexcept>
#include <iomanip>
#include <iostream>

namespace seneca {

    Employee::Employee(std::istream& in) {
        try{
            std::string name, age, id;
            std::getline(in >> std::ws, name, ',');
            std::getline(in >> std::ws, age, ',');
            if (!isNumber(age)) {
                std::string flush;
                std::getline(in, flush);
                throw std::invalid_argument(name + "++Invalid record!\n");
            }

            char ch;
            while (in.get(ch)) {
                if (ch == '\n' || ch == ',') {
                    break;  
                }
                id += ch;
            }


            id = trim(id);
            name = trim(name);
            age = trim(age);

            if (id.empty() || id[0] != 'E' ) {
                throw std::invalid_argument(name + "++Invalid record!\n");
            }
            m_name = name;
            m_age = age;
            m_id = id;
        }
        catch (const std::invalid_argument& er) {
            
            std::cout << er.what();
        }

    }

    std::string Employee::status() const {
        return "Employee";
    }

    std::string Employee::name() const {
        return m_name;
    }

    std::string Employee::id() const {
        return m_id;
    }

    std::string Employee::age() const {
        return m_age;
    }

    void Employee::display(std::ostream& out) const {
        out << "| " << std::left << std::setw(9) << "Employee" << " | "
            << std::setw(9) << id() << " | "
            << std::setw(20) << name() << " | "
            << std::setw(3) << age() << " |";
    }
    std::string trim(const std::string& str) {
        size_t start = str.find_first_not_of(" \t\n\r");
        size_t end = str.find_last_not_of(" \t\n\r");
        if (start == std::string::npos) 
            return "";
        return str.substr(start, end - start + 1);
    }
    bool isNumber(const std::string& str) {
        try {
            int test = std::stoi(str);
            return true || test;
        }
        catch (const std::invalid_argument&) {
            return false;
        }
        catch (const std::out_of_range&) {
            return false;
        }
    }
}
