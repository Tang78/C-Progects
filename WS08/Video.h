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

#ifndef SDDS_VIDEO_H
#define SDDS_VIDEO_H

#include "Media.h"
namespace sdds {
    class Video : public Media {
    private:
        int length;

    protected:
        int get() const;

    public:
        //Default Constructor
        Video();
      ~Video();
        //Single Parameter Constructor
        explicit Video(int len);

        //Deleted Actions
        Video(const Video&) = delete;
        Video& operator=(const Video&) = delete;

        //Pure virtual 'load' function
        void load(std::istream& ist) override;
    };
}
#endif // VIDEO_H
