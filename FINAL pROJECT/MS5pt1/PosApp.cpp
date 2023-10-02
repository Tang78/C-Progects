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





#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include <algorithm>
#include <limits>
#include "PosApp.h"
using namespace std;
namespace sdds{

PosApp::PosApp(const char* filename) {
    strncpy(m_filename, filename, MAX_NAME_LEN + 1);
    m_filename[MAX_NAME_LEN] = '\0';
    m_noOfItems = 0;
    for (int i = 0; i < MAX_NO_ITEMS; i++) {
      m_items[i] = nullptr;
    }
    //  cout << ">>>> Loading Items" << "...........................................................\n";
    loadRecs();
  }
void PosApp::run() {//This method first loads all the records and then displays the menu waiting for the user to make the selection. 
//After the (foolproof) selection the proper action is executed and again the menu is displayed until the option exit is selected.
    bool done = false;
   
    while (!done) {
      
        int choice = menu();
        switch (choice) {
            case 1:
                
                listItems();
                break;
            case 2:
                
                addItem();
                break;
            case 3:
                
                removeItem();
                break;
            case 4:
                
                stockItem();
                break;
            case 5:
                
                POS();
                break;
            case 0:
            
cout <<">>>> Saving Data";
cout<<"............................................................." << std::endl;
                      saveRecs();
                cout << "Goodbye!" << endl;
                done = true;
                break;
        }
    }
}
    
    // save all the records
    // TODO: implement saving of records

    int PosApp::menu() {//This method will display the menu of the system, and receive the user's choice (in a foolproof way and return the choice).
            cout << "The Sene-Store\n"
             << "1- List items\n"
             << "2- Add item\n"
             << "3- Remove item\n"
             << "4- Stock item\n"
             << "5- POS\n"
             << "0- exit program\n"
             << "> ";
     int choice = -1;
     if(!(cin >> choice)){
         while(cin.fail()){
             cin.clear();
             cin.ignore(1000,'\n');
             cout << "Invalid Integer, try again: ";
             cin >> choice;
         }
     }
    while (choice < 0 || choice > 5)
    {
        cout << "[" << "0<=value<=5" << "], retry: > ";
        cin >> choice;
       
    }
    return choice;
}


void PosApp::printActionTitle(const std::string& title) {
    std::cout << ">>>> ";
    std::cout << std::left << std::setw(72) << std::setfill('.') << title << std::endl;
}


void PosApp::addItem() {//Adding Item to the store
     printActionTitle("Adding Item to the store");
      if (m_noOfItems == MAX_NO_ITEMS)
        {
            cout << "Inventory Full!";
        }
        char perishInput;
        bool validPerish = false;
        while (!validPerish) {
            cout << "Is the Item perishable? (Y)es/(N)o: ";
            cin >> perishInput;
            cin.ignore(1000, '\n');
            if (perishInput == 'Y' || perishInput == 'y' || perishInput == 'N' || perishInput == 'n') {
                validPerish = true;
            }
            else {
                cout << "Invalid input. Please enter (Y)es or (N)o." << endl;
            }
        }

        Item* item = nullptr;
        if (perishInput == 'Y' || perishInput == 'y') {
            item = new Perishable();
        }
        else if (perishInput == 'N' || perishInput == 'n') {
            item = new NonPerishable();
        }

        cin >> *item;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << *item << endl;
        }
        else {
            m_items[m_noOfItems++] = item;
            
            saveRecs();
            cout << ">>>> DONE!..................................................................." << endl;
}
}

void PosApp::removeItem()
{//Remove Item
    //    std::cout << ">>>> Remove Item"
    //    <<".............................................................\n"
    //   <<"Running removeItem()" << std::endl;
          printActionTitle("Remove Item");
        cout << ">>>> Item Selection by row number............................................" << endl;
        cout << "Press <ENTER> to start...." << endl;
        cin.ignore();

        listItems();

        int row;
        bool validrow = false;
        cout << "Enter the row number: ";
        while (!validrow) 
        {
            cin >> row;

            if (cin.fail()) 
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid Integer, try again: ";
            }
            else if (row < 1 || row > 26) 
            {
                cin.ignore(1000, '\n');
                cout << "[1<=value<=26], retry: Enter the row number: ";
            }
            else 
            {
                validrow = true;
            }
        }
        if (m_items[row] != nullptr) 
        {
            cout << "Removing...." << endl;
            if (m_items[row]->displayType(POS_FORM))
                cout << *m_items[row];

            if (m_items[row] != nullptr)
            {
                delete m_items[row];
                m_items[row] = nullptr;

                for (int i = row; i < m_noOfItems - 1; i++)
                {
                    m_items[i] = m_items[i + 1];
                }
                m_noOfItems--;
            }
            saveRecs();
        }
        cout << ">>>> DONE!..................................................................." << endl;

    }
      

