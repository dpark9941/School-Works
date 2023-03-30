#include <iostream>
using namespace std;

int main(){
	int n = 0;
	double total = 1.0;
	double allDifferent = 1.0;
	double allDifferentP = 0.0;
	double atLeastTwoP = 0.0;

	cout << "Birthday problem calculator" << endl;
	cout << "Enter the number of people n: ";
	cin >> n;

	for(int i = 0; i < n; i++){
		total *= 365;
		allDifferent *= (365 - i);
	}

	allDifferentP = allDifferent / total;
	atLeastTwoP = 1.0 - allDifferentP;

	cout << endl;
	cout << "The probability that two or more people share the same birthday is ";
	cout << atLeastTwoP * 100 << "%" << endl;


	return 0;
}
