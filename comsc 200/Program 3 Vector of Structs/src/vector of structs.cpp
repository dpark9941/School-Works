//*****************
//Program Name: Program 3: Vector of Structs
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description:
//*****************

#include <iostream>
#include <iomanip>
#include <cstdlib> //rand()
#include <ctime> //time(0)
#include <vector>

using namespace std;

const int MIN = 5;
const int MAX = 50;
const int RGBMIN = 0;
const int RGBMAX = 255;
const int W1 = 4;
const int W2 = 5;

struct Color{
  int red;
  int green;
  int blue;
};

int main(){
  srand(time(0));
  vector<Color> colors;
  int numColors = rand() % (MAX - MIN + 1) + MIN;
  int r, g, b;

  for (int i = 0; i < numColors - 1; i++){
    r = rand() % (RGBMAX - RGBMIN + 1) + RGBMIN;
    g = rand() % (RGBMAX - RGBMIN + 1) + RGBMIN;
    b = rand() % (RGBMAX - RGBMIN + 1) + RGBMIN;
    Color tempColor = {r, g, b}; colors.push_back(tempColor);
  }

  cout << "Color#\tR value\tG value\tB value" << endl;
  cout << "------\t-------\t-------\t-------" << endl;
  for (int i = 0; i < colors.size() - 1; i++){
    cout << setw(W1) << i + 1 << "\t" << setw(W2) << colors.at(i).red << "\t" << setw(W2) << colors.at(i).green << "\t" << setw(W2) << colors.at(i).blue << "\t" << endl;
  }

  cout << endl;
  cout << "I attest that this code is my original programming work, and that I received" << endl;
  cout << "no help creating it. I attest that I did not copy this code or any portion of this" << endl;
  cout << "code from any source." << endl;

  return 0;
}
