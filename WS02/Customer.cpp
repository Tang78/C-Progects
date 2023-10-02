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

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include "Customer.h"
#include "Tools.h"

using namespace std;

namespace sdds {

    // complete
     //Reads the entire input buffer as long as it does not start with '\n', if not ignores it in full
    void read(char* str, int len) {  // Fully provided
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        cin.getline(str, len);
    }

    //This function will set all members of customer to empty states
    void EmptyRecord(Customers& customers) {
        customers.user_name[0] = '\0';
        customers.likes_count = 0;
        customers.retweets_count = 0;
        customers.replies_count = 0;
        customers.share_videos = 0;
    }

    
    void EmptyRecord(CustomersRecord& cr) {//This function will set all members of customerRecords to empty states
        cr.ptr_rec = nullptr;
        cr.noOfRecords = 0;
    }

   

    //Reads the inputs for populating an instance of a Customer struct
    //This function returns false if the name arguement is provided with '\n' input
    bool read(Customers& rec)
    {
        string name;
        cout << " Enter User name: ";
        getline(cin, name);
        strCpy(rec.user_name, name.c_str());

        if (rec.user_name[0]) {

            cout << " Enter likes_count: ";
            cin >> rec.likes_count;
             cin.ignore(90, '\n');

            cout << " Enter retweets_count: ";
            cin >> rec.retweets_count;
            cin.ignore(90, '\n');

            cout << " Enter replies_count: ";
            cin >> rec.replies_count;
           cin.ignore(90, '\n');

            cout << " Enter share videos (y/n): ";
            cin >> rec.share_videos;
            cin.ignore(90, '\n');

            return true;
        }
        return false;
    }

    // complete
    //Add customer to the CustomersRecord instance
    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec) {
        //dynamically allocate memory for a new customer record 
        Customers* records = new Customers[t_rec.noOfRecords + 1];

        // The for loop will copy the existing customer records to the new memory
        for (int i = 0; i < t_rec.noOfRecords; i++) {
            records[i] = t_rec.ptr_rec[i];
        }

        // Add the new customer record to the end of the list
        records[t_rec.noOfRecords] = c_rec;

        // deallocate  memory and update the pointer to new memory
        delete[] t_rec.ptr_rec;
        t_rec.ptr_rec = records;

        // Update the number of records
        t_rec.noOfRecords++;
    }

    //This function will displays a single Customer instance's data
    void display(const Customers& c_rec) {
        cout << c_rec.user_name << ", " << c_rec.likes_count << ", " << c_rec.retweets_count << ", " << c_rec.replies_count
            << ", " << c_rec.share_videos << " (y/n)\n" << endl;
    }

    //This function will display all records of the said inputted Customers
    void display(const CustomersRecord& t_rec) {

        for (int i = 0; i < t_rec.noOfRecords; i++)
        {
            Customers person = t_rec.ptr_rec[i];
            cout << i + 1 << ". " << person.user_name << ", " << person.likes_count << ", " <<
                person.retweets_count << ", " << person.replies_count << ", " <<
                person.share_videos << "\n" << endl;

        }

    }
}
