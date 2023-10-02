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

#include <iostream>
#include "Video.h"
using namespace std;
namespace sdds {
    Video::Video() : length(0) {}

    Video::Video(int len) : length(len< 0 ? 0 : len) {}

    Video::~Video() {
        
    }

    int Video::get() const {
        return length;
    }

    void Video::load(std::istream& is) {
        is >> length;
        is.ignore(1, ',');
    }
}
