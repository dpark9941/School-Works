//*****************
//Program Name: COMSC 200 Final
//Author: Donggyu Park
//IDE Used: Eclipse
//Program description: write a program that is an information system for a video rental store
//*****************

#include "Video.h"
#include "Customer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int getChoice();
void printMainMenu();
void readVideoFile(vector<Video>&);
void readCustomerFile(vector<Customer>&);
void checkOutVideo(vector<Video>&, vector<Customer>);
void checkInVideo(vector<Video>&);
void runReports(vector<Video>&, vector<Customer>&);
void overdueReport(vector<Video>, vector<Customer>);
void newVideoData(vector<Video>);
void newCustomerData(vector<Customer>);
void manageInventory(vector<Video>&);
void listVideo(vector<Video>);
void addVideo(vector<Video>&);
void removeVideo(vector<Video>&);
void updateVideo(vector<Video>&);
void manageCustomer(vector<Customer>&);
void listCustomer(vector<Customer>);
void addCustomer(vector<Customer>&);
void deleteCustomer(vector<Customer>&);
void updateCustomer(vector<Customer>&);
void plagiarismRequirement();

int main() {

  //defines vectors with objects by reading files
  vector<Video> videoList;
  vector<Customer> customerList;

  //reads from the files and populates videoList and customerList
  readVideoFile(videoList);
  readCustomerFile(customerList);

  int choice = 0;
  do {
    //outputs menu instruction
    printMainMenu();
    choice = getChoice(); //gets choice from the user
    switch (choice) {
    case 1:
      checkOutVideo(videoList, customerList);
      break;
    case 2:
      checkInVideo(videoList);
      break;
    case 3:
      runReports(videoList, customerList);
      break;
    case 4:
      manageInventory(videoList);
      break;
    case 5:
      manageCustomer(customerList);
      break;
    case 6:
      cout << "Quitting..." << endl;
      break;
    default:
      cout << "Invalid choice! Back to main menu" << endl;
      break;
    }
  } while (choice != 6);

  plagiarismRequirement();
  return 0;
}

//*****************
//Function name: getChoice
//Purpose: get choice from the user
//List of parameters:
//Returns: choice
//Return type: int
//*****************
int getChoice() {
  int choice;
  cout << "Your choice: ";
  cin >> choice;
  cout << endl;
  return choice;
}

//*****************
//Function name: printMainMenu
//Purpose: prints main menu
//List of parameters:
//Returns:
//Return type: void
//*****************
void printMainMenu() {
  cout << endl;
  cout << "===VIDEO STORE MAIN MENU===" << endl;
  cout << "[1] Check out videos" << endl;
  cout << "[2] Check in videos" << endl;
  cout << "[3] Run reports" << endl;
  cout << "[4] Manage inventory" << endl;
  cout << "[5] Manage customers" << endl;
  cout << "[6] Quit" << endl;
}

//*****************
//Function name: readVideoFile
//Purpose: read strings from "videos.txt" into videoList
//List of parameters: &videoList
//Returns:
//Return type: void
//*****************
void readVideoFile(vector<Video> &videoList) {
  //temporary variables for reading file
  ifstream finVideo("videos.txt");
  string temp;
  string title = "";
  int invNr = 0;
  bool checkedOut = 0;
  bool overdue = 0;
  int customer = 0;

  //reads file into videoList
  while(finVideo.good()) {
    //reads title, inventoryNumber, checkedOut, overdue and customer
    getline(finVideo, title);
    getline(finVideo, temp);
    stringstream ss(temp);
    ss >> invNr >> checkedOut >> overdue >> customer;

    //creates temporary video object and put it into videoList
    Video tempVideo(title, invNr, checkedOut, overdue, customer);
    videoList.push_back(tempVideo);
  }
  finVideo.close();
}

