/*
*****************************************************************************
Full Name  : ORANG TANG ENOW 
Student ID#: 149924219
Email      : otang-enow@myseneca.ca
Section    : NDD
Date       : 29/03/2023
Authenticity Declaration:I have done all the coding by myself and only 
copied the code that my professor provided to complete my workshops and assignments.
*************************************************/
#ifndef SDDS_VRVIDEO_H
#define SDDS_VRVIDEO_H
#include "Video.h"
using namespace std;
namespace sdds {
    class VRVideo : public Video {
    private:
        char* equipment;

    public:
        VRVideo();
        VRVideo(int len, const char* equip);
        virtual ~VRVideo();

        virtual void load(std::istream& istr);
        virtual std::ostream& play(std::ostream& ostr) const;
    };
}
#endif // VRVIDEO_H
