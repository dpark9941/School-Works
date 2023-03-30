//============================================================================
// Name        : mid-term assignment 2.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : mid-term assignment 2
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

ofstream outputFile;

int main(){

	srand(time(0)); //seed value for rand()
	//declarations
	char response; //user response
	bool odd = false, even = false, both = false; //either odd or even or both
	bool outfile = false; //either output a file or not
	bool sumB = false, averageB = false, smallB = false, largeB = false;
	string fileName; //user input of file name

	do
	{
		int columns = 0, rows = 0; //the number of columns and rows
		int sum = 0;
		double average = 0;
		int min = 0, max = 0; // minimum and maximum random number
		double value = 0;
		int digitCounter = 1;
		cout << "This program will output a table of random numbers that you customize" << endl;
		cout << "\t> How many columns do you want (1-15)? ";
		cin >> columns;
		while (columns < 1 || columns > 15)
		{
			cout << "\t> ERROR! 1-15 only: ";
			cin >> columns;
		}
		cout << "\t> How many rows do you want (1-15)? ";
		cin >> rows;
		while (rows < 1 || rows > 15)
		{
			cout << "\t> ERROR! 1-15 only: ";
			cin >> rows;
		}
		cout << "\t> Do you want (O)dd, (E)ven, or (B)oth types of numbers? ";
		cin >> response;
		while (tolower(response) != 'o' && tolower(response) != 'e' && tolower(response) != 'b')
		{
			cout << "\t> ERROR! O/E/B only: ";
			cin >> response;
		}
		if (tolower(response) == 'o')
			odd = true;
		if (tolower(response) == 'e')
			even = true;
		if (tolower(response) == 'b')
		{
			both = true;
		}

		cout << "\t> Do you want to output to a file as well? Y/N: ";
		cin >> response;
		while (tolower(response) != 'y' && tolower(response) != 'n')
		{
			cout << "\t> ERROR! Y/N only: ";
			cin >> response;
		}
		if (tolower(response) == 'y')
		{
			outfile = true;
			cout << "\t> Enter an output filename (no spaces and ending in .txt): ";
			cin >> fileName;
		}
		cout << "\t> What is your minimum random number desired (0 - 10000): ";
		cin >> min;
		while (min < 0 || min > 10000)
		{
			cout << "\t> ERROR! 0-10000 only: ";
			cin >> min;
		}
		cout << "\t> What is your maximum random number desired (1-99999 and must be greater than your minimum random number desired): ";
		cin >> max;
		while (max <= min || max > 99999)
		{
			cout << "\t> ERROR! max must be greater than min and be smaller than 99999: ";
			cin >> max;
		}

		//dynamic field widths
		value = max;
		while (value / 10 >= 1)
		{
			digitCounter++;
			value /= 10;
		}

		//display the sum
		cout << "\t> Display the sum of the random numbers in the table (Y/N)? ";
		cin >> response;
		while (tolower(response) != 'y' && tolower(response) != 'n')
		{
			cout << "\t> ERROR! Y/N only: ";
			cin >> response;
		}
		if (tolower(response) == 'y')
			sumB = true;

		//display the average
		cout << "\t> Display the average of the random numbers in the table (Y/N)? ";
		cin >> response;
		while (tolower(response) != 'y' && tolower(response) != 'n')
		{
			cout << "\t> ERROR! Y/N only: ";
			cin >> response;
		}
		if (tolower(response) == 'y')
			averageB = true;

		//display the largest
		cout << "\t> Display the largest random number generated in the table (Y/N)? ";
		cin >> response;
		while (tolower(response) != 'y' && tolower(response) != 'n')
		{
			cout << "\t> ERROR! Y/N only: ";
			cin >> response;
		}
		if (tolower(response) == 'y')
			smallB = true;

		//display the smallest
		cout << "\t> Display the smallest random numbers generated in the table (Y/N)? ";
		cin >> response;
		while (tolower(response) != 'y' && tolower(response) != 'n')
		{
			cout << "\t> ERROR! Y/N only: ";
			cin >> response;
		}
		if (tolower(response) == 'y')
			largeB = true;

		int largest = min - 1;
		int smallest = max + 1;
		if (outfile)
			outputFile.open(fileName);

		for (int r = 1; r <= rows; r++)
		{
			for (int c = 1; c <= columns; c++)
			{
				if (both)
				{
					int randNr = rand() % (max - min + 1) + min;
					if (outfile)
						outputFile << setw(digitCounter + 2) << randNr;
					cout << setw(digitCounter + 2) << randNr;
					if (randNr > largest)
						largest = randNr;
					if (randNr < smallest)
						smallest = randNr;
					sum += randNr;
				}

				else if (odd)
				{
					int randNr = rand() % (max - min + 1) + min;
					if (randNr % 2 != 1)
					{
						c--;
						continue;
					}
					else
					{
						if (outfile)
							outputFile << setw(digitCounter + 2) << randNr;
						cout << setw(digitCounter + 2) << randNr;
						if (randNr > largest)
							largest = randNr;
						if (randNr < smallest)
							smallest = randNr;
						sum += randNr;
					}

				}

				else if (even)
				{
					int randNr = rand() % (max - min + 1) + min;
					if (randNr % 2 != 0)
					{
						c--;
						continue;
					}
					else
					{
						if (outfile)
							outputFile << setw(digitCounter + 2) << randNr;
						cout << setw(digitCounter + 2) << randNr;
						if (randNr > largest)
							largest = randNr;
						if (randNr < smallest)
							smallest = randNr;
						sum += randNr;
					}

				}

			}
			if (outfile)
				outputFile << endl;
			cout << endl;
		}

		average = (double)sum / (rows*columns);

		if (sumB || averageB || largeB || smallB)
		{
			cout << setprecision(2) << fixed << showpoint << endl;
			cout << "\t> Table statistics" << endl;
			if (outfile)
			{
				outputFile << setprecision(2) << fixed << showpoint << endl;
				outputFile << "\t> Table statistics" << endl;
			}
		}

		if (sumB)
		{
			cout << "\t> Sum: " << sum << endl;
			if (outfile) outputFile << "\t> Sum: " << sum << endl;
		}
		if (averageB)
		{
			cout << "\t> Average: " << average << endl;
			if (outfile) outputFile << "\t> Average: " << average << endl;
		}
		if (largeB)
		{
			cout << "\t> Largest: " << largest << endl;
			if (outfile) outputFile << "\t> Largest: " << largest << endl;
		}
		if (smallB)
		{
			cout << "\t> Smallest: " << smallest << endl;
			if (outfile) outputFile << "\t> Smallest: " << smallest << endl << endl;
		}

		cout << "\t> Repeat program? Y/N: ";
		cin >> response;
		while (tolower(response) != 'y' && tolower(response) != 'n')
		{
			cout << "ERROR! Y/N only: ";
			cin >> response;
		}

	} while (tolower(response) == 'y');

	cout << "Program ending... Have a nice day" << endl;

	return 0;
}
