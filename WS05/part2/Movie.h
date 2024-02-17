/***********************************************************************
// Workshop 5 Part 2
// Module: Movie
// File: Movie.h
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
		void fixSpelling(T& spellChecker) { 
			spellChecker(m_description); 
			spellChecker(m_title);
		}

		friend std::ostream& operator <<(std::ostream& os, const Movie& movie);
	};

}

#endif // !SENECA_MOVIE_H

