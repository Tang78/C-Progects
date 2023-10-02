
#include <iostream>
#include <iomanip>
#include "Bus.h"

using namespace std;

namespace sdds {

	void Bus::drawBus(int seats, int noOfPassengers, ostream& ostr) const//This function willdisplay routine as a private member of Bus class to draw the bus on the screen.
	{
		int i, p;
		ostr.fill('_');
		ostr.width((seats / 2) * 3 + 4);
		ostr << "_";
		ostr << endl << "| ";
		for (i = 0, p = -1; i < (seats / 2); i++, ostr << "[" << ((p += 2) < noOfPassengers ? '2' : ((p == noOfPassengers) ? '1' : ' ')) << "]");
		ostr << "|_\\_" << endl;
		ostr << "| ";
		ostr.fill(' ');
		ostr.width(((seats / 2) * 3 - 14) / 2);
		ostr << " " << "Seneca College";
		ostr.width(((seats / 2) * 3 - 14) / 2 + (seats % 4 != 0));
		ostr << " " << "    )" << endl;
		ostr << "`---OO";
		ostr.fill('-');
		ostr.width((seats / 2) * 3 - 5);
		ostr << "-" << "O---'" << endl;
	}

	Bus::Bus(int numSeats, int numPass)//By default, a bus has 20 seats and no passengers.
	{
		setEmpty();

		if ((numSeats % 2 == 0) && (numSeats >= 10 && numSeats <= 40) && (numPass >= 0 && numPass <= numSeats))
		{
			m_seats = numSeats;
			m_passengers = numPass;
		}
		else
		{
			noService();
		}
	}

	ostream& Bus::display(ostream& ostr) const//
	{
		if (bool(*this))
		{
			drawBus(m_seats, m_passengers, ostr);
			ostr << fixed << setprecision(2) << "Total Fare Price: " << double(*this) << endl;
		}
		else {
			ostr << "Out of service!" << endl;
		}
		return ostr;
	}

	istream& Bus::read(istream& istr)
	{
		istr >> m_seats;

		istr.ignore();

		istr >> m_passengers;

		if (!((m_seats % 2 == 0) && (m_seats >= 10 && m_seats <= 40) && (m_passengers >= 0 && m_passengers <= m_seats)))
		{
			noService();
		}

		return istr;
	}
	Bus::operator bool() const
	{
		return m_seats > 0;
	}
	Bus::operator int() const
	{
		return *this ? m_passengers : -1;
	}
	Bus::operator double() const
	{
		return *this ? m_passengers * TICKET_PRICE : -1;
	}
	bool Bus::operator--()//Works exactly like the prefix operator--
	{
		if (*this && m_passengers != 0)
		{
			--m_passengers;
			return true;
		}
		else
		{
			return false;
		}
	}
	bool Bus::operator++()//Works exactly like the prefix operator++
	{
		if (*this && m_passengers != m_seats)
		{
			++m_passengers;
			return true;
		}
		return false;
	}
	bool Bus::operator--(int)
	{
		return --(*this);
	}
	bool Bus::operator++(int)
	{
		return ++(*this);
	}
	Bus& Bus::operator=(int value)
	{
		if (*this)
		{
			m_passengers = value;

			if (m_passengers > m_seats)
			{
				noService();
			}
		}
		return *this;
	}
	Bus& Bus::operator+=(int value)
	{
		if (*this)
		{
			m_passengers += value;

			if (m_passengers > m_seats)
			{
				noService();
			}
		}

		return *this;
	}
	Bus& Bus::operator+=(Bus& right)
	{
		if (bool(*this) && bool(right))
		{
			if (this->m_passengers + right.m_passengers <= this->m_seats)
			{
				this->m_passengers += right.m_passengers;
				right.m_passengers = 0;
			}
			else
			{
				right.m_passengers -= this->m_seats - this->m_passengers;
				this->m_passengers += this->m_seats - this->m_passengers;
			}
		}
		return *this;
	}
	bool Bus::operator==(const Bus& right) const
	{
		return  (bool(*this) && bool(right) && (this->m_passengers == right.m_passengers));
	}
	void Bus::setEmpty()
	{
		m_seats = 0;
		m_passengers = 0;
	}
	void Bus::noService()
	{
		m_passengers = -1;
		m_seats = -1;
	}
	int operator+(int left, const Bus& right)
	{
		int temp = int(right);
		if (temp != -1)
		{
			left += temp;
		}
		return left;
	}
	ostream& operator<<(ostream& ostr, const Bus& right)
	{
		right.display(ostr);
		return ostr;
	}
	istream& operator>>(istream& istr, Bus& right)
	{
		right.read(istr);
		return istr;
	}
}
