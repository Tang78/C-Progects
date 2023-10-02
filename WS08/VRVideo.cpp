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
#include <cstring>
#include <fstream>
#include "VRVideo.h"
using namespace std;
namespace sdds {
    VRVideo::VRVideo() : Video(), equipment(nullptr) {}

    VRVideo::VRVideo(int len, const char* equip) : Video(len) {
        if (equip != nullptr && len > 0) {
            equipment = new char[strlen(equip) + 1];
            strcpy(equipment, equip);
        }
        else {
            equipment = nullptr;
        }
    }

    VRVideo::~VRVideo() {
        delete[] equipment;
    }

    void VRVideo::load(std::istream& istr) {
        Video::load(istr);
        char size[1000];
        istr.getline(size, 1000, '\n');
        delete[] equipment;
        equipment = new char[strlen(size) + 1];
        strcpy(equipment, size);
    }

    std::ostream& VRVideo::play(std::ostream& ostr) const {
        if (equipment != nullptr) {
            ostr << "VRVideo requires " << equipment << std::endl;
            ostr << "Video Length = " << get();
        }
        return ostr;
    }
}