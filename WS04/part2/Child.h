/***********************************************************************
// Workshop 4 Part 2
// Module: Child
// File: Child.h
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
#ifndef SENECA_CHILD_H
#define SENECA_CHILD_H

#include <string>
#include <iostream>
#include "Toy.h"

namespace seneca {
	class Child {
		std::string m_name;
		unsigned int m_age;
		const Toy** m_toys {nullptr};
		size_t m_noToys;

		void copyToys(const Toy* source[], size_t count);

	public:
		Child(std::string name, int age, const Toy* toys[], size_t count);
		Child(const Child& child);
		Child(Child&& child) noexcept;
		virtual ~Child();
		size_t size() const;
		Child& operator=(const Child& child);
		Child& operator=(Child&& child) noexcept;
		friend std::ostream& operator<<(std::ostream& os, const Child& child);
	};
	
}

#endif // !SENECA_CHILD_H

