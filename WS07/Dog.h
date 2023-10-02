// Dog.h header file
#ifndef DOG_H
#define DOG_H
#include <cstring>
#include "Pet.h"
namespace sdds
{
class Dog :public Pet{
public:
     
    Dog(); // default constructor
    Dog(const char* name, int age=0) ;// parameterized constructor
    ~Dog(); // destructor
   void operator++(int num);
   Dog& operator=(const Dog& other);
    void feed(); // set the dog's name
    void walk(); // set the dog's age
    void reSpawn(); // set the dog's breed
    std::ostream& outputData(std::ostream& os);
private:
     const  double  DOG_RESPAWN_FEE = 1.00;
     const  double  DOG_FEED_FEE = 0.25;
     const  double  DOG_FEE=4.00;
     int walks;
};
std::ostream& operator<< (std::ostream& os, Dog& dog);
}

#endif
