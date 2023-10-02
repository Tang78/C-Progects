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
