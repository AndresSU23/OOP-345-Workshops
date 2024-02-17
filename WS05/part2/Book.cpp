/***********************************************************************
// Workshop 5 Part 2
// Module: Book
// File: Book.cpp
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
#include "Book.h"

#include <iomanip>

namespace seneca {
	Book::Book(const std::string& strBook) {
        size_t pos = 0;
        size_t nextPos = strBook.find(',');

        m_author = strBook.substr(pos, nextPos - pos);
        m_author.erase(0, m_author.find_first_not_of(' ')); 
        m_author.erase(m_author.find_last_not_of(' ') + 1); 

        pos = nextPos + 1;
        nextPos = strBook.find(',', pos);
        m_title = strBook.substr(pos, nextPos - pos);
        m_title.erase(0, m_title.find_first_not_of(' '));
        m_title.erase(m_title.find_last_not_of(' ') + 1);

        pos = nextPos + 1;
        nextPos = strBook.find(',', pos);
        m_country = strBook.substr(pos, nextPos - pos);
        m_country.erase(0, m_country.find_first_not_of(' '));
        m_country.erase(m_country.find_last_not_of(' ') + 1);

        pos = nextPos + 1;
        nextPos = strBook.find(',', pos);
        m_price = std::stod(strBook.substr(pos, nextPos - pos));

        pos = nextPos + 1;
        nextPos = strBook.find(',', pos);
        m_pubYear = std::stoi(strBook.substr(pos, nextPos - pos));

        pos = nextPos + 1;
        m_description = strBook.substr(pos);
        m_description.erase(0, m_description.find_first_not_of(' '));
        m_description.erase(m_description.find_last_not_of(' ') + 1);
	}

    const std::string& Book::title() const { return m_title; }

    const std::string& Book::country() const { return m_country; }

    const size_t& Book::year() const { return m_pubYear; }

    double& Book::price() { return m_price; }

    std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << std::right << std::setw(20) << book.m_author << " | "
            << std::setw(22) << book.m_title << " | "
            << std::setw(5) << book.m_country << " | "
            << std::setw(4) << book.m_pubYear << " | " 
            << std::fixed << std::setprecision(2) << std::setw(6) << book.m_price << " | "
            << book.m_description << '\n';
        return os;
    }

}
