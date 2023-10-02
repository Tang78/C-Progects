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

#define _CRT_SECURE_NO_WARNINGS

#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_POSIO_H
#define SDDS_POSIO_H
#include <iostream>
#include <fstream>
#include "POS.h"
namespace sdds 
{
    class PosIO {
    public:
        virtual std::ostream& write(std::ostream& ostr) const = 0;//Receives and returns references of ostream. This method does not modify its owner.
        virtual std::istream& read(std::istream& istr) = 0;//Receives and returns references of istream.
        virtual std::ofstream& save(std::ofstream& ofstr) const = 0;//Receives and returns references of ofstream. This method does not modify its owner.
        virtual std::ifstream& load(std::ifstream& ifstr) = 0;//Receives and returns references of ifstream.
        virtual ~PosIO() = default;
    };

    std::ostream& operator<<(std::ostream& ostr, const PosIO& obj);
    std::istream& operator>>(std::istream& istr, PosIO& obj);
    std::ofstream& operator<<(std::ofstream& ofstr, const PosIO& obj);
    std::ifstream& operator>>(std::ifstream& ifstr, PosIO& obj);

}

#endif // POSIO_H
