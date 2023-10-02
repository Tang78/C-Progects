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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Media.h"
using namespace std;
namespace sdds {
    std::ostream& operator<<(std::ostream& ostream, const Media& media) {
        return media.play(ostream);
    }

    std::istream& operator>>(std::istream& istream, Media& media) {
        media.load(istream);
        return istream;
    }
    Media::~Media()
    {
    }
    
}

