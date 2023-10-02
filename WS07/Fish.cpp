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
#include "Fish.h"
using namespace std;

namespace sdds
{
    Fish::Fish(const char* name, int age) : Pet(name, age, COST_BASE)
    {
        
    }
    void Fish::reSpawn()
    {
        Pet::reSpawn();
        Pet::addCharge(FISH_RESPAWN_FEE);
    }

    Fish& Fish::operator++(int num)
    {
        if (isAlive()) {
            double healthDelta = 0;
            healthDelta += 0.20 * (getFeeds() - 1);
            applyHealthDelta(healthDelta);
        }
        Pet::operator++(num);
        return *this;
    }
    void Fish::feed()
    {
        Pet::feed(); // Invoke feed() method on the base class (Pet)

        if (isAlive()) // Check if fish is still alive
        {
            Pet::addCharge(FISH_FEED_FEE); // Add fish feeding fee to total charges
        }
    }
    Fish& Fish::operator=(const Fish& other)
    {
        if (this != &other)
        {
            Pet::operator=(other);
            Pet::addCharge(FISH_FEE * 2);
        }
        return *this;
    }
    Fish::~Fish()
    {
        
    }
    std::ostream& operator<<(std::ostream& os, Fish& fish)
    {
        os << "** Generic Fish **" << endl;
        return fish.outputData(os);
    }
}