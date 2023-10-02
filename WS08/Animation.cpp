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
#include "Animation.h"
using namespace std;
namespace sdds {
    Animation::Animation() : Video() {
        dimension=0;
    }

    Animation::Animation(int inputLength, int inputDimension) : Video(inputLength) {
        if (inputLength > 0 && (inputDimension == 2 || inputDimension == 3)) {
            dimension = inputDimension;
        }
        else {
            dimension = 0;
        }
    }

    void Animation::load(std::istream& istr) {
        Video::load(istr);
        istr>> dimension;
        istr.ignore(256, '\n');
        if (dimension != 2 && dimension != 3) {
            dimension = 0;
        }
    }

    std::ostream& Animation::play(std::ostream& ostr) const {
        if (dimension != 0) {
            ostr << "Animation is in " << dimension << "-D" << std::endl;
            ostr << "Video Length = " << get();
        }
        return ostr;
    }
}