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

#define PERCENT_CHANCE_COMMON 5820
#define PERCENT_CHANCE_RARE   3170
#define PERCENT_CHANCE_EPIC   755
#define PERCENT_CHANCE_LEGENDARY 255
#define PERCENT_CHANCE_TOTAL 10000

#define PERCENT_CHANCE_RARE_CURRENCY 411
#define PERCENT_CHANCE_EPIC_CURRENCY 243      // I can find if its a currency if we see if its greater than common chance but less thanc ommon chance + currency chance
#define PERCENT_CHANCE_LEGENDARY_CURRENCY 42

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
  //bool item[BOTH_COMMON + BOTH_RARE + BOTH_EPIC + BOTH_LEGENDARY];

  int lootBoxCount = 0;
  int trackerItemPoolType, trackerHowManyItemsInPool, trackerBuy;
  int userCreditAmount;
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
  bool *item = new bool[trackerHowManyItemsInPool];
  // for (int i = 0; i < trackerHowManyItemsInPool; i++){
  // item[i]= false;
  // }


    for(int i = 0; i < 1; i++){
      // this is where the most of the work is done.
      // so first off we go open up a new loot box making sure at least one of them is a rare or better
      // in our bool it will go COMMON << RARE << EPIC << LEGENDARY and events will come after that.
      // Event Items are guaranteed at least one per event loot box
      // in a loot box I want it to roll 4 times and on the fourth see if a rare or better has spawned.

      int heldItems[4] = {0};
      int maxHeldItems[4];

      int totalNumberOfItemsTracker;
      switch (trackerItemPoolType){
        case NORMAL: totalNumberOfItemsTracker = NORMAL_COMMON + NORMAL_RARE + NORMAL_EPIC + NORMAL_LEGENDARY;  maxHeldItems[0] = NORMAL_COMMON; maxHeldItems[1] = NORMAL_RARE; maxHeldItems[2] = NORMAL_EPIC; maxHeldItems[3] = NORMAL_LEGENDARY;  break;
        case EVENT: totalNumberOfItemsTracker = EVENT_COMMON + EVENT_RARE + EVENT_EPIC + EVENT_LEGENDARY; maxHeldItems[0] = EVENT_COMMON; maxHeldItems[1] = EVENT_RARE; maxHeldItems[2] = EVENT_EPIC; maxHeldItems[3] = EVENT_LEGENDARY; break;
        case BOTH: totalNumberOfItemsTracker = BOTH_COMMON + BOTH_RARE + BOTH_EPIC + BOTH_LEGENDARY; break; maxHeldItems[0] = BOTH_COMMON; maxHeldItems[1] = BOTH_RARE; maxHeldItems[2] = BOTH_EPIC; maxHeldItems[3] = BOTH_LEGENDARY;
      }
      lootBoxCount = 0;
      int totalNumberOfItemsHeld = 0;
      userCreditAmount = 0;
    while(totalNumberOfItemsTracker != totalNumberOfItemsHeld){
      int randomChance;
      int itemsToAdd;
      int rareCounter = 0;
      lootBoxCount++;
      for(int j = 0;j < 4; j++){
        randomChance = rand() % PERCENT_CHANCE_TOTAL;
        if (randomChance > PERCENT_CHANCE_COMMON){rareCounter ++;} // if its higher than common we have a rare
        if(j == 3 && rareCounter == 0){randomChance = rand() % (PERCENT_CHANCE_RARE + PERCENT_CHANCE_EPIC + PERCENT_CHANCE_LEGENDARY) + PERCENT_CHANCE_COMMON;}
        if(randomChance < PERCENT_CHANCE_COMMON){ // this will mean we got a common
          switch(trackerItemPoolType){
            case NORMAL: randomChance = fmod(rand(), NORMAL_COMMON); break;
            case EVENT: randomChance = fmod(rand(), EVENT_COMMON); break;
            case BOTH: randomChance = fmod(rand(), BOTH_COMMON); break;
          }
          if(item[randomChance]){userCreditAmount+=5;}
          else{item[randomChance] = true; totalNumberOfItemsHeld++; heldItems[0]++;}
        }
        else if(randomChance < PERCENT_CHANCE_COMMON + PERCENT_CHANCE_RARE){ // this will mean we got a rare
          if(randomChance < PERCENT_CHANCE_COMMON + PERCENT_CHANCE_RARE_CURRENCY){userCreditAmount+=50;}
          else{
            switch(trackerItemPoolType){
              case NORMAL: randomChance = fmod(rand(), NORMAL_RARE); itemsToAdd = NORMAL_COMMON; break;
              case EVENT: randomChance = fmod(rand(), EVENT_RARE); itemsToAdd = EVENT_COMMON; break;
              case BOTH: randomChance = fmod(rand(), BOTH_RARE); itemsToAdd = BOTH_COMMON; break;
            }
            if(item[randomChance + itemsToAdd]){userCreditAmount+=15;}
            else{item[randomChance + itemsToAdd] = true; totalNumberOfItemsHeld++; heldItems[1]++;}
          }
        }
        else if(randomChance < PERCENT_CHANCE_COMMON + PERCENT_CHANCE_RARE + PERCENT_CHANCE_EPIC){ // this will mean we got an epic
          if(randomChance < PERCENT_CHANCE_COMMON + PERCENT_CHANCE_RARE + PERCENT_CHANCE_EPIC_CURRENCY){userCreditAmount += 150;}
          else{
            switch(trackerItemPoolType){
              case NORMAL: randomChance = fmod(rand(), NORMAL_EPIC); itemsToAdd = NORMAL_COMMON + NORMAL_RARE; break;
              case EVENT: randomChance = fmod(rand(), EVENT_EPIC); itemsToAdd = EVENT_COMMON + EVENT_RARE; break;
              case BOTH: randomChance = fmod(rand(), BOTH_EPIC); itemsToAdd = BOTH_COMMON + BOTH_RARE; break;
            }
            if(item[randomChance + itemsToAdd]){userCreditAmount+=50;}
            else{item[randomChance + itemsToAdd] = true; totalNumberOfItemsHeld++; heldItems[2]++;}
          }
        }
        else{ //this menas we got a legendary
          if (randomChance  < PERCENT_CHANCE_COMMON + PERCENT_CHANCE_RARE + PERCENT_CHANCE_EPIC + PERCENT_CHANCE_LEGENDARY_CURRENCY){userCreditAmount+=500;}
          else{
            switch(trackerItemPoolType){
              case NORMAL: randomChance = fmod(rand(), NORMAL_LEGENDARY); itemsToAdd = NORMAL_COMMON + NORMAL_RARE + NORMAL_EPIC; break;
              case EVENT: randomChance = fmod(rand(), EVENT_LEGENDARY); itemsToAdd = EVENT_COMMON + EVENT_RARE + EVENT_EPIC; break;
              case BOTH: randomChance = fmod(rand(), BOTH_LEGENDARY); itemsToAdd = BOTH_COMMON + BOTH_RARE + BOTH_EPIC; break;
            }
            if(item[randomChance + itemsToAdd]){userCreditAmount+=200;}
            else{item[randomChance + itemsToAdd] = true; totalNumberOfItemsHeld++; heldItems[3]++;}
          }
        }

      }  // end of one loot box open loop
      lootBoxCount++;
      switch (trackerItemPoolType){
      case NORMAL:
        while (userCreditAmount >= 25 && heldItems[0] != maxHeldItems[0]){
          for(int i = 0; i < maxHeldItems[0]; i++){
            if (!item[i]){item[i] = true; totalNumberOfItemsHeld++; heldItems[0]++; userCreditAmount-= 25; break;}
          }
        }
        itemsToAdd = maxHeldItems[0];
        while (userCreditAmount >= 75 && heldItems[1] != maxHeldItems[1]){
          for(int i = 0; i < maxHeldItems[1]; i++){
            if (!item[i + itemsToAdd]){item[i + itemsToAdd] = true; totalNumberOfItemsHeld++; heldItems[1]++; userCreditAmount-= 75; break;}
          }
        }
        itemsToAdd += maxHeldItems[1];
        while (userCreditAmount >= 250 && heldItems[2] != maxHeldItems[2]){
          for(int i = 0; i < maxHeldItems[2]; i++){
            if (!item[i + itemsToAdd]){item[i + itemsToAdd] = true; totalNumberOfItemsHeld++; heldItems[2]++; userCreditAmount-= 250; break;}
          }
        }
        itemsToAdd += maxHeldItems[2];
        while (userCreditAmount >= 1000 && heldItems[1] != maxHeldItems[1]){
          for(int i = 0; i < maxHeldItems[3]; i++){
            if (!item[i + itemsToAdd]){item[i + itemsToAdd] = true; totalNumberOfItemsHeld++; heldItems[3]++; userCreditAmount-= 1000;break;}
          }
        }
        break;

        case EVENT:
        while (userCreditAmount >= 75 && heldItems[0] != maxHeldItems[0]){
          for(int i = 0; i < maxHeldItems[0]; i++){
            if (!item[i]){item[i] = true; totalNumberOfItemsHeld++; heldItems[0]++; userCreditAmount-= 75; break;}
          }
        }
        itemsToAdd = maxHeldItems[0];
        while (userCreditAmount >= 225 && heldItems[1] != maxHeldItems[1]){
          for(int i = 0; i < maxHeldItems[1]; i++){
            if (!item[i + itemsToAdd]){item[i + itemsToAdd] = true; totalNumberOfItemsHeld++; heldItems[1]++; userCreditAmount-= 225; break;}
          }
        }
        itemsToAdd += maxHeldItems[1];
        while (userCreditAmount >= 750 && heldItems[2] != maxHeldItems[2]){
          for(int i = 0; i < maxHeldItems[2]; i++){
            if (!item[i + itemsToAdd]){item[i + itemsToAdd] = true; totalNumberOfItemsHeld++; heldItems[2]++; userCreditAmount-= 750; break;}
          }
        }
        itemsToAdd += maxHeldItems[2];
        while (userCreditAmount >= 3000 && heldItems[1] != maxHeldItems[1]){
          for(int i = 0; i < maxHeldItems[3]; i++){
            if (!item[i + itemsToAdd]){item[i + itemsToAdd] = true; totalNumberOfItemsHeld++; heldItems[3]++; userCreditAmount-= 3000;break;}
          }
        }
        break;

      }
    }
    cout << endl << lootBoxCount << endl;
    }

}