//*****************
//Function name: readCustomerFile
//Purpose: read strings from "customers.txt" into customerList
//List of parameters: &customerList
//Returns:
//Return type: void
//*****************
void readCustomerFile(vector<Customer> &customerList) {
  //temporary variables for reading file
  ifstream finCustomer("customers.txt");
  string temp;
  int customerNumber = 0;
  string lName = "";
  string fName = "";
  string custNr = ""; //declared for getline()

  //reads file into customerList
  while(finCustomer.good()) {
    //reads lastName, firstName and customerNumber
    getline(finCustomer, lName);
    getline(finCustomer, fName);
    getline(finCustomer, custNr);
    customerNumber = stoi(custNr);

    //creates temporary customer object and put it into customerList
    Customer tempCustomer(customerNumber, lName, fName);
    customerList.push_back(tempCustomer);
  }
  finCustomer.close();
}

//*****************
//Function name: checkOutVideo
//Purpose: let the user choose who rented which video and updates data in videoList
//List of parameters: &videoList, customerList
//Returns:
//Return type: void
//*****************
void checkOutVideo(vector<Video> &videoList, vector<Customer> customerList) {
  //temporary variables for accessing vectors
  int videoChoice = 0;
  int customerChoice = 0;
  vector<Video> videoToCheckOut; //stores list of videos that are available to rent
  vector<int> indices; //stores the original index of the videos in tempList

  //creates temporary list of videos that are available to rent
  for (int i = 0; i < videoList.size(); i++) {
    if (!videoList.at(i).getCheckedOut()) { //if the video is NOT checked out
      videoToCheckOut.push_back(videoList.at(i));
      indices.push_back(i);
    }
  }

  //outputs videos available to rent and let the user choose which video to check out
  cout << "***VIDEO CHECK-OUT***" << endl;
  cout << "Select video to check out:" << endl;
  for (int i = 0; i < videoToCheckOut.size(); i++)
    cout << "[" << i + 1 << "] " << videoToCheckOut.at(i).getInvNr() << " " << videoToCheckOut.at(i).getTitle() << endl;
  videoChoice = getChoice();
  //input validation
  while (videoChoice < 1 || videoChoice > videoToCheckOut.size()) {
    cout << "Invalid input. Enter again: ";
    videoChoice = getChoice();
  }

  //outputs customers and let the user choose who rented the video
  cout << "Choose the customer that rented this title:" << endl;
  for (int i = 0; i < customerList.size(); i++)
    cout << "[" << i+1 << "] " << customerList.at(i).getLName() << ", " << customerList.at(i).getFName() << " (" << customerList.at(i).getCustNr() << ")" << endl;
  customerChoice = getChoice();
  //input validation
  while (customerChoice < 1 || customerChoice > customerList.size()) {
    cout << "Invalid input. Enter again: ";
    customerChoice = getChoice();
  }

  videoList.at(indices.at(videoChoice - 1)).setCheckedOut(true); //assigns true to Video::checkedOut of the rented video
  videoList.at(indices.at(videoChoice - 1)).setCustomer(customerList.at(customerChoice - 1).getCustNr()); //updates the Video::customer with Customer::customerNumber
}

//*****************
//Function name: checkInVideo
//Purpose: let the user selects the video being turned in, and updates the object data in the vector
//List of parameters: &videoList
//Returns:
//Return type: void
//*****************
void checkInVideo(vector<Video> &videoList) {
  //temporary variables for accessing vectors
  int videoChoice = 0;
  vector<Video> videoToCheckIn; //stores list of videos that are currently rented
  vector<int> indices; //stores the original index of the videos in videoToCheckOut

  //creates temporary list of videos that are currently rented
  for (int i = 0; i < videoList.size(); i++) {
    if (videoList.at(i).getCheckedOut()) { //if the video is currently rented
      videoToCheckIn.push_back(videoList.at(i));
      indices.push_back(i);
    }
  }

  //outputs videos that are currently rented and let the user choose which video to check in
  cout << "***VIDEO CHECK-IN***" << endl;
  cout << "Select video to check in:" << endl;
  for (int i = 0; i < videoToCheckIn.size(); i++)
    cout << "[" << i + 1 << "] " << videoToCheckIn.at(i).getInvNr() << " " << videoToCheckIn.at(i).getTitle() << endl;
  videoChoice = getChoice();
  //input validation
  while (videoChoice < 1 || videoChoice > videoList.size()) {
    cout << "Invalid input. Enter again: ";
    videoChoice = getChoice();
  }

  videoList.at(indices.at(videoChoice - 1)).setCheckedOut(false); //sets Video::checkedOut to false
  videoList.at(indices.at(videoChoice - 1)).setOverdue(false); //sets Video::overdue to false
  videoList.at(indices.at(videoChoice - 1)).setCustomer(0); //updates the Video::customer with 0
}

