#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
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
    	cout << "found at node #" << result << endl;

    LinkedList<int> list2;
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

    return 0;
}
