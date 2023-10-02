#ifndef FISH_H
#define FISH_H
#include "Pet.h"
namespace sdds
{
class Fish : public Pet 
{
public:
    Fish(const char* name, int age = 0);
    ~Fish();
    void feed();
    void reSpawn();
    Fish& operator++(int num);
    Fish& operator=(const Fish& other);
     //std::ostream& operator<<(std::ostream& os, const Fish& fish);
    const double FISH_RESPAWN_FEE = 0.50;
    const double FISH_FEED_FEE = 0.10;
    const double FISH_FEE=2.00;

};
std::ostream& operator<<(std::ostream& os, Fish& fish);
}

#endif
