
//#include <iostream>
//I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
 //name ::oRANG tANG eNOW , 
//your Seneca email OTANG-ENOW@MYSENECA.CA
//, Seneca Student ID= 149924219
//and the date:2023-03-07
#ifndef SDDS_NUMBERS_H_
#define SDDS_NUMBERS_H_
#include <iostream>
#include<cstring>

#define MAX_STR 256

namespace sdds
{
    class Numbers
    {//THIS ARE THE PRIVATE ATTRIBUTES AND MEMBER FUNCTIONS OF THE CLASS
        unsigned int collection_size;
        double* Collection;
        char file_name[MAX_STR];
        bool original_flag;
        bool added_flag;
        unsigned int countLines(const char* filename);
        void sort(double* collectionPtr, unsigned int size);
        void  setEmpty();
        bool load();
        void save();
        double max()const;
        double min()const;
        double average()const;

    public:
        Numbers();
        Numbers(const char* fname);
        ~Numbers();
        Numbers(const Numbers& other);
        Numbers& operator=(const Numbers& other);
        operator bool() const;
        void sort();
        Numbers& operator +=(const double num);
        std::ostream& display(std::ostream& ostr = std::cout) const;

    };//HELPER FUNCTIONS 
    std::ostream& operator<<(std::ostream& ostr, const Numbers& numbers);
    std::istream& operator>>(std::istream& istr, Numbers& numbers);
}
#endif
