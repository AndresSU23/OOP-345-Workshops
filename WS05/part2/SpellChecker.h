#pragma once
#ifndef SENECA_SPELLCHECKER_H
#define SENECA_SPELLCHECKER_H

#include <string>

namespace seneca {
	class SpellChecker {
		static const int SIZE = 6;
		std::string m_badWords[6];
		std::string m_goodWords[6];
		int m_replaceCount[SIZE] = { 0 };

	public:
		SpellChecker(const char* filename);

		void operator()(std::string& text);

		void showStatistics(std::ostream& out) const;
	};
}

#endif // !SENECA_SPELLCHECKER_H

