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


#include "NonPerishable.h"
#include "Error.h"
#include <cstring>
#include <iomanip>
using namespace std;
namespace sdds {

    // Default Constructor
	char NonPerishable::itemType() const {
		return 'N';
	}

    // Member functions

    std::ostream& NonPerishable::write(std::ostream& ostr) const {
       Item::write(ostr);
        int type = DisplayType();
        if (Item::iserror()) {
            return ostr;
        }

        if (type == POS_LIST) {
            ostr << "    N / A   |";
        }
        else if (type == POS_FORM) {
            ostr << "=============^" << endl;
        }

        return ostr;
    }
}
   
