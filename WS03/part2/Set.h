/***********************************************************************
// Workshop 3 Part 2
// Module: Set
// File: Set.h
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
#ifndef SENECA_SET_H
#define SENECA_SET_H

#include "Collection.h"

namespace seneca {

	template<typename T>
	class Set : public Collection<T, 100> {
	public:
		Set() = default;

		bool add(const T& item) override {
			for (size_t i = 0; i < this->size(); ++i) {
				if (areEqual(item, this->operator[](i))) {
					return false;  // Item already exists in the set
				}
			}

			return Collection<T, 100>::add(item);
		}

	private:
		// Helper function to check equality considering specialization for double
		bool areEqual(const T& a, const T& b) const {
			if constexpr (std::is_same_v<T, double>) {
				return customAbs(a - b) <= 0.01;
			}
			else {
				return a == b;
			}
		}

		// Custom absolute value function for double (replace with your own implementation if needed)
		double customAbs(double x) const {
			return (x < 0) ? -x : x;
		}
	};

}  // namespace seneca

#endif // SENECA_SET_H
