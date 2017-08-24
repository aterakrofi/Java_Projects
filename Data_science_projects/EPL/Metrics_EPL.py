
#Python program to calculate metrics from the English premierleague 
#By Ater Akrofi
from __future__ import division 
import pandas as pd
import numpy as np

#Dataset in csv format
dataset = pd.read_csv("EPL.csv")

#Peak at dataset
dataset.head(4)

#Numpy array of goals scored by Home Team
Home_Team_Goals=np.array(dataset['FTHG'])  # FTHG is full time home goals
print((Home_Team_Goals))

#Numpy array of shots on target by home team
HST=np.array(dataset['HST']) #HST is the home shots on target
print((HST))

#Metric 1 : Total goals

Total_Goals=sum(Home_Team_Goals) #summation of the array of home team goals
print "Total Home goals scored : %s" % Total_Goals

#Metric 2 :Average Goals per game(Total Goals/Total Games)

#every match result is an instance of a match played, hence the count of the full time goals scored= total games
Total_Games=dataset['FTHG'].count() 
#Total goals
print "Total home goals scored : %s" % Total_Goals
#Total number of Games
print "Total Games: %s" % Total_Games
#Average goals per game 
Average_Goals=Total_Goals/Total_Games
print "Average goals per game : %s" % Average_Goals

# Metric 3 : Frequency or number of times a home team scored more than 3 goals
Freq=np.count_nonzero(Home_Team_Goals > 3) # count of goals scored > 3
print "Number of times Home teams scored more than 3 goals: %s" % Freq

#Metric 4 : Shooting percentage(SP) for Liverpool's 1st home game(Liverpool v Leicester)

#LFC_GS = Goals scored by Liverpool against Leicester at array location [33]         
LFC_GS=Home_Team_Goals[33] 
print "Liverpool goals against Leicester: %s" % LFC_GS
#LFC_HST = shots on target by liverpoool against Leicester at array location [33]
LFC_HST=HST[33]
print "Liverpool Shots on target against Leicester: %s" % LFC_HST
#Shooting Percentage(SP) = goals scored / shots on goal taken.
SP=(LFC_GS/LFC_HST)*100
#print('LFC shooting percentage',SP,'%')
print "Liverpool's shooting percentage : %s" % SP

#Corelation between Home goals and shots on target

Corr= np.corrcoef(Home_Team_Goals, HST)
print("Correlation between Home team goals and shots on target : ")
print(Corr)




