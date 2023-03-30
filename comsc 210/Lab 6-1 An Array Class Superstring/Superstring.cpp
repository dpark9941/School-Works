#include "Superstring.h"
#include <iostream>
#include <string>
using namespace std;

Superstring::Superstring(){
	int input;
	cout << "How many strings do you want to store?: ";
	cin >> input;

	setArrSize(input);
	myString = new string[arrSize];
}

Superstring::~Superstring(){
	delete [] myString;
}

//getMyString(): returns myString
//Arguments: (void) | Returns: myString (string *)
string *Superstring::getMyString(){
	return myString;
}

//getArrSize(): returns arrSize
//Arguments: (void) | Returns: myString (int)
int Superstring::getArrSize(){
	return arrSize;
}

//getTemp(): returns temp
//Arguments: (void) | Returns: myString (string)
string Superstring::getTemp(){
	return temp;
}

//setMyString(): sets myString
//Arguments: ms (string *) | Returns: (void)
void Superstring::setMyString(string *ms){
	myString = ms;
}

//setArrSize(): sets arrSize
//Arguments: a (int) | Returns: (void)
void Superstring::setArrSize(int a){
	arrSize = a;
}

//setTemp(): sets temp
//Arguments: t (string) | Returns: (void)
void Superstring::setTemp(string t){
	temp = t;
}

//outputString(): outputs strings in myString[]
//Arguments: (void) | Returns: (void)
void Superstring::outputString(){
	cout << endl;
	cout << "Here are the strings you entered: " << endl << endl;
	for (int i = 0; i < arrSize; i++){
		cout << "String " << i+1 << ": " << *(myString + i) << endl;
	}

	cout << endl;
	cout << "Alphabetically this string comes first: " << getFirst() << endl;
	cout << "Alphabetically this string comes last: " << getLast() << endl;
}

//storeString(): stores a string into myString[]
//Arguments: (string *stringArr, int index, string temp) | Returns: (void)
void Superstring::storeString(string *stringArr, int index, string temp){
	*(stringArr + index) = temp;
}

//getFirst(): returns the string that comes first alphabetically
//Arguments: (void) | Returns: firstS (string)
string Superstring::getFirst(){
	string firstS = *myString;

	for(int i = 0; i < arrSize; i++){
		if(*(myString + i) < firstS)
			firstS = *(myString + i);
	}
	return firstS;
}

//getLast(): returns the string that comes last alphabetically
//Arguments: (void) | Returns: lastS (string)
string Superstring::getLast(){
	string lastS = *myString;

	for(int i = 0; i < arrSize; i++){
		if(*(myString + i) > lastS)
			lastS = *(myString + i);
	}
	return lastS;
}

//getMyString(): returns a user-chosen string from myString[]
//Arguments: (void) | Returns: *(myString + index) (string)
string Superstring::getString(){
	int index = 0;
	cout << "Returning a string from the array" << endl;
	cout << "Enter the index of the string: ";
	cin >> index;

	return *(myString + index);
}
