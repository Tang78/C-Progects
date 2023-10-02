/*
*****************************************************************************
<assessment name example: Milestone - #1 >
Full Name : ORANG TANG ENOW
Student ID#: 149924219
Email : otang-enow@mysenca.ca
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.

******************************************************************************


*/
#include "Perishable.h"
#include "Item.h"
#include"Error.h"
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;


namespace sdds {
    char Perishable::itemType() const {
        return 'P';
    }
  

   // Overridden displayInPOS function
void Perishable::displayInPOS() const {
    cout << "=============v" << endl;
    cout << "Name:        " << getname() << endl;
    cout << "Sku:         " << getsku() << endl;
    cout << "Price:       " << fixed << setprecision(2) << getPrice() << endl;
    cout << "Price + tax: ";
    if (isTaxed()) {
        cout << fixed << setprecision(2) << cost() << endl;
    } else {
        cout << "N/A" << endl;
    }
    cout << "Stock Qty:   " << quantity() << endl;
    // Display the expiry date for the Perishable class
    cout << "Expiry date: " << expirydate << endl;
    cout << "=============^" << endl;
}


    ostream& Perishable::write(ostream& ostr) const {
        Item::write(ostr);
        if (*this) {
        int type = DisplayType();
            if (type == POS_LIST) 
            {
                ostr <<" "<<expirydate <<" |";
            }
            else if (type == POS_FORM) {
                ostr << "Expiry date: " << expirydate << endl;
                ostr << "=============^" << endl;
            }
        }
         return ostr;
    }

   std::ifstream& Perishable::load(std::ifstream& ifstr) {
        Item::load(ifstr);

        if (!Item::iserror() && !ifstr.fail()) {
            Date expd;
            expd.dateOnly(true);
            ifstr.clear();
            ifstr.ignore();
            ifstr >> expd;
            if (ifstr.fail()) {
                errorstate = expd.error();
                ifstr.setstate(ios::failbit);
            }
            else {
                expirydate = expd;
            }
        }

        return ifstr;
    }
    
std::ofstream& Perishable::save(std::ofstream& ofstr) const {
        Item::save(ofstr);

        if (!Item::iserror()) {
            ofstr << ',' << expirydate;
        }

        return ofstr;
    }
    std::istream& Perishable::read(std::istream& istr) {
        Item::read(istr);

        if (*this && istr) {
            Date expd;
            expd.dateOnly(true);
            cout << "Expiry date (YYYY/MM/DD)\n> ";
            istr >> expd;
            if (istr.fail()) {
                errorstate = expd.error();
                istr.setstate(ios::failbit);
            }
            else {
                expirydate = expd;
            }
        }

        return istr;
    }

    
}
