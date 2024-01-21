#include <iostream>
#include <cstring>

#include "event.h"

namespace seneca {

Event::Event() : startTime(g_sysClock) {
    description = new char[128];
}

// Copy constructor
Event::Event(const Event& other) : startTime(other.startTime) {
    description = new char[strlen(other.description)];
    std::strncpy(description, other.description, strlen(other.description));
}

// Destructor
Event::~Event() {
    delete[] description;
}

// Assignment operator
Event& Event::operator=(const Event& other) {
    if (this != &other) {
        startTime = other.startTime;
        set(other.description);
    }
    return *this;
}

// Query to display the content of an Event instance
void Event::display() {
    static int counter = 1; 
    std::cout << counter << ". ";

    int hours = startTime / 3600;
    int minutes = (startTime % 3600) / 60;
    int seconds = startTime % 60;

    if (!description || description[0] == '\0') {
        std::cout << "| No Event |" << std::endl;
    } else {
        printf("%02d:%02d:%02d => %s\n", hours, minutes, seconds, description);
    }

    counter++;
}

// Modifier to set the information about a new event
void Event::set(const char* desc) {
    if (desc && desc[0] != '\0') {
        delete[] description;
        description = new char[strlen(desc)];
        std::strncpy(description, desc, strlen(desc)); 
        startTime = g_sysClock;      
    }
    else {
        std::memset(description, '\0', strlen(description));
        startTime = 0;
    }
}

}  // namespace seneca
