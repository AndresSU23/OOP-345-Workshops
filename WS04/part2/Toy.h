/***********************************************************************
// Workshop 4 Part 2
// Module: Toy
// File: Toy.h
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
#ifndef SENECA_TOY_H
#define SENECA_TOY_H

#include <string>
#include <iostream>

namespace seneca {
	const double TAX = 0.13;

	class Toy {
		unsigned int m_orderId;
		std::string m_name;
		unsigned int m_noItems;
		double m_price;
		double m_salesTax;

		std::string trim(const std::string& str) const;
	public:
		Toy() = default;
		Toy(const std::string& toy);
		Toy(const Toy& toy);
		virtual ~Toy();
		void update(int numItems);

		friend std::ostream& operator<<(std::ostream& os, const Toy& toy);
	};
	
}

#endif // !SENECA_TOY_H

