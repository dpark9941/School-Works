//*****************
//Program Name: Program 4: Create a Simple Class
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: reads text from a file and outputs information about some movies
//*****************

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int ARR_SIZE = 4;

/*
 * Movie
 * ============================
 * - screenWriter: int
 * - yearReleased: int
 * - title: int
 * ============================
 * + setScreenWriter(a: string): void
 * + setYearReleased(y: int): void
 * + setTitle(t: string): void
 * + getScreenWriter(): string
 * + getYearReleased(): int
 * + getTitle(): string
 * ============================
 */

class Movie{
  private:
    string screenWriter;
    int yearReleased;
    string title;
  public:
    void setScreenWriter(string);
    void setYearReleased(int);
    void setTitle(string);
    string getScreenWriter();
    int getYearReleased();
    string getTitle();
};

//assigns a value to the screenWriter member
void Movie::setScreenWriter(string a){
  screenWriter = a;
}

//assigns a value to the yearReleased member
void Movie::setYearReleased(int y){
  yearReleased = y;
}

//assigns a value to the title member
void Movie::setTitle(string t){
  title = t;
}

//returns the value in the screenWriter member
string Movie::getScreenWriter(){
  return screenWriter;
}

//returns the value in the yearReleased member
int Movie::getYearReleased(){
  return yearReleased;
}

//returns the value in the title member
string Movie::getTitle(){
  return title;
}

int main(){
  //variable declaration
  Movie movieList[ARR_SIZE];
  string author;
  int yearReleased;
  string title;

  //program introduction
  cout << "This program will create several objects depicting movies" << endl;
  cout << "Reading input file..." << endl;

  //reads the txt file and stores the values into the array
  int index = 0;
  ifstream fin;
  fin.open("input.txt");
  while (fin.good()){
    getline(fin, author);
    fin >> yearReleased;
    fin.ignore();
    getline(fin, title);
    movieList[index].setScreenWriter(author);
    movieList[index].setYearReleased(yearReleased);
    movieList[index].setTitle(title);
    index++;
  }
  fin.close();
  cout << "Done" << endl << endl;

  //outputs information about the movies
  for (int i = 0; i < ARR_SIZE; i++){
    cout << "Movie: " << movieList[i].getTitle() << endl;
    cout << "\t> Year released: " << movieList[i].getYearReleased() << endl;
    cout << "\t> Screen Writer: " << movieList[i].getScreenWriter() << endl;
    cout << endl;
  }

  cout << endl;
  cout << "I attest that this code is my original programming work, and that I received" << endl;
  cout << "no help creating it. I attest that I did not copy this code or any portion of this" << endl;
  cout << "code from any source." << endl;

  return 0;
}
