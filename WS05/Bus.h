#define _CRT_NO_SECURE_WARNING
#ifndef SDDS_BUS_H
#define SDDS_BUS_H

#include <iostream>

using namespace std;

namespace sdds {
const double TICKET_PRICE = 125.34;

	class Bus
	{
		int m_seats;
		int m_passengers;

		void drawBus(int seats, int noOfPassengers, ostream& ostr) const;

	public:
		Bus(int numSeats = 20, int numPass = 0);

		ostream& display(ostream& ostr = cout) const;
		istream& read(istream& istr = cin);
		operator bool() const;
		operator int() const;
		operator double() const;
		bool operator--();
		bool operator++();
		bool operator--(int);
		bool operator++(int);
		Bus& operator=(int value);
		Bus& operator+=(int value);
		Bus& operator+=(Bus& right);
		bool operator==(const Bus& right) const;
		void setEmpty();
		void noService();

	};
	int operator+(int left, const Bus& right);
	ostream& operator<<(ostream& ostr, const Bus& right);
	istream& operator>>(istream& istr, Bus& right);
}

#endif
