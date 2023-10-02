#define _CRT_SECURE_NO_WARNINGS
#include "Item.h"
#include "Error.h"
#include <cstring>
#include <iomanip>
using namespace std;
namespace sdds {

    // Default Constructor
    Item::Item() {
        sku[0] = '\0';
        name = nullptr;
        price = 0;
        taxed = false;
        Quantity = 0;
        displaytype = 0;
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

    double Item::cost() const {
        return taxed ? price * 1.13 : price;
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

        ifstr.get(inputsku, 257, ','); ifstr.get();
        ifstr.get(inputname, 257, ','); ifstr.get();
        ifstr >> inputprice; ifstr.get();
        ifstr >> inputIstaxed; ifstr.get();
        ifstr >> inputqty;
      if (ifstr.fail()) return ifstr;
     if (strlen(inputsku) > MAX_SKU_LEN) {
            errorstate = ERROR_POS_SKU;
        }
        else if (strlen(inputname) > MAX_NAME_LEN) {
            errorstate = ERROR_POS_NAME;
        }
        else if (inputprice < 1.0) {
            errorstate = ERROR_POS_PRICE;
        }
        else if (inputIstaxed != 0 && inputIstaxed != 1) {
            errorstate = ERROR_POS_TAX;
        }
        else if (inputqty > MAX_STOCK_NUMBER) {
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
        return ifstr;
    }

    std::ostream& Item::write(std::ostream& ostr) const {
        if (displaytype == POS_LIST) {
            if (!errorstate) {
                char temp[21];
                int length = strlen(name);
                if (length <= 20) {
                    strcpy(temp, name);
                }
                else {
                    strncpy(temp, name, 17);
                    temp[17] = name[17];
                    temp[18] = name[18];
                    temp[19] = name[19];
                    temp[20] = '\0';
                }
                ostr << std::left << std::setw(MAX_SKU_LEN) << sku << "|"
                    << std::setw(20) << std::left << temp << "| "
                    << std::setw(6) << std::fixed << std::setprecision(2) << std::right << price << "|"
                    << std::setw(2) << (taxed ? "X" : "") << " |"
                    << std::setw(4) << std::right << Quantity << "|"
                    << std::setw(9) << std::right << std::setprecision(2) << std::right << cost() * Quantity << "|";
            }
            else { ostr << errorstate; }
        }
        else if (displaytype == POS_FORM) {
            if (!errorstate) {
                char temp[21];
                strncpy(temp, name, 20);
                temp[20] = '\0';

                ostr << "=============v" << std::endl;
                ostr << "Name:        " << temp << std::endl;
                ostr << "Sku:         " << sku << std::endl;
                ostr << "Price:       " << std::fixed << std::setprecision(2) << price << std::endl;
                ostr << "Price + tax: ";
                if (taxed) {
                    ostr << std::fixed << std::setprecision(2) << cost();
                }
                else {
                    ostr << "N/A";
                }
                ostr << endl;
                ostr << "Stock Qty:   " << Quantity << endl;
            }
            else { ostr << errorstate; }
        }        return ostr;
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
                cout << "Invalid price value" << "\n> ";
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

    std::ofstream& Item::save(std::ofstream& ofstr) const {
        if (!(*this)) {
            std::cerr << errorstate << std::endl;
        }
        else {
            ofstr << itemType() << ',' << sku << ',' << name << ',' << std::fixed << std::setprecision(2) << price << ',' << (taxed ? '1' : '0') << ',' << Quantity - 1;
        }

        return ofstr;
    }

    

    std::ostream& Item::bprint(std::ostream& ostr) const {

        char formattedName[21];
        strncpy(formattedName, name, 20);
        formattedName[20] = '\0';

        ostr << "| " << std::left << std::setw(20) << formattedName << "|" << std::right << std::setw(10) << std::fixed << std::setprecision(2) << cost() << " | " << (taxed ? " T " : "   ") << " |" << endl;
        return ostr;
    }

}
