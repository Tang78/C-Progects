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

#ifndef SDDS_MEDIA_H
#define SDDS_MEDIA_H
#include <iostream>
namespace sdds {
    class Media {
    public:
        //Pure virtual methods
        virtual std::ostream& play(std::ostream& ostr) const = 0;
        virtual void load(std::istream& istr) = 0;

        //Virtual Destructor
        virtual ~Media() ;

        //Helper functions
         
    };
       std::ostream& operator<<(std::ostream& ost, const Media& media);
         std::istream& operator>>(std::istream& ist, Media& media);

}
#endif // MEDIA_H


