#ifndef POLLINGPLACE_H
#define POLLINGPLACE_H

#include <string>
using namespace std;

struct PollingPlace {
	string address;
	string location; //e.g. school, firehouse, community center
	int machines; //number of voting machines
	int voters; //expected number of voters at that location
};

#endif
