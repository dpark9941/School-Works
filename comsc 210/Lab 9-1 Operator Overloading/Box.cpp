#include "Box.h"

//operator ==: checks if two boxes' volume()s are same
//Arguments: &right | Returns: status
bool Box::operator == (const Box &right){
	bool status;

	if(volume == right.volume)
		status = true;
	else
		status = false;

	return status;
}

//operator >: checks if two boxes' volumes are greater than one another
//Arguments: &right | Returns: status
bool Box::operator > (const Box &right){
	bool status;

	if(volume > right.volume)
		status = true;
	else
		status = false;

	return status;
}

//operator <: checks if two boxes' volumes are less than one another
//Arguments: &right | Returns: status
bool Box::operator < (const Box &right){
	bool status;

	if(volume < right.volume)
		status = true;
	else
		status = false;

	return status;
}

//operator >=: checks if two boxes' lengths, widths, and heights are greater than or equal to one another
//Arguments: &right | Returns: status
bool Box::operator >= (const Box &right){
	bool status;

	if(length >= right.length && width >= right.width && height >= right.height)
		status = true;
	else
		status = false;

	return status;
}

//operator <=: checks if two boxes' lengths, widths, and heights are less than or equal to one another
//Arguments: &right | Returns: status
bool Box::operator <= (const Box &right){
	bool status;

	if(length <= right.length && width <= right.width && height <= right.height)
		status = true;
	else
		status = false;

	return status;
}
