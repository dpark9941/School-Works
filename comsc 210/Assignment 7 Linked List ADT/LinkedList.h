//LinkedList.h
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
using namespace std;

template <class Type>
class LinkedList
{
private:
    struct ListNode
    {
        Type value;
        struct ListNode *next;
    };

    ListNode *head;

public:
    //constructor
    LinkedList() { head = nullptr; }

    //destructor
    ~LinkedList();

    //other methods
    void appendNode(Type);
    void insertNode(Type);
    void deleteNode(Type);
    void displayList() const;

    //additional methods
    int search(Type);
    void insertNodeAt(Type, int);
    void deleteNodeAt(int);
};

//LinkedList(): constructor
//Arguments: none | Returns: none
template <class Type>
LinkedList<Type>::~LinkedList()
{
	ListNode *current;
	ListNode *nextNode;

	//place current at the head of the list
	current = head;

	//while current isn't at the end of the list, delete nodes
	while (current != nullptr)
	{
        //save a pointer to the next node
		nextNode = current->next;

		//delete the current node
		delete current;

		//move current to the next node
		current = nextNode;
    }
}

//appendNode(): appends a new node to the end of the LL
//Arguments: num (Type) | Returns: void
template <class Type>
void LinkedList<Type>::appendNode(Type num)
{
    ListNode *newNode = new ListNode;  //memory alloc for the new node
    ListNode *current;  //nodePtr used for traversing the list

    //housekeeping for newly-created newNode
    newNode->value = num;
    newNode->next = nullptr;

    //if the list is empty make newNode the first node
    if (!head)
        head = newNode;
    //otherwise insert newNode at the end
    else
    {
        current = head;
        //find the last node in the list
        while (current->next)
            current = current->next;
        //insert newNode as the last node
        current->next = newNode;
    }
}

//displayList(): displays the LL's current state
//Arguments: none | Returns: void
template <class Type>
void LinkedList<Type>::displayList() const
{
    ListNode *current;  //moves through the list
    current = head;
    while (current)
    {
        cout << current->value << " ";
        current = current->next;
    }
}

//insertNode(): inserts a new node into the LL in order by value
//Arguments: num (Type) | Returns: void
template <class Type>
void LinkedList<Type>::insertNode(Type num)
{
    ListNode *newNode = new ListNode;
    ListNode *current;
    ListNode *previous = nullptr;  //points to current's previous node

    //housekeeping for newly-created newNode
    newNode->value = num;

    //if the list is empty make newNode the first node
    if (!head)  //same as if (head == nullptr)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    //otherwise insert newNode at the end
    else
    {
        current = head;
        previous = nullptr;
        //skip values less than num
        while (current != nullptr and current->value < num)
        {
            previous = current;
            current = current->next;
        }
        //if newNode is to be first, insert it at the head
        if (previous == nullptr)
        {
            head = newNode;
            newNode->next = current;
        }
        else
        {
            previous->next = newNode;
            newNode->next = current;
        }
    }
}

//deleteNode(): deletes a node with the value num
//Arguments: num (Type) | Returns: void
template <class Type>
void LinkedList<Type>::deleteNode(Type num)
{
    ListNode *current;
    ListNode *previous;

    //if the list is empty, do nothing
    if (!head) return;

    //determine if the first node is the one to be deleted
    if (head->value == num)
    {
        current = head->next;
        delete head;
        head = current;
    }
    else
    {
        //initialize current to the head of the list
        current = head;
        //skip ahead to the correct deletion node
        while (current and current->value != num)
        {
            previous = current;
            current = current->next;
        }
        if (current)
        {
            previous->next = current->next;
            delete current;
        }
    }
}

//search(): searches the list for the node with the value num
//Arguments: num (Type) | Returns: index (int)
template <class Type>
int LinkedList<Type>::search(Type num){
	ListNode *current = head;
	int index = 0; //saves the index of the node that the user is searching for

	while(current){
		index++;
		//if the node's value == user's value
		if(current->value == num)
			break;
		//otherwise, keep traversing the LL
		else
			current = current->next;
	}

	//if current == nullptr; if current has traversed the LL and there is no value that the user is searching for
	if(!current)
		index = 0;

	return index;
}

//insertNodeAt(): inserts a new node into the LL at user-chosen index
//Arguments: num, insertion (Type, int) | Returns: (void)
template <class Type>
void LinkedList<Type>::insertNodeAt(Type num, int insertion){
    ListNode *newNode = new ListNode;
    ListNode *current;
    ListNode *previous = nullptr;  //points to current's previous node

    newNode->value = num;
    newNode->next = nullptr;

    //if the user choose to insert the node at beginning
    if(insertion == 0){
    	newNode->next = head;
    	head = newNode;
    }
    else{
    	current = head;
    	for(int i = 0; i < insertion; i++){
    		previous = current;
    		current = current->next;
    	}
    	previous->next = newNode;
    	newNode->next = current;
    }
}

//deleteNodeAt(): deletes a node from the LL at user-chosen index
//Arguments: deletion (int) | Returns: (void)
template <class Type>
void LinkedList<Type>::deleteNodeAt(int deletion){
    ListNode *current;
    ListNode *previous;

   	//cout << "\n\nDeleting the second node: ";
    //list2.deleteNodeAt(1);
    //use 0 as the index for the first node

    //if the user choose to delete the first node
    if(deletion == 0){
    	previous = head;
    	head = head->next;
    	delete previous;
    }
    else{
    	current = head;
    	deletion--;
    	for(int i = 0; i <= deletion; i++){
    		previous = current;
    		current = current->next;
    	}
    	previous->next = current->next;
    	delete current;
    }
}

#endif /* LINKEDLIST_H_ */
