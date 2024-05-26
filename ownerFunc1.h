#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

// 3.1) Function to get values from Files
void getCarInfo(int counter, int d) {
  // Intializes Variables
  int carValueA, carValueB;
  string carName;
  string carHolder[6] = {"#car.txt", "#motorcycle.txt", "#jeep.txt", "#taxi.txt", "#van.txt", "#truck.txt"};
  // Creates File Object & Retrives Data
  ifstream getStats;
  getStats.open (carHolder[counter]);
  if (getStats.fail()){ 
    printf("HEY"); 
    exit (1);}
  getline(getStats, carName);
  getStats >> carValueA >> carValueB;
  getStats.close();
  // Outputs Retrived Data
  cout << endl << carName << "\t\t" << carValueA << "\t\t\t\t\t" << carValueB;
  usleep(300000*d);
}

// 3) Owner's First  Function - Inventory
void optionOne(int d) {

  // 3.2) Intializes Variables + Clears Console
  if (system("clear") == 1) {}
  int counter = 0;
  string carName;
  char returnBack;
  int profit;
    ifstream getProfit;
    getProfit.open ("profit.txt");
    if (getProfit.fail()){ exit (1);}
    getProfit >> profit;
    getProfit.close();
  int expense;
    ifstream getExpense;
    getExpense.open ("expense.txt");
    if (getExpense.fail()){ exit (1);}
    getExpense >> expense;
    getExpense.close();
  int grossProfit = profit-expense;

  // 3.3) Displays Table
    // 3.3.1) Displays Table Title
    cout << "System Inventory & Profits" << endl;
    usleep(1000000*d);

    // 3.3.2) Diplays Headers for the table
    cout << endl << "Vehicles Name" << "\t\tAvailable Models" << "\tTotal Models";
    cout << endl;
    usleep(700000*d);
    // 3.3.3) Displays Car Infromation
    while (counter != 6) {
      // Calls Function 3.1)
      getCarInfo(counter, d);
      counter++;
    }
  cout << endl;

  // 3.3.4) Displays profits
  usleep(500000*d);
  cout << endl;
  cout << "\033[4;37m" << "Profits:" << "\033[7;32m" << "\t\t\t\t\t\t\t\t$" << profit << endl;

  // 3.3.5) Displays Expenses
  usleep(500000*d);
  cout <<"\033[0;37m" <<"\033[4;37m" << "Expenses:" << "\033[7;31m" << "\t\t\t\t\t\t\t\t$" << expense << endl;
  usleep(500000*d);
  cout << "\033[0;37m" << "\t\t\t\t\t\t\t\t\t\t___________" << endl;

  // 3.3.6) Displays Gross Profit
  usleep(500000*d);
  cout << "\033[4;37m" << "Gross Profit:";
  // If Gross profit is profitable, print green
  if (grossProfit >= 0) {
    cout << "\033[7;32m" << "\t\t\t\t\t\t\t$" << grossProfit;
  // If Gross profit is not profitable, print red
  } else if (grossProfit < 0) {
    cout << "\033[7;31m" << "\t\t\t\t\t\t\t$" << grossProfit;
  }
  cout << endl << endl << endl;


  // 3.4) Asks to return Owner Menu
  usleep(500000*d*3);
  // Asks user if they want to return to the menu
  cout << "\033[0;37m" << "Would you like to return to the Owner Menu? (Y/N): ";
  cin >> returnBack;
  //Checks whether the user said Yes or No
  if (returnBack == 'Y') {      
  } else if (returnBack == 'N') {
    exit(0);
  }
}