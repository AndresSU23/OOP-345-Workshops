#include "SpellChecker.h"

#include <fstream>
#include <iostream>
#include <iomanip>

namespace seneca {
	SpellChecker::SpellChecker(const char* filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw "Bad file name!";
        }

        std::string line;
        for (int i = 0; i < SIZE; ++i) {
            if (!std::getline(file, line)) {
                throw "Invalid file format!";
            }

            size_t pos = line.find(' ');
            if (pos == std::string::npos) {
                throw "Invalid file format!";
            }

            m_badWords[i] = line.substr(0, pos);
            m_goodWords[i] = line.substr(pos + 1);
        }

        file.close();
	}
    void SpellChecker::operator()(std::string& text) {
        for (int i = 0; i < SIZE; ++i) {
            std::string::size_type pos = 0;
            while ((pos = text.find(m_badWords[i], pos)) != std::string::npos) {
                text.replace(pos, m_badWords[i].length(), m_goodWords[i]);
                m_replaceCount[i]++;
                pos += m_goodWords[i].length();
            }
        }
    }

    void SpellChecker::showStatistics(std::ostream& out) const {
        for (int i = 0; i < SIZE; ++i) {
            out << std::setw(15) << std::right << m_badWords[i] << ": " << m_replaceCount[i] << " replacements" << std::endl;
        }
    }
}
 