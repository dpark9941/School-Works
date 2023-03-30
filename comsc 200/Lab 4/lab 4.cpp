//*****************
//Program Name: Lab 4
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Populate the dynamic array of struct objects, and then output the contents of the dynamic array
//*****************

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

struct Restaurant{
	string name;
	int zip;
	float *reviews;
	string *comments;

	~Restaurant(){
		if(reviews)
			delete [] reviews;
		if(comments)
			delete [] comments;
	}
};

void readFile(Restaurant*);
void outputRestaurant(Restaurant*);
void plagiarismRequirement();

const int NUM_RESTAURANT = 3;
const int NUM_REVIEWS = 3;
const int PRECISION = 1;

int main(){
	//creates dynamically allocated Restaurant array
	Restaurant *restaurantList = new Restaurant[NUM_RESTAURANT];

	//reads the file and populates the array
	cout << "Reading restaurant data..." << endl;
	readFile(restaurantList);
	cout << "Done." << endl << endl;

	//displays the data
	outputRestaurant(restaurantList);

	//frees the memories for restaurantList
	delete [] restaurantList;

	plagiarismRequirement();

	return 0;
}

//*****************
//Function name: readFile
//Purpose: reads data from a file into restaurantList
//List of parameters: Restaurant *restaurant
//Returns:
//Return type: void
//*****************
void readFile(Restaurant *restaurant){
	//declares ifstream object
	ifstream fin;

	//opens the file
	fin.open("input.txt");

	//if the file is not open or does not exist
	if(!fin.good()){
		cout << "The file does not exist! Program ending.";
		exit(0); //terminates the program
	}

	//creates dynamic float array and dynamic string array
	for(int i = 0; i < NUM_RESTAURANT; i++){
		(restaurant + i)->reviews = new float[NUM_REVIEWS];
		(restaurant + i)->comments = new string[NUM_REVIEWS];
	}

	//initializes the elements to 0 and ""
	for(int i = 0; i < NUM_REVIEWS; i++){
		for(int j = 0; j < NUM_REVIEWS; j++){
			*(((restaurant + i)->reviews) + i) = 0;
			*(((restaurant + i)->comments) + i) = "";
		}
	}

	//reads the data into the restaurantList
	for(int i = 0; i < NUM_RESTAURANT; i++){
		getline(fin, (restaurant + i)->name);
		fin >> (restaurant + i)->zip;
		for(int j = 0; j < NUM_REVIEWS; j++){
			fin >> *(((restaurant + i)->reviews) + j);
			fin.ignore();
			getline(fin, *(((restaurant + i)->comments) + j));
		}
	}
	//housekeeping
	fin.close();
}

//*****************
//Function name: outputRestaurant
//Purpose: outputs restaurant data in restaurantList
//List of parameters: Restaurant *restaurant
//Returns:
//Return type: void
//*****************
void outputRestaurant(Restaurant *restaurant){
	//output manipulations for the reviews member of Restaurant
	cout << setprecision(PRECISION) << fixed;

	//outputs data foe each restaurant
	for(int i = 0; i < NUM_RESTAURANT; i++){
		cout << "Restaurant summary:" << endl;
		cout << "\t> Name: " << (restaurant + i)->name << endl;
		cout << "\t> Zip: " << (restaurant + i)->zip << endl;
		for(int j = 0; j < NUM_REVIEWS; j++){
			cout << "\t> Review #" << j + 1 << ": " << *(((restaurant + i)->reviews) + j) << ": "
				 << *(((restaurant + i)->comments) + j) << endl;
		}
		cout << endl;
	}
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
