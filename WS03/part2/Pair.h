/***********************************************************************
// Workshop 3 Part 2
// Module: Pair
// File: Pair.h
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
#ifndef SENECA_PAIR_H
#define SENECA_PAIR_H

#include <string>

namespace seneca {
	class Pair
	{
		std::string m_key{};
		std::string m_value{};
	public:
		Pair() : m_key(""), m_value("") {};
		const std::string& getKey() const { return m_key; }
		const std::string& getValue() const { return m_value; }
		Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value } {};

		bool operator==(const Pair& other) const;
	

	};
	std::ostream& operator<<(std::ostream& os, const Pair& pair);
}

#endif // !SENECA_PAIR_H
