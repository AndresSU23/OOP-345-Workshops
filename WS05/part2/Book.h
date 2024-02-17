/***********************************************************************
// Workshop 5 Part 2
// Module: Book
// File: Book.h
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
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include <iostream>
#include <string>

namespace seneca {
	class Book {
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_pubYear{};
		double m_price{};
		std::string m_description;

	public:
		Book() = default;
		Book(const std::string& strBook);
		virtual ~Book() {};
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();

		template<typename T>
		void fixSpelling(T& spellChecker) { 
			spellChecker(m_description);
		}

		friend std::ostream& operator <<(std::ostream& os, const Book& book);
	};
}

#endif // !SENECA_BOOK_H

