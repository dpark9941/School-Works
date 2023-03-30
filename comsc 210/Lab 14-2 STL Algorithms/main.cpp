//*****************
//Program Name: Lab 14-2: STL::Algorithms
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Code some interesting program that uses several of these STL::Algorithms found under <algorithm>
//*****************
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

template <class T>
void displayDeque(deque<T> &);
template <class T>
void Insert(deque<T> &);
template <class T>
void Remove(deque<T> &);
template <class T>
void Sort(deque<T> &);
template <class T>
void Find(deque<T> &);
void plagiarismRequirement();

int main() {
    //populates a deque of int
    deque<int> myDeque;
    myDeque.push_back(1);
    myDeque.push_back(2);
    myDeque.push_back(3);
    myDeque.push_back(4);
    myDeque.push_back(5);

    cout << "This program performs several operations on array" << endl;
    cout << "Your initial array is: ";
    displayDeque(myDeque);

    int choice = 0;
    char anotherOperation = ' ';
    do{
        cout << endl << endl;
        cout << "Select an operation to perform on your array:" << endl;
        cout << "[1] Insert an element" << endl;
        cout << "[2] Remove an element" << endl;
        cout << "[3] Sort array" << endl;
        cout << "[4] Find an element" << endl;
        cout << "[5} Randomly shuffle array" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                Insert(myDeque);
                break;
            case 2:
                Remove(myDeque);
                break;
            case 3:
                Sort(myDeque);
                break;
            case 4:
                Find(myDeque);
                break;
            case 5:
            	random_shuffle(myDeque.begin(), myDeque.end());
            	break;
            default:
                cout << "Error: Invalid choice" << endl;
        }

        cout << "New array: "; displayDeque(myDeque);

        cout << "Perform another operation? (Y/N): ";
        cin >> anotherOperation;

    } while(tolower(anotherOperation) == 'y');

    plagiarismRequirement();

    return 0;
}

template <class T>
void displayDeque(deque<T> &myDeque){
    for(T val : myDeque) cout << val << ' ';
    cout << endl;
}

template <class T>
void Insert(deque<T> &myDeque){
    int operation = 0;
    T insertVal;

    cout << endl;
    cout << "What type of insertion do you want to perform?" << endl;
    cout << "[1] Insert element at the very front" << endl;
    cout << "[2] Insert element at the very back" << endl;
    cout << "[3] Insert element at user-entered position" << endl;
    cout << "Choose which operation to perform: "; cin >> operation;
    cout << "Enter the value to insert: "; cin >> insertVal;

    int position = 0;
    switch(operation){
        case 1:
            myDeque.push_front(insertVal);
            break;
        case 2:
            myDeque.push_back(insertVal);
            break;
        case 3:
            cout << "Enter the position of the value from 1 to " << myDeque.size() << ": ";
            cin >> position;
            myDeque.emplace(myDeque.begin() + position - 1, insertVal);
            break;
        default:
            cout << "Error: invalid choice" << endl;
    }
}

template <class T>
void Remove(deque<T> &myDeque){
    int operation = 0;
    T removeVal;

    cout << endl;
    cout << "What type of insertion do you want to perform?" << endl;
    cout << "[1] Remove element at the very front" << endl;
    cout << "[2] Remove element at the very back" << endl;
    cout << "[3] Remove element at user-entered position" << endl;
    cout << "[4] Remove a user-entered value" << endl;
    cout << "Choose which operation to perform: "; cin >> operation;

    int position = 0;
    switch(operation){
        case 1:
            myDeque.pop_front();
            break;
        case 2:
            myDeque.pop_back();
            break;
        case 3:
            cout << "Enter the position of the value to remove from 1 to " << myDeque.size() << ": ";
            cin >> position;
            myDeque.erase(myDeque.begin() + position - 1);
            break;
        case 4:
        	cout << "Enter the value to remove: "; cin >> removeVal;
        	remove(myDeque.begin(), myDeque.end(), removeVal);
        	break;
        default:
            cout << "Error: invalid choice" << endl;
    }
}

template <class T>
void Sort(deque<T> &myDeque){
    int operation = 0;

    cout << endl;
    cout << "What type of sorting do you want to perform?" << endl;
    cout << "[1] Sort in ascending order" << endl;
    cout << "[2] sort in descending order" << endl;
    cout << "Choose which operation to perform: "; cin >> operation;

    switch(operation){
        case 1:
        	sort(myDeque.begin(), myDeque.end());
        	break;
        case 2:
        	sort(myDeque.begin(), myDeque.end());
        	reverse(myDeque.begin(), myDeque.end());
            break;
        default:
            cout << "Error: invalid choice" << endl;
    }
}

template <class T>
void Find(deque<T> &myDeque){
	T val;

    cout << "Enter a value to find: ";
    cin >> val;

    auto result = find(myDeque.begin(), myDeque.end(), val);

    cout << (result != myDeque.end() ? "Found." : "Not found.") << endl;
}

//*****************
//Function name: plagiarismRequirement
//Purpose: outputs plagiarism Requirement
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
