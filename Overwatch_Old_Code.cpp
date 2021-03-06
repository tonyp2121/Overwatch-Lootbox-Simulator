// Anthony Pallone
// This is the old code now, Overwatch has since updated and changed the item drop percentage to basically make duplicates impossible so I'll make another version.

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
#define PERCENT_CHANCE_EVENT 666
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

int main(void){
  srand(time(NULL));
  string userInput;
  //bool item[BOTH_COMMON + BOTH_RARE + BOTH_EPIC + BOTH_LEGENDARY];

  int lootBoxCount = 0;
  int trackerItemPoolType;
  int userCreditAmount;
  do{
  cout << "Enter 'N' for normal Overwatch Loot 'B' for both normal and Event Items" << endl;
  cin >> userInput;
}while(userInput != "N" && userInput != "n" && userInput != "B" && userInput != "b");
  // must add a check to see whether to buy items or not
  if(userInput == "N" || userInput == "n"){trackerItemPoolType = NORMAL;}
  else if(userInput == "B" || userInput == "b"){trackerItemPoolType = BOTH;

  int maxHeldItems[8] = {NORMAL_COMMON, NORMAL_RARE, NORMAL_EPIC, NORMAL_LEGENDARY, EVENT_COMMON, EVENT_RARE, EVENT_EPIC, EVENT_LEGENDARY};

  int totalNumberOfItemsTracker

  switch (trackerItemPoolType){
    case NORMAL: totalNumberOfItemsTracker = NORMAL_COMMON + NORMAL_RARE + NORMAL_EPIC + NORMAL_LEGENDARY; break;
    case BOTH: totalNumberOfItemsTracker = BOTH_COMMON + BOTH_RARE + BOTH_EPIC + BOTH_LEGENDARY;  break;
  }
  bool *item = new bool[totalNumberOfItemsTracker];
  int lootBoxAvg = 0;
  int loopCount = 1000;
    for(int i = 0; i < loopCount; i++){
      // this is where the most of the work is done.
      // so first off we go open up a new loot box making sure at least one of them is a rare or better
      // in our bool it will go COMMON << RARE << EPIC << LEGENDARY and events will come after that.
      // Event Items are guaranteed at least one per event loot box
      // in a loot box I want it to roll 4 times and on the fourth see if a rare or better has spawned.

      int heldItems[8] = {0,0,0,0,0,0,0,0};
      if(i > 0) for (int k = 0; k < totalNumberOfItemsTracker; k++) item[k] = false; // set everything to 0 after the first go around
      lootBoxCount = 0;
      int totalNumberOfItemsHeld = 0;
      userCreditAmount = 0;
    while(totalNumberOfItemsTracker != totalNumberOfItemsHeld){
      int randomChance;
      int randomChanceEvent;
      int itemsToAdd;
      int rareCounter = 0;
      int eventItemCounter = 0;
      for(int j = 0;j < 4; j++){
        bool isEventItem = false;
        randomChance = rand() % PERCENT_CHANCE_TOTAL;
        if (trackerItemPoolType == BOTH){
          randomChanceEvent = rand() % PERCENT_CHANCE_TOTAL;
          if(randomChanceEvent < PERCENT_CHANCE_EVENT || eventItemCounter == 0 && j == 3){eventItemCounter++; isEventItem = true;}
        }
        if (randomChance >= PERCENT_CHANCE_COMMON){rareCounter ++;} // if its higher than common we have a rare
        if(j == 3 && rareCounter == 0){randomChance = rand() % (PERCENT_CHANCE_RARE + PERCENT_CHANCE_EPIC + PERCENT_CHANCE_LEGENDARY) + PERCENT_CHANCE_COMMON;} // this i here becasue in OW oyu have to have a rare or bettre
        if(randomChance < PERCENT_CHANCE_COMMON){ // this will mean we got a common
          switch(trackerItemPoolType){
            case NORMAL: randomChance = fmod(rand(), NORMAL_COMMON); break;
            case BOTH: if (isEventItem){randomChance = fmod(rand(), EVENT_COMMON) + NORMAL_COMMON;} else{ fmod(rand(), NORMAL_COMMON);} break;
          }
          if(item[randomChance]){userCreditAmount+=5;}
          else{item[randomChance] = true; totalNumberOfItemsHeld++; if(isEventItem){heldItems[4]++;} else{heldItems[0]++;}}
          //cout << "I got a common" << endl;
        }
        else if(randomChance < PERCENT_CHANCE_COMMON + PERCENT_CHANCE_RARE){ // this will mean we got a rare
          if(randomChance < PERCENT_CHANCE_COMMON + PERCENT_CHANCE_RARE_CURRENCY){userCreditAmount+=50;}
          else{
            switch(trackerItemPoolType){
              case NORMAL: randomChance = fmod(rand(), NORMAL_RARE); itemsToAdd = NORMAL_COMMON; break;
              case BOTH: if (isEventItem){randomChance = fmod(rand(), EVENT_RARE); itemsToAdd = BOTH_COMMON + NORMAL_RARE;} else{mod(rand(), NORMAL_RARE); itemsToAdd = BOTH_COMMON;}  break;
            }
            if(item[randomChance + itemsToAdd]){userCreditAmount+=15;}
            else{item[randomChance + itemsToAdd] = true; totalNumberOfItemsHeld++; if(isEventItem){heldItems[5]++;} else{heldItems[1]++;}}
          }
          //cout << "I got a rare" << endl;
        }
        else if(randomChance < PERCENT_CHANCE_COMMON + PERCENT_CHANCE_RARE + PERCENT_CHANCE_EPIC){ // this will mean we got an epic
          if(randomChance < PERCENT_CHANCE_COMMON + PERCENT_CHANCE_RARE + PERCENT_CHANCE_EPIC_CURRENCY){userCreditAmount += 150;}
          else{
            switch(trackerItemPoolType){
              case NORMAL: randomChance = fmod(rand(), NORMAL_EPIC); itemsToAdd = NORMAL_COMMON + NORMAL_RARE; break;
              case BOTH: if (isEventItem) {randomChance = fmod(rand(), EVENT_EPIC); itemsToAdd = BOTH_COMMON + BOTH_RARE + NORMAL_EPIC;} else {randomChance = fmod(rand(), NORMAL_EPIC); itemsToAdd = BOTH_COMMON + BOTH_RARE;} break;
            }
            if(item[randomChance + itemsToAdd]){userCreditAmount+=50;}
            else{item[randomChance + itemsToAdd] = true; totalNumberOfItemsHeld++; if(isEventItem){heldItems[6]++;} else{heldItems[2]++;}
          }
          //cout << "I got a epic" << endl;
        }
        else{ //this menas we got a legendary
          if (randomChance  < PERCENT_CHANCE_COMMON + PERCENT_CHANCE_RARE + PERCENT_CHANCE_EPIC + PERCENT_CHANCE_LEGENDARY_CURRENCY){userCreditAmount+=500;}
          else{
            switch(trackerItemPoolType){
              case NORMAL: randomChance = fmod(rand(), NORMAL_LEGENDARY); itemsToAdd = NORMAL_COMMON + NORMAL_RARE + NORMAL_EPIC; break;
              case BOTH: if (isEventItem) {randomChance = fmod(rand(), EVENT_LEGENDARY); itemsToAdd = BOTH_COMMON + BOTH_RARE + BOTH_EPIC + NORMAL_EPIC;} else {randomChance = fmod(rand(), NORMAL_LEGENDARY); itemsToAdd = BOTH_COMMON + BOTH_RARE + BOTH_EPIC;} break;
            }
            if(item[randomChance + itemsToAdd]){userCreditAmount+=200;}
            else{item[randomChance + itemsToAdd] = true; totalNumberOfItemsHeld++; if(isEventItem){heldItems[7]++;} else{heldItems[3]++;}}
          }
          //cout << "I got a legendary" << endl;
        }

      }  // end of one loot box open loop
      lootBoxCount++;
      // cout << lootBoxCount << endl;
      // cout << endl;
      // cout << userCreditAmount << endl;  here for debugging
      switch (trackerItemPoolType){
      case NORMAL:
        while (userCreditAmount >= 25 && heldItems[0] != maxHeldItems[0]){
          for(int k = 0; k < maxHeldItems[0]; k++){
            if (!item[k]){item[k] = true; totalNumberOfItemsHeld++; heldItems[0]++; userCreditAmount-= 25; break;}
          }
        }
        itemsToAdd = maxHeldItems[0];
        while (userCreditAmount >= 75 && heldItems[1] != maxHeldItems[1]){
          for(int k = 0; k < maxHeldItems[1]; k++){
            if (!item[k + itemsToAdd]){item[k + itemsToAdd] = true; totalNumberOfItemsHeld++; heldItems[1]++; userCreditAmount-= 75; break;}
          }
        }
        itemsToAdd += maxHeldItems[1];
        while (userCreditAmount >= 250 && heldItems[2] != maxHeldItems[2]){
          for(int k = 0; k < maxHeldItems[2]; k++){
            if (!item[k + itemsToAdd]){item[k + itemsToAdd] = true; totalNumberOfItemsHeld++; heldItems[2]++; userCreditAmount-= 250; break;}
          }
        }
        itemsToAdd += maxHeldItems[2];
        while (userCreditAmount >= 1000 && heldItems[3] != maxHeldItems[3]){
          for(int k = 0; k < maxHeldItems[3]; k++){
            if (!item[k + itemsToAdd]){item[k + itemsToAdd] = true; totalNumberOfItemsHeld++; heldItems[3]++; userCreditAmount-= 1000;break;}
          }
        }
        break;

      case BOTH:
        while (userCreditAmount >= 25 && heldItems[0] != maxHeldItems[0]){
          for(int k = 0; k < maxHeldItems[0]; k++){
            if (!item[k]){item[k] = true; totalNumberOfItemsHeld++; heldItems[0]++; userCreditAmount-= 25; break;}
          }
        }
        itemsToAdd = maxHeldItems[0];
        while (userCreditAmount >= 75 && heldItems[1] != maxHeldItems[1]){
          for(int k = 0; k < maxHeldItems[1]; k++){
            if (!item[k + itemsToAdd]){item[k + itemsToAdd] = true; totalNumberOfItemsHeld++; heldItems[1]++; userCreditAmount-= 75; break;}
          }
        }
        itemsToAdd += maxHeldItems[1];
        while (userCreditAmount >= 250 && heldItems[2] != maxHeldItems[2]){
          for(int k = 0; k < maxHeldItems[2]; k++){
            if (!item[k + itemsToAdd]){item[k + itemsToAdd] = true; totalNumberOfItemsHeld++; heldItems[2]++; userCreditAmount-= 250; break;}
          }
        }
        itemsToAdd += maxHeldItems[2];
        while (userCreditAmount >= 1000 && heldItems[3] != maxHeldItems[3]){
          for(int k = 0; k < maxHeldItems[3]; k++){
            if (!item[k + itemsToAdd]){item[k + itemsToAdd] = true; totalNumberOfItemsHeld++; heldItems[3]++; userCreditAmount-= 1000;break;}
          }
        }
        itemsToAdd = NORMAL_COMMON;
        while (userCreditAmount >= 75 && heldItems[4] != maxHeldItems[4]){
          for(int k = 0; k < maxHeldItems[4]; k++){
            if (!item[k + itemsToAdd]){item[k+ itemsToAdd] = true; totalNumberOfItemsHeld++; heldItems[4]++; userCreditAmount-= 75; break;}
          }
        }
        itemsToAdd = BOTH_COMMON + NORMAL_RARE;
        while (userCreditAmount >= 225 && heldItems[5] != maxHeldItems[5]){
          for(int k = 0; k < maxHeldItems[5]; k++){
            if (!item[k + itemsToAdd]){item[k + itemsToAdd] = true; totalNumberOfItemsHeld++; heldItems[5]++; userCreditAmount-= 225; break;}
          }
        }
        itemsToAdd = BOTH_COMMON + BOTH_RARE + NORMAL_EPIC;
        while (userCreditAmount >= 750 && heldItems[6] != maxHeldItems[6]){
          for(int k = 0; k < maxHeldItems[6]; k++){
            if (!item[k + itemsToAdd]){item[k + itemsToAdd] = true; totalNumberOfItemsHeld++; heldItems[6]++; userCreditAmount-= 750; break;}
          }
        }
        itemsToAdd = BOTH_COMMON + BOTH_RARE + BOTH_EPIC + NORMAL_LEGENDARY;
        while (userCreditAmount >= 3000 && heldItems[7] != maxHeldItems[7]){
          for(int k = 0; k < maxHeldItems[7]; k++){
            if (!item[k + itemsToAdd]){item[k + itemsToAdd] = true; totalNumberOfItemsHeld++; heldItems[7]++; userCreditAmount-= 3000;break;}
          }
        }
        break;

      }
    }
    lootBoxAvg += lootBoxCount;
    // cout << endl << lootBoxCount << endl;
    }
    cout << lootBoxAvg/loopCount << endl;
}
