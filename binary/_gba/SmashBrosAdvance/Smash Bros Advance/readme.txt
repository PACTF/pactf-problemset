Super Smash Bros. ADVANCE
-------------------------

This is the official (but not licenced by Nintendo. mind you) README for the Smash Bros. ADV Project
being put together by thegamefreak0134, The_Perfection, and Natso. I am thegamefreak0134, and you're
reading this basically because I sat down one night and decided we needed an official readme, just to
keep a history of the project. This will always reflect the current release. Right-O, now on to the
Table of Contents.

*****************
Table of Contents
*****************
(betcha didn't see that comin'.)

1) About the Project
2) Project Status (What works)
3) To-Do List (What doesn't work)
4) Controlls
5) Project History
6) Contributing
7) Credits and Contact info
8) Legal Stuff

Note: The "Ctrl-F" trick should work.


********************
1) About the Project
********************

I guess you could say we're all Smash Bros Addicts, if there is such a thing. No, we're not joining a
club, get over it. The whole project started when Perfection and I were playing the game, and started
analysing it. Well, the sign of obsession with any game is when you start to do research on it and
figure out how it works. We looked at the game, and started to figure out what it would be like to code.
Then, someone (can't remember who) came up with the idea of trying some stuff out on the GBA, since we
had some basic knowledge at the time. That spawned into a whole series of discussions, which basically
concluded like this:

Nintendo has for too long deproved us of a Smash Bros. handheld version of any kind, so we're going to
do it in their stead. Better yet, we'll do it on the GBA rather than the DS (1) cause we can't program
on the DS, and (2) because it will be infinitely harder to get to work.

That being said, we took on the biggest project we've ever taken on. We've been working for a couple of
months by now, and we only have the very basics of the engine down. It's a long road ahead...

The main goal of the project, game wise, is to create a version of Super Smash Bros. that plays out just
like all the other versions, so there is no real learning curve. Unfortunately, emulating nintendo goodness
is not all that easy. Our goal is to get everything from characters down to items and projectiles to behave
as the original games would have them behave. We're using the 64 version for beginning development, but
will migrate to the GameCube style of things later down the line.


Obviously, the hardest part of the game to develop is the engine. We have to get a system up and running
that can calculate the physics for all kinds of different characters, items, projectiles, and the like.
Better yet, it has to be able to calculate all of this every frame. NOT easy. Considering that at any time
you can have 4 characters, 5 items, and around 20 projectiles flying around, this is no simple task. 

(Actually, so far the hardest part to code was the camera routine. We have the camera panning and zooming
just like the real thing, so you still have all the tactical advantage of seeing all players at once.
Bad thing here is, it takes a bunch of divides, which we all know are a royal pain in the ***)

Once we have the engine down, it will be a matter of hand-drawing and hand-coding every single state of
every character, item, and projectile. To make matters a little easier, we;ve designed a visual state
editor for the characters. Yes folks, I wrote a program to write code for me. Am I lazy or what? Anywho,
it opens up the possibility of having others create characters for us, which might be nice if we want
to add some community characters later along the line as unlockables.

The theme of the games (since we have to keep the concept original, of course) will be board game style.
The characters are the markers of the board, and your actions in battle determine where you go on the
board. We will still include the classic and adventure modes, they will simply be different boards. We
haven't decided on whether to have multiple boards, like in mario party, or wheather to have one huge
board that can play out differently every time.

Thats about all we have for now, for the about stuff. 

******************************
2) Project Status (What works)
******************************

This is the biggie. Here is a list of our current achievements with the project. Note that at early stages, 
this list may seem a bit, well, small. We're going as fast as we can, mind you!

Camera Routine
Frames System
States System
Physics Engine (Basic)
1 Character (Partial movement)

