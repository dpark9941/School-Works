
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "Check.h"
using namespace std;

int main() {
  //defines vector of type Check
  vector<Check> checkList;

  //variable declaration for reading file
  ifstream finCheck("checks.txt");
  string payee, date, tempAmount, memo, tempCheckNo;
  float amount;
  int checkNo;

  //reads file into checkList
  while (finCheck.good()) {
    getline(finCheck, payee);
    getline(finCheck, date);
    getline(finCheck, tempAmount);
    getline(finCheck, memo);
    getline(finCheck, tempCheckNo);
    amount = stof(tempAmount);
    checkNo = stoi(tempCheckNo);
    Check tempCheck(payee, date, amount, memo, checkNo);
    checkList.push_back(tempCheck);
  }
  finCheck.close();

  for (Check tempCheck : checkList)
    tempCheck.print();

  return 0;
}
