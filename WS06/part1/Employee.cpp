#include "employee.h"
#include <sstream>
#include <stdexcept>
#include <iomanip>

namespace seneca {

    Employee::Employee(std::istream& in) {
        try{
            std::string name, age, id;
            std::getline(in >> std::ws, name, ',');
            std::getline(in >> std::ws, age, ',');
            std::getline(in >> std::ws, id);


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
        out << "| " << std::left << std::setw(10) << status() << " | "
            << std::setw(10) << id() << " | "
            << std::setw(20) << name() << " | "
            << std::setw(3) << age() << " |" << std::endl;
    }
    std::string Employee::trim(const std::string& str) {
        size_t start = str.find_first_not_of(" \t\n\r");
        size_t end = str.find_last_not_of(" \t\n\r");
        if (start == std::string::npos) 
            return "";
        return str.substr(start, end - start + 1);
    }
}
