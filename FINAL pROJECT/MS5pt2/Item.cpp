/*
*****************************************************************************
<assessment name example: Milestone - #1 >
Full Name : ORANG TANG ENOW
Student ID#: 149924219
Email : otang-enow@mysenca.ca
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.

******************************************************************************


*/

#define _CRT_SECURE_NO_WARNINGS
#include "Item.h"
#include "Error.h"
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;
namespace sdds {

    // Default Constructor
    // Item::Item() {
    //     sku[0] = '\0';
    //     name = nullptr;
    //     price = 0;
    //     taxed = false;
    //     Quantity = 0;
    //     displaytype = 0;
    // }


     Item::Item() {
        sku[0] = '\0';
        name = new char[1];
        name[0] = '\0';
        price = 0;
        taxed = false;
        Quantity = 0;
        displaytype = 0;
    
    }

    bool Item:: iserror() const {
        return errorstate;
    }
    Item& Item::operator=(const Item& other) {//Reduces the quantity by the right-hand value and returns the quantity. If the value is more than the quantity then the quantity will be set to zero and the Item error will be set to ERROR_POS_STOC
        if (this == &other) {
            return *this; 
        }
        strncpy(sku, other.sku, MAX_SKU_LEN);
        sku[MAX_SKU_LEN] = '\0';
        delete[] name;
      if (other.name != nullptr) {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }
        else {
            name = nullptr;
        }
        price = other.price;
        taxed = other.taxed;
        Quantity = other.Quantity;
        displaytype = other.displaytype;
        errorstate = other.errorstate;
        return *this;
    }
    Item::Item(const Item& other) {//
        *this = other;
    }

const char* Item::getname() const {
    return name;
}
    Item::~Item() {// default destructor 
        delete[] name;
        name = nullptr;
    }

    

    bool Item::operator>(const Item& other) const {//Compares two items alphabetically based on their names.
        return (strcmp(name, other.name) > 0);
    }

    int Item::operator+=(int value) {//Adds an integer value (right-hand operand) to the quantity and returns the quantity. If the sum of the value and the quantity exceeds the MAX_STOCK_NUMBER then the quantity 
    //will be set to MAX_STOCK_NUMBER and the Item error will be set to ERROR_POS_QTY.
        int newquantity = Quantity + value;
        return (newquantity > MAX_STOCK_NUMBER) ? MAX_STOCK_NUMBER : newquantity;
    }
    bool Item::operator==(const Item& other) const {
        return (itemType() == other.itemType()) && (strcmp(getsku(), other.getsku()) == 0);
    }

    bool Item::operator==(const char* sku) const {//Compares an Item to a C-string and returns true if the C-sting is a match to the SKU code of the Item.
        return (strcmp(getsku(), sku) == 0) && (itemType() == 'T');
    }
    int Item::operator-=(int value) {//Reduces the quantity by the right-hand value and returns the quantity. If the value is more than the quantity then the quantity will be set to zero and the Item error will be set to ERROR_POS_STOCK.
        int newquantity = Quantity - value + 1;
        return (newquantity < 0) ? 0 : newquantity;
    }

    Item::operator bool() const {//Returns the opposite of the status of the error attribute. This method does not modify the object.
        return !errorstate;
    }

    double& operator+=(double& left, const Item& right) {
        left += right.cost() * right.quantity();
        return left;
    }

    Item& Item::displayType(int value) {
        displaytype = value;
        return *this;
    }

    // double Item::cost() const {
    //     return taxed ? price * 1.13 : price;
    // }

    double Item::getPrice() const {
    return price;
}


 int Item::quantity(int newQuantity) {
    if (newQuantity != -1) {
        Quantity = newQuantity;
    }
    return Quantity;
 };


    double Item::cost() const {
    return price * (1 + taxed * TAX);
}



bool Item::isTaxed() const {
    return taxed;
}

    int Item::quantity() const {
        return Quantity;
    }
    char Item::itemType() const {
        return 'I';
    }

