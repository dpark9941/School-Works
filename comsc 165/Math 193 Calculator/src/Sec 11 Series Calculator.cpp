#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

const double e = 2.71828182846;
const double pi = 3.14159265359;
const int SET_PRECISION = 6;

void CalculateTerm(int, vector<double>&);
void CalculatePartialSum(vector<double>, vector<double>&);
void CalculateSeries();

int main() {

	int numTerms; //the number of terms
	vector<double> sequence;
	vector<double> partialSums;

	cout << "enter the number of terms of the sequence: ";
	cin >> numTerms;

	CalculateTerm(numTerms, sequence);
	CalculatePartialSum(sequence, partialSums);

	cout << fixed << setprecision(SET_PRECISION);
	cout << "The terms of the sequence are:" << endl;
	for (int i = 0; i < numTerms; i++) {
		cout << sequence.at(i) << endl;
	}

	cout << endl;

	cout << "The partial sums are:" << endl;
	for (int i = 0; i < numTerms; i++) {
		cout << partialSums.at(i) << endl;
	}

	return 0;
}

void CalculateTerm(int numTerms, vector<double> &sequence){
	double term;
	for (int i = 1; i <= numTerms; i++){
		term = 1 / (double)(i);
		sequence.push_back(term);
	}
}
void CalculatePartialSum(vector<double> sequence, vector<double> &partialSums){
	double partialSum;
	int nthTerm = 1;
	while (nthTerm <= sequence.size()){
		partialSum = 0;
		for (int i = 0; i < nthTerm; i++){
			partialSum += sequence.at(i);
		}
		partialSums.push_back(partialSum);
		nthTerm++;
	}
}
