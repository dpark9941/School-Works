//*****************
//Program Name: Lab 12-1: Binary Search Tree
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Write new member functions that will allow developers to certain tasks
//*****************

#include <iostream>
#include "BinaryTree.h"
using namespace std;

const string sep = "\n\n*******************\n";

void plagiarismRequirement();

int main()
{
   //create BT and report initial stats
   BinaryTree<int> tree;

   //displays the statistics for the initial tree
   cout << "Created initial BT. Statistics:" << endl;
   cout << "Number of nodes: " << tree.numNodes() << endl;
   cout << "Number of leaf nodes: " << tree.numLeafNodes() << endl;
   cout << "Height: " << tree.treeHeight() << endl;

   //insert some values into the BT
   cout << sep << "Inserting nodes 5, 8, 3, 12, 9:\n";
   tree.insertNode(5);
   tree.insertNode(8);
   tree.insertNode(3);
   tree.insertNode(12);
   tree.insertNode(9);
   //display the nodes
   cout << "Here are the values in the tree:\n";
   tree.displayInOrder();
   cout << "Number of nodes: " << tree.numNodes() << endl;
   cout << "Number of leaf nodes: " << tree.numLeafNodes() << endl;
   cout << "Height: " << tree.treeHeight() << endl;

   //delete 8 node, 12 node
   cout << sep << "Deleting 8 and 12:\n";
   tree.remove(8);
   tree.remove(12);

   //display the nodes
   cout << "Here are the values in the tree:\n";
   tree.displayInOrder();
   cout << "Number of nodes: " << tree.numNodes() << endl;
   cout << "Number of leaf nodes: " << tree.numLeafNodes() << endl;
   cout << "Height: " << tree.treeHeight() << endl;

   //insert new values
   cout << sep << "Inserting nodes 42, 6, 19: \n";
   tree.insertNode(42);
   tree.insertNode(6);
   tree.insertNode(19);

   //display the nodes
   cout << "Here are the values in the tree:\n";
   tree.displayInOrder();
   cout << "Number of nodes: " << tree.numNodes() << endl;
   cout << "Number of leaf nodes: " << tree.numLeafNodes() << endl;
   cout << "Height: " << tree.treeHeight() << endl;

   //search for values 42, 99
   cout << sep << "Searching for 42: ";
   tree.searchNode(42) ? cout << "found.\n" : cout << "not found.\n";
   cout << "Searching for 99: ";
   tree.searchNode(99) ? cout << "found.\n" : cout << "not found.\n";

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
