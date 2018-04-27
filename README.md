# Blasterman
BlasterMan is an experimental project to replicate Bomberman gameplay with Unreal Engine.

The following are features implemented for this test:
 
• Static top-down view on the level
• One pre-defined map 
• “Couch Co-Op”: Two players play on one machine using different keys to control two characters 
• Make the characters distinguishable somehow (color, nameplate, …) 
• Both players using the keyboard, Red Player using A,S,D,W for movement and Left Shift for placing a bomb, Blue Player using Left,Down,Right,Up for movement and Enter for placing a bomb
• Implementation of different pickups 
	o Longer bomb blasts 
	o More bombs 
	o Faster run speed 
	o Remote-controlled bombs (timed power-up, 10 seconds) 
	o Player is starting with only one bomb that can be active at a time 
	o Placing a bomb subtracts one from the count, when the bomb explodes the count goes up again 
	o Amount is upgradable with pickups 
• Player death when standing in bomb blast 
• Bomb blasts is linear in the four main directions 
• Bomb blast 
	o Can penetrate players/pickups when going off (killing/destroying them) Are stopped by walls
	o Trigger other bombs 
• Differentiation between destructible and indestructible walls, destructible walls can spawn random pickups (~30% chance to spawn something) upon destruction 
• Win conditions: 
	o Show win screen when only one player is alive 
	o Show a map timer, that counts down and ends the round  
	o Show draw when the last players die in the same bomb blast (or chained bombs) or multiple players are alive when the timer runs out 
	o After round end, freeze game in its current state • Reset option on end screen 
	o Starts another round 
	o Previous score should be saved
	
Bonus:
	• Camera that pans in/out depending on distance between players in the level 
	• Random Power Spawn Actor
	
Timespent : 32 Hours
I have a lot of fun working on this project. However, it took me longer than 15 hours. However, most of the time is for me to study and research on how to do things in UE4.
Since I have only used UE4 for a short time for about two years ago.

Further Works:
If I continue work on this project, I will do a game design document first. At the moment, my game idea is to creat an online-multiplayer adventure bomberman game. 
Players control a bomber man play through a series of levels competing with players around the world. Bomber man can be upgraded and customized.
After I have finished my game design doc, I will work on technical design document and start project from scratch.

