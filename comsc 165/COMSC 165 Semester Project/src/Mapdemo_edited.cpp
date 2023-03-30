#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const string DIR = "D:\\DVC\\2020SP\\COMSC-165-1317\\Workspace\\COMSC 165 Semester Project\\MapDataText\\"; //map data directory. Need to be edited according to your own directory

//function prototypes
void ReadText(string);
int GetInput(int);
void Goto();
int Action();
void Street();
void Inn();
void Forest();
void Alleyway();
void Store();
void Sewers();
void Castle();
void Church();

int main() {
	Street();
    cout << "End of demo.";
    return 0;
}

void ReadText(string file_name)
{
	ifstream file_reader;
	file_reader.open(DIR+file_name);

	//if the file is not open
	if(file_reader.fail())
	{
		cout << "Error! The text file does not exist!\n";
		cout << "Program ending..." << endl;
		exit(0);
	}

	// output the content from the text file
	string temp;
	while(!file_reader.eof())
	{
		getline(file_reader,temp);
		cout << temp << endl;
	}
	file_reader.close();
}

int GetInput(int input = 0)
{
	cout << endl;
	cout << "Choose your option:\n"
		 << "1) Move\n"
		 << "2) Action\n"
		 << "Enter: ";
	cin >> input;
	while(input != 1 && input != 2){
		cout << "\nOnly Enter 1 or 2: ";
		GetInput();
	}

	return input;
}

void Goto()
{
	int choice;
	cout << endl;
	cout << "Go to:\n"
		 << "1) Street\n"
		 << "2) Inn\n"
		 << "3) Forest\n"
		 << "4) Alleyway\n"
		 << "5) Store\n"
		 << "6) Sewers\n"
		 << "7) Castle\n"
		 << "8) Church\n"
		 << "Or any number to end\n"
		 << "Enter: ";
	cin >> choice;

	if(choice == 1) Street();
	else if(choice == 2) Inn();
	else if(choice == 3) Forest();
	else if(choice == 4) Alleyway();
	else if(choice == 5) Store();
	else if(choice == 6) Sewers();
	else if(choice == 7) Castle();
	else if(choice == 8) Church();
	else
	{
		cout << "Program ending...";
		exit(0);
	}
}

int Action()
{
	int action_type;
	cout << endl;
	cout << "Action 1\n"
		 << "Action 2\n"
		 << "Action 3\n"
		 << "\nEnter: ";
	cin >> action_type;

	return action_type;
}

void Street()
{
	string file_name = "Street.txt";
	ReadText(file_name);

	if (GetInput() == 1) Goto();
	else Action(); //if GetInput() == 2
}

void Inn()
{
	string file_name = "Inn.txt";
	ReadText(file_name);

	if (GetInput() == 1) Goto();
	else Action(); //if GetInput() == 2
}

void Forest()
{
	string file_name = "Forest.txt";
	ReadText(file_name);

	if (GetInput() == 1) Goto();
	else Action(); //if GetInput() == 2
}

void Alleyway()
{
	string file_name = "Alleyway.txt";
	ReadText(file_name);

	if (GetInput() == 1) Goto();
	else Action(); //if GetInput() == 2
}

void Store()
{
	string file_name = "Store.txt";
	ReadText(file_name);

	if (GetInput() == 1) Goto();
	else Action(); //if GetInput() == 2
}

void Sewers()
{
	string file_name = "Sewers.txt";
	ReadText(file_name);

	if (GetInput() == 1) Goto();
	else Action(); //if GetInput() == 2
}

void Castle()
{
	string file_name = "Castle.txt";
	ReadText(file_name);

	if (GetInput() == 1) Goto();
	else Action(); //if GetInput() == 2
}

void Church()
{
	string file_name = "Church.txt";
	ReadText(file_name);

	if (GetInput() == 1) Goto();
	else Action(); //if GetInput() == 2
}
