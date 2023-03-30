#ifndef MAPDATA_H_INCLUDED
#define MAPDATA_H_INCLUDED
#include "InTown.h"
#include "enemyBattle.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

class Mapping {
    friend class InTown;
private:
    int choice;
    int location_id;
    std::string temp;
    const std::string DIR = "D:\\DVC\\2020SP\\COMSC-165-1317\\Workspace\\COMSC 165 Semester Project\\MapDataText\\"; // CHANGE BASED ON LOCATION!
    std::string file_loc;
public:
// read file
void ReadText(std::string file_name) // FIX THIS PLS!!!!
{
	std::ifstream file;
	file.open(file_name);

	//if the file is not open
	if(file.fail())
	{
		std::cout << "Error! The text file does not exist!\n";
		std::cout << "Program ending..." << std::endl;
		exit(0);
	}

	// output the content from the text file
	std::string temp;
	while(!file.eof())
	{
		getline(file,temp);
		std::cout << temp << std::endl;
	}
	file.close();
}

void Street() {
	location_id = 5;
	file_loc = "Street.txt";
	ReadText(DIR+file_loc);

	switch (choice) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	default:
		break;
	}
}

void Inn() {
	location_id = 2;
	file_loc = "Inn.txt";
	ReadText(DIR+file_loc);

	switch (choice) {
	case 1:
		break;
	case 2:

		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	default:
		break;
	}
}

void Forest() {
	location_id = 3;
	file_loc = "Forest.txt";
	ReadText(DIR+file_loc);

	switch (choice) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	default:
		break;
	}
}
void Alleyway() {
	location_id = 4;
	file_loc = "Alleyway.txt";
	ReadText(DIR+file_loc);

	switch (choice) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	default:
		break;
	}
}
void Castle() {
}
void Sewers() {
}
void Store() {
}
void Church() {
}
};

#endif // MAPDATA_H_INCLUDED
