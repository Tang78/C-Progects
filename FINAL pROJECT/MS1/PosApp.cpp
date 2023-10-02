#include <iostream>
#include <stdexcept>
#include "PosApp.h"
using namespace std;
namespace sdds{

PosApp::PosApp(std::string filename) : filename(filename) {}//Constructor

void PosApp::run() {//This method first loads all the records and then displays the menu waiting for the user to make the selection. 
//After the (foolproof) selection the proper action is executed and again the menu is displayed until the option exit is selected.
    bool done = false;
    cout<<">>>> Loading Items"
      <<"...........................................................\n"
     <<"Loading data from datafile.csv\n";
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
                cout << "Saving data in datafile.csv" << endl;
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
             << "5- Point of Sale\n"
             << "0- exit program\n"
             << "> ";
    int choice = -1;
    bool valid = false;
    while (!valid) {
    
        string input;
        getline(cin, input);
        try {
            choice = stoi(input);
            if (choice >= 0 && choice <= 5) {
                valid = true;
            } else {
                cout << "[" << "0<=value<=5" << "], retry: > ";
            }
        } catch (invalid_argument e) {
            cout << "Invalid Integer, try again: ";
        }
    }
    return choice;
}


void PosApp::addItem() {//Adding Item to the store
    std::cout << ">>>> Adding Item to the store"
    <<"................................................\n"
    << "Running addItem()" << std::endl;
}

void PosApp::removeItem() {//Remove Item
       std::cout << ">>>> Remove Item"
       <<".............................................................\n"
      <<"Running removeItem()" << std::endl;
}

void PosApp::stockItem() {//Select an Item to stock
        std::cout << ">>>> Select an item to stock"
<<".................................................\n"
    << "Running stockItem()" << std::endl;
}

void PosApp::listItems() {//Listing Items
        std::cout << ">>>> Listing Items"
<<"...........................................................\n"
    << "Running listItems()" << std::endl;
}

void PosApp::POS() {//Starting Point of Sale
    std::cout<<">>>> Starting Point of Sale"
<<"..................................................\n"
    << "Running POS()" << std::endl;
}

}
