#include "college.h"
#include <iomanip>

namespace seneca {

    College& College::operator+=(Person* thePerson) {
        m_persons.push_back(thePerson);
        return *this;
    }

    void College::display(std::ostream& out) const {
        static int testNum = 1;
        
        out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
        out << "|                                        Test #" << testNum++ << " Persons in the college!                                               |" << std::endl;
        out << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
        for (const auto& person : m_persons) {
            if (!person->id().empty()){
                person->display(out);
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
