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



#ifndef SDDS_ERROR_H
#define SDDS_ERROR_H
#include <iostream>

namespace sdds {
   class Error {
      char* m_message;
   public:
      Error();
      Error(const char* errorMessage);
      Error(const Error& em) ;
      Error& operator=(const Error& em) ;
       ~Error();
      const char* message()const;
      operator bool()const;
      Error& clear();
		std::ostream& display(std::ostream& os) const;
   };

   std::ostream& operator<<(std::ostream& os, const Error& E);
}
#endif
