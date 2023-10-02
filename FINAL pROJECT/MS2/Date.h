#ifndef SDDS_Date_H_
#define SDDS_Date_H
#include <iostream>
#include "Error.h"
// SDDS namespace 
namespace sdds {
   class Date {
   private:
      // member variables
	   int m_year;
	   int m_month;
	   int m_day;
	   int m_hour;
	   int m_minute;
	   Error errorMessage;
       bool m_dateOnly;
    int  set(int year, int mon, int day, int hour, int min) const;
    public:
    int MonthDays(int year, int month);
      // constructors
      Date();
	  Date(int year, int mon, int day);
      Date(int year, int mon, int day, int hour, int min = 0);
     
	  bool operator==(const Date& D)const; 
	  bool operator!=(const Date& D)const; 
	  bool operator<(const Date& D)const; 
	  bool operator>(const Date& D)const;
	  bool operator<=(const Date& D)const; 
	  bool operator>=(const Date& D)const;
	  // methods
      const Error& error();
      operator bool() const;
	  Date& dateOnly(bool value);
	  void Datecheck();

      // istream  and ostream read and write methods

	  std::istream& read(std::istream& is);

	  std::ostream& display(std::ostream& os) const;

   };
   // operator<< and >> overload prototypes for cout and cin

	std::istream& operator >> (std::istream& is, Date& D);
	std::ostream& operator << (std::ostream& os,  Date& D);
    

}

#endif