//*****************
//Function name: runReports
//Purpose: let the user manipulate the lists
//List of parameters: &videoList, &customerList
//Returns:
//Return type: void
//*****************
void runReports(vector<Video> &videoList, vector<Customer> &customerList) {
  cout << "***RUN REPORTS***" << endl;
  cout << "[1] Overdue video report" << endl;
  cout << "[2] Write new video database" << endl;
  cout << "[3] Write new customer database" << endl;
  cout << "Press any other number to return to Main menu" << endl;

  switch(getChoice()) {
  case 1:
    overdueReport(videoList, customerList);
    break;
  case 2:
    newVideoData(videoList);
    break;
  case 3:
    newCustomerData(customerList);
    break;
  default:
    break;
  }
}

//*****************
//Function name: overdueReport
//Purpose: prints overdue videos and the culprit
//List of parameters: videoList, customerList
//Returns:
//Return type: void
//*****************
void overdueReport(vector<Video> videoList, vector<Customer> customerList){
  vector<Video> overdueList;
  vector<Customer> culpritList;

  //finds overdue videos and the culprits
  for (Video overdueVideo : videoList) {
    if (overdueVideo.getOverdue()) { //if the video is overdue
      //puts the video in the overdueList
      overdueList.push_back(overdueVideo);
      //and finds the culprit
      for (Customer possibleCulprit : customerList) {
        if (overdueVideo.getCustomer() == possibleCulprit.getCustNr()){ //if the culprit is found
          //puts the customer in the curpritList
          culpritList.push_back(possibleCulprit);
          break;
        }
      }
    }
  }

  cout << "***OVERDUE VIDEOS***" << endl;
  for (int i = 0; i < overdueList.size(); i++) {
    cout << "Inventory #: " << overdueList.at(i).getInvNr() << " / " << "Title: " << overdueList.at(i).getTitle() << endl;
    cout << "\tCustomer #: " << culpritList.at(i).getCustNr() << " (" << culpritList.at(i).getLName() << ", " << culpritList.at(i).getFName() << ")" << endl;
  }
}

//*****************
//Function name: newVideoData
//Purpose: writes videoList to a new file
//List of parameters: videoList
//Returns:
//Return type: void
//*****************
void newVideoData(vector<Video> videoList) {
  string fileName;
  cout << "Enter the file name: ";
  cin.ignore(); //empties keyboard buffer
  getline(cin, fileName);
  while (fileName == "videos.txt") { //input validation
    cout << "ERROR. The file name must be different." << endl;
    cout << "Enter again: ";
    getline(cin, fileName);
  }

  //writes videoList to a new file
  ofstream foutVideo;
  foutVideo.open(fileName);
  for (Video tempVideo : videoList) {
    foutVideo << tempVideo.getTitle() << endl;
    foutVideo << tempVideo.getInvNr() << ' ' << tempVideo.getCheckedOut() << ' ' << tempVideo.getOverdue() << ' ' << tempVideo.getCustomer() << endl;
  }
  foutVideo.close();
}

