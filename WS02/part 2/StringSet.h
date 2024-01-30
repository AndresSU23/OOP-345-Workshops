/***********************************************************************
// Workshop 2 Part 2
// Module: StringSet
// File: StringSet.h
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
#ifndef SENECA_STRINGSET_H
#define SENECA_STRINGSET_H

namespace seneca {
	class StringSet {
		std::string* m_arr{};
		size_t m_size{ 0 };

	public:
		StringSet() = default;
		StringSet(const char* str);
		StringSet(const StringSet& other);
		StringSet(StringSet&& other) noexcept;
		~StringSet();
		size_t size() const;
		std::string operator[](size_t i) const;
		StringSet& operator=(const StringSet& other);
		StringSet& operator=(StringSet&& other) noexcept;
	};
}

#endif // !SENECA_STRINGSET_H

