#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "event.h"
#include <iomanip>

namespace seneca {
    unsigned int g_sysClock = 1;

    Event::Event(): startTime(seneca::g_sysClock) {
        description = new char[128];
    }
    Event::Event(const Event& other) : startTime(other.startTime) {
        *this = other;
    }
    Event::~Event() {
        delete[] description;
    }
    Event& Event::operator=(const Event& other){
        startTime = other.startTime;
        set(other.description);
        return *this;
    }
    // Query to display the content of an Event instance
    void Event::display() {
        static int counter = 1; 
        std::cout << " " << counter << ". ";

        int hours = startTime / 3600;
        int minutes = (startTime % 3600) / 60;
        int seconds = startTime % 60;

        if (description && strlen(description)) {
            std::cout << std::setfill('0') << std::setw(2) << hours << ":"
                << std::setfill('0') << std::setw(2) << minutes << ":"
                << std::setfill('0') << std::setw(2) << seconds << " => "
                << description << std::endl;
        } else {
            std::cout << "| No Event |" << std::endl;
        }

        counter++;
    }

    void Event::set(const char* desc) {
        if(description) delete[] description;
        if (desc && strlen(desc)) {
            description = new char[strlen(desc) + 1];
            std::strcpy(description, desc);
            startTime = g_sysClock;
        }
        else {           
            description = nullptr;
            startTime = 0;
        }
    }


    

}  // namespace seneca
