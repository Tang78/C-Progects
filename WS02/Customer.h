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



#ifndef SDDS_CUSTOMER_H_
#define SDDS_CUSTOMER_H_

namespace sdds {

    struct Customers {
        char user_name[21];
        int retweets_count;;
        int likes_count;
        int replies_count;
        char share_videos;
    };

    struct CustomersRecord {
        Customers* ptr_rec;  // Dynamically holds the customers' tweets' report.
        int noOfRecords;
    };
    void addCustomer(CustomersRecord& t_rec, const Customers& c_rec);
        void EmptyRecord(Customers& customers);
    void EmptyRecord(CustomersRecord& customerr);
    bool read(Customers& rec);
    void display(const Customers& c_rec);
    void display(const CustomersRecord& t_rec);







       
    void read(char* str, int len);
   
    // to be completed





              
}

#endif 
