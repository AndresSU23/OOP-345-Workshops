/***********************************************************************
// Workshop 4 Part 2
// Module: ConfirmOrder
// File: ConfirmOrder.h
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
#ifndef SENECA_CONFIRMORDER_H
#define SENECA_CONFIRMORDER_H

#include "Toy.h"

namespace seneca {
	class ConfirmOrder {
		const Toy** m_toys{ nullptr };
		size_t m_size{ 0 };
		void resize(size_t newSize);

	public:
		ConfirmOrder() = default;
		ConfirmOrder(const ConfirmOrder& other);
		ConfirmOrder(ConfirmOrder&& other) noexcept;
		~ConfirmOrder();
		ConfirmOrder& operator=(const ConfirmOrder& other);
		ConfirmOrder& operator=(ConfirmOrder&& other) noexcept;
		ConfirmOrder& operator+=(const Toy& toy);
		ConfirmOrder& operator-=(const Toy& toy);

		friend std::ostream& operator<<(std::ostream& os, const ConfirmOrder& order);
	};
}

#endif // !SENECA_CONFIRMORDER_H

