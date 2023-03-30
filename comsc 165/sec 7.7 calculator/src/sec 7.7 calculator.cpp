#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

const double e = 2.71828182846;
const double pi = 3.14159265359;

double t (vector<double>&, double);
double s (vector<double>&, double);
void func(double, double, double, vector<double>&);
void StringToMath(string);

int main() {

	double start, end, n;
	vector<double> yValue;
	string function;

	cout << "enter starting point: ";
	cin >> start;
	cout << "enter ending point: ";
	cin >> end;
	cout << "enter the number of subintervals: ";
	cin >> n;
	/*
	cout << "enter the function (in terms of x): ";
	getline(cin, function);
	*/

	double dx = (end - start) / n;
	dx -= 0.0000000000000001;

	func(start, end, dx, yValue);

	cout << setprecision(8);
	cout << "Tn: " << t(yValue, dx) << endl;
	cout << "Sn: " << s(yValue, dx) << endl;

	return 0;
}

//Trapezoidal Rule
double t (vector<double> &yVal, double dx){

	double subtotal = 0, Tn;

	for (int i = 0; i < yVal.size(); i++) {
		if (i != 0 && i != yVal.size() - 1){
			subtotal += 2 * yVal.at(i);
		} else {
			subtotal += yVal.at(i);
		}
	}

	Tn = (1.0/2.0) * dx * subtotal;

	return Tn;
}

//Simpson's Rule
double s (vector<double> &yVal, double dx){

	double subtotal = 0, Sn;

	for (int i = 0; i < yVal.size(); i++) {
		if (i != 0 && i != yVal.size() - 1){
			if (i % 2 == 1){
				subtotal += 4 * yVal.at(i);
			} else {
				subtotal += 2 * yVal.at(i);
			}
		} else {
			subtotal += yVal.at(i);
		}
	}

	Sn = (1.0/3.0) * dx * subtotal;

	return Sn;
}

void func(double start, double end, double dx, vector<double> &yVal){

	double y;
	double xVal = start;
	int j = 0;

	while (xVal <= end){
		y = pow(xVal,3);
		yVal.push_back(y);
		j++;
		xVal += dx;
	}
}

//Recursive descent parser
//Shunting-yard algorithm
void StringToMath(string function){
	double y;
	char mult = '*', div = '/', add = '+', sub = '-', power = '^', factorial = '!';
	char open = '(', close = ')';

	for (int i = 0; function.at(i) != '\0'; i++){

	}

}