*********************************
3) To-Do List (What doesn't work)
*********************************

Idealy, this list should get smaller. However, as we have ideas they'll get thrown here occasionally.

Advanced Physics Engine (gravity, flying, etc.)
Hit Creation
Hit Detection (collision bubbles, hopefully)
1 fully Playable character
More characters, as time allows
Items
Projectiles
Damage
Damage Counters
Physics effects caused by damage
Move Priority
Custom  Graphics for every character (to avoid copyright issues)
Sound (likely ripped)
Music (original arrangements)
Voice (ripped to start, original if we can find voices) (gee, won't that be fun)
Levels
Better Collision on levels
Platforms (nightmares in small packages)
Different Battle Modes
Menu System
Rules and whatnot
Flashy Stuff (different outfits, etc)
Bonuses (bad dreams)
Intro Sequence
Multiplayer (oh please oh please)
Computer AI (much help will be needed here)
If computer AI {
Board Game Maps
Master Hand and Crazy Hand
Dark/Metal versions of characters
Adventure Stages
}

"Shoot the Credits" (There will probably be many if we get here. Three would be boring, dont'cha think?)


************
4) Controlls
************

For the current release of the demo, you can't do very much. Sorry about this, we're working. You are
Kirby, and there is a decoy mario "doll" center stage. You can walk and jump, (and fall) and thats about
it. Note that if you fall offscreen, the game tends to go funny. Since you won't be able to get to these
positions once we have the death boundaries set in place, don't worry about it.

D+pad - Move Kirby Left or Right.
A - Jump

Main things to notice here are the nice panning and scaling of the camera. Every frame of animation you see
was designed by our visual state editor. Note that at all times both kirby and mario can be seen, even if you
fall bayond the boundaries.



******************
5) Project History
******************

April 29, 2006-
	Wrote this README.txt
	First jump taken by kirby. Big day for the state and physics engine, as all appears to be working well.
	Perfection got his gamecube back. We can study properly now.

Before April 29, 2006-
	Expanded level. 2048 pixels wide for level = 512 pixels for map. (Level is 4x more accurate than screen.)
	Applied basic physics to level collision.
	First level collision. Crude, but OK for now.
	Level collision thought up.
	Kirby takes his first steps in the new system. (another big day.)
	Created states system
	Created frames system
	Actually got camera routine working. (big day, and real project start at this point)
	Designed camera routine.
	Started project



***************
6) Contributing
***************

You want to help us out? Thats great! We'd love to have some outsiders help us, we kinda want this to be
a big project. Send us an e-mail (look at contacts) and let us know what you think you can contribute. We're
looking for:

Artists
composers
Programming advice
Debuggers (later, when engine is more stable. Errors are kinda obvious at this point)


We will NOT accept:

You should add <name of character>
You should do <name of improvement>
You should compile using <something other than DevKitAdv>

or anything similar. Send us an e-mail, send work if you have it, and we'll let you know. 

Alright, alright. If you must give away something with monetary value, the only thing we really lack is a
flash cart. Although this isn't terribly important not, it will be later when we start dealing with advanced
effects and such. If you want to donate one (we will need the cable and software too, if you do) send us an 
e-mail and we'll send an address back to you. Big thanks if you can!


***************************
7) Credits and Contact info
***************************

thegamefreak0134 - Engine designer, main coder. (for now.)
Contact:
E-mail: thegamefreak0134@yahoo.com
gbadev.org: thegamefreak0134

The_Perfection - Project coordinater, main research and design.
Contact:

Natso - Multiplayer Engine, Help with GBA topics
Contact:


**************
8) Legal Stuff
**************

This game is NOT licenced by nintendo in any way, shape or form. With any due luck, they don't even know it 
exists. Thus, if it causes you any harm, if your little sister flushes it down the toilet when you beat her,
or if it gives you medical conditions you didn't have before the prospect of sueing for easy money, tough. By
playing this game, you release us (the developers) from any liabilities caused by it and by the use of it 
thereof. (Wow, you even read the disclaimer. Bravo!)

This is freeware and should never be treated as anything else. Please to not go selling this to anyone. It can't
make any profits or we are in serious copyright trouble, so keep that in mind. If we do make carts available, we
will sell them for only the cost of the carts and shipping. 

This game is NOT to be re-distributed in any way without the other things in the release package. (like this file.)
Also, I don't care who you think you are, if you're going to go and make a ROM image of it, please do NOT put a
damn intro on it. Kay? (these are official curses to you, oh "mode7" with your evil intros. CURSES!)

Course, we're not going to go off and actually enforce any of this, but just so you know, this is how we feel.

-End of File-


-Ha, you thought. REAL end of file.-