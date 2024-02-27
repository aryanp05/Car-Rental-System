#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

// 4.1.1) Function to display car choices 
void displayVehicles(int d, int type) {
  cout << "Which Model would you like to change to ";  
  if (type == 0) {cout << "Available";}
  else if (type == 1) {cout << "Total";}
  cout << " Models?" << endl;
  usleep(1000000*d);
  cout << "\t1) Honda Civics🚗\n";
  usleep(700000*d);
  cout << "\t2) BMW Motorcycle🏍️\n";
  usleep(700000*d);
  cout << "\t3) Jeep Wrangler🚙\n";
  usleep(700000*d);
  cout << "\t4) Toyota Taxi🚕\n";
  usleep(700000*d);
  cout << "\t5) Mercedies Van🚐 \n";
  usleep(700000*d);
  cout << "\t6) Ford Truck🚛\n";
  usleep(1000000*d);
}
// 4.1.2) Function to change car amounts
void changesVehicles(int d, int type, int round) {
  // Initializing Variables
  string placeHolder;
  string carHolder[6] = {"#car.txt", "#motorcycle.txt", "#jeep.txt", "#taxi.txt", "#van.txt", "#truck.txt"};
  int unit[2], change;

  // Creating an fstream object to read data
  ifstream AMN;
  // Opening the file name based on what round variable is given
  AMN.open (carHolder[round]);
  if (AMN.fail()){exit(1);}
  // Stores the data of the string and numbers
  getline(AMN, placeHolder);
  AMN >> unit[0] >> unit[1];
  AMN.close();

  // Clears the console and asks user how much they want to change the car amount by
  system ("clear");
  cout << "How many cars would you like to\nadd or subtract (add '-') from " << unit[type] << ": "; 
  // Takes input and changes it
  cin >> change;
  unit[type] += change;
  cout << endl;
  usleep(1000000*d);
  // Outputs the total amount of cars
  cout << "There are now " << unit[type] << " models";
  
  // Creates an Fstream object to write the data into the file
  ofstream changeAmount;
  changeAmount.open (carHolder[round]);
  if (changeAmount.fail()) {exit(1);}
  changeAmount << placeHolder << endl << unit[0] << endl << unit[1];
  changeAmount.close();
}

// 4.1.3) Function to set the round variable & call function 4.1.2) based on user input
void readInput(int choice, int d, int type, int round) {
  // Switch case to run function using a round value specific to the choice
  switch (choice) {
        case 1:{
            round = 0;
            changesVehicles(d, type, round);
            break;}
        case 2:{
            round = 1;
            changesVehicles(d, type, round);
            break;}
        case 3: {
            round = 2;
            changesVehicles(d, type, round);
            break;}
        case 4: {
            round = 3;
            changesVehicles(d, type, round);
            break;}
        case 5: {
            round = 4;
            changesVehicles(d, type, round);
            break;}
        case 6: {
            round = 5;
            changesVehicles(d, type, round);
            break;}
        } 
}

// 4.) Owner's Second  Function - Inventory Altercation
void optionTwo(int d) {
  // 4.2) Initializing Variables + Clears System
  system("clear");
  int choice, unit[2], profit, expense, change, round, PH;
  int type = 0;

  // 4.3) Displays a list of options 
  usleep(500000*d);
    cout << "System Altercation" << endl << endl;
    usleep(750000*d);
    cout << "What would you like to change?" << endl;
    usleep(1000000*d);
    cout << "\t1) Available Model Number" << endl;
    usleep(500000*d);
    cout << "\t2) Total Model Number" << endl;
    usleep(500000*d);
    cout << "\t3) Profits" << endl;
    usleep(500000*d);
    cout << "\t4) Expenses" << endl;
    usleep(1000000*d);
    // Asks Owner for their desired action
    cout << endl << "Enter Option: ";
    cin >> choice;

  // 4.4) Alters Invenotry
    // Runs if choice is 1 (Available Models)
    if (choice == 1) {
      system ("clear");
      // Runs Function 4.1.1) To Display Choices
      displayVehicles(d, type);
      // Takes the user input
      cout << "Enter Choice: ";
      cin >> choice;
      // Runs Function 4.1.3)
      readInput(choice, d, type, round);
      } 

    // Runs if choice is 2 (Total Models)
      else if (choice == 2) {
        // Setting type to 1 to inform function to change Total Models
        type = 1;
        system ("clear");
        // Runs Function 4.1.1) To Display Choices
        displayVehicles(d, type);
        // Takes the user input in
        cout << "Enter Choice: ";
        cin >> choice;
        // Runs Function 4.1.3)
        readInput(choice, d , type, round);
      }

    // Runs if choice is 3 (profit)
      else if (choice == 3) {
        // Creates Fstream Object to read data
        ifstream profitIntake;
        profitIntake.open ("profit.txt");
        if (profitIntake.fail()){ exit (1);}
        profitIntake >> profit;
        profitIntake.close();

        // Clears System
        system ("clear");
        // Displays current profit
        cout << "The current profit is $" << profit << endl << endl;
        usleep(1000000*d);

        // Asks user how much they want to change the profit by
        cout << "How much would you like to change it by (use '-'): ";
        cin >> PH;
        // Alters the profit
        profit += PH;
        // Creates a fstream object to output the new total profit amount in the file
          ofstream profitOutput;
          profitOutput.open ("profit.txt");
          if (profitOutput.fail()) {exit(1);}
          profitOutput << profit;
          profitOutput.close();
        cout << endl;
        usleep(500000);
        // Displays New Profit
        cout << "Profit is now $" << profit;
      } 
    // Runs if choice is 4 (expenses)
      else if (choice == 4) {
        // Creates Fstream Object to read data
        ifstream expenseIntake;
        expenseIntake.open ("expense.txt");
        if (expenseIntake.fail()){ exit (1);}
        expenseIntake >> expense;
        expenseIntake.close();

        // Clears System
        system ("clear");
        // Displays current expenses
        cout << "The current expenses is $" << expense << endl << endl;
        usleep(1000000*d);
        // Asks user how much they want to change the expenses by
        cout << "How much would you like to change it by (use '-'): ";
        cin >> PH;
        // Alters the expenses
        expense += PH;
        // Creates a fstream object to output the new total expenses amount in the file
        ofstream expenseOutput;
        expenseOutput.open ("expense.txt");
        if (expenseOutput.fail()) {exit(1);}
        expenseOutput << expense;
        expenseOutput.close();
        cout << endl;
        usleep(500000);
        // Displays New Expenses
        cout << "Expenses is now $" << expense;
      }
    
    cout << endl << endl << endl;
    // 4.5) Asks to return Owner Menu
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