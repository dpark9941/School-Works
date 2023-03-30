//*****************
//Program Name: Assignment 5: Linked List with Choices
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Create a node struct that will store a restaurant review
//*****************

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Node{
	float review;
	string comment;
	Node *nextNode;
};

const int P1 = 1;

void getInput(float *, string *);
Node* buildListForward();
Node* buildListBackward();
void outputNode(Node *);
void plagiarismRequirement();

int main(){
	Node *list;
	//asks the user if they want the node to be at the head of the list or the tail of the list
	int choice = 0;
	cout << "Which linked list method should we use?" << endl;
	cout << "\t[1] New nodes are added at the head of the linked list" << endl;
	cout << "\t[2] New nodes are added at the tail of the linked list" << endl;
	cout << "\tChoice: ";
	cin >> choice;
	while(choice != 1 && choice != 2){
		cout << "ERROR! Enter only 1 or 2: ";
		cin >> choice;
	}

	if(choice == 1)
		list = buildListBackward();
	else if(choice == 2)
		list = buildListForward();

	outputNode(list);

	plagiarismRequirement();

	return 0;
}

//*****************
//Function name: getInput
//Purpose: gets review and comments data from the user
//List of parameters: float *rating, string *comment
//Returns:
//Return type:
//*****************
void getInput(float *rating, string *comment){
	cout << "Enter review rating 0-5: ";
	cin >> *rating;
	while(*rating > 5.0 || *rating < 0.0){
		cout << "ERROR! Enter from 0.0 to 5.0: ";
		cin >> *rating;
	}
	cin.ignore();
	cout << "Enter review comments: ";
	getline(cin, *comment);
}

//*****************
//Function name: buildListBackward
//Purpose: adds a node at the head of a list and returns the first node
//List of parameters:
//Returns: first
//Return type: Node*
//*****************
Node* buildListBackward(){
	Node *first = nullptr, *newNode = nullptr;
	float userReview;
	string userComment;
	char again;

	do{
		getInput(&userReview, &userComment);
		newNode = new Node;
		newNode->review = userReview;
		newNode->comment = userComment;
		newNode->nextNode = nullptr;

		newNode->nextNode = first;
		first = newNode;

		cout << "Enter another review? Y/N: ";
		cin >> again;
	} while(tolower(again) != 'n');

	return first;
}

//*****************
//Function name: buildListForward
//Purpose: adds a node at the tail of a list and returns the first node
//List of parameters:
//Returns: first
//Return type: Node*
//*****************
Node* buildListForward(){
	Node *first = nullptr, *last = nullptr, *newNode = nullptr;
	float userReview;
	string userComment;
	char again;

	do{
		getInput(&userReview, &userComment);
		newNode = new Node;
		newNode->review = userReview;
		newNode->comment = userComment;
		newNode->nextNode = nullptr;

		if(first == nullptr){  //if the first node is empty; if the list is empty
			first = newNode;
			last = newNode;
		}
		else{
			last->nextNode = newNode;
			last = newNode;
		}

		cout << "Enter another review? Y/N: ";
		cin >> again;
	} while(tolower(again) != 'n');

	return first;
}

//*****************
//Function name: outputNode
//Purpose: outputs the elements of a node
//List of parameters: Node *list
//Returns:
//Return type: void
//*****************
void outputNode(Node *list){
	Node *current = list;
	int count = 0;
	cout << setprecision(P1) << fixed;
	cout << "Outputting all node from the head:" << endl;
	while(current != NULL){
		cout << "Review #" << count + 1 << endl;
		cout << "\t> Review: " << current->review << endl;
		cout << "\t> Comment: " << current->comment << endl;
		cout << endl;
		current = current->nextNode;
		count++;
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
