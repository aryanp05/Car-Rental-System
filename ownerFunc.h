#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include "ownerFunc1.h"
#include "ownerFunc2.h"
#include "ownerFunc3.h"
#include "ownerFunc4.h"
using namespace std;

// 2.) Owner's Usage
void ownerFunction(int d, string ownerName, string ownerPassword){

  // 2.1) Initializing Variables + Clearing Console
  int ownerChoice;
  system ("clear");
  
  // 2.2) Welcomes Admin and Displays Options 
  usleep(500000*d);
  cout << "Welcome " << ownerName << endl << endl;
  usleep(1000000*d);
  cout << "What would you like to do?" << endl;
  usleep(1000000*d);
  cout << "\t1) View Statistics" << endl;
  usleep(500000*d);
  cout << "\t2) Change Inventory & Profits" << endl;
  usleep(500000*d);
  cout << "\t3) Change Owner Credentials" << endl;
  usleep(500000*d);
  cout << "\t4) Toggle Delays" << endl;
  usleep(500000*d);
  cout << "\t5) Return to Home" << endl;
  usleep(1200000*d);
  // Uses Fstream object to get value for d
  ifstream delayVar;
  delayVar.open ("delay.txt");
  if(delayVar.fail()){exit(1);}
  delayVar >> d;
  delayVar.close();

  // 2.3) Runs Owner's Desired Action
  cout << endl << "Enter Option: ";
  cin >> ownerChoice; 
  
    // 2.3.1) Return Home Function
    if (ownerChoice == 5) {
    system ("clear");
    // 2.3.2) Toggle Delays Function
    } else if (ownerChoice == 4) {
      optionFour(d);
      d = 0;
      ownerFunction(d, ownerName, ownerPassword);
    // 2.3.3) Altering Owner Credentials Function
    } else if (ownerChoice == 3) {
      optionThree(ownerName, ownerPassword, d);
      d = 0;
      ownerFunction(d, ownerName, ownerPassword);
    // 2.3.4) Alter Vehicles & Profit/Expenses 
    } else if (ownerChoice == 2) {
      optionTwo(d);
      d = 0;
      ownerFunction(d, ownerName, ownerPassword);
    // 2.3.5) Display Inventory Function
    } else if (ownerChoice == 1) {
      optionOne(d);
      d = 0;
      ownerFunction(d, ownerName, ownerPassword);
    }
}