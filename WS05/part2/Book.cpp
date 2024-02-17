#include "Book.h"

#include <iomanip>

namespace seneca {
	Book::Book(const std::string& strBook) {
        size_t pos1 = 0;
        size_t pos2 = strBook.find(',');
        size_t lastPos = 0;
        size_t commaCount = 0;

        while (pos2 != std::string::npos) {
            std::string token = strBook.substr(pos1, pos2 - pos1);

            size_t start = token.find_first_not_of(" ");
            size_t end = token.find_last_not_of(" ");
            token = token.substr(start, end - start + 1);

            if (commaCount == 0) m_author = token; 
            else if (commaCount == 1) m_title = token; 
            else if (commaCount == 2) m_country = token; 
            else if (commaCount == 3) m_price = std::stod(token); 
            else if (commaCount == 4) m_pubYear = std::stoi(token); 

            lastPos = pos2; 
            pos1 = lastPos + 1; 
            pos2 = strBook.find(',', pos1); 
            commaCount++; 
        }

        std::string lastToken = strBook.substr(lastPos + 1);
        size_t start = lastToken.find_first_not_of(" ");
        size_t end = lastToken.find_last_not_of(" ");
        m_description = lastToken.substr(start, end - start + 1);
	}

    const std::string& Book::title() const { return m_title; }

    const std::string& Book::country() const { return m_country; }

    const size_t& Book::year() const { return m_pubYear; }

    double& Book::price() { return m_price; }

    std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << std::left << std::setw(20) << book.m_author << " | "
            << std::setw(22) << book.m_title << " | "
            << std::setw(5) << book.m_country << " | "
            << std::setw(4) << book.m_pubYear << " | "
            << std::fixed << std::setprecision(2) << std::setw(6) << book.m_price << " | "
            << book.m_description;
        return os;
    }

}
