/*
*****************************************************************************
<assessment name example: Milestone - #1 >
Full Name : Orang Tang Enow 
Student ID#: 149924219
Email : otang-enow@myseneca.ca
Section : 1
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.

******************************************************************************


*/

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
