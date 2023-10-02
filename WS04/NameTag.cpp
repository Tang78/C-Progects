/**********************************************
                        Workshop 4 
Full Name  : Orang Tang Enow 
Student ID#: 149924219
Email      : otang-enow@myseneca.ca
Section    : NDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <limits>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstring>
#include "NameTag.h"

using namespace std;

namespace sdds
{
    //default constructor (for an empty tag)
    NameTag::NameTag()
    {
        setEmpty();
    }

    //This function will set the variablesof the class Nametag to empty state
    void NameTag::setEmpty()
    {
        name = nullptr;
        extension = 0;
    }


    //Overloaded constructor that receives the name
    NameTag::NameTag(const char* n)
    {
        //this will check if the value of n is empty 
        if (n != nullptr && n[0] != '\0')
        {
            std::string inputString = n;
            std::string::size_type inputStringLength = inputString.size();//find the lenght of output 
            if (inputStringLength > 40)
            {
                inputString = inputString.substr(0, 40);
            }
            name = new char[inputStringLength + 1];//update the values 
            strcpy(name, inputString.c_str());
            name[inputStringLength] = '\0';
            extension = -1;
        }
        else {
            setEmpty();
        }
    }

    //constructor with two arguments to set the name and the extension
    NameTag::NameTag(const char* n, int ext) : name(nullptr), extension(0)
    {
        if (n != nullptr)
        {
            name = new char[strlen(n) + 1];
            strcpy(name, n);

            extension = ext;
        }
        else {
            setEmpty();
        }
    }



    //This is the destructor of the function 
    NameTag::~NameTag()
    {
        delete[] name;
    }

    //Method to read the inputs for overwriting the said nametag instance
    NameTag& NameTag::read()
    {
        std::string n;
        std::cout << "Please enter the name: ";
        std::getline(std::cin, n);

        if (n.length() > 40) {
            n = n.substr(0, 40);
        }
        delete[] name;
        name = new char[n.length() + 1];
        strcpy(name, n.c_str());
        this->name[n.length()] = '\0';
        char extensionopt;
        std::cout << "Would you like to enter an extension? (Y)es/(N)o: ";
        do {
            std::cin >> extensionopt;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (tolower(extensionopt) != 'y' && tolower(extensionopt) != 'n')
            {
                std::cout << "Only (Y) or (N) are acceptable, try agin: ";
            }
        } while (tolower(extensionopt) != 'y' && tolower(extensionopt) != 'n');
        int extension = 0;
        if (tolower(extensionopt) == 'n')
        {
            extension = -1;
        }
        else if (tolower(extensionopt) == 'y')
        {
            std::string value;
            bool validExtension = false;
            std::cout << "Please enter a 5 digit phone extension: ";

            while (!validExtension)
            {
                std::cin >> value;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::stringstream stream(value);
                if (stream >> extension && stream.eof()) {
                    if (extension >= 10000 && extension <= 99999) {
                        validExtension = true;
                    }
                    else {
                        std::cout << "Invalid value [10000<=value<=99999]: ";
                    }
                }
                else {
                    std::cout << "Bad integer value, try again: ";
                }
            }
        }
        this->extension = extension;

        return *this;
    }


    //a function called print to print the name tag 
    std::ostream& NameTag::print() const
    {
        if (name != nullptr && (extension == -1 || (extension >= 10000 && extension <= 99999)))
        {
            int width = strlen(name) > 20 ? 42 : 22;
            cout << "+";
            for (int i = 0; i < width; i++) 
            {
                cout << "-";
            }
            cout << "+" << endl;

            cout << "|";
            for (int i = 0; i < width; i++) {
                cout << " ";
            }
            cout << "|" << endl;
            cout << "| " << setw(width - 1) << left << name << "|" << endl;

            cout << "|";
            for (int i = 0; i < width; i++) 
            {
                cout << " ";
            }
            cout << "|" << endl;
            cout << "| Extension: ";


            if (extension == -1)
            {
                cout << "N/A";

            }
            else
            {
                cout << extension;
            }

            string countExtension = std::to_string(extension);
            if (extension != -1)
            {
                for (int i = 0; i < (int)(width - 12 - countExtension.size()); i++)
                {
                    cout << " ";
                }
            }

            else {

                for (int i = 0; i < (int)(width - 12 - 3); i++) {
                    cout << " ";
                }

            }
            cout << "|" << endl;

            cout << "|";
            for (int i = 0; i < width; i++)
            {
                cout << " ";
            }
            cout << "|" << endl;

            cout << "+";
            for (int i = 0; i < width; i++) 
            {
                cout << "-";
            }
            cout << "+" << endl;

        }
        else {
            cout << "EMPTY NAMETAG!" << endl;
        }
        return cout;

    }

}
