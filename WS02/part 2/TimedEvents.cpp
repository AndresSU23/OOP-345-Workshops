/***********************************************************************
// Workshop 2 Part 2
// Module: TimedEvents
// File: TimedEvents.cpp
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
#include "TimedEvents.h"
#include <iomanip>

namespace seneca {
	Event TimedEvents::m_events[DEFAULT_EVENTS] = {};

	void TimedEvents::startClock() {
		m_startTime = std::chrono::steady_clock::now();
	}
	void TimedEvents::stopClock() {
		m_endTime = std::chrono::steady_clock::now();
	}
	void TimedEvents::addEvent(const char* newEvent) {
		m_events[m_currentRecords].m_name = newEvent;
		m_events[m_currentRecords].m_timeUnit = "nanoseconds";
		m_events[m_currentRecords].m_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);
		m_currentRecords++;
	}
	Event TimedEvents::operator[](int i) const {
		return m_events[i];
	}
	int TimedEvents::current_records() const { return m_currentRecords; }
	std::ostream& operator<<(std::ostream& os, const TimedEvents& timedEvents) {
		os << "--------------------------\nExecution Times:\n--------------------------\n";
		for (auto i = 0; i < timedEvents.current_records(); i++) {
			os << std::left << std::setw(21) << timedEvents[i].m_name;
			os << std::right << std::setw(13) << timedEvents[i].m_duration.count() << ' ' << timedEvents[i].m_timeUnit << '\n';
		}
		os << "--------------------------\n";
		return os;
	}
}
