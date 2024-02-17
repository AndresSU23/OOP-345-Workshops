#pragma once
#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H

#include <iostream>
#include <string>

namespace seneca {
	class Movie {
		std::string m_title;
		size_t m_releaseYear {};
		std::string m_description;

	public:
		Movie() = default;
		Movie(const std::string& strMovie);
		virtual ~Movie() {};
		const std::string& title() const;

		template<typename T>
		void fixSpelling(T& spellChecker) { spellChecker(m_description); }

		friend std::ostream& operator <<(std::ostream& os, const Movie& movie);
	};

}

#endif // !SENECA_MOVIE_H

