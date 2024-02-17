#include <iomanip>

#include "Movie.h"

namespace seneca {
	Movie::Movie(const std::string& strMovie) {
        size_t pos1 = 0;
        size_t pos2 = strMovie.find(',');
        size_t lastPos = 0;
        size_t commaCount = 0;

        while (pos2 != std::string::npos) {
            std::string token = strMovie.substr(pos1, pos2 - pos1);
            size_t start = token.find_first_not_of(" ");
            size_t end = token.find_last_not_of(" ");
            token = token.substr(start, end - start + 1);

            if (commaCount == 0) m_title = token;
            else if (commaCount == 1) m_releaseYear = std::stoi(token);

            lastPos = pos2;
            pos1 = lastPos + 1;
            pos2 = strMovie.find(',', pos1);
            commaCount++;
        }

        std::string lastToken = strMovie.substr(lastPos + 1);
        size_t start = lastToken.find_first_not_of(" ");
        size_t end = lastToken.find_last_not_of(" ");
        m_description = lastToken.substr(start, end - start + 1);
	}

    const std::string& Movie::title() const { return m_title; }

    std::ostream& operator<<(std::ostream& os, const Movie& movie) {
        os << std::left << std::setw(40) << movie.m_title << " | "
            << std::setw(4) << movie.m_releaseYear << " | "
            << movie.m_description;
        return os;
    }

}

