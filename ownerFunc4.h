#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

// 6.) Owner's Fourth Function - Toggle Delays
void optionFour(int d) {

  // 6.1) Clears Console + Initializes Variables
  system ("clear");
  char delayToggle;
  char returnBack;

  // 6.2) Asks user whether they would like to keep system text delays on. Takes input
  cout << "Would you like keep system text delays on? (Y/N): ";
  cin >> delayToggle;

  // 6.3) Creates object to access delay.txt file and opens
  ofstream delayAlter;
  delayAlter.open ("delay.txt");
  if (delayAlter.fail()) {exit(1);}
  // Changes the value stored inside the text file to 1 or 0 based on the Owner input. The varible d's value comes from this file, and if d = 0, d*delayTime = 0
  if (delayToggle == 'Y') {
    delayAlter << 1;
  } else if (delayToggle == 'N') {
    delayAlter << 0;
    }
  // Closes delay.txt file
  delayAlter.close();


  // 6.4) Asks to return Owner Menu
  usleep(500000*d);
  cout << endl << endl << endl;
  // Asks user if they want to return to the menu
  cout << "\033[0;37m" << "Would you like to return to the Owner Menu? (Y/N): ";
  cin >> returnBack;
  //Checks whether the user said Yes or No
  if (returnBack == 'Y') {   
  } else if (returnBack == 'N') {
  exit(0);
  }
}
