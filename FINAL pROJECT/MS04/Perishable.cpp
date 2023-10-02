#include "Perishable.h"
#include "Item.h"
#include"Error.h"
#include <iostream>
using namespace std;


namespace sdds {
    char Perishable::itemType() const {
        return 'P';
    }

    ostream& Perishable::write(ostream& ostr) const {
        Item::write(ostr);
        if (*this) {
        int type = DisplayType();
            if (type == POS_LIST) 
            {
                ostr << ' ' << ' ' << expirydate << ' ' << '|';
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