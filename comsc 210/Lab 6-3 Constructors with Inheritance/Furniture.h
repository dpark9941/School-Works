#ifndef FURNITURE_H
#define FURNITURE_H

#include <iostream>
#include <string>
using namespace std;

class Furniture{
private:
	string brand;
	int yearMade;
public:
	//constructors
	Furniture(){
		brand = "";
		yearMade = 0;
	}

	Furniture(string b, int y){
		brand = b;
		yearMade = y;
	}

	//mutators
	void setBrand(string b) {brand = b;}
	void setYearMade(int y) {yearMade = y;}

	//accessors
	string getBrand() {return brand;}
	int getYearMade() {return yearMade;}

	//other methods
	void print(){ //outputs the furniture's brand and year made
		cout << "Brand: " << brand << endl;
		cout << "Year made: " << yearMade << endl;
	}
};

#endif
