#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <type_traits>
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
    void deleteNodeAt(int);
    void displayList() const;
    int search(Type);
    void insertNodeAt(Type, int);
    void deleteNodesByValue(Type);

    //mid-term methods
    //averages
    int getCount();
    Type calcSum();
    double calcAverage();

    //occurrences
    int getFrequency(Type);
    void outputCounts();

    //additional method
    void purgeOddEven(int);
};

//destructor
//Arguments: none | Returns: void
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

//deleteNodesByValue(): deletes nodes containing a certain value
//Arguments: num (Type) | Returns: void
template <class Type>
void LinkedList<Type>::deleteNodesByValue(Type num)
{
    ListNode *current;
    ListNode *previous;
    ListNode *last;

    //if the list is empty, do nothing
    if (!head) return;
    else
    {
        current = head;

        while (current)
        {
            if (current->value == num)
            {
                if (current == head)
                {
                    head = head->next;
                    delete current;
                    current = head;
                    if (head == NULL) last = NULL;
                }
                else
                {
                    previous->next = current->next;
                    if(current == last) last = previous;
                    delete current;
                    current = previous-> next;
                }
            }
            else
            {
                previous = current;
                current = current->next;
            }
        } // end while
    }
}

//appendNode(): appends a node to the end of the LL
//Arguments: num (Type) | Returns: void
template <class Type>
void LinkedList<Type>::appendNode(Type num)
{
    ListNode *newNode = new ListNode;  //memory alloc for the new node
    ListNode *current;  //current used for traversing the list

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

//displayList(): outputs LL to console in simple format
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
    cout << endl;
}

//insertNode(): inserts node in increasing order based on value
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

//insertNodeAt(): inserts a node in a specified position
//Arguments: value (Type), position (int) | Returns: void
template <class Type>
void LinkedList<Type>::insertNodeAt(Type value, int pos)
{
    //allocate a new node & store the value of the current list node in it
    ListNode *newNode = new ListNode;
    newNode->value = value;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    if (pos == 0)
    {
    	newNode->next = head;
    	head = newNode;
    	return;
    }

    ListNode *current = head;  //walk through nodes
    int numberToSkip = 1; //
    while (numberToSkip <= pos)
    {
        if (current->next == nullptr || numberToSkip == pos)
        {
	        ListNode *tempPtr = current->next;
	        current->next = newNode;
		    newNode->next = tempPtr;
            return;
        }
        //not at end and have not skipped enough so continue
	    current = current->next;
        numberToSkip++;
    }
}

//deleteNode(): deletes first node containing a certain value
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
		while (current != nullptr and current->value != num)
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

//deleteNodeAt(): deletes a node at a specific position
//Arguments: position (int) | Returns: void
template <class Type>
void LinkedList<Type>::deleteNodeAt(int pos)
{
    //pos is number of nodes to skip
	ListNode *current = head;
    if (current == nullptr) return;
    while (pos > 0 && current)
    {
		//skip ahead
		current = current->next;
		pos--;
    }
    //current is the node that should be deleted.
    if (current == head)
    {
        head = head->next;
	    delete current;
	    return;
    }
    else
    {
        if (current == nullptr) return; //nothing to do: pos was too big.
        //need to delete current
        //so we come up behind current and delete it
        ListNode *trailer = head;
        while (trailer->next != current)
            trailer = trailer->next;
        trailer->next = current->next;
        delete current;
    }
}

//search(): searches for a node by value
//Arguments: search term (Type) | Returns: index if found, 0 if not found
template <class Type>
int LinkedList<Type>::search(Type val)
{
    int index = 1;
    ListNode *nodePtr = nullptr;

    nodePtr = head;
    while (nodePtr)
        if( nodePtr->value == val)
            return index;
        else
        {
            nodePtr = nodePtr->next;
            index++;
        }
   return 0;
}

//mid-term methods

//getCount(): counts the number of nodes in the list
//Arguments: none (void) | Returns: count (int)
template <class Type>
int LinkedList<Type>::getCount(){
	int count = 0;
	ListNode *current = nullptr;

	current = head;
	while(current){
		count++;
		current = current->next;
	}

	return count;
}

//calcSum(): calculates the sum of values of the nodes in the list
//Arguments: none (void) | Returns: sum (Type)
template <class Type>
Type LinkedList<Type>::calcSum(){
	if (!is_same<Type, int>::value and !is_same<Type, double>::value
	    and !is_same<Type, float>::value)
	{
	    cerr << "Type mismatch in calculating sum.";
	    exit(EXIT_FAILURE);
	}

	Type sum = 0;
	ListNode *current = nullptr;

	current = head;
	while(current){
		sum += current->value;
		current = current->next;
	}

	return sum;
}

//calcAverage(): calculates the average value of the LL
//Arguments: none (void) | Returns: average (Type)
template <class Type>
double LinkedList<Type>::calcAverage(){
	double average = 0;

	average = calcSum() / (double)getCount();

	return average;
}

//getFrequency(): counts the frequency of val in the LL
//Arguments: val (Type) | Returns: frequency (int)
template <class Type>
int LinkedList<Type>::getFrequency(Type val){
	int frequency = 0;
	ListNode *current = nullptr;

	current = head;
	while(current){
		if(val == current->value)
			frequency++;
		current = current->next;
	}

	return frequency;
}

//ouputCounts(): outputs the frequency of val in the LL
//Arguments: val (Type) | Returns: frequency (int)
template <class Type>
void LinkedList<Type>::outputCounts(){
	bool frequent; //true if getFrequency(val) > 1
	int frequency;
	Type val;
	ListNode *current = nullptr;

	current = head;
	cout << "The frequency for each value in the list:" << endl;
	cout << "Value\tFrequency" << endl;
	cout << "-----\t---------" << endl;
	while(current){
		val = current->value;
		frequency = getFrequency(val);
		frequent = frequency - 1;

		//if val's frequency is 1
		if(!frequent)
			cout << val << '\t' << getFrequency(val) << endl;
		//if val's frequency is 2 or more
		else{
			ListNode *frequentNode;
			frequentNode = current;
			while(frequency){
				frequentNode = current;
				if(frequentNode->value == val){
					frequency--;
					frequentNode = frequentNode->next;
				}
				else
					frequentNode = frequentNode->next;
			}
			cout << val << '\t' << getFrequency(val) << endl;
		}
		current = current->next;
	}
}

template <class Type>
void LinkedList<Type>::purgeOddEven(int oddEven){
	//if oddEven == 0, deletes evens
	//if oddEven == 1, deletes odds

	Type val;
	ListNode *current = nullptr;

	current = head;
	while(current){
		val = current->value;
		if(val % 2 == oddEven){
			current = current->next;
			deleteNode(val);
		}
		else
			current = current->next;
	}
}

#endif /* LINKEDLIST_H_ */
