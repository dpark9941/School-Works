//stackType.h

#ifndef stackType_H
#define stackType_H
#include <iostream>
#include <cassert>
using namespace std;

template <class Type>
class stackType
{
private:
    int maxStackSize; //maximum stack size
    int stackTop;     //points to the top of the stack
    Type *list;       //pointer to the array that holds the stack
    void copyStack(const stackType<Type>& otherStack);
       //method only available internally via operator= overload
       //   and the copy constructor

public:
    //stack methods
    const stackType<Type>& operator=(const stackType<Type>&);
    void initializeStack()     { stackTop = 0; }
    bool isEmptyStack() const  { return(stackTop == 0); }
    bool isFullStack() const   { return(stackTop == maxStackSize); }
    void push(const Type& newItem);
    Type top() const;
    void pop();

    //constructors
    stackType(int stackSize = 100);
    stackType(const stackType<Type>&);

    //destructors
    ~stackType();

    //overloaded operators
    bool operator == (const stackType &);

    //other methods
    void displayStack();
    void reverseStack(stackType &);
};

//Function to make a copy of otherStack.
//Postcondition: A copy of otherStack is created and assigned
//    to this stack.
template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack)
{
    delete [] list;
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;

    list = new Type[maxStackSize];

        //copy otherStack into this stack
    for (int j = 0; j < stackTop; j++)
        list[j] = otherStack.list[j];
} //end copyStack

//Overload the assignment operator
template <class Type>
const stackType<Type>& stackType<Type>::operator=
                    (const stackType<Type>& otherStack)
{
    if (this != &otherStack) //avoid self-copy
        copyStack(otherStack);

    return *this;
} //end operator=

//Function to add newItem to the stack.
//Precondition: The stack exists and is not full.
//Postcondition: The stack is changed and newItem is
//    added to the top of the stack.
template <class Type>
void stackType<Type>::push(const Type& newItem)
{
    if (!isFullStack())
    {
        list[stackTop] = newItem;   //add newItem to the top
        stackTop++; //increment stackTop
    }
    else
        cerr << "Cannot add to a full stack." << endl;
}//end push

//Function to return the top element of the stack.
//Precondition: The stack exists and is not empty.
//Postcondition: If the stack is empty, the program
//    terminates; otherwise, the top element of the stack
//    is returned.
template <class Type>
Type stackType<Type>::top() const
{

    assert(stackTop != 0);          //if stack is empty,
                                    //terminate the program
    return list[stackTop - 1];      //return the element of the
                                    //stack indicated by
                                    //stackTop - 1
}//end top

//Function to remove the top element of the stack.
//Precondition: The stack exists and is not empty.
//Postcondition: The stack is changed and the top element is
//    removed from the stack.
template <class Type>
void stackType<Type>::pop()
{
    if (!isEmptyStack())
        stackTop--;                 //decrement stackTop
    else
        cerr << "Cannot remove from an empty stack." << endl;
}//end pop

//Constructor
//Create an array of the size stackSize to hold
//the stack elements. The default stack size is 100.
//Postcondition: The variable list contains the base address
//   of the array, stackTop = 0, and maxStackSize = stackSize
template <class Type>
stackType<Type>::stackType(int stackSize)
{
    if (stackSize <= 0)
    {
        cerr << "Size of the array to hold the stack must "
             << "be positive." << endl;
        cerr << "Creating an array of size 100." << endl;

        maxStackSize = 100;
    }
    else
        maxStackSize = stackSize;   //set the stack size to
                                    //the value specified by
                                    //the parameter stackSize

    stackTop = 0;                   //set stackTop to 0
    list = new Type[maxStackSize];  //create the array to
                                    //hold the stack elements
}//end constructor

//Copy constructor
template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
    list = NULL;
    stackTop = 0;
    maxStackSize = 0;

    copyStack(otherStack);
}//end copy constructor

//Destructor
//Remove all the elements from the stack.
//Postcondition: The array (list) holding the stack
//    elements is deleted.
template <class Type>
stackType<Type>::~stackType() //destructor
{
    delete [] list; //deallocate the memory occupied
                    //by the array
}//end destructor

//operator ==: checks if two boxes' volume()s are same
//Arguments: &right | Returns: status
template <class Type>
bool stackType<Type>::operator == (const stackType &right){
	bool status = true;

	//checks for the case of self-assignment
	if(this == &right)
		status = true;

	//checks if the size of the two stacks are equal
	else if(maxStackSize != right.maxStackSize)
		status = false;

	//checks if the stack tops are equal
	else if(stackTop != right.stackTop)
		status = false;

	//checks if all the elements in the stacks are the same
	else{
		for(int i = stackTop; i > 0; i--){
			if(list[i-1] != right.list[i-1]) //if the two corresponding elements are different
				status = false;
			break;
		}
	}

	return status;
}

//displayStack(): displays the elements of the stack from top
//Arguments: none | Returns: void
template <class Type>
void stackType<Type>::displayStack(){
	for(int i = stackTop; i > 0; i--)
		cout << '\t' << list[i-1] << endl;
}

//reverseStack(): creates a reverse copy of a target stack
//Arguments: &reverse | Returns: void
template <class Type>
void stackType<Type>::reverseStack(stackType &reverse){
	//if the size of the two stacks are different
	if(maxStackSize != reverse.maxStackSize){
		cerr << "The size of two stacks are different" << endl;
		cerr << "Setting the size of the new stack as the size of the target stack..." << endl;
		reverse.maxStackSize = maxStackSize;
	}

	for(int i = stackTop - 1; i >= 0; i--) //counts down in stack1
		reverse.push(list[i]);
}

#endif
