#define _CRT_SECURE_NO_WARNINGS
#include "Contact.h"
#include "Tools.h"
#include <cstring>
#include <iostream>

using namespace std;

namespace sdds {

    Contact::Contact() : Person() {//Default Constructor
        m_address = nullptr;
        m_city = nullptr;
        m_province[0] = '\0';
        m_postalCode[0] = '\0';
    }

    Contact::Contact(const Contact& copy) : Person(copy) {//Invoke the base class's constructors and Methods in copy construction and copy assignment to make 
    //sure the base class's resources are managed properly.
        m_address = nullptr;
        m_city = nullptr;
        m_province[0] = '\0';
        m_postalCode[0] = '\0';
        *this = copy;
    }

    Contact& Contact::operator=(const Contact& copy) {//Invoke the base class's constructors and Methods in copy construction and 
    //copy assignment to make sure the base class's resources are managed properly.
        if (this != &copy) {
            Person::operator=(copy);
            delAlloCopy(m_address, copy.m_address);
            delAlloCopy(m_city, copy.m_city);
            if (validPostCode(copy.m_postalCode)) {
                strcpy(m_province, copy.m_province);
                strcpy(m_postalCode, copy.m_postalCode);
            }
        }
        return *this;
    }

    Contact::~Contact() {//Override all the virtual functions and virtual 
    //operators of the Person class and implement the rule of three.
        delete[] m_address;
        delete[] m_city;
    }

    std::ostream& Contact::write(std::ostream& ostr)const {//Override all the virtual functions and virtual operators of the Person class
    //and implement the rule of three.
        if (*this) {
            Person::write(ostr);
            cout << m_address << endl << m_city << " " << m_province << endl;
            cout << m_postalCode[0] << m_postalCode[1] << m_postalCode[2] << " ";
            cout << m_postalCode[3] << m_postalCode[4] << m_postalCode[5] << endl;
        }
        return ostr;
    }

    std::istream& Contact::read(std::istream& istr) {//Override all the virtual functions and virtual 
    //operators of the Person class and implement the rule of three.
        delete[] m_address;
        m_address = dynRead(istr, ',');
        delete[] m_city;
        m_city = dynRead(istr, ',');
        istr.getline(m_province, 3, ',');
        istr.getline(m_postalCode, 8);
        if (!validPostCode(m_postalCode)) {
            m_postalCode[0] = '\0';
            *this = Contact();
        }
        return istr;
    }

    bool Contact::validPostCode(const char* postalCode) const {//Test the validity of the postal code 
        bool valid = false;
        if (strLen(postalCode) == 6) {
            valid = isalpha(postalCode[0]) && isdigit(postalCode[1]) && isalpha(postalCode[2]) &&
                isdigit(postalCode[3]) && isalpha(postalCode[4]) && isdigit(postalCode[5]);
        }
        return valid;
    }
}
