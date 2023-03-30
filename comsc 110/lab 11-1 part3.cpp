//============================================================================
// Name        : lab 11-1 part2.cpp
// Author      : Donggyu Park
// IDE Used    : Eclipse
// Description : gets info from the user and writes them into a structure
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

struct JobInfo{
	string description;
	string status; //full time or part time
	double salary;
	string type; //salaried or hourly
};

JobInfo makeJobs();
void writeJobs(JobInfo&);

int main(){
	JobInfo job1;
	job1 = makeJobs();
	return 0;
}

//=======================================================
//Function name: makeJobs
//Purpose: calls a function that writes informations and returns a structure
//Return type: JobInfo
//Returns: job
//=======================================================
JobInfo makeJobs(){
	JobInfo job;
	writeJobs(job);
	return job;
}
//=======================================================
//Function name: writeJobs
//Purpose: writes informations about a job into a structure
//List of parameters: a data structure
//Return type: void
//Returns:
//=======================================================
void writeJobs(JobInfo &job){
	cout << "Enter" << endl;
	cout << "Description: ";
	getline(cin, job.description);
	cout << "Status (full time or part time): ";
	getline(cin, job.status);
	cout << "Salary: ";
	cin >> job.salary;
	cin.ignore();
	cout << "Type (salaried or hourly): ";
	getline(cin, job.type);
}
