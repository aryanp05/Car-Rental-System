#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include <cstdlib>
using namespace std;

// 9.) Function to return vehicles
void user2(int d) {
  // 9.1) Initializing Variables + Clears Console
  int payRate[6] = {25, 32, 35, 27, 40, 45};
  int userChoice, unitA, unitB, days, cost, profit, cardInfo2, cardInfo3;
  long long cardInfo1;
  string carName, fName, lName;
  string carFile[6] = {"#car.txt", "#motorcycle.txt", "#jeep.txt", "#taxi.txt", "#van.txt", "#truck.txt"};
  if (system("clear") == 1) {}

  // 9.2) Welcomes user
  usleep(1000000*d);
  cout << "Welcome to the Returning Section!" << endl << endl;
  usleep(1000000*d);

  // 9.3) Asks user which car they want to return
  cout << "Which Model would you like to Return?" << endl;
  usleep(1500000*d);
  cout << "\t1) Honda Civics🚗\n";
  usleep(1000000*d);
  cout << "\t2) BMW Motorcycle🏍️\n";
  usleep(1000000*d);
  cout << "\t3) Jeep Wrangler🚙\n";
  usleep(1000000*d);
  cout << "\t4) Toyota Taxi🚕\n";
  usleep(1000000*d);
  cout << "\t5) Mercedies Van🚐 \n";
  usleep(1000000*d);
  cout << "\t6) Ford Truck🚛\n";
  // Asks user for input
  usleep(1300000*d);
  cout << "Enter Model Number: ";
  cin >> userChoice;
  userChoice -= 1;

  // 9.4) Gets Information from the carFile
  ifstream getStats;
  getStats.open (carFile[userChoice]);
  if (getStats.fail()){ exit (1);}
  getline(getStats, carName);
  getStats >> unitA >> unitB;
  getStats.close();

  // 9.5) Asks user how many days they have been renting for
  // Clears System
  if (system("clear") == 1) {}
    
  cout << "How many Days have you rented the car for: ";
  cin >> days;

  // 9.6) Calculates Total amount user needs to pay
  usleep(500000*d);
  cost = days*payRate[userChoice];
  cout << endl << endl << "The total amount you need to pay is $" << cost << endl << endl;

  // 9.7) Asks user for personal & payment information
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

  // Thanks user for using rental system
  cout << endl;
  usleep(1000000*d);
  cout << "Thanks for renting with us. We hope to see you soon!";

    // Opens file and increase the available amount by 1
    unitA += 1;
    ofstream changeAmount;
    changeAmount.open (carFile[userChoice]);
    if (changeAmount.fail()) {exit(1);}
    changeAmount << carName << endl << unitA << endl << unitB;
    changeAmount.close();

  // Gets Profit amount from the file
    ifstream profitIntake;
    profitIntake.open ("profit.txt");
    if (profitIntake.fail()){ exit (1);}
    profitIntake >> profit;
    profitIntake.close();

  //Increases Profit
    profit += cost;
    ofstream profitOutput;
    profitOutput.open ("profit.txt");
    if (profitOutput.fail()) {exit(1);}
    profitOutput << profit;
    profitOutput.close();
    exit(0);

}