// Anthony Pallone

#include <string>
#include <iostream>
#include <cmath>

using namespace std;

#define NORMAL 0
#define EVENT 1
#define BOTH 2

#define PERCENT_CHANCE_COMMON 58.66
#define PERCENT_CHANCE_RARE   31.69
#define PERCENT_CHANCE_EPIC   7.22
#define PERCENT_CHANCE_LEGENDARY 2.43

#define NORMAL_COMMON 848
#define NORMAL_RARE 295
#define NORMAL_EPIC 233
#define NORMAL_LEGENDARY 99

#define EVENT_COMMON 315
#define EVENT_RARE 171
#define EVENT_EPIC 57
#define EVENT_LEGENDARY 31

#define BOTH_COMMON 1163
#define BOTH_RARE 466
#define BOTH_EPIC 290
#define BOTH_LEGENDARY 120

#define NORMAL_COMMON_PRICE 25
#define NORMAL_RARE_PRICE 75
#define NORMAL_EPIC_PRICE 250
#define NORMAL_LEGENDARY_PRICE 1000

#define DUPLICATE_CREDIT_COMMON 5
#define DUPLICATE_CREDIT_RARE 15
#define DUPLICATE_CREDIT_EPIC 50
#define DUPLICATE_CREDIT_LEGENDARY 200

int main(void){
  string userInput;
  int tracker;
  do{
  cout << "Enter 'N' for normal Overwatch Loot 'E' for event only Overwatch Loot or 'B' for both" << endl;
  cin >> userInput;
  }while(userInput != "N" && userInput != "n" && userInput != "E" && userInput != "e" && userInput != "B" && userInput != "b" &&)
  switch (userInput)
    case "N":  tracker = NORMAL; break;
    case "n":  tracker = NORMAL; break;
    case "E":  tracker = EVENT; break;
    case "e":  tracker = EVENT; break;
    case "B":  tracker = BOTH; break;
    case "b":  tracker = BOTH; break;


}
