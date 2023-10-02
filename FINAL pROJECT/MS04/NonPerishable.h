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
