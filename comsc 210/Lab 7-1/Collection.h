#ifndef COLLECTION_H
#define COLLECTION_H

#include <iostream>
#include <vector>
using namespace std;

/*
----------------------------
  	  	 Collection
----------------------------
- myVector : vector<T>
----------------------------
+ Collection(int, T)
+ push(T) : void
+ print() : void
+ setValue(T, int) : void
----------------------------
*/

template <typename T>
class Collection{
private:
	vector<T> myVector;
public:
	//constructor
	Collection(int size, T initialize){
		for(int i = 0; i < size; i++){
			myVector.push_back(initialize);
		}
	}

	//push(): pushes data at the end of myVector
	//Arguments: val (T) | Returns: (void)
	void push(T val){
		myVector.push_back(val);
	}

	//print(): prints data of myVector
	//Arguments: none | Returns: (void)
	void print(){
		for(T val : myVector)
			cout << val << endl;
		cout << endl;
	}

	//setValue(): assigns val to ith element of myVector
	//Arguments: val, i (T, int) | Returns: (void)
	void setValue(T val, int i){
		myVector[i] = val;
	}
};

#endif
