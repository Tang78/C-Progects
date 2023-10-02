/*
*****************************************************************************
                        Workshop 2 - Part 2
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

// Please don't change this file
// This file is to test your source code

#include <iostream>
#include "Customer.h"
using namespace std;
using namespace sdds;

int main() {
    bool Check = false;

    Customers c_rec;
    EmptyRecord(c_rec);

    CustomersRecord t_rec;
    EmptyRecord(t_rec);

    cout << "---------  Customers records entry ------------------" << endl;
    while (!Check) {
        cout << endl<<"Enter customer information (to exit, press Enter): " << endl;
        if (read(c_rec)) {
            addCustomer(t_rec, c_rec);
        }
        else {
            Check = true;
        }
    }
    cout << "---------------------------------------------------------" << endl;
    cout << "                Users' tweets report                     " << endl;
    cout << " user name, likes, re-tweets, replies, share videos (y/n)" << endl;
    cout << "---------------------------------------------------------" << endl;

    display(t_rec);
    cout << "---------------------------------------------------------" << endl;
    cout << "            Report was successfully created                " << endl;

    delete[] t_rec.ptr_rec;
    cout << "Dynamically allocated memory was successfully deallocated" << endl;
    cout << "---------------------------------------------------------" << endl;

    }




