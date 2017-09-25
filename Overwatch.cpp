// Anthony Pallone
// This is the updated version that is currently unwritten.
// Thankfully this code will be much easier to write and parse than the old system as I'm going to assume its 100% new items
// (besides the chance of coin drops as I have only gotten new items until I've run out of new items to get and from what I've screen
//  the general consensus is its like that)

#include <string>
#include <iostream>
#include <cmath>
#include <time.h>
#include <stdlib.h>

using namespace std;

#define NORMAL 0
#define EVENT 1
//
// These are temp percent chances from the old system I keep them here in case they have not changed
//
#define PERCENT_CHANCE_COMMON 5820
#define PERCENT_CHANCE_RARE   3170
#define PERCENT_CHANCE_EPIC   755
#define PERCENT_CHANCE_LEGENDARY 255
#define PERCENT_CHANCE_EVENT 666
#define PERCENT_CHANCE_TOTAL 10000
//
//
//
#define PERCENT_CHANCE_RARE_CURRENCY 411
#define PERCENT_CHANCE_EPIC_CURRENCY 243      // I can find if its a currency if we see if its greater than common chance but less thanc ommon chance + currency chance
#define PERCENT_CHANCE_LEGENDARY_CURRENCY 42

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

#define BASE_COMMON_AMOUNT 860
#define BASE_RARE_AMOUNT 309
#define BASE_EPIC_AMOUNT 250
#define BASE_LEGENDARY_AMOUNT 105

void LootboxOpen(bool *ItemList);
void PurchaseItem(bool *ItemList);

int main(int argc, char *argv[]) {
	srand(time(NULL));
	

	return 0;
}

void LootboxOpen(bool *ItemList)
{

}

void PurchaseItem(bool *ItemList)
{

}
