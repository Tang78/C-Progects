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
