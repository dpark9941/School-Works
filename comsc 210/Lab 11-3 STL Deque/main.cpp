//*****************
//Program Name: Lab 11-3: STL Deque
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Write a program that reads an input file of words, and outputs the unique, sorted set of words using STL Set
//*****************

#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <cstdlib>
#include <ctime>
using namespace std;

void displayDeque(deque<string>);
void addCustomer(deque<string> &, int &);
void serveCustomer(deque<string> &, int &);
void plagiarismRequirement();

//potential customers
const string names[] = {"Joe", "Jen", "Job", "Jya", "Jed", "Jim", "Jet",
            "Jai", "Jay", "Jan", "Jin", "Jae", "Jax", "Jad", "Jao",
            "Joo", "Jiu", "Jef"};

int main(){
	//holds the index of the next available customer
	int nextCustomer = 0;

	//creates an empty deque of customers
	deque<string> storeQ;
	//adds 5 customers to the queue
	for(nextCustomer = 0; nextCustomer < 5; nextCustomer++)
		storeQ.push_back(names[nextCustomer]);
	cout << "Initial queue: ";
	displayDeque(storeQ);

	//perform 15 random operations on the queue
	srand(time(0)); //seed value for rand()
	int addOrServe = 0;
	for(int i = 0; i < 15; i++){
		addOrServe = rand() % 2; //determines which operation to perform
		if(addOrServe) addCustomer(storeQ, nextCustomer);
		else serveCustomer(storeQ, nextCustomer);
	}

	plagiarismRequirement();

	return 0;
}

//*****************
//Function name: displayList
//Purpose: outputs the element of list
//List of parameters: list<int> tempList
//Returns:
//Return type: void
//*****************
void displayDeque(deque<string> tempDeque){
	for(auto val : tempDeque)
		cout << val << ' ';
	cout << endl << endl;
}

//*****************
//Function name: addCustomer
//Purpose: performs adding operations on the queue
//List of parameters: deque<string> tempDeque
//Returns:
//Return type: void
//*****************
void addCustomer(deque<string> &storeQ ,int &nextCustomer){
	int isRegularCustomer = rand() % 3;
	if(isRegularCustomer){
		cout << "Now adding " << names[nextCustomer] << " to the rear of the queue." << endl;
		storeQ.push_back(names[nextCustomer]);
	}
	else{
		cout << "Now adding Special Customer " << names[nextCustomer] << " to the front of the queue." << endl;
		storeQ.push_front(names[nextCustomer]);
	}
	nextCustomer++;
	displayDeque(storeQ);
}

//*****************
//Function name: serveCustomer
//Purpose: performs serving operations on the queue
//List of parameters: deque<string> tempDeque
//Returns:
//Return type: void
//*****************
void serveCustomer(deque<string> &storeQ, int &nextCustomer){
	if(!storeQ.empty()){
		int isRegularCustomer = rand() % 3;
		if(isRegularCustomer){
			cout << "Now serving " << storeQ.front() << " from the front of the queue." << endl;
			storeQ.pop_front();
		}
		else{
			cout << "Now serving VIP Customer " << storeQ.back() << " from the back of the queue." << endl;
			storeQ.pop_back();
		}
	}
	else
		cout << "Queue is empty; cannot serve a customer." << endl;

	displayDeque(storeQ);
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
