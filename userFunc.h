#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include "userFunc1.h"
#include "userFunc2.h"
#include "userFunc3.h"
using namespace std;

// 7) Function to introduce a customer to the program
void customerWelcome(string userName, int d) {

  // 7.1) Initializing Variables + Clearing System
  int userChoice;
  system ("clear");
  
  // 7.2) Displays User's name and options of functions
  usleep(500000*d);
  cout << "Welcome " << userName << ", We're glad you choose to rent with us!" << endl;
  usleep(1000000*d);
  cout << endl << "Would you like to Rent, Return, or access Help: " << endl;
  usleep(500000*d);
  cout << "\t1) Renting" << endl;
  usleep(500000*d);
  cout << "\t2) Returning" << endl;
  usleep(500000*d);
  cout << "\t3) Help Information" << endl;
  usleep(700000*d);

  // 7.3) Asks for user input
  cout << "Enter Choice: ";
  cin >> userChoice;
  
  // 7.4) Based on input choice, runs Function
  if (userChoice == 1) {
    user1(d);
  } else if (userChoice == 2) {
    user2(d);
  } else if (userChoice == 3) {
    user3(d);
  }
}