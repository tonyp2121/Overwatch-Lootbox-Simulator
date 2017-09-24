# Must be ran on no later than python 2.7 because of the way dict_items ar used
# the count of particular items isnt a part of it
# as of 9-24-17 it works on the default game however later on I hope to add support for
# getting num of items from each event specifically

import json

Categories = ['sprays','voicelines','poses','icons','intros','emotes','skins']
Heros = ['all','ana','bastion','dva','doomfist','genji','hanzo','junkrat','lucio',
        'mccree','mei','mercy','orisa','pharah','reaper','reinhardt','roadhog','soldier-76',
        'sombra','symmetra','torbjorn','tracer','widowmaker','winston','zarya','zenyatta']
DefaultItems=[0,1,1,0,1,1,1]

#
# Because of the way the json file is built skins dont have built in rarity  and
# emotes are assumed to be epic besides dva which is a special case scenario
# so I will just do skins in a seperate way
# any additional skins after the 4 Rare and 2 epics are assumed legendary at least for the
# base cosmetics, when I add support for different events I'll have to just
# keep track of how many epics there are for skins and assume everything else is legendary
#

NumOfBaseCommon = 0
NumOfBaseRare = 0
NumOfBaseEpic = 0
NumOfBaseLegendary = 0

LevelOfRarityWereOn = 0

Config = json.loads(open('OverwatchItemsListBase.json').read())

for Characters in Heros:
    LevelOfRarityWereOn = 0 #Increases as categories change so first two are common,
                            #The next two are rare, etc, etc
    for Objects in Categories:
        if Config[Characters][Objects].values().count(True) is 0:
            LevelOfRarityWereOn += 1
            continue
        if LevelOfRarityWereOn < 2:   #Commons
            NumOfBaseCommon+= Config[Characters][Objects].values().count(True) - DefaultItems[LevelOfRarityWereOn]
        elif LevelOfRarityWereOn < 4: #Rares
            NumOfBaseRare+= Config[Characters][Objects].values().count(True) - DefaultItems[LevelOfRarityWereOn]
        elif LevelOfRarityWereOn < 6: #Epics
            NumOfBaseEpic+= Config[Characters][Objects].values().count(True) - DefaultItems[LevelOfRarityWereOn]
            if Characters is 'dva': #dva has the only base legendary emote
                if Objects is 'emotes':
                    NumOfBaseLegendary += 1
                    NumOfBaseEpic -= 1
        else:                         #Skins
            NumOfBaseRare += 4        #Always 4 Rares in base game
            NumOfBaseEpic += 2        #Always 2 Epics in base game
            NumOfBaseLegendary += Config[Characters][Objects].values().count(True) - 4 - 2 - DefaultItems[LevelOfRarityWereOn]
                                      #Whatever the rest is there is legendaries
        LevelOfRarityWereOn += 1
    if Characters is 'all':
        NumOfBaseCommon -= 3 #3 default sprays
        NumOfBaseRare -= 2   #3 default items

print("Number of Base Commons is " + str(NumOfBaseCommon))
print("Number of Base Rares is " + str(NumOfBaseRare))
print("Number of Base Epics is " + str(NumOfBaseEpic))
print("Number of Base Legendary is " + str(NumOfBaseLegendary))
print("\nTotal number of Base items is " + str(NumOfBaseCommon+NumOfBaseRare+NumOfBaseLegendary+NumOfBaseEpic))
