#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H
#include "Date.h"
#include "Item.h"


namespace sdds {
    class Perishable : public Item {
    private:
        Date expirydate;

    public:
        std::ostream& write(std::ostream& ostr) const ;
        std::istream& read(std::istream& istr) ;
        std::ifstream& load(std::ifstream& ifstr) ;
        std::ofstream& save(std::ofstream& ofstr) const ;
        char itemType() const ;
    };
}

#endif