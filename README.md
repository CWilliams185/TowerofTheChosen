# TowerofTheChosen
The original c++ source code of a text-based RPG I made around 2013-2014. Unfinished, and soon to be translated to Java.

The gameplay loop involves taking a character up each level of a tower, with the end goal to find and defeat the Dark Lord.
The concept was to allow strategy via physical vs magical damage, with a sense of randomness in attack calculations.
RNG equivalent to d100 are used for hit and critical chance when using physical attack. Magic attacks were never fully
implemented, but would have had 100% accuracy at the cost of mp (consumable magic points). Game possesses auto save functionality
after each successful combat.

The optimal strategy involved cheesing the game. The Dark Lord appears between floors 21 and 41, within a spectrum of chance.
Floor 41 has a 100% chance of the Dark Lord appearing. Reset the game if you run into him prematurely, and farm experience on
floors 21-40 to be at as high of a level as possible.
