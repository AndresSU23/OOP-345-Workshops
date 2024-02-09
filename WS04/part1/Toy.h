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
		virtual ~Toy();
		void update(int numItems);

		friend std::ostream& operator<<(std::ostream& os, const Toy& toy);
	};
	
}

#endif // !SENECA_TOY_H

