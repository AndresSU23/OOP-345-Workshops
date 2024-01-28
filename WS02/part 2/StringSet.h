#pragma once
#ifndef SENECA_STRINGSET_H
#define SENECA_STRINGSET_H

namespace seneca {
	class StringSet {
		std::string* m_arr{};
		int m_size{ 0 };

	public:
		StringSet() = default;
		StringSet(const char* str);
		StringSet(const StringSet& other);
		StringSet(StringSet&& other) noexcept;
		~StringSet();
		size_t size() const;
		std::string operator[](size_t i) const;
		StringSet& operator=(const StringSet& other);
		StringSet& operator=(StringSet&& other) noexcept;
	};
}

#endif // !SENECA_STRINGSET_H

