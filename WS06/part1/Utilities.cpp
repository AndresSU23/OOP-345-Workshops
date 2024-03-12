#include "utilities.h"
#include <sstream>

namespace seneca {

    Person* buildInstance(std::istream& in) {
        char tag;
        in >> tag;
        if (tag == 'e' || tag == 'E') {
            in >> tag;
            return new Employee(in);
        }
        std::string line;
        std::getline(in, line);
        return nullptr;
    }
}
