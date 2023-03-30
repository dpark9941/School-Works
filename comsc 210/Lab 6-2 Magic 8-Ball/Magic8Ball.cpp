#include "Magic8Ball.h"
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

Magic8Ball::Magic8Ball(){
	srand(time(0));
	selectedAns = rand() % (MAX - MIN + 1) + MIN;

}

//outputString(): shakes the magic 8-ball
//Arguments: (void) | Returns: (void)
void Magic8Ball::shake(){
	int shake = rand() % (MAX - MIN + 1) + MIN;
	setSelectedAns(shake);
	incrementCount(shake);
}
