/***********************************************************************
// Workshop 5 Part 2
// Module: Collection
// File: Collection.h
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
#ifndef SENECA_COLLECTION_H
#define SENECA_COLLECTION_H

#include <string>

namespace seneca {
	template<typename T>
	class Collection {
		std::string m_name;
        T* m_array{ nullptr };
        size_t m_size{ 0 };
		
        void (*functionPtr)(const Collection<T>&, const T&) {nullptr};

	public:
        Collection(const std::string& name) : m_name(name) {};
		~Collection() { delete[] m_array; }

		Collection(const Collection&) = delete;
		Collection& operator=(const Collection&) = delete;

		const std::string& name() const { return m_name; }
        size_t size() const { return m_size; }
		void setObserver(void (*observer)(const Collection<T>&, const T&)) { functionPtr = observer; }
        Collection<T>& operator+=(const T& item) {
            bool exists = false;
            for (size_t i = 0; i < m_size; ++i) {
                if (m_array[i].title() == item.title()) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                T* newArray = new T[m_size + 1];
                for (size_t i = 0; i < m_size; ++i) {
                    newArray[i] = std::move(m_array[i]);
                }
                newArray[m_size] = item;
                delete[] m_array;
                m_array = newArray; 
                ++m_size;

                if (functionPtr) {
                    functionPtr(*this, item);
                }
            }
            return *this;
        }
        T& operator[](size_t idx) const {
            if (idx >= m_size) {
                throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(m_size) + "] items.");
            }
            return m_array[idx];
        }
        T* operator[](const std::string& title) const {
            for (size_t i = 0; i < m_size; ++i) {
                if (m_array[i].title() == title) {
                    return &m_array[i];
                }
            }
            return nullptr;
        }
        friend std::ostream& operator <<(std::ostream& os, const Collection& collection) {
            for (size_t i = 0; i < collection.m_size; i++) {
                os << collection[i];
            }
            return os;
        }
	};
}

#endif // !SENECA_COLLECTION_H
