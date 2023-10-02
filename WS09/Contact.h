/*
*****************************************************************************
Full Name  : ORANG TANG ENOW 
Student ID#: 149924219
Email      : otang-enow@myseneca.ca
Section    : NDD
Date       : 29/03/2023
Authenticity Declaration:I have done all the coding by myself and only 
copied the code that my professor provided to complete my workshops and assignments.
*************************************************/
#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H
#include "Person.h"

namespace sdds {
    class Contact : public Person {
        char* m_address;
        char* m_city;
        char m_province[3];
        char m_postalCode[8];
        bool validPostCode(const char* postalCode) const;
    public:
        Contact();
        Contact(const Contact& copy);
        Contact& operator=(const Contact& copy);
       virtual ~Contact();
       virtual std::ostream& write(std::ostream& ostr)const;
       virtual std::istream& read(std::istream& istr);
    };
}

#endif // !SDDS_CONTACT_H
