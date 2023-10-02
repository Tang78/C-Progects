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


#ifndef SDDS_PosApp_H__
#define SDDS_PosApp_H__

#include "POS.h"
#include "PosIO.h"
#include "Item.h"
#include "Perishable.h"
#include "NonPerishable.h"
#include <cstring>

namespace sdds
{
class PosApp {
public:
    PosApp(const char* filename);
    void run();
    ~PosApp();

        int findItemIndexBySku(const char* sku) const;
private:
    char m_filename[128];
    Item* m_items[MAX_NO_ITEMS];
    int m_noOfItems;

    void printActionTitle(const std::string& title);

    int menu();
    void addItem();
    void removeItem();
    void stockItem();
    void listItems();
    void POS();
    void saveRecs();
    void loadRecs();
};
}

#endif
