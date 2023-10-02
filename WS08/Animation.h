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

#ifndef SDDS_ANIMATION_H
#define SDDS_ANIMATION_H
#include "Video.h"
namespace sdds {
    class Animation : public Video {
    private:
        int dimension;

    public:
        //Default Constructor
        Animation();

        //Parameterful Constructor
        Animation(int inputLength, int inputDimension);

        //Overriden 'load' function inherited from base class of Video
        void load(std::istream& istr) ;

        //Overriden 'play' function inherited from base class of Video
        std::ostream& play(std::ostream& ostr) const ;
    };

#endif // ANIMATION_H
}

