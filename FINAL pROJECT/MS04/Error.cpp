#include "Error.h"
#include <cstring>
#include <string>

namespace sdds {
   Error::Error() {
      m_message = nullptr;
   }

   Error::Error(const char* errorMessage) {
      if ( errorMessage!= nullptr) {
			m_message = new char[strlen(errorMessage) + 1];
			strcpy(m_message, errorMessage);
		}
		else {
			m_message = nullptr;
		}
	}
Error::Error(const Error& em) {
    if (em.m_message != nullptr && em.m_message[0] != '\0') {
			m_message = new char[strlen(em.m_message) + 1];
			strcpy(m_message, em.m_message);
		}
		else {
			m_message = nullptr;
		}
	}
   Error::~Error() {
       if(m_message)
       {
      delete[] m_message;
       }
   }
   Error& Error::operator=(const Error& em) {
        if (this != &em) {
			if (em.m_message != nullptr && em.m_message[0] != '\0') {
				if (m_message != nullptr) {
					delete[] m_message;
					m_message = nullptr;
				}
				m_message = new char[strlen(em.m_message) + 1];
				strcpy(m_message, em.m_message);
			}
			else {
				m_message = nullptr;
			}
		}
		return *this;
	}


   const char* Error::message() const {
      return m_message;
   }

   Error::operator bool() const {
      return m_message != nullptr;
   }

   Error& Error::clear()  {
       if ( m_message!= nullptr) {
			delete[] m_message;
		}
		m_message = nullptr;
		return *this;
   }
std::ostream& Error::display(std::ostream& os) const {
		if (m_message) {
			os << message();
		}
		return os;
	}

   std::ostream& operator<<(std::ostream& os, const Error& E) {
      E.display(os);
		return os;
	}
}
