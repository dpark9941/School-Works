#include "Movie.h"
#include <iostream>
#include <string>
using namespace std;

Movie::Movie(){
	screenWriter = "";
	yearReleased = 0;
	title = "";
}

Movie::Movie(string sw, int yr, string t){
	screenWriter = sw;
	yearReleased = yr;
	title = t;
}

string Movie::getScreenWriter(){
	return screenWriter;
}

int Movie::getYearReleased(){
	return yearReleased;
}

string Movie::getTitle(){
	return title;
}

void Movie::setScreenWriter(string sw){
	screenWriter = sw;
}

void Movie::setYearReleased(int yr){
	yearReleased = yr;
}

void Movie::setTitle(string t){
	title = t;
}
