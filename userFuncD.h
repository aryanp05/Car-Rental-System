#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

// 11.) Function to display options for renting
void rentalDisplay() {
  // 11.1) Two string arrays to carry all the emojis to create an image
  string carDisplay[10] ={ 
  "⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️",   
  "⬛️🟥🟥🟥🟥🟥🟥🟥🟥🟥⬛️🟪🟪🟪🟪🟪🟪🟪🟪🟪⬛️🟩🟩🟩🟩🟩🟩🟩🟩🟩⬛️", 
  "⬛️🟥Honda       🚗🟥⬛️🟪BMW         🏍️ 🟪⬛️🟩Jeep        🚙🟩⬛️", 
  "⬛️🟥Civic         🟥⬛️🟪Motorcycle    🟪⬛️🟩Wrangler      🟩⬛️", 
  "⬛️🟥💺  4-5 People🟥⬛️🟪💺  1-2 People🟪⬛️🟩💺  4-5 People🟩⬛️", 
  "⬛️🟥💼  2-4 Bags  🟥⬛️🟪💼  1 Bag     🟪⬛️🟩💼  3-6 Bags  🟩⬛️", 
  "⬛️🟥💳 $25 Per Day🟥⬛️🟪💳 $32 Per Day🟪⬛️🟩💳 $35 Per Day🟩⬛️", 
  "⬛️🟥Car Code:    1🟥⬛️🟪Car Code:    2🟪⬛️🟩Car Code:    3🟩⬛️", 
  "⬛️🟥🟥🟥🟥🟥🟥🟥🟥🟥⬛️🟪🟪🟪🟪🟪🟪🟪🟪🟪⬛️🟩🟩🟩🟩🟩🟩🟩🟩🟩⬛️",
  "⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️" 
  };
  string carDisplay2[9] = {
 "⬛️🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬛️🟧🟧🟧🟧🟧🟧🟧🟧🟧⬛️", 
  "⬛️🟨Toyota      🚕🟨⬛️⬜️Mercedies   🚐⬜️⬛️🟧Ford        🚛🟧⬛️", 
  "⬛️🟨Taxi          🟨⬛️⬜️Van           ⬜️⬛️🟧Truck         🟧⬛️", 
  "⬛️🟨💺  4-5 People🟨⬛️⬜️💺  2-8 People⬜️⬛️🟧💺  1-2 People🟧⬛️", 
  "⬛️🟨💼  2-4 Bags  🟨⬛️⬜️💼  1-12 Bags ⬜️⬛️🟧💼  100~ Bags 🟧⬛️", 
  "⬛️🟨💳 $27 Per Day🟨⬛️⬜️💳 $40 Per Day⬜️⬛️🟧💳 $45 Per Day🟧⬛️", 
  "⬛️🟨Car Code:    4🟨⬛️⬜️Car Code:    5⬜️⬛️🟧Car Code:    6🟧⬛️", 
  "⬛️🟨🟨🟨🟨🟨🟨🟨🟨🟨⬛️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬛️🟧🟧🟧🟧🟧🟧🟧🟧🟧⬛️",
  "⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️"  
  };

// 11.2.1) For loop to display contents of the first string array
for (int i = 0; i < 10; i++) {
  cout << carDisplay[i] << endl;
}

// 11.2.2) For loop to display contents of the second string array
for (int i = 0; i < 9; i++) {
  cout << carDisplay2[i] << endl;
}
  cout << endl << endl;
}