/*
*****************************************************************************
                        Workshop 7
Full Name  : Orang Tang Enow 
Student ID#: 149924219
Email      : otang-enow@myseneca.ca
Section    : NDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Dog.h"
using namespace std;

namespace sdds
{
    Dog::Dog(const char* name, int age) : Pet(name, age, DOG_FEE)//, m_walks(walks)
    {
        walks = 0;
    }

    Dog::~Dog()
    {
    }

    void Dog::operator++(int num) {
        if (isAlive()) {
            double healthDelta = 0;
            healthDelta += 0.15 * (getHugs() - 1);
            healthDelta += 0.10 * (getFeeds() - 2);
            healthDelta += 0.10 * (getGrooms() - 1);
            healthDelta += 0.20 * (walks - 2);

            applyHealthDelta(healthDelta);

            Pet::operator++(num);
           // return *this;

            walks = 0;
        }
    }

    Dog& Dog::operator=(const Dog& other)
    {
        if (this != &other)
        {
            walks = other.walks;
            Pet::operator=(other);
            addCharge(DOG_FEE*2);
        }
        return *this;
    }

    void Dog::feed()
    {
        Pet::feed(); // Invoke feed() method on the base class (Pet)

        if (isAlive()) // Check if fish is still alive
        {
            addCharge(DOG_FEED_FEE); // Add fish feeding fee to total charges
        }
    }

    void Dog::walk()
    {
        if (isAlive()) // Check if dog is still alive
        {
            walks++; //If so, increment number of walks on record
        }
    }

    void Dog::reSpawn()
    {
        Pet::reSpawn();
        addCharge(DOG_RESPAWN_FEE);
        walks = 0;
    }

    std::ostream& Dog::outputData(ostream& os)
    {
        os << "   Walks: " << walks << endl;
        return Pet::outputData(os);
    }

    ostream& operator<<(std::ostream& os, Dog& dog)
    {
        os << "** Generic Dog **" << endl;
        
        return dog.outputData(os);
    }

}
