//Actor.h
#ifndef ACTOR_H
#define ACTOR_H
#include <iostream>
#include <string>
#include "BinaryTree.h"
using namespace std;

//forward declare Employee class
class Actor;

//overload stream operator
ostream &operator<< (ostream &, Actor &);

class Actor
{

private:
	string name;
	int actID;
public:
    //constructor
	Actor(int id = 0, string n = "") { actID = id, name = n; }

    //setters and getters
	void setactID(int id) {actID = id;}
	void setName(string n) {name = n;}
	int getactID() {return actID;}
	string getName() {return name;}

    //overloaded operators
	bool operator==(int id)
		{ return this->getactID() == id; }
	bool operator==(const Actor &rightActor)
		{ return this->getactID() == rightActor.actID; }
	bool operator<(Actor rightActor)
		{ return this->getactID() < rightActor.actID; }
	bool operator>(Actor rightActor)
		{ return this->getactID() > rightActor.actID; }

    //keep this code for overloading <<
    friend ostream &operator<<(ostream &strm, Actor &obj)
    {
        strm << "ID Number: " << obj.actID << "\tName: " << obj.name << endl;
        return strm;
    }
};
#endif
