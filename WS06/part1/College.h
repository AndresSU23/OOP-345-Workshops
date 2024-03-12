#pragma once
#ifndef COLLEGE_H
#define COLLEGE_H

#include <iostream>
#include <vector>
#include "employee.h"

namespace seneca {

    class College {
    private:
        std::vector<Person*> m_persons;

    public:
        College() = default;
        College(const College&) = delete; // Disable copy constructor
        College& operator=(const College&) = delete; // Disable assignment operator

        College& operator+=(Person* thePerson);
        void display(std::ostream& out) const;
    };
}

#endif // COLLEGE_H
