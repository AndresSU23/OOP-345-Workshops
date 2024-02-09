/***********************************************************************
// Workshop 4 Part 2
// Module: Child
// File: Child.cpp
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

#include "Child.h"

namespace seneca {
	void Child::copyToys(const Toy* source[], size_t count) {
		m_toys = new const Toy * [count];
		for (size_t i = 0; i < count; ++i) {
			m_toys[i] = new Toy(*source[i]); 
		}
		m_noToys = count;
	}

	Child::Child(std::string name, int age, const Toy* toys[], size_t count) : m_name(name), m_age(age), m_noToys(count) {
		copyToys(toys, count);
	}

	Child::Child(const Child& child) : m_name(std::move(child.m_name)), m_age(child.m_age), m_toys(nullptr), m_noToys(0) {
		copyToys(child.m_toys, child.m_noToys);
	}

	Child::Child(Child&& child) noexcept : m_name(std::move(child.m_name)), m_age(child.m_age), m_toys(child.m_toys), m_noToys(child.m_noToys) {
		child.m_toys = nullptr;
		child.m_noToys = 0;
		child.m_age = 0;
	}

	Child::~Child() {
		for (size_t i = 0; i < m_noToys; ++i) {
			delete m_toys[i];
		}
		delete[] m_toys;
	}

	size_t Child::size() const {
		return m_noToys;
	}

	Child& Child::operator=(const Child& child) {
		if (this != &child) {
			for (size_t i = 0; i < m_noToys; ++i) {
				delete m_toys[i];
			}
			delete[] m_toys;

			m_name = child.m_name;
			m_age = child.m_age;
			copyToys(child.m_toys, child.m_noToys);
		}
		return *this;
	}

	Child& Child::operator=(Child&& child) noexcept {
		if (this != &child) {
			for (size_t i = 0; i < m_noToys; ++i) {
				delete m_toys[i];
			}
			delete[] m_toys;

			m_name = std::move(child.m_name);
			m_age = child.m_age;
			m_toys = child.m_toys;
			m_noToys = child.m_noToys;

			child.m_toys = nullptr;
			child.m_noToys = 0;
			child.m_age = 0;
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Child& child)
	{
		static int count = 0; 
		count++; 

		os << "--------------------------\n"
			<< "Child " << count << ": " << child.m_name << " " << child.m_age << " years old:\n"
			<< "--------------------------\n";

		if (child.m_noToys == 0) {
			os << "This child has no toys!\n";
		}
		else {
			for (size_t i = 0; i < child.m_noToys; ++i) {
				os << *child.m_toys[i];
			}
		}

		os << "--------------------------\n";
		return os;
	}
}

