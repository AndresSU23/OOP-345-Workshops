/***********************************************************************
// Workshop 3 Part 2
// Module: Collection
// File: Collection.h
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
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <iostream>

#include "Pair.h"

namespace seneca {

	template<typename T, unsigned int CAPACITY>
	class Collection {
		T m_elements[CAPACITY];
		size_t m_size{ 0 };
		static T dummy;

	public:

		Collection() : m_size(0) {};
		virtual ~Collection() {};
		unsigned int size() const {
			return m_size;
		}

		void display(std::ostream& os = std::cout) const { 
			os << "----------------------\n| Collection Content |\n----------------------\n";
			for (size_t i = 0; i < m_size; ++i) {
				os << m_elements[i] << std::endl;
			}
			os << "----------------------\n";
		}

		virtual bool add(const T& item) {
			if (m_size < CAPACITY) {
				m_elements[m_size++] = item;
				return true;
			}
			return false;
		}

		T operator[](unsigned int index) const {
			if (index < m_size)
			{
				return m_elements[index];
			}
			else
			{
				return dummy;
			}

		};
	};
	template<typename T, unsigned int Capacity>
	T Collection<T, Capacity>::dummy{};
	template<>
	Pair Collection<Pair, 100>::dummy = Pair("No Key", "No Value");
}
#endif // !SENECA_COLLECTION_H

