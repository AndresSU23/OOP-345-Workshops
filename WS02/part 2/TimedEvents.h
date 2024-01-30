/***********************************************************************
// Workshop 2 Part 2
// Module: TimedEvents
// File: TimedEvents.h
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
#include <string>
#include <chrono>
#include <iostream>
#ifndef SENECA_TIMEDEVENTS_H
#define SENECA_TIMEDEVENTS_H
#define DEFAULT_EVENTS 10

namespace seneca {
	struct Event {
		std::string m_name{};
		std::string m_timeUnit{};
		std::chrono::steady_clock::duration m_duration;

		Event() = default;
	};
	
	class TimedEvents {
		int m_currentRecords{0};
		std::chrono::steady_clock::time_point m_startTime;
		std::chrono::steady_clock::time_point m_endTime;
		static Event m_events[DEFAULT_EVENTS];

	public:
		TimedEvents() = default;
		void startClock();
		void stopClock();
		void addEvent(const char* newEvent);
		int current_records() const;
		Event operator [](int i) const;
	};
	std::ostream& operator <<(std::ostream& os, const TimedEvents& timedEvents);
	
}

#endif // !SENECA_TIMEDEVENTS_H

