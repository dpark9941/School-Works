//*****************
//Program Name: COMSC 210 FA20 Midterm
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description:
//*****************

#include "LinkedList.h"
#include <iostream>
using namespace std;

void plagiarismRequirement();

int main(){
    LinkedList<double> list;

    cout << "Adding four nodes to the LL: ";
    list.appendNode(5.2);
    list.appendNode(7.9);
    list.appendNode(12.6);
    list.appendNode(15.5);
    list.displayList();

    cout << "\n\nInserting 10.2 into the LL in order: ";
    list.insertNode(10.2);
    list.displayList();

    cout << "\n\nDeleting 7.9: ";
    list.deleteNode(7.9);
    list.displayList();

    cout << "\n\nSearching for 5.2 in the LL...";
    int result = list.search(5.2);
    if (result == 0)
        cout << "not found.\n";
    else
        cout << "found at node #" << result << endl << endl;

    LinkedList<int> list2;
    cout << "Creating list2..." << endl;
    list2.appendNode(50);
    list2.appendNode(55);
    list2.appendNode(82);
    list2.appendNode(91);
    list2.appendNode(42);
    list2.appendNode(60);
    list2.appendNode(12);
    cout << "\n\nNew Linked List of ints: ";
    list2.displayList();
    cout << "\n\nInserting 30 as the new fourth node: ";
	list2.insertNodeAt(30, 3);
	list2.displayList();
	cout << "\n\nDeleting the second node: ";
	list2.deleteNodeAt(1);
	list2.displayList();

    cout << endl << "Mid-term material" << endl << endl;

    cout << "The number of nodes in the list: " << list.getCount() << endl;
    cout << "The number of nodes in the list2: " << list2.getCount() << endl << endl;

    cout << "The sum of the values of the nodes in the list: " << list.calcSum() << endl;
    cout << "The sum of the values of the nodes in the list2: " << list2.calcSum() << endl << endl;

    cout << "The average value of the LL: " << list.calcAverage() << endl;
    cout << "The average value of the LL2: " << list2.calcAverage() << endl << endl;

    cout << "The frequency of 10.2 in list: " << list.getFrequency(10.2) << endl;
    cout << "The frequency of 12 in list2: " << list2.getFrequency(12) << endl << endl;

    cout << "Adding 12.6 and 15.5 to the list" << endl << endl;
    list.appendNode(12.6);
    list.appendNode(12.6);
    list.appendNode(15.5);
    list.appendNode(15.5);
    list.appendNode(15.5);

    cout << "Adding 82 and 91 to the list2" << endl << endl;
    list2.appendNode(82);
    list2.appendNode(82);
    list2.appendNode(91);

    list.outputCounts();
    cout << endl;
    list2.outputCounts();
    cout << endl;

    cout << "Purging odd values..." << endl;
    list2.purgeOddEven(1);
    cout << "New list: ";
    list2.displayList();

    LinkedList<char> list3;
    list3.appendNode('a');
    list3.appendNode('b');
    list3.appendNode('c');
    cout << "The sum of the values of the nodes in the list3: " << list3.calcSum() << endl;

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
