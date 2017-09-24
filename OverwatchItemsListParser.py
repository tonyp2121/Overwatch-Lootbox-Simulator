# Must be ran on no later than python 2.7 because of the way dict_items ar used
# the count of particular items isnt a part of it

import json

Categories = ['sprays','voicelines','poses','icons','intros','emotes','skins']
Heros = ['all','ana','bastion','dva','doomfist','genji','hanzo','junkrat','lucio',
        'mccree','mei','mercy','orisa','pharah','reaper','reinhardt','roadhog','soldier-76',
        'sombra','symmetra','torbjorn','tracer','widowmaker','winston','zarya','zenyatta']

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

Config = json.loads(open('OverwatchItemsList.json').read())

for Characters in Heros:
    LevelOfRarityWereOn = 0 #Increases as categories change so first two are common,
                            #The next two are rare, etc, etc
    for Objects in Categories:
        if LevelOfRarityWereOn < 2:   #Commons
            NumOfBaseCommon+= Config[Characters][Objects].values().count(True)
        elif LevelOfRarityWereOn < 4: #Rares
            NumOfBaseRare+= Config[Characters][Objects].values().count(True)
        elif LevelOfRarityWereOn < 6: #Epics
            NumOfBaseEpic+= Config[Characters][Objects].values().count(True)
            if Characters is 'dva': #dva has the only base legendary emote
                if Objects is 'emotes':
                    NumOfBaseLegendary += 1
                    NumOfBaseEpic -= 1
        else:                         #Skins
            NumOfBaseRare += 4        #Always 4 Rares
            NumOfBaseEpic += 2        #Always 2 Epics
            NumOfBaseLegendary += Config[Characters][Objects].values().count(True) - 4 -2
                                      #Whatever the rest is there is legendaries
        LevelOfRarityWereOn += 1

print("Number of Base Commons is " + str(NumOfBaseCommon))
print("Number of Base Rares is " + str(NumOfBaseRare))
print("Number of Base Epics is " + str(NumOfBaseEpic))
print("Number of Base Legendary is " + str(NumOfBaseLegendary))
print("\nTotal number of Base items is " + str(NumOfBaseCommon+NumOfBaseRare+NumOfBaseLegendary+NumOfBaseEpic))
