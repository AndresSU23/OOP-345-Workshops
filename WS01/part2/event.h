/***********************************************************************
// Workshop 1 Part 2
// Module: Event
// File: event.h
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

#ifndef SENECA_EVENT_H
#define SENECA_EVENT_H

namespace seneca {
    extern unsigned int g_sysClock;
    class Event {
    private:
        char* description{nullptr};
        unsigned int startTime{ 0 };
    public:
        Event();

        Event(const Event& other);

        ~Event();

        Event& operator=(const Event& other);

        void display();

        void set(const char* desc = nullptr);
    };

    

}  

#endif  // SENECA_EVENT_H
