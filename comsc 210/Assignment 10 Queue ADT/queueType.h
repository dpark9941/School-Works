//queueType.h
#ifndef QUEUETYPE_H
#define QUEUETYPE_H
#include <iostream>
#include <cassert>
using namespace std;

template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type> *next;
};

template <class Type>
class queueType
{
private:
    nodeType<Type> *queueFront; //pointer to the front of the queue
    nodeType<Type> *queueRear;  //pointer to the rear of the queue
    int count;                  //holds number of nodes in queue

public:
    //constructors and destructors
    queueType();
    //copy constructor
    queueType(const queueType<Type>& otherQueue);
    ~queueType();

    //overloaded operators
    const queueType<Type>& operator= (const queueType<Type>&);

    //other methods
    bool isEmptyQueue() const   //returns true if queue is empty
        { return(queueFront == nullptr); }
    bool isFullQueue() const    //returns true if queue is full
        { return false; }
    void initializeQueue();     //initializes queue to an empty state
    Type front() const;         //returns first element of queue
    Type back() const;          //returns last element of queue
    void addQueue(const Type&); //adds element to queue
    void deleteQueue();         //removes queue's first element
    void printQueue();          //simple print function sep by spaces

    void moveToFront(int);
    int getCount() {return count;}
};

//default constructor
template<class Type>
queueType<Type>::queueType()
{
    queueFront = nullptr;
    queueRear = nullptr;
    count = 0;
} //end default constructor

//copy constructor
template<class Type>
queueType<Type>::queueType(const queueType<Type>& otherQueue){
	nodeType<Type> *newNode;
	nodeType<Type> *current;

	//if the other queue is empty
	if(!otherQueue.queueFront){
	    queueFront = nullptr;
	    queueRear = nullptr;
	    count = 0;
	}
	else{
		//copies the first node
		current = otherQueue.queueFront;
		queueFront = new nodeType<Type>;
		queueFront->info = current->info;
		queueFront->next = nullptr;
		queueRear = queueFront;
		current = current->next;

		//copies the remaining list
		while(current){
			newNode = new nodeType<Type>;
			newNode->info = current->info;
			newNode->next = nullptr;
			queueRear->next = newNode;
			queueRear = newNode;
			current = current->next;
		}
		count = otherQueue.count;
	}
}//end copy constructor

//Function to initialize the queue to an empty state.
//Postcondition: queueFront = nullptr; queueRear = nullptr
template<class Type>
void queueType<Type>::initializeQueue()
{
    nodeType<Type> *temp;

    //first delete all nodes in the possibly existing queue
    while(queueFront)  //while there are elements left in the queue
    {
        temp = queueFront;  //set temp to current node
        queueFront = queueFront->next;  //advance to next node
        delete temp;    //deallocate memory occupied by temp
    }
    queueRear = nullptr;
    count = 0;
}

//Function to add queueElement to the queue
//Precondition: The queue exists and is not full.
//Postcondition: The queue is changed and queueElement is
//    added to the queue.
template<class Type>
void queueType<Type>::addQueue(const Type& element)
{
    nodeType<Type> *newNode = new nodeType<Type>; //create the node

    newNode->info = element;   //store the info
    newNode->next = nullptr;   //initialize next to nullptr
    count++;

    if (queueFront == nullptr) //if initially the queue is empty
    {
        queueFront = newNode;
        queueRear = newNode;
    }
    else                       //otherwise add newNode at the end
    {
        queueRear->next = newNode;
        queueRear = queueRear->next;
    }
}

//Function to return the first element of the queue.
//Precondition: The queue exists and is not empty.
//Postcondition: If the queue is empty, the program
//    terminates; otherwise, the first element of the
//    queue is returned.
template<class Type>
Type queueType<Type>::front() const
{
    assert(queueFront != nullptr);
    return queueFront->info;
}

//Function to return the last element of the queue.
//Precondition: The queue exists and is not empty.
//Postcondition: If the queue is empty, the program
//    terminates; otherwise, the last element of the
//    queue is returned.
template<class Type>
Type queueType<Type>::back() const
{
    assert(queueRear != nullptr);
    return queueRear->info;
}