//*****************
//Function name: newCustomerData
//Purpose: writes customerList to a new file
//List of parameters: customerList
//Returns:
//Return type: void
//*****************
void newCustomerData(vector<Customer> customerList) {
  string fileName;
  cout << "Enter the file name: ";
  cin.ignore(); //empties keyboard buffer
  getline(cin, fileName);
  while (fileName == "customers.txt") { //input validation
    cout << "ERROR. The file name must be different." << endl;
    cout << "Enter again: ";
    getline(cin, fileName);
  }

  //writes customerList to a new file
  ofstream foutCustomer;
  foutCustomer.open(fileName);
  for (Customer tempCustomer : customerList) {
    foutCustomer << tempCustomer.getLName() << endl;
    foutCustomer << tempCustomer.getFName() << endl;
    foutCustomer << tempCustomer.getCustNr() << endl;
  }
  foutCustomer.close();
}

//*****************
//Function name: manageInventory
//Purpose: let the user edit videoList
//List of parameters: &videoList
//Returns:
//Return type: void
//*****************
void manageInventory(vector<Video> &videoList) {
  cout << "***MANAGE INVENTORY***" << endl;
  cout << "[1] List videos" << endl;
  cout << "[2] Add video to inventory" << endl;
  cout << "[3] Remove video from inventory" << endl;
  cout << "[4] Update video data" << endl;
  cout << "[5] Return to main menu" << endl;

  switch(getChoice()) {
  case 1:
    listVideo(videoList);
    break;
  case 2:
    addVideo(videoList);
    break;
  case 3:
    removeVideo(videoList);
    break;
  case 4:
    updateVideo(videoList);
    break;
  default:
    break;
  }
}

//*****************
//Function name: listVideo
//Purpose: prints the videos in videoList
//List of parameters: videoList
//Returns:
//Return type: void
//*****************
void listVideo(vector<Video> videoList) {
  for (int i = 0; i < videoList.size(); i++)
    cout << "[" << i + 1 << "] " << videoList.at(i).getInvNr() << " " << videoList.at(i).getTitle() << endl;
}

//*****************
//Function name: addVideo
//Purpose: adds a new video to videoList
//List of parameters: &videoList
//Returns:
//Return type: void
//*****************
void addVideo(vector<Video> &videoList) {
  string title;
  int invNr;

  //let the user enter the title and inventoryNumber to add video
  cout << "Enter the title: ";
  cin.ignore(); //empties keyboard buffer
  getline(cin, title);
  cout << "Enter the inventory number: ";
  cin >> invNr;
  //input validation
  while ((invNr / 1000) >= 1) { //if invNr is more than 4 digits
    cout << "The number is too big. Enter no more than 3 digits." << endl;
    cout << "Enter again: ";
    cin >> invNr;
  }

  //adds the user-entered video to videoList
  Video tempVideo(title, invNr, false, false, 0);
  videoList.push_back(tempVideo);
}

//*****************
//Function name: removeVideo
//Purpose: removes a video from videoList
//List of parameters: &videoList
//Returns:
//Return type: void
//*****************
void removeVideo(vector<Video> &videoList) {
  int choice;
  //let the user choose which video to remove
  cout << "Select a video to remove:" << endl;
  for (int i = 0; i < videoList.size(); i++)
    cout << "[" << i + 1 << "] " << videoList.at(i).getInvNr() << " " << videoList.at(i).getTitle() << endl;
  choice = getChoice();
  //input validation
  while (choice < 1 || choice > videoList.size()) {
    cout << "Invalid input. Enter again: ";
    choice = getChoice();
  }
  //removes the video
  videoList.erase(videoList.begin() + choice - 1);
}

