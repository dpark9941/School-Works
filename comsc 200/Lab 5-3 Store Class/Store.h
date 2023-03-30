#ifndef STORE_H
#define STORE_H

#include <string>
#include <vector>
using namespace std;

/*
----------------------------
            Store
----------------------------
- name : string
- address : string
- city : string
- storeNumber : int
- annualRevenue : double
----------------------------
+ Store()
+ Store(string, string, string, int, double)
+ Store(string, int)
+ getName() : string
+ getAddress() : string
+ getCity() : string
+ getStoreNumber() : int
+ getAnnualRevenue() : double
+ setName(string) : void
+ setAddress(string) : void
+ setCity(string) : void
+ setStoreNumber(int) : void
+ setAnnualRevenue(double) : void
+ printStore() : void
----------------------------
*/

class Store{
private:
	string name;
	string address;
	string city;
	int storeNumber;
	double annualRevenue;
public:
	//constructors
	Store();
	Store(string, string, string, int, double);
	Store(string, int);

	//accessors
	string getName();
	string getAddress();
	string getCity();
	int getStoreNumber();
	double getAnnualRevenue();

	//mutators
	void setName(string);
	void setAddress(string);
	void setCity(string);
	void setStoreNumber(int);
	void setAnnualRevenue(double);

	//other functions
	void printStore();
};

#endif