//Function  to remove the first element of the queue.
//Precondition: The queue exists and is not empty.
//Postcondition: The queue is changed and the first element
//    is removed from the queue.
template<class Type>
void queueType<Type>::deleteQueue()
{
    nodeType<Type> *temp;

    if (!isEmptyQueue())  //if the queue's not empty
    {
        temp = queueFront;             //temp points to first node
        queueFront = queueFront->next; //advance queueFront
        delete temp;                   //delete the first node
        if (queueFront == nullptr)     //if after deletion the
                                       //queue is empty
            queueRear = nullptr;       //set queueRear to nullptr
        count--;
    }
    else  //the queue's already empty, error
        cerr << "Cannot remove from an empty queue" << endl;
}

//Function to output the queue to the console in simple format.
//Precondition: The queue exists and is not empty.
template <class Type>
void queueType<Type>::printQueue()
{
    nodeType<Type> *current;  //current will traverse the queue

    if (!isEmptyQueue())  //if the queue's not empty
    {
        current = queueFront;  //current points to the first node
        while (current)
        {
            cout << current->info << " ";
            current = current->next;
        }
        cout << endl;
    }
    else
        cerr << "ERROR, can't print an empty queue.\n";
}

//Function to move an element of the queue to the front
//Precondition: The queue exists and is not empty.
//Postcondition: If the queue is empty, the program outputs an error message;
//    otherwise, the 'moveToFront'th element of the queue is moved to the front.
template <class Type>
void queueType<Type>::moveToFront(int index){
	//if the queue is not empty
	if(!isEmptyQueue()){
		nodeType<Type> *current = nullptr;
		nodeType<Type> *previous = nullptr;
		nodeType<Type> *toFront = nullptr;

		//if the element being moved to the front is not the front element
		if(index != 1){
			//traverse through the queue to the index
			current = queueFront;
			for(int i = 0; i < index-1; i++){
				previous = current;
				current = current->next;
			}

			//copies current node to toFront
			toFront = new nodeType<Type>;
			toFront->info = current->info;

			//moves toFront to the front of the queue
			toFront->next = queueFront;
			queueFront = toFront;

			//deletes current
			previous->next = current->next;
			delete current;
			//if it is the last element that was deleted
			if(index == count)
				queueRear = previous;
		}
	}
	else
		cout << "The queue is empty" << endl;
}
//destructor
template<class Type>
queueType<Type>::~queueType()
{
    nodeType<Type> *temp;
    while (queueFront)  //while elements remain in the queue
    {
        temp = queueFront;              //set temp to front node
        queueFront = queueFront->next;  //advance front to next node
        delete temp;                    //deallocate temp
    }
    queueRear = nullptr;                // set rear to nullptr
}

//overloaded assignment operator =
template<class Type>
const queueType<Type>& queueType<Type>::operator=
    (const queueType<Type>& otherQueue)
{
    nodeType<Type> *newNode; //pointer to create a node
    nodeType<Type> *current; //pointer to traverse the queue

    if (this != &otherQueue) //avoid self-copy
    {
        if (queueFront != nullptr)  //if queue isn't empty destroy our queue
                                    //so we can copy in a new one
            initializeQueue();

        if (otherQueue.queueFront == nullptr) //if otherQueue is empty
        {
            queueFront = nullptr;  //set our locative pointers to nullptr
            queueRear = nullptr;
        }
        else //otherList is not empty
        {
            //current points to the list to be copied
            current = otherQueue.queueFront;

            //copy the first node
            queueFront = new nodeType<Type>;    //create the node
            queueFront->info = current->info;   //copy the info
            queueFront->next = nullptr;         //set the next node to null
            queueRear = queueFront;     //make rear point to the first node
            current = current->next;    //advance current on otherQueue

            //copy the remaining list
            while (current)
            {
                newNode = new nodeType<Type>;  //create a node
                newNode->info = current->info; //copy the info
                newNode->next = nullptr;
                queueRear->next = newNode; //attach newNode after rear
                queueRear = newNode;       //set rear to actual rear node
                current = current->next;   //advance current
            }
        }
    }
    return *this;
}

#endif
