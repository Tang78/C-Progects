/***********************************************************************
// OOP244 Workshop 9:
// File	Utils.h
// Version 1.0
// Date	Winter of 2023
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Utils.h"
using namespace std;
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