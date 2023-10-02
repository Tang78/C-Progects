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
#ifndef SDDS_NONPERISHABLE_H
#define SDDS_NONPERISHABLE_H
#include "Item.h"
namespace sdds {
  class NonPerishable : public Item {
  public:
    std::ostream& write(std::ostream& ostr) const;
    char itemType() const;
  };
}

#endif // !SDDS_NONPERISHABLE_H
