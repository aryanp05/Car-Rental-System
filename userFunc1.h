#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include "userFuncD.h"
using namespace std;

// 8.) Function for customer to rent cars
void user1(int d) {

  // 8.1.1) Initializing Variables
  int userChoice;
  string carName;
  int unitA, unitB;

  // 8.1.2) Setting Car Infomration
  int payRate[6] = {25, 32, 35, 27, 40, 45};
  string seats[6] = {"4-5", "1-2", "4-5", "4-5", "2-8", "1-2"};
  string bags[6] = {"2-4", "1", "3-6", "2-4", "1-12", "100~"};
  string carFile[6] = {"#car.txt", "#motorcycle.txt", "#jeep.txt", "#taxi.txt", "#van.txt", "#truck.txt"};
  string milage[6] = {"Unlimited", "Unlimited", "Unlimited", "Unlimited", "Unlimited", "Unlimited"};
  string type[6] = {"Automatic", "Automatic", "Automatic", "Automatic", "Automatic", "Automatic"};
  // 8.1.3) Clearing the console
  system("clear");

  // 8.2) Outputing a welcome message
  usleep(500000*d);
  cout << "Welcome to the Rental Section, Take a look at\nour car selection!" << endl << endl;

  // 8.3) Runs Function within userFuncD.h to display visual of all vehicle mdoels
  usleep(1000000*d);
  rentalDisplay();
  cout << endl << endl;

  // 8.4) Takes input for which car they would like to see 
  usleep(1000000*d);
  cout << "What Car would you like to inspect: ";
  cin >> userChoice;
  userChoice -= 1;
  // Clears system
  system("clear");

  // 8.5) Gets Information from the carFile
  ifstream getStats;
  getStats.open (carFile[userChoice]);
  if (getStats.fail()){ exit (1);}
  getline(getStats, carName);
  getStats >> unitA >> unitB;
  getStats.close();

  // 8.6) Displays car Information
   cout << "\033[4;37m" << endl;
  usleep(500000*d);
  cout << "\t\t\t\t\t" << carName;
  cout << "\033[0;0m" << endl;
  usleep(500000*d);
  cout << "Seating Capacity: " << seats[userChoice] << endl;
  usleep(500000*d);
  cout << "Storage Bag Capacity: " << bags[userChoice] << endl;
  usleep(500000*d);
  cout << "Milage Rate: " << milage[userChoice] << endl;
  usleep(500000*d);
  cout << "Vehicle Operation Type: " << type[userChoice] << endl;
  usleep(500000*d);
  cout << "Rental Rate Per Day: $" << payRate[userChoice] << endl;
  usleep(500000*d);

  // 8.7) Checks Car Availability and displays if avaible
  cout << "Car Availability: ";
  // If there are more than 3 models
  if (unitA > 3) {
    // Changes color to green & says avaible
    cout << "\033[0;32m" << "AVAILABLE" << endl << endl;
  // If there are less than 3, but more than 0  
  } else if ((unitA <= 3) && (unitA > 0)) {
    // Changes color to magenta & says its low stock 
    cout << "\033[0;35m" << "LOW AVAILABILITY" << endl << endl;
  // If there are no models  
  } else if (unitA <= 0 ) {
    // Changes color to red & and says its not available
    cout << "\033[0;31m" << "UNAVAILABLE" << endl << endl;
    usleep(1500000*d);

    // Sets variable to return back
    int returnBack;
    // Tells user to input a number to return back 
    cout << "\033[0;37m" << "Enter any number to return back: ";
    cin >> returnBack;
    // Recursion
    user1(d);
  }
  
  // 8.8) Asks to confirm renting
  usleep(100000*d);
  char rentOption;
  cout << "\033[0;37m" << "Would you like to rent this car(Y/N): ";
  cin >> rentOption;
  // If user doesn't want to rent, recursion of the function occurs
  if (rentOption == 'N') {
    user1(d);
  // If user wants to rent, runs code  
  } else if (rentOption == 'Y') {
    // Clears system + Initializing Variables
    system("clear");
    string fName, lName, address;
    long long cardInfo1, cardInfo2, cardInfo3;

    // Thanks user for purchasing & asks for information
    usleep(1000000*d);
    cout << "Thanks for renting with us, please type\nin your personal and payment infromation" << endl << endl;
    usleep(500000*d);
    cout << "First Name: ";
    cin >> fName;
    cout << "Last Name: ";
    cin >> lName;
    cout << "Card Number: ";
    cin >> cardInfo1;
    cout << "Expirey Date (MMYYYY): ";
    cin >> cardInfo2;
    cout << "CVS: ";
    cin >> cardInfo3;
    //to_string(cardInfo1).length();
    cout << endl;

    // Confirms Purchase with user
    usleep(1000000*d);
    cout << "Your purchase has been sucessful, you may pick up your rental\ncar. We hope you have a great time in your new rental!";
    
    //Opens file and reduces the available amount by 1
    unitA -= 1;
    ofstream changeAmount;
    changeAmount.open (carFile[userChoice]);
    if (changeAmount.fail()) {exit(1);}
    changeAmount << carName << endl << unitA << endl << unitB;
    changeAmount.close();
    exit(0);
  }
}