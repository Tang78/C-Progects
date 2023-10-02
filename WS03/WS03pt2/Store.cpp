#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Store.h"
#include <iomanip>
#include <vector>
#include <cstring>
using namespace std;
namespace sdds {
	void Store::setStore(const char* sName, int no)
	{//This function checks if sName is an empty pointer and if the value of no is valid or not .If valid it will set the values 
		if (sName == nullptr || no <= 0)
		{// If the values are empty if will set the class variables to azero valuse else it will set withn the actuall given fuctions 
			m_sName[0] = '\0';
			m_noOfToys = 0;
		}
		else {
			strcpy(m_sName, sName);
			m_sName[MAX_SNAME - 1] = '\0';
			m_noOfToys = no;
		}
		m_addToys = 0;
	}
	void Store::setToys(const char* tname, int sku, double price, int age) //Add the toys one at a time to the toy array 
		//and addtoys will keep track of the number of toys addedd
	{
		if (m_addToys < m_noOfToys)
		{
			Toys temporayToy;
		temporayToy.addToys(tname, sku, price, age);
		m_toy[m_addToys] = temporayToy;
			m_addToys++;
		}
	}
	void Store::display() const //if the object is valid it will printb the information in the given format an ensure the appropraite empty spaces
		//we use setw to give a fixed amout of width and extra spaces 
	{
		if (m_noOfToys == 0) {
			std::cout << "Invalid Store" << std::endl;
		}

		cout << setfill('*') << setw(60) << "*" << endl;
		cout << m_sName << endl;
		cout << setfill('*') << setw(60) << "*" << endl;
		cout << "list of the toys" << endl;

		cout << setfill(' ')<< setw(30);
		std::cout << "SKU";
		cout << setfill(' ') << setw(10);
		std::cout << "Age";
		cout << setfill(' ') << setw(11);
		std::cout << "Price";
		cout << setfill(' ') << setw(10);
		std::cout << "Sale" << endl;
		for (int i = 0; i < m_addToys; ++i) 
		{
		m_toy[i].display();
		}
	}

	void Store::find(int sku)//This method will go through the arrays of toys and match the received SKU number with the stored toys' SKU number to find out if the toys are on sale or not.
		//If the number matches then it will pass true to the appropriate Toys method.
		//After that, it will call the calSale() of the toys class to know the sale value.


	{
		for (int i = 0; i < m_addToys; ++i)
		{
			if (m_toy[i].GETSKU() == sku) {
				m_toy[i].calSale();
			}
		}
	}
	void Store::setEmpty()//Set the variables back to empty
	{
		m_sName[0] = '\0';
		m_noOfToys = 0;
		m_addToys = 0;
	}
}


