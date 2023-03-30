//============================================================================
// Name        : lab 11-1 part1.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : creates structures and displays the contents
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

struct HouseData{
	string type;
	string color;
	int yearBuilt;
	int bedrooms;
	int bathrooms;
	double price;
};

void displayHouse(HouseData);

int main(){
	HouseData house1;
	house1.type = "Apartment";
	house1.color = "Yellow";
	house1.yearBuilt = 2001;
	house1.bedrooms = 3;
	house1.bathrooms = 2;
	house1.price = 100000;

	HouseData house2 = {
			"Tent",
			"Green",
			2019,
			1,
			0,
			500};

	displayHouse(house1);
	displayHouse(house2);

	return 0;
}

//=======================================================
//Function name: displayHouse
//Purpose: displays informations about a house
//List of parameters: a data structure
//Return type: void
//Returns:
//=======================================================
void displayHouse(HouseData house){
	cout << "Type: " << house.type << endl;
	cout << "Color: " << house.color << endl;
	cout << "Year Built: " << house.yearBuilt << endl;
	cout << "# of Bedrooms: " << house.bedrooms << endl;
	cout << "# of Bathrooms: " << house.bathrooms << endl;
	cout << "Purchase Price: $ " << house.price << endl;
	cout << endl;
}
