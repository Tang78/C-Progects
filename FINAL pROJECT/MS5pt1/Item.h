/*
*****************************************************************************
Full Name : Orang Tang Enow 
Student ID#: 149924219
Email : otang-enow@myseneca.ca
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.

******************************************************************************


*/

#define _CRT_SECURE_NO_WARNINGS



#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H

#include <iostream>
#include <fstream>
#include "Error.h"
#include "PosIO.h"
#include "POS.h"
namespace sdds {
    class Item : public PosIO {
    public:
        char sku[MAX_SKU_LEN + 1];//A C-string to keep an SKU code up to MAX_SKU_LEN characters.
        char* name;//A dynamically allocated C-string to keep the name of the Item up to MAX_NAME_LEN characters.
        double price;//A double value
        bool taxed;//A boolean that indicates if the Item is taxable or not.
        int Quantity;//An integer value for the stock number of the Item. (number of items in the shop)
        int displaytype;//An integer flag that can be either POS_LIST to display the Item in List mode or POS_FORM to display the Item in Form mode.
        Error errorstate;//An Error object to keep the error status of the Item.
       
     int quantity(int newQuantity = -1);

        double cost() const;
        Item();
        Item(const Item& other);
        
        Item& operator=(const Item& other);
        ~Item();

        bool operator==(const Item& other) const;
        bool  operator>(const Item& other) const;
        bool operator==(const char* sku) const;

  int DisplayType() const{
    return displaytype;
 }
        int operator+=(int value);
        int operator-=(int value);
        operator bool() const;

        virtual char itemType() const;
         bool iserror() const;
        Item& displayType(int value);

        int quantity() const;
        Item& clear();
        const char* getsku() const;
        const char* getname() const;
        std::ostream& write(std::ostream& ostr) const ;
        std::istream& read(std::istream& istr) ;
        std::ofstream& save(std::ofstream& ofstr) const ;
        std::ifstream& load(std::ifstream& ifstr) ;

        std::ostream& bprint(std::ostream& ostr) const;
    };
    double& operator+=(double& totalCost, const Item& item);
}


#endif // ITEM_H
