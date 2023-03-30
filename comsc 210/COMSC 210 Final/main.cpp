//*****************
//Program Name: COMSC 210 FA20 Final
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Write a program that will simulate the checkout lines at a typical grocery store using nested data structures
//*****************

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <fstream>
#include <ctime>
using namespace std;

//class definitions
class Customer
{
private:
    string name;
    double cash;
    double bill;
public:
    Customer()
        { name = ""; cash = 0.0; bill = 0.0; }
    Customer(string n, double c, double b)
        { name = n; cash = c; bill = b; }
    void setName(string n) { name = n; }
    void setCash(double c) { cash = c; }
    void setBill(double b) { bill = b; }
    string getName()       { return name; }
    double getCash()       { return cash; }
    double getBill()       { return bill; }
    void adjustBill(int a) { bill -= a; }
};

class GroceryStore
{
private:
public:
    vector<deque<Customer>> cashiers;
    void setCashier(deque<Customer> d)
        {  cashiers.push_back(d);  }
    int getSize()
        { return cashiers.size(); }
};

//constants
const int NUM_OPERATIONS = 25; //the number of operations to perform on checkout lines
const int MAX_BILL = 50; //max range for the grocery bill
const int MIN_BILL = 10; //min range for the grocery bill
const int MAX_CASH = 100; //max range for the customer's cash
const int MIN_CASH = 25; //min range for the customer's cash

//function prototypes
void plagiarismRequirement();
Customer createCustomer(vector<string> &);
void displayLane(GroceryStore);
void openNewLane(GroceryStore &);
bool fourOrMore(GroceryStore);
void addCustomer(deque<Customer> &, vector<string> &);
void displayAdd(deque<Customer>, int);
void serveCustomer(deque<Customer> &);
void displayServe(deque<Customer>, int);

int main(){
	srand(time(0));
	//reads names.txt into the name array
	vector<string> names; //name container
	string name; //temporary variable for each name in the file
	ifstream fin("names.txt"); //opens the file
	while(fin >> name) { names.push_back(name); } //reads the names into the vector
	fin.close(); //housekeeping

	//creates and initializes the first checkout lane
	GroceryStore costco;
	deque<Customer> tempLane;
	tempLane.push_back(createCustomer(names));
	tempLane.push_back(createCustomer(names));
	costco.setCashier(tempLane);

	cout << "Initial setup: " << endl;
	displayLane(costco);

	int operationCount = 0;
	while(operationCount++ < NUM_OPERATIONS){
		cout << "=================================== Operation #" << operationCount << " ===================================" << endl << endl;

		//checks if there is any lane with 4 or more customers
		if(fourOrMore(costco)){
			cout << "*manager's action*" << endl;
			openNewLane(costco);
			displayLane(costco);
		}

		cout << "Lane operations: " << endl;
		for(int i = 0; i < costco.getSize(); i++){
			//empty lane guard
			if(costco.cashiers[i].empty()){
				addCustomer(costco.cashiers[i], names);
				displayAdd(costco.cashiers[i], i);
			}

			//if there are no empty lanes
			else{
				int addOrServe = rand() % 2;
				switch(addOrServe){
				case 0:
					addCustomer(costco.cashiers[i], names);
					displayAdd(costco.cashiers[i], i);
					break;
				case 1:
					//no cash guard; if the customer's cash is less than the bill
					if(costco.cashiers[i].front().getCash() < costco.cashiers[i].front().getBill()){
						double diff = costco.cashiers[i].front().getBill() - costco.cashiers[i].front().getCash();
						costco.cashiers[i].front().adjustBill(diff);

						cout << "Lane #" << i+1 << ": *manager's action*" << endl;
						cout << "Customer " << costco.cashiers[i].front().getName() << " is short on cash; items returned and bill reduced by "
							 << diff << " to $" << costco.cashiers[i].front().getBill() << endl;
					}
					//if the customer has sufficient amount of cash
					else{
						displayServe(costco.cashiers[i], i);
						serveCustomer(costco.cashiers[i]);
					}
				}
			}
		}
		displayLane(costco);
	}

	plagiarismRequirement();

	return 0;
}

//creates a customer object and returns it
Customer createCustomer(vector<string> &names){
	Customer newCustomer;
	double newCash = rand() % (MAX_CASH - MIN_CASH + 1) + MIN_CASH;
	double newBill = rand() % (MAX_BILL - MIN_BILL + 1) + MIN_BILL;

	newCustomer.setName(names.at(0));
	newCustomer.setCash(newCash);
	newCustomer.setBill(newBill);

	//removes the first element of names so next customer can be added
	names.erase(names.begin());

	return newCustomer;
}

//displays the lanes in the grocery store
void displayLane(GroceryStore costco){
	cout << endl << "------------- New Lane -------------" << endl;
	for(int i = 0; i < costco.getSize(); i++){
		cout << "Lane #" << i+1 << ": " << endl;
		if(costco.cashiers[i].empty()) cout << "\t<empty>" << endl;
		else
			for(auto customer : costco.cashiers[i])
				cout << '\t' << customer.getName() << " (bill: $" << customer.getBill() << " cash: $" << customer.getCash() << ")" << endl;
		cout << endl;
	}
}

//opens a new lane if(fourOrMore())
void openNewLane(GroceryStore &costco){
	deque<Customer> newLane;

	//traverse through the vector to find the lane with 4 customers
	for(int i = 0; i < costco.getSize(); i++){
		if(costco.cashiers[i].size() >= 4){
			cout << "Creating new lane by moving customer "
				 << costco.cashiers[i].front().getName()
				 << "(bill: $" << costco.cashiers[i].front().getBill()
				 << " cash: $" << costco.cashiers[i].front().getCash() << ")"
				 << " to Lane " << costco.getSize() + 1 << endl;
			newLane.push_back(costco.cashiers[i].front());
			costco.cashiers[i].pop_front();
		}
	}
	costco.setCashier(newLane);
}

//checks if there are more than 4 customers in one lane
bool fourOrMore(GroceryStore costco){
	bool fourOrMore = false;
	for(int i = 0; i < costco.getSize(); i++)
		if(costco.cashiers[i].size() >= 4)
			fourOrMore = true;

	return fourOrMore;
}

//adds a customer to a lane
void addCustomer(deque<Customer> &queue, vector<string> &names){
	queue.push_back(createCustomer(names));
}

void displayAdd(deque<Customer> queue, int whichLane){
	cout << "Lane #" << whichLane + 1 << ": Added customer "
		 << queue.back().getName()
		 << "(bill: $" << queue.back().getBill()
		 << " cash: $" << queue.back().getCash() << ")"
		 << " to Lane " << whichLane + 1 << endl;
}

//serves a customer from a lane
void serveCustomer(deque<Customer> &queue){
	queue.pop_front();
}

void displayServe(deque<Customer> queue, int whichLane){
	cout << "Lane #" << whichLane + 1 << ": Customer "
		 << queue.front().getName()
		 << " checks out with bill: $" << queue.front().getBill()
		 << " using cash on hand of $" << queue.front().getCash() << endl;
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
