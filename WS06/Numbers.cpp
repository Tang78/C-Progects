#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Numbers.h"

using namespace std;

namespace sdds {
    //Sort method (implemented)
    void Numbers::sort(double* nums, unsigned int size) {
        unsigned int i, j;
        double temp;
        for (i = size - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (nums[j] > nums[j + 1]) {
                    temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
    }

    //Sets all attributes to null, zero, false or empty Cstring.
    void Numbers::setEmpty()
    {
        Collection = nullptr;
        file_name[0] = '\0';
        collection_size = 0;
        original_flag = false;
        added_flag = false;
    }

    //Method to read file and update the corresponding attributes
    bool Numbers::load()
    {
        //Declare variables
        unsigned int i = 0, x = countLines(file_name);

        //Proceed if the file is not empty and has valid content
        if (x > 0u)
        {
            //Set m_numbers's size to the number of lines in the file
            Collection = new double[x];
            ifstream inFile(file_name);
            //Feed the file content to the ith element in the array
            while (inFile)
            {
                inFile >> Collection[i];
                if (inFile)
                {
                    i++;
                }
            }
            if (i != x)// if the number of lines in the file is not equal to the number of values in the collection
            {
                delete[] Collection;
                setEmpty();
            }
            else //Otherwise further update the class member properties
            {
                collection_size = x;
                original_flag = true;
            }
        }
        return Collection != nullptr;
    }

    //Overwrite the original file with the new values
    void Numbers::save()
    {
        if (original_flag && added_flag)
        {
            ofstream outFile(file_name);
            outFile.precision(2);
            for (unsigned int i = 0; i < collection_size; i++)
            {
                outFile << fixed << setprecision(2);
                outFile << Collection[i] << endl;
            }
        }
    }

    //Returns the largest double number in the **Collection**
    double Numbers::max() const
    {
        double maxValue = Collection[0];
        for (unsigned int i = 1; i < collection_size; i++)
        {
            if (Collection[i] > maxValue)
            {
                maxValue = Collection[i];
            }
        }
        return maxValue;
    }

    //    Returns the smallest double number in the** Collection**
    double Numbers::min() const
    {
        double minValue = Collection[0];
        for (unsigned int i = 1; i < collection_size; i++)
        {
            if (Collection[i] < minValue)
            {
                minValue = Collection[i];
            }
        }
        return minValue;
    }

    //Returns the average of the double numbers in the **Collection**
    double Numbers::average() const
    {
        double sum = 0.0;
        for (unsigned int i = 0; i < collection_size; i++)
        {
            sum += Collection[i];
        }
        return (collection_size > 0) ? (sum / collection_size) : 0.0;
    }

    //One argument constructor
    Numbers::Numbers(const char* fname)
    {
        setEmpty();
        strncpy(file_name, fname, 256);
        file_name[255] = '\0'; // add null terminator to ensure string is properly terminated
        load();
    }

    //Default constructor
    Numbers::Numbers()
    {
        setEmpty();
    }

    //Returns true if the **Numbers** object is in a good state (not empty) and false if it is not
    Numbers::operator bool() const
    {
        return Collection != nullptr;
    }

    //Calls the private sort method from the publicly accessible method
    void Numbers::sort()
    {
        sort(Collection, collection_size);
    }

    //Copy constructor
    Numbers::Numbers(const Numbers& other)
    {
        setEmpty();
        *this = other;
    }

    //Copy Assignment Operator
    Numbers& Numbers::operator=(const Numbers& other)
    {
        //Follow copy procedure

        if (this != &other) {

            // Save the original data
            save();

            // Delete the current Collection
            delete[] Collection;

            // Set the current object to the empty state
            setEmpty();

            // Copy from the other object if it's not empty
            if (other) {
                // Allocate memory for the Collection
                Collection = new double[other.collection_size];

                // Copy the double values
                for (unsigned int i = 0; i < other.collection_size; i++) {
                    Collection[i] = other.Collection[i];
                }

                // Update the Collection size and flags
                std::strcpy(file_name, other.file_name);
                collection_size = other.collection_size;
                original_flag = false;
                added_flag = false;
            }
        }
        // Return the reference to the current object
        return *this;
    }

    //Overload the += operator to add a single double value to the list of numbers in the array and then return the reference of the current object
    //Given that the current object is not empty
    Numbers& Numbers::operator+=(double value)
    {/*
        if (m_numbers != nullptr) */
        if (*this) {
            double* temp = new double[collection_size + 1];
            std::memcpy(temp, Collection, collection_size * sizeof(double));
            delete[] Collection;
            Collection = temp;
            temp[collection_size] = value;
            collection_size++;
            added_flag = true;
        }
        return *this;
    }

    //Destructor
    Numbers::~Numbers()
    {
        save();
        delete[] Collection;
    }

    //Method to count the number of lines in a file (implemented)
    unsigned int Numbers::countLines(const char* filename) { /**/
        unsigned int lines = 0u;
        ifstream nums(filename);
        while (nums) {
            lines += (nums.get() == '\n');
        }
        return lines;
    }

    //Display the contents of the file in a user-friendly manner
    std::ostream& Numbers::display(std::ostream& ostr) const
    {
        if (Collection == nullptr) {
            ostr << "Empty list";
        }
        else {
            ostr << std::fixed << std::setprecision(2);
            if (!original_flag) {
                ostr << "Copy of ";
            }
            ostr << file_name << std::endl;

            // Insert the numbers in the Collection
            ostr << Collection[0];
            for (unsigned int i = 1; i < collection_size; i++) {
                ostr << ", " << Collection[i];
            }
            ostr << std::endl;

            // Insert a line of dashes
            ostr << std::setw(76) << std::setfill('-') << "" << std::endl;

            // Insert Collection information
            ostr << "Total of " << collection_size << " number(s), Largest: " << max() << ", Smallest: " << min()
                << ", Average: " << average() << std::endl;

            // Insert a line of equal signs
            ostr << std::setw(76) << std::setfill('=') << "";
            // ostr << std::setw(76) << std::setfill('=') << "" << std::endl;
        }
        return ostr;
    }

    // Input and output operator overloading
    std::ostream& operator<<(std::ostream& os, const Numbers& num) {
        return num.display(os);
    }

    std::istream& operator>>(std::istream& istr, Numbers& numbers) {
        double num;
        istr >> num;
        numbers += num;
        return istr;
    }
}