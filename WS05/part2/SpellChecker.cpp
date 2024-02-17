/***********************************************************************
// Workshop 5 Part 2
// Module: SpellChecker
// File: SpellChecker.cpp
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
#include "SpellChecker.h"

#include <fstream>
#include <iostream>
#include <iomanip>

namespace seneca {
    void SpellChecker::removeSpaces(std::string& str) {
        while (!str.empty() && std::isspace(str.front())) {
            str.erase(str.begin());
        }

        while (!str.empty() && std::isspace(str.back())) {
            str.pop_back();
        }
    }

	SpellChecker::SpellChecker(const char* filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::invalid_argument("Bad file name!");
        }
        for (int i = 0; i < SIZE; ++i) {
            std::string line;
            if (!std::getline(file, line)) {
                throw "Error reading file!";
            }
            size_t pos = line.find(" ");
            if (pos == std::string::npos) {
                throw "Invalid format!";
            }
            std::string badWord = line.substr(0, pos);
            std::string goodWord = line.substr(pos + 1);

            removeSpaces(badWord);
            removeSpaces(goodWord);

            m_badWords[i] = badWord;
            m_goodWords[i] = goodWord;
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
        out << "Spellchecker Statistics\n";
        for (int i = 0; i < SIZE; ++i) {
            out << std::setw(15) << std::right << m_badWords[i] << ": " << m_replaceCount[i] << " replacements" << std::endl;
        }
    }
}
 