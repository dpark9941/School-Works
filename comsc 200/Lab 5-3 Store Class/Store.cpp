#include "Store.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

Store::Store(){
	name = "";
	address = "";
	city = "";
	storeNumber = 0;
	annualRevenue = 0.0;
}

Store::	Store(string n, string a, string c, int sn, double ar){
	name = n;
	address = a;
	city = c;
	storeNumber = sn;
	annualRevenue = ar;
}

Store::Store(string n, int sn){
	name = n;
	address = "";
	city = "";
	storeNumber = sn;
	annualRevenue = 0.0;
}

string Store::getName(){
	return name;
}

string Store::getAddress(){
	return address;
}

string Store::getCity(){
	return city;
}

int Store::getStoreNumber(){
	return storeNumber;
}

double Store::getAnnualRevenue(){
	return annualRevenue;
}

void Store::setName(string n){
	name = n;
}

void Store::setAddress(string a){
	address = a;
}

void Store::setCity(string c){
	city = c;
}

void Store::setStoreNumber(int sn){
	storeNumber = sn;
}

void Store::setAnnualRevenue(double ar){
	annualRevenue = ar;
}

void Store::printStore(){
	cout << setprecision(2) << fixed;
	cout << "Name: " << name << endl;
	cout << "Address: " << address << ' ' << city << endl;
	cout << "Store number: " << storeNumber << endl;
	cout << "Annual revenue: $" << annualRevenue << endl;
	cout << endl;
}
