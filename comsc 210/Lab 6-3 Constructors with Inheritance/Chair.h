#ifndef CHAIR_H
#define CHAIR_H

#include "Furniture.h"
using namespace std;

class Chair : public Furniture{
private:
	int legs;
	string color;
public:
	//constructors
	Chair() : Furniture() {
		legs = 0;
		color = "";
	}

	Chair(string b, int y, int l, string c) : Furniture(b, y){
		legs = l;
		color = c;
	}

	//other methods
	void printChair(){ //outputs information about chair
		Furniture::print();
		cout << "Legs: " << legs << endl;
		cout << "Color: " << color << endl;
	}
};

#endif
