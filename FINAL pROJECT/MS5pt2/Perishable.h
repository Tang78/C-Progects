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

#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include "Date.h"
#include "Item.h"


namespace sdds {
    class Perishable : public Item {
    private:
        Date expirydate;


    public:
    
    // Overridden displayInPOS function
        virtual void displayInPOS() const;

        std::ostream& write(std::ostream& ostr) const ;
        std::istream& read(std::istream& istr) ;
        std::ifstream& load(std::ifstream& ifstr) ;
        std::ofstream& save(std::ofstream& ofstr) const ;
        char itemType() const ;
    };
}

#endif
