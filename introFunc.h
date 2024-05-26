// Setting Libraries & Namespace
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include "ownerFunc.h"
#include "userFunc.h"
using namespace std;


// 1.) Welcome Screen + User Identifier
void introFunc() {

  // 1.1) Initializing Variables + Creating File Objects to get Values
  string userName;
  string inputPassword;
  int attemptPW = 0;
  string ownerName;
    ifstream ownerID;
    ownerID.open ("ownerID.txt");
    if (ownerID.fail()){exit (1);}
    while (getline(ownerID, ownerName)) {}
    ownerID.close();
  string ownerPassword;
    ifstream ownerPW;
    ownerPW.open ("ownerPW.txt");
    if (ownerPW.fail()){ exit (1);}
    while (getline(ownerPW, ownerPassword)) {}
    ownerPW.close();
  int d;
    ifstream delayVar;
    delayVar.open ("delay.txt");
    if(delayVar.fail()){exit(1);}
    delayVar >> d;
    delayVar.close();

  // 1.2) Welcoming User To The Program + Formatted Text
  cout << "\033[7;31m" << "--------------------------------------------------------";
  cout << "\033[0;31m" << endl;
  cout << "\t\t\t\t\t\t🚦Welcome to🚦\n\t\t\t\t\tThe Car Rental System\n";
  cout << "\033[7;31m" << "--------------------------------------------------------\n\n";
  cout << "\033[0;0m" << endl;
  usleep(500000*d);

  // 1.3) Identifying User
    // Asks User for input
    cout << "What is your name: ";
    cin >> userName;

    // Checks if User's name matches the Owner Predetermined Username
    if (ownerName == userName) {
      // Asks for Owner Password
      usleep(500000*d);
      cout << endl << "What is the password: ";

      // While Loop to ask for two password Attempts
      while(attemptPW != 2) {
        // Intakes password and checks if it matches the owner password
        cin >> inputPassword;
        if (ownerPassword == inputPassword) {
          // Calls Function within ownerFunc.h
          ownerFunction(d, ownerName, ownerPassword);
          // Once user breaks out of the Owner Function, re-calls itself
          introFunc();
          break;

        }else if (ownerPassword != inputPassword) {
          // Tells user they typed the incorrect  password and increases password attempts 
          usleep(500000*d);
          cout << endl << "You have typed the password incorrectly\n" << "What is the password: ";
          attemptPW++;
      }
    } 
  }

  // If User's name is not the Owner Identifer name, assumes user is a customer & runs this block of code
  cout << endl;
  usleep(100000*d);
  // Calls Function within userFunc.h
  customerWelcome(userName, d);
}