//*****************
//Function name: updateVideo
//Purpose: updates a video in videoList
//List of parameters: &videoList
//Returns:
//Return type: void
//*****************
void updateVideo(vector<Video> &videoList) {
  int choice;
  char YorN;

  //let the user choose which video to update
  cout << "Select a video to update:" << endl;
  for (int i = 0; i < videoList.size(); i++)
    cout << "[" << i + 1 << "] " << videoList.at(i).getInvNr() << " " << videoList.at(i).getTitle() << endl;
  choice = getChoice();
  //input validation
  while (choice < 1 || choice > videoList.size()) {
    cout << "Invalid input. Enter again: ";
    choice = getChoice();
  }

  //asks the user if they want to update title
  cout << "Title currently is: " << videoList.at(choice - 1).getTitle() <<". Update title? Y/N: ";
  cin >> YorN;
  //input validation
  while (tolower(YorN) != 'y' && tolower(YorN) != 'n') {
    cout << "Only enter y/n: ";
    cin >> YorN;
  }

  if (tolower(YorN) == 'y') {
    string newTitle;
    cout << "Enter new title: ";
    getline(cin, newTitle);
    videoList.at(choice - 1).setTitle(newTitle);
  }

  //asks the user if they want to update inventoryNumber
  cout << "Inventory # currently is: " << videoList.at(choice - 1).getInvNr() << ". Update inventory number? Y/N: ";
  cin >> YorN;
  //input validation
  while (tolower(YorN) != 'y' && tolower(YorN) != 'n') {
    cout << "Only enter y/n: ";
    cin >> YorN;
  }

  if (tolower(YorN) == 'y') {
    int newInvNr;
    cout << "Enter new inventory number: ";
    cin >> newInvNr;
    //input validation
    while ((newInvNr / 1000) >= 1) { //if newInvNr is more than 4 digits
      cout << "The number is too big. Enter no more than 3 digits." << endl;
      cout << "Enter again: ";
      cin >> newInvNr;
    }
    videoList.at(choice - 1).setInvNr(newInvNr);
  }
}

//*****************
//Function name: manageCustomer
//Purpose: let the user edit customerList
//List of parameters: &customerList
//Returns:
//Return type: void
//*****************
void manageCustomer(vector<Customer> &customerList) {
  cout << "***MANAGE CUSTOMER***" << endl;
  cout << "[1] List customers" << endl;
  cout << "[2] Add customer" << endl;
  cout << "[3] Delete customer" << endl;
  cout << "[4] Update customer" << endl;
  cout << "[5] Return to main menu" << endl;

  switch(getChoice()) {
  case 1:
    listCustomer(customerList);
    break;
  case 2:
    addCustomer(customerList);
    break;
  case 3:
    deleteCustomer(customerList);
    break;
  case 4:
    updateCustomer(customerList);
    break;
  case 5:
    updateCustomer(customerList);
    break;
  default:
    break;
  }
}

//*****************
//Function name: listCustomer
//Purpose: prints the customers in customerList
//List of parameters: customerList
//Returns:
//Return type: void
//*****************
void listCustomer(vector<Customer> customerList) {
  for (int i = 0; i < customerList.size(); i++)
    cout << "[" << i+1 << "] " << customerList.at(i).getLName() << ", " << customerList.at(i).getFName() << " (" << customerList.at(i).getCustNr() << ")" << endl;
}

//*****************
//Function name: addCustomer
//Purpose: adds a customer to customerList
//List of parameters: &customerList
//Returns:
//Return type: void
//*****************
void addCustomer(vector<Customer> &customerList) {
  int custNr;
  string fName;
  string lName;

  //let the user enter custNr, fName and lName
  cout << "Enter the customer number: ";
  cin >> custNr;
  //input validation
  while ((custNr / 10000) >= 1) { //if custNr is more than 5 digits
    cout << "The number is too big. Enter no more than 4 digits." << endl;
    cout << "Enter again: ";
    cin >> custNr;
  }
  cout << "Enter the first name: ";
  cin >> fName;
  cout << "Enter the last name: ";
  cin >> lName;

  //adds the user-entered customer to customerList
  Customer tempCustomer(custNr, lName, fName);
  customerList.push_back(tempCustomer);
}

