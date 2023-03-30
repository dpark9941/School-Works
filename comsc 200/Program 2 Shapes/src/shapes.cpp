//*****************
//Program Name: Program 2: Shapes
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: does calculations for various shapes and outputs the results to console and txt file
//*****************

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

const double PI = 3.14159265359;
const string OBJECT1 = "SQUARE";
const string OBJECT2 = "RECTANGLE";
const string OBJECT3 = "CIRCLE";
const string OBJECT4 = "TRIANGLE";
const string OBJECT5 = "CUBE";
const string OBJECT6 = "BOX";
const string OBJECT7 = "CYLINDER";

int main(){

  string object = "";
  double dim1 = 0, dim2 = 0, dim3 = 0;
  ifstream fin;
  ofstream fout;
  fin.open("shapes.txt");
  fout.open("output.txt");

  //output formatting
  cout << fixed << showpoint << setprecision(2);
  fout << fixed << showpoint << setprecision(2);

  while (fin >> object >> dim1 >> dim2 >> dim3){

    if (object == OBJECT1){ //SQUARE
      cout << object << " side = " << dim1 << " area = " << dim1 * dim1 << " perimeter = " << 4 * dim1 << endl;
      fout << object << " side = " << dim1 << " area = " << dim1 * dim1 << " perimeter = " << 4 * dim1 << endl;
    }
    else if (object == OBJECT2){ //RECTANGLE
      cout << object << " length = " << dim1 << " width = " << dim2 << " area = " << dim1 * dim2 << " perimeter = " << 2 * (dim1 + dim2) << endl;
      fout << object << " length = " << dim1 << " width = " << dim2 << " area = " << dim1 * dim2 << " perimeter = " << 2 * (dim1 + dim2) << endl;
    }
    else if (object == OBJECT3){ //CIRCLE
      cout << object << " radius = " << dim1 << " area = " << PI * dim1 * dim1 << " perimeter = " << 2 * PI * dim1 << endl;
      fout << object << " radius = " << dim1 << " area = " << PI * dim1 * dim1 << " perimeter = " << 2 * PI * dim1 << endl;
    }
    else if (object == OBJECT4){ //TRIANGLE
      cout << object << " side = " << dim1 << " area = " << dim1 * dim1 * pow(3, 0.5) * 0.25 << " perimeter = " << 3 * dim1 << endl;
      fout << object << " side = " << dim1 << " area = " << dim1 * dim1 * pow(3, 0.5) * 0.25 << " perimeter = " << 3 * dim1 << endl;
    }
    else if (object == OBJECT5){ //CUBE
      cout << object << " side = " << dim1 << " volume = " << dim1 * dim1 * dim1 << " surface = " << 6 * dim1 * dim1 << endl;
      fout << object << " side = " << dim1 << " volume = " << dim1 * dim1 * dim1 << " surface = " << 6 * dim1 * dim1 << endl;
    }
    else if (object == OBJECT6){ //BOX
      cout << object << " length = " << dim1 << " width = " << dim2 << " height = " << dim3 << " volume = " << dim1 * dim2 * dim3 << " surface = " << 2 * (dim1 * dim1 + dim2 * dim2 + dim3 * dim3) << endl;
      fout << object << " length = " << dim1 << " width = " << dim2 << " height = " << dim3 << " volume = " << dim1 * dim2 * dim3 << " surface = " << 2 * (dim1 * dim1 + dim2 * dim2 + dim3 * dim3) << endl;
    }
    else if (object == OBJECT7){ //CYLINDER
      cout << object << " radius = " << dim1 << " height = " << dim2 << " volume = " << PI * dim1 * dim1 * dim2 << " surface = " << 2 * (PI * dim1 * dim1) +  (2 * PI * dim1) * dim2 << endl;
      fout << object << " radius = " << dim1 << " height = " << dim2 << " volume = " << PI * dim1 * dim1 * dim2 << " surface = " << 2 * (PI * dim1 * dim1) +  (2 * PI * dim1) * dim2 << endl;
    }
    else { //Invalid shapes
      cout << object << " invalid shape" << endl;
      fout << object << " invalid shape" << endl;
    }
  }

  cout << "I attest that this code is my original programming work, and that I received" << endl;
  cout << "no help creating it. I attest that I did not copy this code or any portion of this" << endl;
  cout << "code from any source." << endl;

  fout << "I attest that this code is my original programming work, and that I received" << endl;
  fout << "no help creating it. I attest that I did not copy this code or any portion of this" << endl;
  fout << "code from any source." << endl;

  fin.close();
  fout.close();

  return 0;
}
