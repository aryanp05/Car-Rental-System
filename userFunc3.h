#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

// 10.) Function to provide help information
void user3(int d) {
  // Clear System
  if (system("clear") == 1) {}

  // 10.1) Tells user methods to contact for help
  cout << "Welcome to the help center,\nWe're always happy to help" << endl << endl ;
  usleep(1500000*d);
  cout << "Please contact us through" << endl;
  usleep(500000*d);
  cout << "\tEmail: car.rentsystem@gmail.com" << endl;
  usleep(500000*d);
  cout << "\tPhone Number: 1234567890" << endl;
  usleep(500000*d);
  cout << "\tInstagram: @rentalCarCA" << endl;
  exit(0);  
}