    Item& Item::clear() {
        errorstate.clear();
        return *this;
    }
    std::ifstream& Item::load(std::ifstream& ifstr)
    {
        errorstate.clear();
        char inputsku[257];
        char inputname[257];
        double inputprice;
        int inputIstaxed;
        int inputqty;

        ifstr.get(inputsku, 257, ','); 
        ifstr.get();
        ifstr.get(inputname, 257, ','); 
        ifstr.get();
        ifstr >> inputprice; 
        ifstr.get();
        ifstr >> inputIstaxed; 
        ifstr.get();
        ifstr >> inputqty;
      if (!ifstr.fail()) 
      {
          
     if (strlen(inputsku) > MAX_SKU_LEN)
     {
            errorstate = ERROR_POS_SKU;
        }
        else {
            if(strlen(inputname) > MAX_NAME_LEN) 
            {
            errorstate = ERROR_POS_NAME;
        }
        else 
        {
            if (inputprice < 0) {
                
            errorstate = ERROR_POS_PRICE;
        }
        else 
        {
        if (inputIstaxed != 0 && inputIstaxed != 1) 
        {
            errorstate = ERROR_POS_TAX;
        }
        else 
        {if (inputqty > MAX_STOCK_NUMBER) 
        {
            errorstate = ERROR_POS_QTY;
        }
        else {
            delete[] name;
            strcpy(sku, inputsku);
            name = new char[strlen(inputname) + 1];
            strcpy(name, inputname);
            price = inputprice;
            taxed = inputIstaxed;
            Quantity = inputqty;
        }
        }
        }
        }
            
        }
      }
        return ifstr;
    }


void Item::displayInPOS() const {
    cout << "=============v" << endl;
    cout << "Name:        " << getname() << endl;
    cout << "Sku:         " << getsku() << endl;
    cout << "Price:       " << fixed << setprecision(2) << getPrice() << endl;
    cout << "Price + tax: ";
    if (isTaxed()) {
        cout << fixed << setprecision(2) << cost() << endl;
    } else {
        cout << "N/A" << endl;
    }
    cout << "Stock Qty:   " << quantity() << endl;
    // If you have an expiry date, display it here
    cout << "=============^" << endl;
}



std::ostream& Item::write(std::ostream& os) const {
    if (displaytype == sdds::POS_LIST) {
        // Output item information in the POS_LIST format
       // os << "   " << 1 << " | ";
        os << setfill(' ')<<setw(6) << left << sku << " |";
        os << setfill(' ')<<setw(18) << left << name << "  | ";
        os <<  setfill(' ')<<setw(6) << right<< fixed << setprecision(2) << price << "|";
        os <<(taxed ? " X " : "   ") << "| ";
        os <<  setfill(' ')<<setw(3) << right << Quantity << "| ";
        os <<  setfill(' ')<<setw(8) << fixed << setprecision(2) << cost() * Quantity << "| ";
    } else if (displaytype == sdds::POS_FORM) {
        os << "=============v" << std::endl;
                os << "Name:        " << name << std::endl;
                os << "Sku:         " << sku << std::endl;
                os << "Price:       " << std::fixed << std::setprecision(2) << price << std::endl;
                os << "Price + tax: ";
                if (taxed) {
                    os << std::fixed << std::setprecision(2) << cost();
                }
                else {
                    os << "N/A";
                }
                os << endl;
                os << "Stock Qty:   " << Quantity << endl;
        // Output item information in the POS_FORM format
        // Update this section to match the desired output format for POS_FORM
    } else {
        os << errorstate;
        // Handle any other display types or default output format
    }
     os.unsetf(ios::fixed);
        os.unsetf(ios::right);
    return os;
}

 const char* Item::getsku() const {
        return sku;
    }

    std::istream& Item::read(std::istream& istr) {
        char skuInput[100];
        char nameInput[100];
        double priceInput;
        char taxInput;
        int quantityInput;

        bool skuError, nameError, priceError, taxError, qtyError;
        cout << "Sku\n> ";
        do {
           istr.getline(skuInput, 100);
            skuError = istr.fail() || strlen(skuInput) > MAX_SKU_LEN;
            if (skuError) {
                cout << "SKU too long" << "\n> ";
            }
        } while (skuError);

        cout << "Name\n> ";
        do {
            istr.getline(nameInput, MAX_NAME_LEN);
            nameError = istr.fail() || strlen(nameInput) > MAX_NAME_LEN;
            if (nameError) {
                istr.clear();
                istr.ignore(1000, '\n');
                cout << "Item name too long" << "\n> ";
            }
        } while (nameError);

        cout << "Price\n> ";
        do {
            istr >> priceInput;
            priceError = istr.fail() || priceInput < 0;
            if (priceError) {
                istr.clear();
                istr.ignore(1000, '\n');
                //cout << "Invalid price value" << "\n> ";
            }
        } while (priceError);

        cout << "Taxed?\n(Y)es/(N)o: ";
        do {
            istr >> taxInput;
            const bool isTaxInputValid = (taxInput == 'Y' || taxInput == 'y' || taxInput == 'N' || taxInput == 'n');
            taxError = istr.fail() || !isTaxInputValid;
            if (taxError) {
                istr.clear();
                istr.ignore(1000, '\n');
                cout << "Only 'y' and 'n' are acceptable: ";
            }
        } while (taxError);
        istr.ignore(1000, '\n');

        cout << "Quantity\n> ";
        do {
            istr >> quantityInput;
            qtyError = istr.fail() || quantityInput <= 0 || quantityInput >= MAX_STOCK_NUMBER;
            if (qtyError) {
                istr.clear();
                istr.ignore(1000, '\n');
                cout << "Invalid quantity value" << "\n> ";
            }
        } 
        while (qtyError);
        istr.ignore(1000, '\n');
        strcpy(sku, skuInput);
        delete[]  name;
        name = new char[strlen(nameInput) + 1];
        strcpy(name, nameInput);
        price = priceInput;
        taxed = (taxInput == 'Y' || taxInput == 'y');
        Quantity = quantityInput;
        return istr;
    }
void Item::setQuantity(int qty) {
    Quantity = qty;
}
    std::ofstream& Item::save(std::ofstream& ofstr) const {
        if (!(*this)) {
            std::cerr << errorstate << std::endl;
        }
        else {
            ofstr << itemType() << ',' << sku << ',' << name << ',' << std::fixed << std::setprecision(2) << price << ',' << (taxed ? '1' : '0') << ',' << Quantity ;
            ofstr.unsetf(ios::fixed);
            ofstr.unsetf(ios::right);
            
        }
       return ofstr;
    }

    

    std::ostream& Item::bprint(std::ostream& ostr) const {

        char formattedName[21];
        strncpy(formattedName, name, 20);
        formattedName[20] = '\0';
        ostr << "| " << std::left << std::setw(20) << formattedName << "|" << std::right << std::setw(10) << std::fixed << std::setprecision(2) << cost() << " | " << (taxed ? " T " : "   ") << " |" << endl;
        ostr.unsetf(ios::fixed);
        ostr.unsetf(ios::right);
        return ostr;
    }

}
