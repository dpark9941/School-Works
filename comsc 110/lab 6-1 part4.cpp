//============================================================================
// Name        : lab 6-1 part4.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : creats people database including name, age, weight and zip code
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

void database(int, string, int, int, int);

ofstream outputFile("output.txt");

int main(){

	int people; //how many people
	string name;
	int age;
	int weight;
	int zipcode;
	int i;

	cout << "Enter the number of people you have data for: ";
	cin >> people;
	while (people <= 0)
	{
		cout << "ERROR! Enter a positive number: ";
		cin >> people;
	}
	for (i = 1; i <= people; i++)
	{
		cout << "Person #" << i << endl;
		cout <<"\t> Name: ";
		cin.ignore();
		getline(cin, name);
		cout << "\t> Age: ";
		cin >> age;
		while (age <= 0)
			{
				cout << "ERROR! Enter a positive number: ";
				cin >> age;
			}
		cout << "\t> Weight: ";
		cin >> weight;
		while (weight <= 0)
			{
				cout << "ERROR! Enter a positive number: ";
				cin >> weight;
			}
		cout << "\t> ZIP code: ";
		cin >> zipcode;
		database(i, name, age, weight, zipcode);
	}

	outputFile.close();

	return 0;
}

void database(int i, string name, int age, int weight, int zipcode){


	cout << "Person #" << i << endl;
	cout << "\t> Name: " << name << endl;
	cout << "\t> Age: " << age << endl;;
	cout << "\t> Weight: " << weight << endl;
	cout << "\t> ZIP code: " << zipcode << endl << endl;

	outputFile << "Person #" << i << endl;
	outputFile << "\t> Name: " << name << endl;
	outputFile << "\t> Age: " << age << endl;;
	outputFile << "\t> Weight: " << weight << endl;
	outputFile << "\t> ZIP code: " << zipcode << endl << endl;

}
