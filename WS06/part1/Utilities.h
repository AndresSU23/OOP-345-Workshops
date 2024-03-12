#pragma once
#ifndef UTILITIES_H
#define UTILITIES_H

#include "employee.h"
#include <iostream>

namespace seneca {

    Person* buildInstance(std::istream& in);
}

#endif // UTILITIES_H
