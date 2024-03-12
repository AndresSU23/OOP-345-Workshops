/***********************************************************************
// Workshop 6 Part 2
// Module: Utilities
// File: Utilities.h
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
#ifndef SENECA_UTILITIES_H
#define SENECA_UTILITIES_H

#include "employee.h"
#include <iostream>

namespace seneca {

    Person* buildInstance(std::istream& in);
}

#endif // SENECA_UTILITIES_H
