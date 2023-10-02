
#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_DATE_H
#define SDDS_DATE_H

#include "Error.h"
#include <iostream>

namespace sdds {
	class Date {
	private:
		int year_;
		int month_;
		int day_;
		int hour_;
		int minute_;
		bool dateOnly_;
		Error errorMessage;    
        int MonthDays(int year, int month) const;
        void Datecheck();

    public:
        Date();
        Date(bool Flag);
        Date(int year, int month, int day, int hour);
        Date(int year, int month, int day, int hour, int minute);
       Date(int year, int month, int day);
        
        bool operator==(const Date& D) const;
        bool operator!=(const Date& D) const;
        bool operator<(const Date& D) const;
        bool operator>(const Date& D) const;
        bool operator<=(const Date& D) const;
        bool operator>=(const Date& D) const;
        
        operator bool() const;
        const Error& error() const;

        Date& dateOnly(bool flag);
        friend std::ostream& operator<<(std::ostream& ostr, const Date& D);
        friend std::istream& operator>>(std::istream& istr, Date& D);
    };
}

#endif // SDDS_DATE_H
