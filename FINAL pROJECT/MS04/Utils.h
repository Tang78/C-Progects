/*
*****************************************************************************
						
Full Name  : Orang Tang Enow 
Student ID#: 
Email      : otang-enow@mysenecacollege.ca
Section    : ndd

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include<ctime>
namespace sdds {

	std::tm getLocalTime();

	void getSysDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly);
}

#endif // !SDDS_UTILS_H_
