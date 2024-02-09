/***********************************************************************
// Workshop 4 Part 2
// Module: ConfirmOrder
// File: ConfirmOrder.cpp
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

#include "ConfirmOrder.h"

namespace seneca {
    void ConfirmOrder::resize(size_t newSize) {
        const Toy** temp = new const Toy * [newSize];
        for (size_t i = 0; i < newSize -1; ++i) {
            temp[i] = m_toys[i];
        }
        delete[] m_toys;
        m_toys = temp;
    }

    ConfirmOrder::ConfirmOrder(const ConfirmOrder& other) : m_toys(new const Toy* [other.m_size]), m_size(other.m_size) {
        for (size_t i = 0; i < m_size; ++i) {
            m_toys[i] = other.m_toys[i];
        }
    }

    ConfirmOrder::ConfirmOrder(ConfirmOrder&& other) noexcept : m_toys(other.m_toys), m_size(other.m_size) {
        other.m_toys = nullptr;
        other.m_size = 0;
    }

    ConfirmOrder::~ConfirmOrder() {
        delete[] m_toys;
    }

    ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& other) noexcept {
        if (this != &other) {
            delete[] m_toys;
            m_toys = other.m_toys;
            m_size = other.m_size;
            other.m_toys = nullptr;
            other.m_size = 0;
        }
        return *this;
    }

    ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& other) {
        if (this != &other) {
            delete[] m_toys;

            m_toys = new const Toy * [other.m_size];
            m_size = other.m_size;

            for (size_t i = 0; i < m_size; ++i) {
                m_toys[i] = other.m_toys[i];
            }
        }
        return *this;
    }

    ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy) {
        for (size_t i = 0; i < m_size; ++i) {
            if (m_toys[i] == &toy) {
                return *this; 
            }
        }
        resize(m_size + 1);
        m_toys[m_size++] = &toy;
        return *this;
    }

    ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy) {
        for (size_t i = 0; i < m_size; ++i) {
            if (m_toys[i] == &toy) {
                for (size_t j = i; j < m_size - 1; ++j) {
                    m_toys[j] = m_toys[j + 1];
                }
                m_size--;
                return *this;
            }
        }
        return *this;
    }


    std::ostream& operator<<(std::ostream& os, const ConfirmOrder& order) {
        os << "--------------------------\n"
            << "Confirmations to Send\n"
            << "--------------------------\n";

        if (order.m_size == 0) {
            os << "There are no confirmations to send!\n";
        }
        else {
            for (size_t i = 0; i < order.m_size; ++i) {
                os << *order.m_toys[i];
            }
        }

        os << "--------------------------\n";
        return os;
    }

}

