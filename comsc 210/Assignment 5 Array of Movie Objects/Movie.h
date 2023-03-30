#ifndef MOIVIE_H
#define MOVIE_H

#include <string>
using namespace std;

/*
----------------------------
         Movie
----------------------------
- screenWriter: string
- yearReleased: int
- title: string
----------------------------
+ Movie()
+ Movie(string, int, string)
+ getScreenWriter(): string
+ getYearReleased(): int
+ getTitle(): string
+ setScreenWriter(string): void
+ setYearReleased(int): void
+ setTitle(string): void
----------------------------
*/

class Movie{
private:
	string screenWriter;
	int yearReleased;
	string title;
public:
	//constructors
	Movie();
	Movie(string, int, string);

	//accessors
	string getScreenWriter();
	int getYearReleased();
	string getTitle();

	//mutators
	void setScreenWriter(string);
	void setYearReleased(int);
	void setTitle(string);
};

#endif
