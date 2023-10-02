
/*
*****************************************************************************
                        Workshop 4 - 
Full Name  : Orang Tang Enow
Student ID#: 149924219
Email      : otang-enow@myseneca.ca
Section    : ndd

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/
#ifndef NAMETAG_H
#define NAMETAG_H

namespace sdds
{
    class NameTag 
    {
        char* name; //std::string name;//dynamic array/dynamic sequence to store the name 
        int extension; //five-digit extension number

    public:
        void setEmpty();
        NameTag();
        NameTag(const char* inputName);
        NameTag(const char* inputName, int ext);
        ~NameTag();
        std::ostream& print() const;
        NameTag& read();
    };
}
#endif // !NAMETAG_H
