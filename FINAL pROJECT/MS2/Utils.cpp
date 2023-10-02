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
#include <ctime>
#include "Utils.h"

namespace sdds {

    std::tm getLocalTime()
    {
        std::time_t now = std::time(nullptr);
        return *std::localtime(&now);
    }

    void getSysDate(int& year, int& mon, int& day, int& hour, int& min, bool dateOnly) {
        std::tm lt = getLocalTime();
        day = lt.tm_mday;
        mon = lt.tm_mon + 1;
        year = lt.tm_year + 1900;
        if (dateOnly) {
            hour = min = 0;
        }
        else {
            hour = lt.tm_hour;
            min = lt.tm_min;
        }
    }
}