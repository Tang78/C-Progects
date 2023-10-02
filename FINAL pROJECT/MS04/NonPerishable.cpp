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
            ostr << "     N / A   |";
        }
        else if (type == POS_FORM) {
            ostr << "=============^" << endl;
        }

        return ostr;
    }
}
   