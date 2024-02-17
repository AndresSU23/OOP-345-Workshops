/***********************************************************************
// Workshop 5 Part 2
// Module: SpellChecker
// File: SpellChecker.h
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
#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H

#include <string>

namespace seneca {
	class SpellChecker {
		static const int SIZE = 6;
		std::string m_badWords[6];
		std::string m_goodWords[6];
		int m_replaceCount[SIZE] = { 0 };

		void removeSpaces(std::string& str);

	public:
		SpellChecker(const char* filename);

		void operator()(std::string& text);

		void showStatistics(std::ostream& out) const;
	};
}

#endif // !SENECA_SPELLCHECKER_H

