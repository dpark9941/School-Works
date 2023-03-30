//*****************
//Program Name: Lab 7-2
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Write an interactive, menu-driven program to do two simple linked list operations: add node and delete node
//*****************

#include <iostream>
#include <cstdlib> //srand()
#include <ctime> //time();
using namespace std;

const int MIN_NODES = 10;
const int MAX_NODES = 50;
const int MIN_VAL = 0;
const int MAX_VAL = 100;

struct Node{
	int data;
	Node *nextNode;
};

Node *buildList(int);
int menu();
void outputList(Node *);
void addNode(Node *&);
void deleteNode(Node *&);
void plagiarismRequirement();

int main(){
	Node *myList;

	//creates a linked list
	int numNodes;
	cout << "How many nodes do you want to generate? [" << MIN_NODES << " - " << MAX_NODES << "]: ";
	cin >> numNodes;
	//input validation
	while(numNodes < MIN_NODES || numNodes > MAX_NODES){
		cout << "Error. Only enter " << MIN_NODES << " to " << MAX_NODES << ": ";
		cin >> numNodes;
	}
	myList = buildList(numNodes);

	int userChoice = 0;
	while(userChoice != 4){
		userChoice = menu();

		switch(userChoice){
		case 1:
			outputList(myList);
			break;
		case 2:
			addNode(myList);
			break;
		case 3:
			deleteNode(myList);
			break;
		case 4:
			cout << "Program ending..." << endl;
			break;
		default:
			cout << "Error. Only enter 1 to 4" << endl;
		}
	}

	return 0;
}

//buildList(): populates the linked list with randon numbers
//Arguments: size (int) | Returns: head (Node *)
Node *buildList(int size){
	srand(time(0)); //seed value for rand()
	Node *head = nullptr, *last = nullptr, *newNode = nullptr;

	//populates nodes with random numbers
	for(int i = 0; i < size; i++){
		newNode = new Node;
		newNode->data = rand() % (MAX_VAL - MIN_VAL + 1) + MIN_VAL;
		newNode->nextNode = nullptr;

		//if the list is empty
		if(head == nullptr){
			head = newNode;
			last = newNode;
		}
		else {
			last->nextNode = newNode;
			last = newNode;
		}
	}
	return head;
}

//menu(): outputs menu and gets input from the user
//Arguments:  (void) | Returns: useChoice (int)
int menu(){
	int userChoice;
	cout << endl;
	cout << "Enter:\t" << "[1] Output LL" << endl;
	cout << "\t[2] Insert node" << endl;
	cout << "\t[3] Delete node" << endl;
	cout << "\t[4] Quit" << endl;
	cout << endl << "Your choice: ";
	cin >> userChoice;
	cout << endl;

	return userChoice;
}

//outputList(): outputs the contents of the linked list
//Arguments: list (Node *) | Returns: (void)
void outputList(Node *list){
	Node *current = list;
	cout << "Current Linked List:" << endl;
	while(current != nullptr){
		cout << current->data << ' ';
		current = current->nextNode;
	}
	cout << endl;
}

//addNode(): adds a node to the list at user-chosen insertion point
//Arguments: head (Node *&) | Returns: (void)
void addNode(Node *&head){
	Node *p, *current, *newNode;
	int newNodeVal;

	//creates a new node
	cout << "Enter the new node's value: ";
	cin >> newNodeVal;
	newNode = new Node;
	newNode->data = newNodeVal;
	newNode->nextNode = nullptr;

	//outputs the contents of the list so the user can choose where to add a new node
	int insertion;
	int index = 1;
	current = head;
	cout << "Enter the node number just prior to your insertion point: " << endl;
	cout << "[0] New node at beginning" << endl;
	while(current != nullptr){
		cout << "[" << index << "] " << current->data << endl;
		current = current->nextNode;
		index++;
	}
	cout << "Enter your choice: ";
	cin >> insertion;

	//if the user chooses to add at beginning
	if(insertion == 0){
		newNode->nextNode = head;
		head = newNode;
	}
	else{
		current = head;
		for(int i = 0; i < insertion; i++){
			p = current;
			current = current->nextNode;
		}
		p->nextNode = newNode;
		newNode->nextNode = current;
	}
}

//deleteNode(): deletes a node from the list at user-chosen deletion point
//Arguments: head (Node *&) | Returns: (void)
void deleteNode(Node *&head){
	Node *p, *current;

	//outputs the contents of the list so the user can choose which node to delete
	int deletion;
	int index = 1;
	current = head;
	cout << "Enter the node number number to be deleted: " << endl;
	while(current != nullptr){
		cout << "[" << index << "] " << current->data << endl;
		current = current->nextNode;
		index++;
	}
	cout << "Enter your choice: ";
	cin >> deletion;

	//if the user choose to delete the first node
	if(deletion == 1){
		p = head;
		head = head->nextNode;
		delete p;
	}
	else{
		current = head;
		deletion--;
		for(int i = 0; i < deletion; i++){
			p = current;
			current = current->nextNode;
		}
		p->nextNode = current->nextNode;
		delete current;
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

