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
#include "PosIO.h"
using namespace std;
namespace sdds {
    std::ostream& operator<<(std::ostream& ostr, const PosIO& obj) {//Implement two insertion operator<< operator overloads that invoke the write and 
    //save pure virtual methods to work with ostream and ofstream.
        return obj.write(ostr);
    }

    std::istream& operator>>(std::istream& istr, PosIO& obj) {
        return obj.read(istr);
    }

    std::ofstream& operator<<(std::ofstream& ofstr, const PosIO& obj) {
        return obj.save(ofstr);
    }

    std::ifstream& operator>>(std::ifstream& ifstr, PosIO& obj) {
        return obj.load(ifstr);
    }
}