//*****************
//Function name: deleteCustomer
//Purpose: deletes a customer from customerList
//List of parameters: &customerList
//Returns:
//Return type: void
//*****************
void deleteCustomer(vector<Customer> &customerList) {
  int choice;
  //let the user choose which customer to delete
  cout << "Select a video to remove:" << endl;
  for (int i = 0; i < customerList.size(); i++)
    cout << "[" << i+1 << "] " << customerList.at(i).getLName() << ", " << customerList.at(i).getFName() << " (" << customerList.at(i).getCustNr() << ")" << endl;
  choice = getChoice();
  //input validation
  while (choice < 1 || choice > customerList.size()) {
    cout << "Invalid input. Enter again: ";
    choice = getChoice();
  }

  //removes the video
  customerList.erase(customerList.begin() + choice - 1);
}

//*****************
//Function name: updateCustomer
//Purpose: updates a customer in customerList
//List of parameters: &customerList
//Returns:
//Return type: void
//*****************
void updateCustomer(vector<Customer> &customerList) {
  int choice;
  char YorN;

  //let the user choose which customer to update
  cout << "Select a customer to update:" << endl;
  for (int i = 0; i < customerList.size(); i++)
    cout << "[" << i+1 << "] " << customerList.at(i).getLName() << ", " << customerList.at(i).getFName() << " (" << customerList.at(i).getCustNr() << ")" << endl;
  choice = getChoice();
  //input validation
  while (choice < 1 || choice > customerList.size()) {
    cout << "Invalid input. Enter again: ";
    choice = getChoice();
  }

  //asks the user if they want to update last name
  cout << "Last name currently is: " << customerList.at(choice - 1).getLName() <<". Update last name? Y/N: ";
  cin >> YorN;
  //input validation
  while (tolower(YorN) != 'y' && tolower(YorN) != 'n') {
    cout << "Only enter y/n: ";
    cin >> YorN;
  }
  if (tolower(YorN) == 'y') {
    string newLName;
    cout << "Enter new last name: ";
    getline(cin, newLName);
    customerList.at(choice - 1).setLName(newLName);
  }

  //asks the user if they want to update first name
  cout << "First name currently is: " << customerList.at(choice - 1).getLName() <<". Update first name? Y/N: ";
  cin >> YorN;
  //input validation
  while (tolower(YorN) != 'y' && tolower(YorN) != 'n') {
    cout << "Only enter y/n: ";
    cin >> YorN;
  }
  if (tolower(YorN) == 'y') {
    string newFName;
    cout << "Enter new first name: ";
    getline(cin, newFName);
    customerList.at(choice - 1).setFName(newFName);
  }

  //asks the user if they want to update customer number
  cout << "Customer number currently is: " << customerList.at(choice - 1).getCustNr() <<". Update customer number? Y/N: ";
  cin >> YorN;
  //input validation
  while (tolower(YorN) != 'y' && tolower(YorN) != 'n') {
    cout << "Only enter y/n: ";
    cin >> YorN;
  }
  if (tolower(YorN) == 'y') {
    int newCustNr;
    cout << "Enter new customer number: ";
    cin >> newCustNr;
    //input validation
    while ((newCustNr / 10000) >= 1) { //if newCustNr is more than 5 digits
      cout << "The number is too big. Enter no more than 4 digits." << endl;
      cout << "Enter again: ";
      cin >> newCustNr;
    }
    customerList.at(choice - 1).setCustNr(newCustNr);
  }
}

//*****************
//Function name: plagiarismRequirement
//Purpose: outputs Plagiarism Requirement
//List of parameters:
//Returns:
//Return type: void
//*****************
void plagiarismRequirement(){
  cout << endl;
  cout << "I attest that this code is my original programming work, and that I received" << endl;
  cout << "no help creating it. I attest that I did not copy this code or any portion of this" << endl;
  cout << "code from any source." << endl;
}
