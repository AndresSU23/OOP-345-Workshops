#include "Toy.h"
#include <iomanip>

namespace seneca {
	std::string Toy::trim(const std::string& str) const {
		size_t start = 0;
		while (start < str.length() && std::isspace(str[start])) {
			start++;
		}

		size_t end = str.length();
		while (end > start && std::isspace(str[end - 1])) {
			end--;
		}

		return str.substr(start, end - start);
	}
	Toy::Toy(const std::string& toy) {
		size_t pos1 = 0;
		size_t pos2 = toy.find(':');
		size_t pos3 = toy.find(':', pos2 + 1);
		size_t pos4 = toy.find(':', pos3 + 1);

		m_orderId = std::stoi(trim(toy.substr(pos1, pos2 - pos1)));
		m_name = trim(toy.substr(pos2 + 1, pos3 - pos2 - 1));
		m_noItems = std::stoi(trim(toy.substr(pos3 + 1, pos4 - pos3 - 1)));
		m_price = std::stof(trim(toy.substr(pos4 + 1)));

		m_salesTax = m_price * TAX;
	}
	Toy::~Toy(){}

	void Toy::update(int numItems) {
		m_noItems = numItems;
	}

	std::ostream& operator<<(std::ostream& os, const Toy& toy) {
		double subtotal = toy.m_price * toy.m_noItems;
		double tax = toy.m_salesTax * toy.m_noItems;
		double total = subtotal + tax;

		os << std::left << std::setw(5) << "Toy" << std::setw(9) << toy.m_orderId << ":"
			<< std::right << std::setw(18) << toy.m_name
			<< std::setw(3) << toy.m_noItems << " items "
			<< std::setw(8) << std::fixed << std::setprecision(2) << toy.m_price << "/item "
			<< std::setw(10) << "subtotal:" << std::setw(7) << std::fixed << std::setprecision(2) << subtotal
			<< std::setw(7) << " tax:" << std::setw(6) << std::fixed << std::setprecision(2) << tax
			<< std::setw(7) << " total:" << std::setw(7) << std::fixed << std::setprecision(2) << total << '\n';

		return os;
	}
}

