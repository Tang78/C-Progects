#ifndef SDDS_TOYS_H
#define SDDS_TOYS_H
//#define MAX_NUM_TOYS 10
#define MAX_TNAME 31//maximum space occupied by a name 
namespace  sdds 
{
	class Toys//Toy class which contains private menbers  varaibles and public functions 
	{
		char m_tName[MAX_TNAME];
		int m_sku;
		double m_price;
		int m_age;
		bool m_onsale;
	public:
		void addToys(const char* tname, int sku, double price, int age);
		void isSale(bool sale);
		void calSale();
		void display()const;
		int GETSKU();
		Toys();//default constructor of toys thatb will set the values
	};
}
#endif
