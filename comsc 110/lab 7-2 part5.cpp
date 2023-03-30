//============================================================================
// Name        : lab 7-2 part5.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : outputs the sum of the sales of each regions
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

const int MONTHS = 12; //size of the rows of the array
const int REGIONS = 3; //size of the columns of the array

int main(){

	int sales [MONTHS][REGIONS] = {{6545, 6420, 6541},
									{4688, 9280, 9874},
									{1258, 6000, 3214},
									{8452, 5050, 7412},
									{3650, 8544, 8523},
									{2140, 5222, 9632},
									{3250, 9512, 1478},
									{3659, 4500, 2589},
									{4521, 3200, 3698},
									{6900, 3205, 8451},
									{2630, 4722, 9562},
									{5024, 8744, 3568}};

	cout << "This program displays the sum of sales by region" << endl << endl;

	for (int r = 0; r < REGIONS; r++){
		int sum = 0; //sum of each row
		for (int m = 0; m < MONTHS; m++)
			sum += sales[m][r];
		cout << "Region " << r + 1 << " Sales: " << sum << endl;
	}
	return 0;
}

