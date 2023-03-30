//*****************
//Program Name: Assignment 4: Most Frequent Value
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: Write a program that will find the most frequent value stored in an array of positive integers
//*****************

#include <iostream>
using namespace std;

int mostFrequentValue(int*);
int findMax(int*);
void plagiarismRequirement();

const int ARR_SIZE = 9;

int main(){
	int arr[ARR_SIZE] = {5, 1, 4, 5, 7, 1, 1, 6, 7};
	int index;

	index = mostFrequentValue(arr);

	if(index != -1){
		cout << "The most frequent value of the array is " << arr[index] << endl;
	}
	else{
		cout << "There is no most frequent value in the array" << endl;
	}

	plagiarismRequirement();

	return 0;
}

//*****************
//Function name: mostFrequentValue
//Purpose: finds the most frequent value in an array
//List of parameters:
//Returns:
//Return type: int
//*****************
int mostFrequentValue(int *arr){
	//creates a dynamically allocated array that holds the counts of each element
	//and a pointer to the array
	int *counts = new int[ARR_SIZE];
	int index;

	//initializes all elements of counts to 0
	for(int i = 0; i < ARR_SIZE; i++)
		counts[i] = 0;

	//compares the elements of two array and counts the frequency of each element of arr
	for(int i = 0; i < ARR_SIZE; i++){
		for(int j = 0; j < ARR_SIZE; j++){
			if(arr[i] == arr[j]){
				counts[i]++; //stores the frequency of each element
			}
		}
	}

	index = findMax(counts);

	//frees the memories for dynamically allocated count array
	delete [] counts;

	return index;
}

//*****************
//Function name: findMax
//Purpose: finds the biggest frequency value in counts array
//List of parameters: int *counts
//Returns: index
//Return type: int
//*****************
int findMax(int *counts){
	int temp; //holds a frequency element of the counts array
	int index; //holds the index of the biggest frequency in the array

	//finds the index of the biggest frequency value
	temp = counts[0];
	index = 0;
	for(int i = 0; i < ARR_SIZE; i++){
		if(counts[i] > temp){
			temp = counts[i];
			index = i;
		}
	}

	/*
	 * If there is only one highest frequency value in counts array,
	 * then the occurrence of that frequency value in counts array and the frequency value itself have to be the same.
	 * For example, consider an array int arr[ARR_SIZE] = {5, 1, 4, 5, 7, 1, 1, 6, 7};
	 * The counts[ARR_SIZE] for arr[ARR_SIZE] should be   {2, 3, 1, 2, 2, 3, 3, 1, 2}
	 * In the counts[ARR_SIZE] above, 3 is the biggest value of the counts array and it occurs three times.
	 * In other cases, where the array looks like {1, 2, 3, 4, 5} or {1, 1, 1, 2, 2, 2},
	 * the counts[] would look like 			  {1, 1, 1, 1, 1} or {3, 3, 3, 3, 3, 3}.
	 * Here, 1 is the biggest value of the counts array and it occurs five times and
	 * 		 3 is the biggest value of the counts array and it occurs six times.
	 * 		 ==> the occurrence of the frequency value != the frequency value itself
	 * Thus, if there are more than one value that is the most frequent or there is no most frequent value,
	 * the function will have to return -1
	 */
	//counts how many times the highest frequency value occurred in the counts array
	int occurrence = 0;
	for(int i = 0; i < ARR_SIZE; i++)
		if(counts[i] == counts[index])
			occurrence++;

	//if there are more than one value that is the most frequent or there is no most frequent value,
	//assigns -1 to index variable
	if(occurrence != counts[index])
		index = -1;

	return index;
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
