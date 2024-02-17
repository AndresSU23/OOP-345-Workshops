#pragma once
#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H

#include <iostream>
#include <string>

namespace seneca {
	class Book {
		std::string m_author;
		std::string m_title;
		std::string m_country;
		size_t m_pubYear{};
		double m_price;
		std::string m_description;

	public:
		Book() = default;
		Book(const std::string& strBook);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();

		friend std::ostream& operator <<(std::ostream& os, const Book& book);
	};
}

#endif // !SENECA_BOOK_H

