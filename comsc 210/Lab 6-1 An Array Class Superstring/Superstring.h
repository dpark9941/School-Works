#ifndef SUPERSTRING_H
#define SUPERSTRING_H

#include <string>
using namespace std;

/*
----------------------------
         Superstring
----------------------------
- myString: string*
- arrSize: int
- temp: string
----------------------------
+ Superstring()
+ ~Superstring()
+ getMyString(): string *
+ getArrSize(): int
+ getTemp(): string
+ setMyString(string *): void
+ setArrSize(int): void
+ setTemp(string): void
+ outputString(): void
+ storeString(string *, int, string): void
+ getFirst(): string
+ getLast(): string
+ getString(): string
----------------------------
*/

class Superstring{
private:
	string *myString;
	int arrSize;
	string temp;
public:
	//constructor
	Superstring();

	//destructor
	~Superstring();

	//accessors
	string *getMyString();
	int getArrSize();
	string getTemp();

	//mutators
	void setMyString(string *);
	void setArrSize(int);
	void setTemp(string);

	//other methods
	void outputString();
	void storeString(string *, int, string);
	string getFirst();
	string getLast();
	string getString();
};
#endif
