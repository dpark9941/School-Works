#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int ord;

	cout << "Enter the size of the matrix: ";
	cin >> ord;

	double matrix[ord][ord];
	double C[ord][ord]; //stores the cofactors
	double M[ord][ord]; //stores the minors
	double det;

	for (int r = 0; r < ord; r++) {
		cout << "Enter the " << r+1 << "th row: ";
	}

	//calculates Cnn
	for (int r = 0; r <ord; r++) {
		for (int c = 0; c < ord; c++) {
			C[r][c] = pow(-1, r+c) * M[r][c];
		}
	}

	//expanding 1st row
	for (int c = 0; c < ord; c++) {
		int r = 1;
		det = matrix[r][c] * C[r][c];
	}

	cout << "The determinant of the matrix is " << det << endl;




	return 0;
}
