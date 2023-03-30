//*****************
//Program Name: Lab 9-2: Multiple Inheritance
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write three classes and exercise Multiple Inheritance
//*****************

#ifndef ALPHA_H
#define ALPHA_H

#include <string>
using namespace std;

class Alpha {
private:
  int number;
  string sentence;
public:
  //constructors
  Alpha() {
    number = 0;
    sentence = "";
  }
  Alpha(int number, string sentence) {
    setNumber(number);
    setSentence(sentence);
  }

  //mutators
  void setNumber(int number) {this->number = number;}
  void setSentence(string sentence) {this->sentence = sentence;}

  //accessors
  int getNumber() {return number;}
  string getSentence() {return sentence;}
};

#endif
