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
