#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Toys.h"
 namespace sdds
{
int i=1;
int j=0;
     Toys::Toys() {//default constructor
         m_tName[0] = '\0';
         m_sku = 0;
         m_price = 0.0;
         m_age = 0;
         m_onsale = false;
     }
     void Toys::addToys(const char* tname, int sku, double price, int age) {//this method will set the received values to the appropriate data members. 
         //Otherwise will be set to an empty state.
  if (tname && strlen(tname) > 0 && sku >= 10000000 && sku<=99999999 && price >= 0 && age >0)
  {
        strcpy(m_tName, tname);
         m_sku = sku;
        m_price = price;
          m_age = age;
     }
      else {
        m_tName[0] = '\0';
       m_sku = 0;
       m_price = 0.0;
       m_age = 0;
       m_onsale = false;
            }
        }

 void Toys::isSale(bool sale) {//It will assign the received value to the data member m_onSale.
            m_onsale = sale;
        }

 void Toys::calSale() {//It will decrease the toys price to 20% then the original price.

            m_price = m_price * 0.8;
            m_onsale = true;
        }

 void Toys::display() const {
   //if a toy is valid it will print out the following 
   if (m_tName[0] != '\0') {
    j+=1;
    if(j>6){
     j=1;}
 std::cout<<"Toy["
   <<j
 <<"] :"
 << std::left << std::setw(15) << m_tName
   << std::right << std::setw(10) << m_sku
    << std::right << std::setw(6) << m_age
   << std::fixed << std::setprecision(2) << std::right << std::setw(12) << m_price;
  if (m_onsale) {// this is to display if a toy is on sale or not .The value true will mean it is on sale and hence will be displayed
  std::cout << std::right << std::setw(11) <<" On Sale "<<std::endl;
    }
    else {
       std::cout << std::right << std::setw(8) << "  " << std::endl;
      }
  }

      else {
  std::cout << "Toy[";
  std::cout<<i;
  std::cout<<"] :Invalid Toy" << std::endl;
            }
i+=1;
	}
   int Toys::GETSKU()//this function helps us use m_sku in the function find 
 {
     return m_sku;
 }
}
