#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

// 5.) Owner's Third  Function - Credentials
void optionThree(string ownerName, string ownerPassword, int d){

  // 5.1) Getting values from files
  ifstream ownerID;
  ownerID.open ("ownerID.txt");
  if (ownerID.fail()){exit (1);}
  while (getline(ownerID, ownerName))
  ownerID.close();

  ifstream ownerPW;
  ownerPW.open ("ownerPW.txt");
  if (ownerPW.fail()){ exit (1);}
  while (getline(ownerPW, ownerPassword))
  ownerPW.close();

  // 5.2) Clears Console + Initalizes Variables
  if (system("clear") == 1) {}
  char changeToggle;

  // 5.3.1) Confirms if Owner wants to change the login credintials
  usleep(500000*d);
  cout << "Are you sure you want to change the credentials? \n(Y/N): ";
  cin >> changeToggle;

  // 5.3.2) Runs code if owner wants to change admin name
  if (changeToggle == 'Y') {

    // 5.4.1) Asks if admin wants to change identifier name
    usleep(500000*d);
    cout << endl << "Would you like to change username? (Y/N): ";
    cin >> changeToggle;
    // Runs if owner wants to change username
    if (changeToggle == 'Y') {
      // 5.4.2) Asks for new owner identifier name (username)
      usleep(500000*d);
      cout << endl << "What would you like to change the old username(" << ownerName << ") to?" << endl;
      cout << "Enter New Name: ";
      cin >> ownerName;

      // 5.4.3) Creates object to edit ownerID.txt
      ofstream changeName;
      changeName.open ("ownerID.txt");
      if (changeName.fail()) {exit(1);}
      // Changes the value of the name
      changeName << ownerName;
      changeName.close();
    } 

    // 5.5.1) Asks if owner wants to change password
    usleep(500000*d);
    cout << endl << "Would you like to change password? (Y/N): ";
    cin >> changeToggle;
    // Runs if owner wants to change password
    if (changeToggle == 'Y') {

      // 5.5.2) Asks for new owner password
      usleep(500000*d);
      cout << endl << "What would you like to change the old password(" << ownerPassword << ") to?" << endl;
      cout << "Enter New Password: ";
      cin >> ownerPassword;

      // 5.5.4) Creates object to edot ownerPW.txt
      ofstream changePassword;
      // Opens the text file
      changePassword.open ("ownerPW.txt");
      if (changePassword.fail()) {exit(1);}
      // Changes the value of the name
      changePassword << ownerPassword;
      changePassword.close();
    } 
  }
  // 5.6) Asks to return Owner Menu
  cout << endl << endl << endl;
  usleep(500000*d*3);
  char returnBack;
  // Asks user if they want to return to the menu
  cout << "\033[0;37m" << "Would you like to return to the Owner Menu? (Y/N): ";
  cin >> returnBack;
  //Checks whether the user said Yes or No
  if (returnBack == 'Y') {
  } else if (returnBack == 'N') {
    exit(0);
  }
}