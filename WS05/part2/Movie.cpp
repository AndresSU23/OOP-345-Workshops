/***********************************************************************
// Workshop 5 Part 2
// Module: Movie
// File: Movie.cpp
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
#include <iomanip>

#include "Movie.h"

namespace seneca {
	Movie::Movie(const std::string& strMovie) {
        size_t pos = 0;
        size_t nextPos = strMovie.find(',');

        m_title = strMovie.substr(pos, nextPos - pos);
        m_title.erase(0, m_title.find_first_not_of(' ')); 
        m_title.erase(m_title.find_last_not_of(' ') + 1); 

        pos = nextPos + 1;
        nextPos = strMovie.find(',', pos);
        m_releaseYear = std::stoi(strMovie.substr(pos, nextPos - pos));

        pos = nextPos + 1;
        m_description = strMovie.substr(pos);
        m_description.erase(0, m_description.find_first_not_of(' '));
        m_description.erase(m_description.find_last_not_of(' ') + 1);
	}

    const std::string& Movie::title() const { return m_title; }

    std::ostream& operator<<(std::ostream& os, const Movie& movie) {
        os << std::right << std::setw(40) << movie.m_title << " | "
            << std::setw(4) << movie.m_releaseYear << " | "
            << movie.m_description << '\n';
        return os;
    }

}

