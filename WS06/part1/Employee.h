#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

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
        std::string status() const;
        std::string name() const override;
        std::string id() const override;
        std::string age() const override;
        void display(std::ostream& out) const override;
        std::string trim(const std::string& str);
    };
}

#endif // EMPLOYEE_H
