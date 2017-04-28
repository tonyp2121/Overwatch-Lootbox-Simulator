// Anthony Pallone

#include <string>
#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>

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

#define EVENT_COMMON_PRICE 75
#define EVENT_RARE_PRICE 225
#define EVENT_EPIC_PRICE 750
#define EVENT_LEGENDARY_PRICE 3000

#define DUPLICATE_CREDIT_COMMON 5
#define DUPLICATE_CREDIT_RARE 15
#define DUPLICATE_CREDIT_EPIC 50
#define DUPLICATE_CREDIT_LEGENDARY 200

#define BUY 6
#define DONT_BUY 7

int main(void){
  srand(time(NULL));
  string userInput;
  bool item[BOTH_COMMON + BOTH_RARE + BOTH_EPIC + BOTH_LEGENDARY];
  int lootBoxCount = 0;
  int trackerItemPoolType, trackerHowManyItemsInPool, trackerBuy;
  int UserCreditAmount;
  do{
  cout << "Enter 'N' for normal Overwatch Loot 'E' for event only Overwatch Loot or 'B' for both" << endl;
  cin >> userInput;
}while(userInput != "N" && userInput != "n" && userInput != "E" && userInput != "e" && userInput != "B" && userInput != "b");
  // must add a check to see whether to buy items or not
  if(userInput == "N" || userInput == "n"){trackerItemPoolType = NORMAL;}
  else if(userInput == "E" || userInput == "e"){trackerItemPoolType = EVENT;}
  else if(userInput == "B" || userInput == "b"){trackerItemPoolType = BOTH;}

  switch(trackerItemPoolType){
  case NORMAL: trackerHowManyItemsInPool = NORMAL_COMMON + NORMAL_RARE + NORMAL_EPIC + NORMAL_LEGENDARY; break;
  case EVENT: trackerHowManyItemsInPool = EVENT_COMMON + EVENT_RARE + EVENT_EPIC + EVENT_LEGENDARY; break;
  case BOTH: trackerHowManyItemsInPool = BOTH_COMMON + BOTH_RARE + BOTH_EPIC + BOTH_LEGENDARY; break;
}


    for(int i = 0; i < 10000; i++){
      // this is where the most of the work is done.
      // so first off we go open up a new loot box making sure at least one of them is a rare or better
      // in our bool it will go COMMON << RARE << EPIC << LEGENDARY and events will come after that.
      // Event Items are guaranteed at least one. per event loot box



    }

}