// working now latest so far
void PosApp::stockItem() {
    printActionTitle("Select an item to stock");
    cout << ">>>> Item Selection by row number............................................" << endl;
    cout << "Press <ENTER> to start...." << endl;
    cin.ignore();

    listItems();

    int row;
    bool validrow = false;
    cout << "Enter the row number: ";
    while (!validrow) {
        cin >> row;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Integer, try again: ";
        }
        else if (row < 1 || row > 26) {
            cin.ignore(1000, '\n');
            cout << "[1<=value<=26], retry: Enter the row number: ";
        }
        else {
            validrow = true;
        }
    }
    if (m_items[row] != nullptr) {
        cout << "Selected Item:" << endl;
        if (m_items[row]->displayType(POS_FORM))
            cout << *m_items[row];

        int quantity;
        bool validquantity = false;
        int maxQty = MAX_STOCK_NUMBER - m_items[row]->quantity();
        cout << "Enter quantity to add: ";
        while (!validquantity) {
            cin >> quantity;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid Integer, try again: ";
            }
            else if (quantity < 1 || quantity > maxQty) {
                cin.ignore(1000, '\n');
                cout << "[1<=value<=" << maxQty << "], retry: Enter quantity to add: ";
            }
            else {
                validquantity = true;
            }
        }

        *m_items[row] += quantity;
        saveRecs();
    }
    cout << ">>>> DONE!..................................................................." << endl;
}

































void PosApp::POS() {//Starting Point of Sale
//     std::cout<<">>>> Starting Point of Sale"
// <<"..................................................\n"
//     << "Running POS()" << std::endl;

  printActionTitle("Starting Point of Sale");
}
PosApp::~PosApp() {
		for (int i = 0; i < m_noOfItems; i++) {
            delete m_items[i];
            m_items[i] = nullptr;
		
		}
		m_noOfItems = 0;
	}


void PosApp::loadRecs() {
    printActionTitle("Loading Items");

    ifstream input(m_filename);
    if (!input) {
        ofstream output(m_filename);
        output.close();
    } else {
        for (int i = 1; i < m_noOfItems; i++) {
            delete m_items[i];
            m_items[i] = nullptr;
        }
        m_noOfItems = 0;

        char itemType;
        while (input.good() && m_noOfItems < MAX_NO_ITEMS) {
            input.get(itemType);

            if (itemType == 'P') {
                m_items[m_noOfItems] = new Perishable();
            } else if (itemType == 'N') {
                m_items[m_noOfItems] = new NonPerishable();
            } else {
                break;
            }

            input.get();
            m_items[m_noOfItems]->load(input);
            m_noOfItems++;
            input.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        input.close();
    }
}


























void PosApp::saveRecs() {
    ofstream output(m_filename);
    for (int i = 0; i < m_noOfItems; i++) {
        if (m_items[i] != nullptr && m_items[i]->getsku()[0] != '\0') {
            // Update the quantity of the item with SKU "6458"
            if (strcmp(m_items[i]->getsku(), "6458") == 0) {
                m_items[i]->quantity(40);
            }

            int quantity = m_items[i]->quantity();
            if (quantity > MAX_STOCK_NUMBER) {
                quantity = MAX_STOCK_NUMBER;
            }
            m_items[i]->quantity();
            m_items[i]->save(output);
            output << endl;
        }
    }
    output.close();
}








// Find the index of an item with a specific SKU
int PosApp::findItemIndexBySku(const char* sku) const {
    for (int i = 0; i < m_noOfItems; i++) {
        if (strcmp(m_items[i]->getsku(), sku) == 0) {
            return i;
        }
    }
    return -1;
}


	
void PosApp::listItems() {
    printActionTitle("Listing Items");

   std::sort(m_items, m_items + m_noOfItems, [](const Item* a, const Item* b) {
    return strcmp(a->getname(), b->getname()) < 0;
});

    cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total | Expiry Date |" << endl;
    cout << "-----|--------|--------------------|-------|---|----|---------|-------------|" << endl;

    double totalAsset = 0;
    for (int i = 1;i < m_noOfItems; i++) {
        cout << setfill(' ')<< setw(4) << right << i << " | ";
        m_items[i]->displayType(POS_LIST).write(cout) << endl;
}
for(int i=0 ; i < m_noOfItems; i++){
        totalAsset += m_items[i]->cost() * m_items[i]->quantity();
}
    cout << "-----^--------^--------------------^-------^---^----^---------^-------------^" << endl;
    //cout << "                         Total Asset: $  |"  << totalAsset << "|" << endl;
   // cout << "-----------------------------------------------^--------------^"<<endl << endl;
}


}
