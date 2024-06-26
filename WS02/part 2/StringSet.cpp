/***********************************************************************
// Workshop 2 Part 2
// Module: StringSet
// File: StringSet.cpp
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
#include <iostream>
#include <fstream>
#include "StringSet.h"

namespace seneca {
	seneca::StringSet::StringSet(const char* file) {
		std::ifstream fileStream(file);
		if (!fileStream.is_open()) {
			
			std::cerr << "Error opening file: " << file << std::endl;
		}
		else {
		
			char ch;

			while (fileStream.get(ch)) { if (ch == ' ') { m_size++; } }

			fileStream.clear();
			fileStream.seekg(0, std::ios::beg);

			m_arr = new std::string[++m_size];
			size_t i = 0;
			while (fileStream.get(ch)) {
				if (ch == ' ') {
					i++;
				}
				else {
					if (i < m_size) {m_arr[i] += ch;}
				}
			}
		}

	}
	StringSet::StringSet(const StringSet& other) : m_size(other.m_size) {
		m_arr = new std::string[m_size];
		for (size_t i = 0; i < m_size; ++i) {
			m_arr[i] = other.m_arr[i];
		}
	}
	StringSet::StringSet(StringSet&& other) noexcept {
		m_size = other.m_size;
		m_arr = other.m_arr;  
		other.m_size = 0;
		other.m_arr = nullptr;
	}
	StringSet::~StringSet() {
		delete[] m_arr;
	}
	size_t StringSet::size() const { return m_size; }
	std::string StringSet::operator[](size_t i) const
	{
		std::string emptyString;
		return (i >= m_size) ? emptyString : m_arr[i];
	}
	StringSet& StringSet::operator=(const StringSet& other) {
		if (this != &other) { 
			delete[] m_arr;

			m_size = other.m_size;
			m_arr = new std::string[m_size];
			for (size_t i = 0; i < m_size; ++i) {
				m_arr[i] = other.m_arr[i];
			}
		}
		return *this;
	}
	StringSet& StringSet::operator=(StringSet&& other) noexcept {
		if (this != &other) {
			delete[] m_arr;

			m_size = other.m_size;
			m_arr = other.m_arr;  
			other.m_size = 0;
			other.m_arr = nullptr;
		}
		return *this;
	}
}
