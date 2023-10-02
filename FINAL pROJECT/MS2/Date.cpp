/*
*****************************************************************************
						MileStone Two
Full Name  : Rohan Tankala
Student ID#: 122836166
Email      : rtankala1@myseneca.ca
Section    : NDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "Date.h"
#include "Utils.h"
#include "POS.h"

using namespace std;

namespace sdds {
	int Date::set(int year, int mon, int day, int hour, int min) const {
		return year * 535680 + mon * 44640 + day * 1440 + hour * 60 + min;
	}
	int Date::MonthDays(int year, int month) {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = month >= 1 && month <= 12 ? month : 13;
		mon--;
		return days[mon] + int((mon == 1) * ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	void Date::Datecheck() {
		int day = MonthDays(m_year, m_month);
		errorMessage.clear();
		if (m_year < MIN_YEAR || m_year > MAX_YEAR) {
			errorMessage = "Invalid Year";
		}
		else if (m_month <= 0 || m_month > 12) {
			errorMessage = "Invalid Month";
		}
		else if (m_day <= 0 || m_day > day) {
			errorMessage = "Invalid Day";
		}
		if (!m_dateOnly) {
			if (m_hour < 0 || m_hour > 24) {
				errorMessage = "Invalid Hour";
			}
			else if (m_minute < 0 || m_minute > 59) {
				errorMessage = "Invlid Minute";
			}
		}
	}

	Date::Date() {
		m_dateOnly = false;
		getSysDate(m_year, m_month, m_day, m_hour, m_minute, m_dateOnly);
		this->Datecheck();
	}
	Date::Date(int year, int month, int day) {
		m_dateOnly = true;
		m_year = year;
		m_month = month;
		m_day = day;
		this->Datecheck();
	}
	Date::Date(int year, int month, int day, int hour, int minute) {
		m_dateOnly = true;
		m_year = year;
		m_month = month;
		m_day = day;
		m_hour = hour;
		m_minute = minute;
		this->Datecheck();
	}
	Date::operator bool() const {
		return !errorMessage;
	}

	Date& Date::dateOnly(bool date) {
		m_dateOnly = date;
		if (date) {
			m_hour = 0;
			m_minute = 0;
		}
		return *this;
	}

	//Getter
	const Error& Date::error() {
		return errorMessage;
	}

	bool Date::operator==(const Date& D) const {
		return set(m_year, m_month, m_day, m_hour, m_minute) == set(D.m_year, D.m_month, D.m_day, D.m_hour, D.m_minute);
	}
	bool Date::operator!=(const Date& D) const {
		return set(m_year, m_month, m_day, m_hour, m_minute) != set(D.m_year, D.m_month, D.m_day, D.m_hour, D.m_minute);
	}
	bool Date::operator<(const Date& D) const {
		return set(m_year, m_month, m_day, m_hour, m_minute) < set(D.m_year, D.m_month, D.m_day, D.m_hour, D.m_minute);
	}
	bool Date::operator>(const Date& D) const {
		return set(m_year, m_month, m_day, m_hour, m_minute) > set(D.m_year, D.m_month, D.m_day, D.m_hour, D.m_minute);
	}
	bool Date::operator<=(const Date& D) const {
		return set(m_year, m_month, m_day, m_hour, m_minute) <= set(D.m_year, D.m_month, D.m_day, D.m_hour, D.m_minute);
	}
	bool Date::operator >=(const Date& D) const {
		return set(m_year, m_month, m_day, m_hour, m_minute) >= set(D.m_year, D.m_month, D.m_day, D.m_hour, D.m_minute);
	}

	std::ostream& Date::display(std::ostream& os) const {
		if (errorMessage) {
			os << errorMessage << "(";
		}
		os << m_year << "/" << std::setw(2) << std::setfill('0') << m_month << "/"
			<< std::setw(2) << m_day;
		if (!m_dateOnly) {
			os << ", " << std::setw(2) << m_hour << ":" << std::setw(2) << m_minute;
		}
		if (errorMessage) {
			os << ")";
		}
		return os;
	}
	
	std::istream& Date::read(std::istream& is) {
		errorMessage.clear();
		m_year = 0;
		m_month = 0;
		m_day = 0;
		m_hour = 0;
		m_minute = 0;

		is >> m_year;
		if (is.fail()) {
			errorMessage = "Cannot read year entry";
			return is;
		}

		is.ignore();
		is >> m_month;
		if (is.fail()) {
			errorMessage = "Cannot read month entry";
			return is;
		}

		is.ignore();
		is >> m_day;
		if (is.fail()) {
			errorMessage = "Cannot read day entry";
			return is;
		}

		if (!m_dateOnly) {
			is.ignore();
			is >> m_hour;
			if (is.fail()) {
				errorMessage = "Cannot read hour entry";
				return is;
			}

			is.ignore();
			is >> m_minute;
			if (is.fail()) {
				errorMessage = "Cannot read minute entry";
				return is;
			}
		}

		Datecheck();

		return is;
	}



	//Helper functions
	std::ostream& operator<<(std::ostream& os, Date& leftDate){
		leftDate.display(os);
		return os;
	}
	std::istream& operator>>(std::istream& is, Date& leftDate) {
		leftDate.read(is);
		return is;
	}
}