//*****************
//Program Name: Lab 5-3: Store Class
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Create a demo program that exercises Store class
//*****************

#include "Store.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

double calculateSum(vector<Store>);
void plagiarismRequirement();

int main(){
	//creates a vector to store Store objects
	vector<Store> storeList;

	//creates Store object using mutator methods
	Store store1;
	store1.setName("DVC Book Center");
	store1.setAddress("321 Golf Club Road");
	store1.setCity("Pleasant Hill");
	store1.setStoreNumber(1);
	store1.setAnnualRevenue(12345.60);

	//creates Store objects using constructors
	Store store2("DVC Cafeteria", "321 Golf Club Road", "Pleasant Hill", 2, 19372.34);
	Store store3("Peet's Coffee", 3);

	//puts the Store objects into the vector
	storeList.push_back(store1);
	storeList.push_back(store2);
	storeList.push_back(store3);

	//outputs information about the stores in the vector
	for(Store tempStore : storeList)
		tempStore.printStore();

	//outputs the sum of the revenue of the stores
	cout << setprecision(2) << fixed;
	cout << "The total revenue: $" << calculateSum(storeList) << endl;

	plagiarismRequirement();

	return 0;
}

//*****************
//Function name: calculateSum
//Purpose: calculates the total revenue of the stores in the vector and returns it
//List of parameters: vector<Store> tempList
//Returns: totalRevenue
//Return type: double
//*****************
double calculateSum(vector<Store> tempList){
	double totalRevenue = 0.0;

	for(Store tempStore : tempList)
		totalRevenue += tempStore.getAnnualRevenue();

	return totalRevenue;
}

//*****************
//Function name: plagiarismRequirement
//Purpose: outputs Plagiarism Requirement
//List of parameters:
//Returns:
//Return type: void
//*****************
void plagiarismRequirement(){
  cout << endl;
  cout << "I attest that this code is my original programming work, and that I received" << endl;
  cout << "no help creating it. I attest that I did not copy this code or any portion of this" << endl;
  cout << "code from any source." << endl;
}
