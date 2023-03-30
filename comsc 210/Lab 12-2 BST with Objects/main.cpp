//*****************
//Program Name: Lab 12-2: BST with Objects
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Write a class named "Actor" that represents an Actor
//*****************
#include <iostream>
#include "Actor.h"
#include "BinaryTree.h"
using namespace std;

void plagiarismRequirement();

int main()
{
    int num = 44266;
    BinaryTree<Actor> tree;

    Actor actor1(52521, "John Heard");
    tree.insertNode(actor1);
    Actor actor2(64815, "Reese Witherspoon");
    tree.insertNode(actor2);
    Actor actor3(81214, "Jennifer Garner");
    tree.insertNode(actor3);
    Actor actor4(44266, "Sophia Loren");
    tree.insertNode(actor4);
    Actor actor5(33615, "Debbie Boone");
    tree.insertNode(actor5);
    Actor actor6(33040, "George Carlin");
    tree.insertNode(actor6);
    Actor actor7(12841, "Ashley Judd");
    tree.insertNode(actor7);
    Actor actor8(94664, "Josh Groban");
    tree.insertNode(actor8);

    //display actors
    cout << "List of actors:\n";
    tree.displayInOrder();

    //get an ID number to search for
    cout << "\nEnter a union ID number to search for: ";
    cin >> num;

    //search for the employee in the tree
    Actor *ptr = tree.searchNode(num);

    //display the results of the search
    if(ptr)
    	cout << "Actor was found: " << ptr->getName() << endl;
    else
    	cout << "Actor was not found" << endl;

    plagiarismRequirement();

    return 0;
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
