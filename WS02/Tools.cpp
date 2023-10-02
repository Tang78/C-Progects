/*
*****************************************************************************
                        Workshop 2 - Part 2
Full Name  : Orang Tang Enow
Student ID#: 149924219
Email      : otang-enow@myseneca.ca
Section    : NDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Tools.h"

namespace sdds {
   void strCpy(char* str1, const char* str2) {
      while(*str2) {
         *str1++ = *str2++;
      }
      *str1 = 0;
   }
}
