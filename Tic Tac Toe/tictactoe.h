#pragma once

//Constants for array dimensions
const int ROW = 3;
const int COLUMN = 3;

//Array
static char gameArray[ROW][COLUMN] = { ' ' };

//Function prototypes
void displayMenu();
void displayWelcome();
void gameMode(int, int);
void displayControls();
void singlePlayer(int, int);
void multiPlayer(int, int);
void displayStartGrid();
void playerOneMove(char, char, bool, int, int);
void playerTwoMove(char, char, bool, int, int);
bool checkTaken(int);
void cpuMove(char, char, int, int);
int diceRoll();
void placePlayerSelection(int, char);
void checkIfWin(char, char, bool, int&, int&);
void displayUpdatedBoard();
void cpuChoicePrint(int);
void displayWinningBoard(const char gameArray[ROW][COLUMN], std::string);
void displayScore(bool, const int, const int);