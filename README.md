Name: 			Cornel Stoica
Project Name: 	Tic-Tac-Toe-Game/W-Array
Updated date: 	3/23/20


About program/game:

This is a C++ console-based tic-tac-toe game with an unbeatable CPU player. Game has 2 modes: single player and multiplayer.

In single player mode, the player goes against the CPU in a battle for highest score.
In multiplayer mode, two players are allowed to battle against each other for highest score.

Most of the program code is used up by CPU move logic.
NOTE: Not all unique and possible needed to be implemented - only the most important ones based on player choices and board analysis.

Game has been tested in both single player and multiplayer modes.

As of 3/23/20, no bugs have been found and game passed tests.

Game begins with a welcome message from which a main menu with options is displayed that allows a player(s) to begin match.





Code revisions:

3/23/20

- Got rid of bloat by removing "using namespace std." By not including the entirety of the std namespace into the current namespace
  of the program, I opted for the scope resolution operator(::).
- Created a header file for constant and function prototypes.
- Created two more .ccp files (one for the large cpu move logic function and another for the rest of the functions).
- Tested the game again (works groovy).

11/1/20

- Changed the gameArray variable to static char in the header file. This restricts the scope of the definition to the current
  object file, and allows multiple object files to have their own copy of the variable.
- Tested the game again (works groovy).