// Welcome to my Tic Tac Toe game. Game has 2 modes: Single Player (against cpu) or Multiplayer (1v1).
//
//Created by: Cornel Stoica
//Date: 12/16/19


#include <iostream>
#include <string>
#include <ctime>
#include "windows.h" //For sleep

using namespace std;

//Constants for array dimensions
const int ROW = 3;
const int COLUMN = 3;

//Array
char gameArray[ROW][COLUMN] = { ' ' };

//Function prototypes
void displayMenu();
void displayWelcome();
void gameMode();
void displayControls();
void singlePlayer();
void multiPlayer();
void displayStartGrid();
void playerOneMove(char, char, bool);
void playerTwoMove(char, char, bool);
bool checkTaken(int);
void cpuMove(char, char);
int diceRoll();
void placePlayerSelection(int, char);
void checkIfWin(char, char, bool);
void displayUpdatedBoard();
void cpuChoicePrint(int);
void displayWinningBoard(const char gameArray[ROW][COLUMN], string);

int main()
{
    displayWelcome();
    displayMenu();

    cout << endl << endl; //Extra space

    return 0;
}


//Function to display welcome message
void displayWelcome()
{
    cout << "Welcome to Tic Tac Toe! See menu below for options." << endl << endl;
}

//Function to display menu
void displayMenu()
{
    int menuOption = 0;
    
    do {
        cout << "Main menu." << endl;
        cout << "New Game \t\t(1)" << endl;
        cout << "Display controls \t(2)" << endl;
        cout << "Quit \t\t\t(3)" << endl << endl;

        cout << "Please make a selection now: ";

        cin >> menuOption;

        if (cin.fail() && !isdigit(menuOption))
        {
            cout << "Invalid choice. Please try again!" << endl;
            cin.clear();
            cin.ignore();
        }

        cout << endl;

    } while (menuOption != 1 && menuOption != 2 && menuOption != 3);

    if (menuOption == 1)
        gameMode();
    else if (menuOption == 2)
    {
        displayControls();
        displayMenu();
    }
    else
    {
        cout << "Thank you for playing. Goodbye!" << endl << endl;
        exit(0);
    }
}

//Function to display game mode
void gameMode()
{
    int modeChoice = { 0 };

    do {

        cout << "Available Game Modes. " << endl;
        cout << "Single Player (vs CPU) \t(1) " << endl;
        cout << "Two Player (vs player) \t(2) " << endl << endl;
        cout << "Please make a selection: ";
        cin >> modeChoice;

        if (cin.fail() && !isdigit(modeChoice))
        {
            cout << "Invalid choice. Please try again!" << endl;
            cin.clear();
            cin.ignore();
        }

        cout << endl;

    } while (modeChoice != 1 && modeChoice != 2);

    if (modeChoice == 1)
        singlePlayer();
    else
        multiPlayer();

}


//Function to display controls
void displayControls()
{ 
    cout << endl;
    cout << "The grid is setup as follows: " << endl;
    cout << "     :     :     " << endl;
    cout << "  1  :  2  :  3  " << endl;
    cout << "_____:_____:_____" << endl;
    cout << "     :     :     " << endl;
    cout << "  4  :  5  :  6  " << endl;
    cout << "_____:_____:_____" << endl;
    cout << "     :     :     " << endl;
    cout << "  7  :  8  :  9  " << endl;
    cout << "     :     :     " << endl;
    cout << endl;        
    cout << "To choose a square, simply type in the number." << endl;
    cout << "For example, to place an X or O in the middle square, type 5." << endl;
    cout << endl << endl; //Extra space
}

//Function for single player mode
void singlePlayer()
{
    int playerOneScore = { 0 }; //Reset score to 0
    int diceOne = { 0 };
    int diceCPU = { 9 };
    int key = { 0 };
    char playerOneSymbol = ' ';
    char cpuSymbol = ' ';
    bool multiFlag = false;

    //Reset grid squares
    for (int x = 0; x < ROW; x++)
        for (int y = 0; y < COLUMN; y++)
            gameArray[x][y] = ' ';

    //CODE BELOW IS TAKING TOO LONG TO EXECUTE. WILL COME BACK TO LATER.
    ////Repeat dice roll if a tie
    //do {
    //    diceOne = diceRoll();
    //    diceCPU = diceRoll();
    //} while (diceOne == diceCPU);
    
    cout << "Game start!" << endl;
    cout << "Let's determine who goes first by rolling a dice." << endl << endl;
    cout << "Player One rolled a " << diceOne << "." << endl;
    cout << "CPU rolled a " << diceCPU << "." << endl << endl;
    
    //Determine symbols based on who goes first/second
    if (diceOne > diceCPU)
    {
        playerOneSymbol = 'X';
        cpuSymbol = 'O';
        cout << "Player One goes first (X)." << endl;
        cout << "CPU goes second (O)." << endl;
    }
    else
    {
        playerOneSymbol = 'O';
        cpuSymbol = 'X';
        cout << "CPU goes first (X)." << endl;
        cout << "Player One goes second (O)." << endl;

    }

    cout << "Press a key to continue...";
    cin >> key;       
    cin.clear(); //Clear cin state after key press

    /////////////////////DONT NEED NOW displayStartGrid(); //Display start grid

    if (diceOne > diceCPU)
        playerOneMove(playerOneSymbol, cpuSymbol, multiFlag); //Player one makes first move
    else
        cpuMove(playerOneSymbol, cpuSymbol); //CPU makes first move
        
}

//Function for single player mode
void multiPlayer()
{
    int playerOneScore = { 0 }; //Reset score to 0
    int playerTwoScore = { 0 }; //Reset score to 0
    int diceOne = { 0 };
    int diceTwo = { 9 };
    int key = { 0 }; //For continue purposes
    char playerOneSymbol = ' ';
    char playerTwoSymbol = ' ';
    char cpuSymbol = ' ';
    bool multiFlag = true;

    //Reset grid squares
    for (int x = 0; x < ROW; x++)
        for (int y = 0; y < COLUMN; y++)
            gameArray[x][y] = ' ';

    //CODE BELOW IS TAKING TOO LONG TO EXECUTE. WILL COME BACK TO LATER.
    ////Repeat dice roll if a tie
    //do {
    //    diceOne = diceRoll();
    //    diceCPU = diceRoll();
    //} while (diceOne == diceCPU);

    cout << "Game start!" << endl;
    cout << "Let's determine who goes first by rolling a dice." << endl << endl;
    cout << "Player One rolled a " << diceOne << "." << endl;
    cout << "Player Two rolled a " << diceTwo << "." << endl << endl;

    //Determine symbols based on who goes first/second
    if (diceOne > diceTwo)
    {
        playerOneSymbol = 'X';
        playerTwoSymbol = 'O';
        cout << "Player One goes first (X)." << endl;
        cout << "Player Two second (O)." << endl;
    }
    else
    {
        playerOneSymbol = 'O';
        playerTwoSymbol = 'X';
        cout << "Player Two goes first (X)." << endl;
        cout << "Player One second (O)." << endl;

    }

    cout << "Press a key to continue...";
    cin >> key;
    cin.clear();

    /////////////////////DONT NEED NOW displayStartGrid(); //Display start grid

    if (diceOne > diceTwo)
        playerOneMove(playerOneSymbol, playerTwoSymbol, multiFlag); //Player one makes first move
    else
        playerTwoMove(playerOneSymbol, playerTwoSymbol, multiFlag); //CPU makes first move
}

//Function to display start grid
void displayStartGrid()
{
    cout << endl << endl;
    cout << "Current board: " << endl;
    cout << "     :     :     " << endl;
    cout << "     :     :     " << endl;
    cout << "_____:_____:_____" << endl;
    cout << "     :     :     " << endl;
    cout << "     :     :     " << endl;
    cout << "_____:_____:_____" << endl;
    cout << "     :     :     " << endl;
    cout << "     :     :     " << endl;
    cout << "     :     :     " << endl;
    cout << endl;
}

//Function to get dice roll
int diceRoll()
{
    int result = { 0 };

    srand(time(NULL));
    result = rand() % 6 + 1;

    return result;
}

//Function to make player move
void playerOneMove(char playerOneSymbol, char otherSymbol, bool multiFlag)
{
    int PlayerOneChoice = { 0 };
    bool taken = false;
    
    do {

        cout << endl;
        cout << "Player One, please make a selection (1-9): ";
        cin.ignore();
        cin >> PlayerOneChoice;
       
        if (!isdigit(PlayerOneChoice) && (PlayerOneChoice < 1 || PlayerOneChoice > 9))
        {
            cin.clear();
            cout << "Invalid choice. Please try again!" << endl;         
        }        
        else {      
            taken = checkTaken(PlayerOneChoice);
            if (taken == true)
                cout << "Square already occupied. Make another selection." << endl;
        }

    } while ((PlayerOneChoice != 1 && PlayerOneChoice != 2 && PlayerOneChoice != 3 &&
              PlayerOneChoice != 4 && PlayerOneChoice != 5 && PlayerOneChoice != 6 &&
              PlayerOneChoice != 7 && PlayerOneChoice != 8 && PlayerOneChoice != 9) || (taken==true));

    placePlayerSelection(PlayerOneChoice, playerOneSymbol); //Place player's one selection on board
    displayUpdatedBoard(); //Display updated game grid board
    checkIfWin(playerOneSymbol, otherSymbol, multiFlag); //Check if win occured     

    //Next player goes depending on multiFlag
    if (multiFlag == false)
        cpuMove(playerOneSymbol, otherSymbol); //CPU goes next (single player)
    else
        playerTwoMove(playerOneSymbol, otherSymbol, multiFlag); //Player goes goes next (multiplayer)
}

void playerTwoMove(char playerOneSymbol, char playerTwoSymbol, bool multiFlag)
{
    int PlayerTwoChoice = { 0 };
    bool taken = false;

    do {

        cout << endl;
        cout << "Player Two, please make a selection (1-9): ";
        cin.ignore();
        cin >> PlayerTwoChoice;
        
        if (!isdigit(PlayerTwoChoice) && (PlayerTwoChoice < 1 || PlayerTwoChoice > 9))
        {
            cin.clear();
            cout << "Invalid choice. Please try again!" << endl;
        }
        else {
            taken = checkTaken(PlayerTwoChoice);
            if (taken == true)
                cout << "Square already occupied. Make another selection." << endl;
        }

    } while ((PlayerTwoChoice != 1 && PlayerTwoChoice != 2 && PlayerTwoChoice != 3 &&
        PlayerTwoChoice != 4 && PlayerTwoChoice != 5 && PlayerTwoChoice != 6 &&
        PlayerTwoChoice != 7 && PlayerTwoChoice != 8 && PlayerTwoChoice != 9) || (taken == true));

    placePlayerSelection(PlayerTwoChoice, playerTwoSymbol); //Place player two selection on board
    displayUpdatedBoard(); //Display updated game grid board
    checkIfWin(playerOneSymbol, playerTwoSymbol, multiFlag); //Check if win occured     

    //Next player goes 
    playerOneMove(playerOneSymbol, playerTwoSymbol, multiFlag);
}

//Function to make cpu move
void cpuMove(char playerOneSymbol, char cpuSymbol)
{
    int randomNum = { 0 };
    bool multiFlag = false;

    cout << endl << endl;
    cout << "Please wait. Computer is thinking";
    Sleep(400);
    cout << ".";
    Sleep(400);
    cout << ".";
    Sleep(400);
    cout << ".";
    Sleep(400);
    cout << "." << endl;

    //Determine cpu selection based on game board analysis
    if (cpuSymbol == 'X') {

        // If board is empty and CPU goes first
        if (gameArray[0][0] == ' ' && gameArray[0][1] == ' ' && gameArray[0][2] == ' ' && gameArray[1][0] == ' '
            && gameArray[1][1] == ' ' && gameArray[1][2] == ' ' && gameArray[2][0] == ' ' && gameArray[2][1] == ' '
            && gameArray[2][2] == ' ') {

            do {
                srand(time(NULL));
                randomNum = 1 + rand() % 9;
            } while (randomNum % 2 == 0); //Repeat if random number is even. We want an odd number

            if (randomNum == 1) {
                gameArray[0][0] = 'X';
                cpuChoicePrint(1);
            }
            else if (randomNum == 3) {
                gameArray[0][2] = 'X';
                cpuChoicePrint(3);
            }
            else if (randomNum == 5) {
                gameArray[1][1] = 'X';
                cpuChoicePrint(5);
            }
            else if (randomNum == 7) {
                gameArray[2][0] = 'X';
                cpuChoicePrint(7);
            }
            else {
                gameArray[2][2] = 'X';
                cpuChoicePrint(9);
            }
        }

        //If board is not empty and CPU is 'X'        
        else {

            //Scenarios for when X is gonna complete a line
            // Rows 1-3
            if (gameArray[0][0] == 'X' && gameArray[0][1] == 'X' && gameArray[0][2] == ' ') {
                gameArray[0][2] = 'X';
                cpuChoicePrint(3);
            }
            else if (gameArray[0][0] == 'X' && gameArray[0][2] == 'X' && gameArray[0][1] == ' ') {
                gameArray[0][1] = 'X';
                cpuChoicePrint(2);
            }
            else if (gameArray[0][1] == 'X' && gameArray[0][2] == 'X' && gameArray[0][0] == ' ') {
                gameArray[0][0] = 'X';
                cpuChoicePrint(1);
            } //End of row 1
            else if (gameArray[1][0] == 'X' && gameArray[1][1] == 'X' && gameArray[1][2] == ' ') {
                gameArray[1][2] = 'X';
                cpuChoicePrint(6);
            }
            else if (gameArray[1][0] == 'X' && gameArray[1][2] == 'X' && gameArray[1][1] == ' ') {
                gameArray[1][1] = 'X';
                cpuChoicePrint(5);
            }
            else if (gameArray[1][1] == 'X' && gameArray[1][2] == 'X' && gameArray[1][0] == ' ') {
                gameArray[1][0] = 'X';
                cpuChoicePrint(4);
            } // End of row 2
            else if (gameArray[2][0] == 'X' && gameArray[2][1] == 'X' && gameArray[2][2] == ' ') {
                gameArray[2][2] = 'X';
                cpuChoicePrint(9);
            }
            else if (gameArray[2][0] == 'X' && gameArray[2][2] == 'X' && gameArray[2][1] == ' ') {
                gameArray[2][1] = 'X';
                cpuChoicePrint(8);
            }
            else if (gameArray[2][1] == 'X' && gameArray[2][2] == 'X' && gameArray[2][0] == ' ') {
                gameArray[2][0] = 'X';
                cpuChoicePrint(7);
            } // End of row 3

            //Columns 1-3
            else if (gameArray[0][0] == 'X' && gameArray[1][0] == 'X' && gameArray[2][0] == ' ') {
                gameArray[2][0] = 'X';
                cpuChoicePrint(7);
            }
            else if (gameArray[0][0] == 'X' && gameArray[2][0] == 'X' && gameArray[1][0] == ' ') {
                gameArray[1][0] = 'X';
                cpuChoicePrint(4);
            }
            else if (gameArray[1][0] == 'X' && gameArray[2][0] == 'X' && gameArray[0][0] == ' ') {
                gameArray[0][0] = 'X';
                cpuChoicePrint(1);
            } //End of column 1
            else if (gameArray[0][1] == 'X' && gameArray[1][1] == 'X' && gameArray[2][1] == ' ') {
                gameArray[2][1] = 'X';
                cpuChoicePrint(8);
            }
            else if (gameArray[0][1] == 'X' && gameArray[2][1] == 'X' && gameArray[1][1] == ' ') {
                gameArray[1][1] = 'X';
                cpuChoicePrint(5);
            }
            else if (gameArray[1][1] == 'X' && gameArray[2][1] == 'X' && gameArray[0][1] == ' ') {
                gameArray[0][1] = 'X';
                cpuChoicePrint(2);
            } //End of column 2
            else if (gameArray[0][2] == 'X' && gameArray[1][2] == 'X' && gameArray[2][2] == ' ') {
                gameArray[2][2] = 'X';
                cpuChoicePrint(9);
            }
            else if (gameArray[0][2] == 'X' && gameArray[2][2] == 'X' && gameArray[1][2] == ' ') {
                gameArray[1][2] = 'X';
                cpuChoicePrint(6);
            }
            else if (gameArray[1][2] == 'X' && gameArray[2][2] == 'X' && gameArray[0][2] == ' ') {
                gameArray[0][2] = 'X';
                cpuChoicePrint(3);
            } //End of column 3

            //Diagonals 1-2
            else if (gameArray[0][0] == 'X' && gameArray[1][1] == 'X' && gameArray[2][2] == ' ') {
                gameArray[2][2] = 'X';
                cpuChoicePrint(9);
            }
            else if (gameArray[0][0] == 'X' && gameArray[2][2] == 'X' && gameArray[1][1] == ' ') {
                gameArray[1][1] = 'X';
                cpuChoicePrint(5);
            }
            else if (gameArray[1][1] == 'X' && gameArray[2][2] == 'X' && gameArray[0][0] == ' ') {
                gameArray[0][0] = 'X';
                cpuChoicePrint(1);
            } //End of diagonal 1
            else if (gameArray[0][2] == 'X' && gameArray[1][1] == 'X' && gameArray[2][0] == ' ') {
                gameArray[2][0] = 'X';
                cpuChoicePrint(7);
            }
            else if (gameArray[0][2] == 'X' && gameArray[2][0] == 'X' && gameArray[1][1] == ' ') {
                gameArray[1][1] = 'X';
                cpuChoicePrint(5);
            }
            else if (gameArray[1][1] == 'X' && gameArray[2][0] == 'X' && gameArray[0][2] == ' ') {
                gameArray[0][2] = 'X';
                cpuChoicePrint(3);
            } //End of diagonal 2 (X's matching)

            //Scenarios for X countering 3rd O
            // Rows 1-3
            else if (gameArray[0][0] == 'O' && gameArray[0][1] == 'O' && gameArray[0][2] == ' ') {
                gameArray[0][2] = 'X';
                cpuChoicePrint(3);
            }
            else if (gameArray[0][0] == 'O' && gameArray[0][2] == 'O' && gameArray[0][1] == ' ') {
                gameArray[0][1] = 'X';
                cpuChoicePrint(2);
            }
            else if (gameArray[0][1] == 'O' && gameArray[0][2] == 'O' && gameArray[0][0] == ' ') {
                gameArray[0][0] = 'X';
                cpuChoicePrint(1);
            } //End of row 1
            else if (gameArray[1][0] == 'O' && gameArray[1][1] == 'O' && gameArray[1][2] == ' ') {
                gameArray[1][2] = 'X';
                cpuChoicePrint(6);
            }
            else if (gameArray[1][0] == 'O' && gameArray[1][2] == 'O' && gameArray[1][1] == ' ') {
                gameArray[1][1] = 'X';
                cpuChoicePrint(5);
            }
            else if (gameArray[1][1] == 'O' && gameArray[1][2] == 'O' && gameArray[1][0] == ' ') {
                gameArray[1][0] = 'X';
                cpuChoicePrint(4);
            } // End of row 2
            else if (gameArray[2][0] == 'O' && gameArray[2][1] == 'O' && gameArray[2][2] == ' ') {
                gameArray[2][2] = 'X';
                cpuChoicePrint(9);
            }
            else if (gameArray[2][0] == 'O' && gameArray[2][2] == 'O' && gameArray[2][1] == ' ') {
                gameArray[2][1] = 'X';
                cpuChoicePrint(8);
            }
            else if (gameArray[2][1] == 'O' && gameArray[2][2] == 'O' && gameArray[2][0] == ' ') {
                gameArray[2][0] = 'X';
                cpuChoicePrint(7);
            } // End of row 3

            //Columns 1-3
            else if (gameArray[0][0] == 'O' && gameArray[1][0] == 'O' && gameArray[2][0] == ' ') {
                gameArray[2][0] = 'X';
                cpuChoicePrint(7);
            }
            else if (gameArray[0][0] == 'O' && gameArray[2][0] == 'O' && gameArray[1][0] == ' ') {
                gameArray[1][0] = 'X';
                cpuChoicePrint(4);
            }
            else if (gameArray[1][0] == 'O' && gameArray[2][0] == 'O' && gameArray[0][0] == ' ') {
                gameArray[0][0] = 'X';
                cpuChoicePrint(1);
            } //End of column 1
            else if (gameArray[0][1] == 'O' && gameArray[1][1] == 'O' && gameArray[2][1] == ' ') {
                gameArray[2][1] = 'X';
                cpuChoicePrint(8);
            }
            else if (gameArray[0][1] == 'O' && gameArray[2][1] == 'O' && gameArray[1][1] == ' ') {
                gameArray[1][1] = 'X';
                cpuChoicePrint(5);
            }
            else if (gameArray[1][1] == 'O' && gameArray[2][1] == 'O' && gameArray[0][1] == ' ') {
                gameArray[0][1] = 'X';
                cpuChoicePrint(2);
            } //End of column 2
            else if (gameArray[0][2] == 'O' && gameArray[1][2] == 'O' && gameArray[2][2] == ' ') {
                gameArray[2][2] = 'X';
                cpuChoicePrint(9);
            }
            else if (gameArray[0][2] == 'O' && gameArray[2][2] == 'O' && gameArray[1][2] == ' ') {
                gameArray[1][2] = 'X';
                cpuChoicePrint(6);
            }
            else if (gameArray[1][2] == 'O' && gameArray[2][2] == 'O' && gameArray[0][2] == ' ') {
                gameArray[0][2] = 'X';
                cpuChoicePrint(3);
            } //End of column 3

            //Diagonals 1-2
            else if (gameArray[0][0] == 'O' && gameArray[1][1] == 'O' && gameArray[2][2] == ' ') {
                gameArray[2][2] = 'X';
                cpuChoicePrint(9);
            }
            else if (gameArray[0][0] == 'O' && gameArray[2][2] == 'O' && gameArray[1][1] == ' ') {
                gameArray[1][1] = 'X';
                cpuChoicePrint(5);
            }
            else if (gameArray[1][1] == 'O' && gameArray[2][2] == 'O' && gameArray[0][0] == ' ') {
                gameArray[0][0] = 'X';
                cpuChoicePrint(1);
            } //End of diagonal 1
            else if (gameArray[0][2] == 'O' && gameArray[1][1] == 'O' && gameArray[2][0] == ' ') {
                gameArray[2][0] = 'X';
                cpuChoicePrint(7);
            }
            else if (gameArray[0][2] == 'O' && gameArray[2][0] == 'O' && gameArray[1][1] == ' ') {
                gameArray[1][1] = 'X';
                cpuChoicePrint(5);
            }
            else if (gameArray[1][1] == 'O' && gameArray[2][0] == 'O' && gameArray[0][2] == ' ') {
                gameArray[0][2] = 'X';
                cpuChoicePrint(3);
            } //End of diagonal 2

            //3rd turn placing x diagonally if O is in a corner and X in middle
            else if (gameArray[0][0] == 'O' && gameArray[1][1] == 'X' && gameArray[2][2] == ' ') {
                gameArray[2][2] = 'X';
                cpuChoicePrint(9);
            }
            else if (gameArray[0][2] == 'O' && gameArray[1][1] == 'X' && gameArray[2][0] == ' ') {
                gameArray[2][0] = 'X';
                cpuChoicePrint(7);
            }
            else if (gameArray[2][0] == 'O' && gameArray[1][1] == 'X' && gameArray[0][2] == ' ') {
                gameArray[0][2] = 'X';
                cpuChoicePrint(3);
            }
            else if (gameArray[2][0] == 'O' && gameArray[1][1] == 'X' && gameArray[0][0] == ' ') {
                gameArray[0][0] = 'X';
                cpuChoicePrint(1);
            }

            //3rd turn placing X in a corner if X starts in square 1
            else if (gameArray[0][0] == 'X' && gameArray[1][0] == 'O' && gameArray[0][2] == ' ') {
                gameArray[0][2] = 'X';
                cpuChoicePrint(3);
            }
            else if (gameArray[0][0] == 'X' && gameArray[2][1] == 'O' && gameArray[0][2] == ' ') {
                gameArray[0][2] = 'X';
                cpuChoicePrint(3);
            }
            else if (gameArray[0][0] == 'X' && gameArray[1][2] == 'O' && gameArray[2][0] == ' ') {
                gameArray[2][0] = 'X';
                cpuChoicePrint(7);
            }
            else if (gameArray[0][0] == 'X' && gameArray[0][1] == 'O' && gameArray[2][0] == ' ') {
                gameArray[2][0] = 'X';
                cpuChoicePrint(7);
            }
            else if (gameArray[0][0] == 'X' && gameArray[2][0] == 'O' && gameArray[0][2] == ' ') {
            gameArray[0][2] = 'X';
            cpuChoicePrint(3);
            }
            else if (gameArray[0][0] == 'X' && gameArray[2][2] == 'O' && gameArray[2][0] == ' ') {
            gameArray[2][0] = 'X';
            cpuChoicePrint(7);
            }
            else if (gameArray[0][0] == 'X' && gameArray[0][2] == 'O' && gameArray[2][0] == ' ') {
            gameArray[2][0] = 'X';
            cpuChoicePrint(7);
            }

            //3rd turn placing X in a corner if X starts in square 3
            else if (gameArray[0][2] == 'X' && gameArray[0][1] == 'O' && gameArray[2][2] == ' ') {
            gameArray[2][2] = 'X';
            cpuChoicePrint(9);
            }
            else if (gameArray[0][2] == 'X' && gameArray[1][0] == 'O' && gameArray[2][2] == ' ') {
            gameArray[2][2] = 'X';
            cpuChoicePrint(9);
            }
            else if (gameArray[0][2] == 'X' && gameArray[2][1] == 'O' && gameArray[2][2] == ' ') {
            gameArray[2][2] = 'X';
            cpuChoicePrint(9);
            }
            else if (gameArray[0][2] == 'X' && gameArray[1][2] == 'O' && gameArray[0][0] == ' ') {
            gameArray[0][0] = 'X';
            cpuChoicePrint(1);
            }
            else if (gameArray[0][2] == 'X' && gameArray[0][0] == 'O' && gameArray[2][2] == ' ') {
            gameArray[2][2] = 'X';
            cpuChoicePrint(9);
            }
            else if (gameArray[0][2] == 'X' && gameArray[2][0] == 'O' && gameArray[0][0] == ' ') {
            gameArray[0][0] = 'X';
            cpuChoicePrint(1);
            }
            else if (gameArray[0][2] == 'X' && gameArray[2][2] == 'O' && gameArray[0][0] == ' ') {
            gameArray[0][0] = 'X';
            cpuChoicePrint(1);
            }

            //3rd turn placing X in a corner if X starts in square 7
            else if (gameArray[2][0] == 'X' && gameArray[1][0] == 'O' && gameArray[2][2] == ' ') {
                gameArray[2][2] = 'X';
                cpuChoicePrint(9);
            }
            else if (gameArray[2][0] == 'X' && gameArray[2][1] == 'O' && gameArray[0][0] == ' ') {
                gameArray[0][0] = 'X';
                cpuChoicePrint(1);
            }
            else if (gameArray[2][0] == 'X' && gameArray[1][2] == 'O' && gameArray[0][0] == ' ') {
                gameArray[0][0] = 'X';
                cpuChoicePrint(1);
            }
            else if (gameArray[2][0] == 'X' && gameArray[0][1] == 'O' && gameArray[0][0] == ' ') {
                gameArray[0][0] = 'X';
                cpuChoicePrint(1);
            }
            else if (gameArray[2][0] == 'X' && gameArray[0][0] == 'O' && gameArray[0][2] == ' ') {
            gameArray[0][2] = 'X';
            cpuChoicePrint(3);
            }
            else if (gameArray[2][0] == 'X' && gameArray[0][2] == 'O' && gameArray[0][0] == ' ') {
            gameArray[0][0] = 'X';
            cpuChoicePrint(1);
            }
            else if (gameArray[2][0] == 'X' && gameArray[2][2] == 'O' && gameArray[0][0] == ' ') {
            gameArray[0][0] = 'X';
            cpuChoicePrint(1);
            }

            //3rd turn placing X in a corner if X starts in square 9
            else if (gameArray[2][2] == 'X' && gameArray[1][0] == 'O' && gameArray[2][0] == ' ') {
                gameArray[2][0] = 'X';
                cpuChoicePrint(7);
            }
            else if (gameArray[2][2] == 'X' && gameArray[2][1] == 'O' && gameArray[0][2] == ' ') {
                gameArray[0][2] = 'X';
                cpuChoicePrint(3);
            }
            else if (gameArray[2][2] == 'X' && gameArray[1][2] == 'O' && gameArray[2][0] == ' ') {
                gameArray[2][0] = 'X';
                cpuChoicePrint(7);
            }
            else if (gameArray[2][2] == 'X' && gameArray[0][1] == 'O' && gameArray[2][0] == ' ') {
                gameArray[2][0] = 'X';
                cpuChoicePrint(7);
            }
            else if (gameArray[2][2] == 'X' && gameArray[2][0] == 'O' && gameArray[0][2] == ' ') {
            gameArray[0][2] = 'X';
            cpuChoicePrint(3);
            }
            else if (gameArray[2][2] == 'X' && gameArray[0][0] == 'O' && gameArray[2][0] == ' ') {
            gameArray[2][0] = 'X';
            cpuChoicePrint(7);
            }
            else if (gameArray[2][2] == 'X' && gameArray[0][2] == 'O' && gameArray[2][0] == ' ') {
            gameArray[2][0] = 'X';
            cpuChoicePrint(7);
            }
            
            //5th Turn placing X to win a fork
            else if (gameArray[0][0] == 'X' && gameArray[0][1] == 'O' && gameArray[2][0] == 'X' && gameArray[1][0] == 'O' && gameArray[1][1] == ' ') {
                gameArray[1][1] = 'X';
                cpuChoicePrint(5);
            }
            else if (gameArray[0][0] == 'X' && gameArray[1][0] == 'O' && gameArray[2][0] == 'X' && gameArray[2][1] == 'O' && gameArray[1][1] == ' ') {
                gameArray[1][1] = 'X';
                cpuChoicePrint(5);
            }
            else if (gameArray[0][0] == 'X' && gameArray[1][0] == 'O' && gameArray[2][0] == 'X' && gameArray[1][2] == 'O' && gameArray[1][1] == ' ') {
                gameArray[1][1] = 'X';
                cpuChoicePrint(5);
            }
            else if (gameArray[0][2] == 'X' && gameArray[0][1] == 'O' && gameArray[2][2] == 'X' && gameArray[1][2] == 'O' && gameArray[1][1] == ' ') {
                gameArray[1][1] = 'X';
                cpuChoicePrint(5);
            }
            else if (gameArray[0][2] == 'X' && gameArray[1][0] == 'O' && gameArray[2][2] == 'X' && gameArray[1][2] == 'O' && gameArray[1][1] == ' ') {
            gameArray[1][1] = 'X';
            cpuChoicePrint(5);
            }
            else if (gameArray[0][2] == 'X' && gameArray[2][1] == 'O' && gameArray[2][2] == 'X' && gameArray[1][2] == 'O' && gameArray[1][1] == ' ') {
                gameArray[1][1] = 'X';
                cpuChoicePrint(5);
            }
            else if (gameArray[0][0] == 'X' && gameArray[0][1] == 'O' && gameArray[0][2] == 'X' && gameArray[1][0] == 'O' && gameArray[1][1] == ' ') {
                gameArray[1][1] = 'X';
                cpuChoicePrint(5);
            }
            else if (gameArray[0][0] == 'X' && gameArray[0][1] == 'O' && gameArray[0][2] == 'X' && gameArray[2][1] == 'O' && gameArray[1][1] == ' ') {
                gameArray[1][1] = 'X';
                cpuChoicePrint(5);
            }
            else if (gameArray[0][0] == 'X' && gameArray[0][1] == 'O' && gameArray[0][2] == 'X' && gameArray[1][2] == 'O' && gameArray[1][1] == ' ') {
                gameArray[1][1] = 'X';
                cpuChoicePrint(5);
            }
            else if (gameArray[2][0] == 'X' && gameArray[2][1] == 'O' && gameArray[2][2] == 'X' && gameArray[1][0] == 'O' && gameArray[1][1] == ' ') {
                gameArray[1][1] = 'X';
                cpuChoicePrint(5);
            }
            else if (gameArray[2][0] == 'X' && gameArray[2][1] == 'O' && gameArray[2][2] == 'X' && gameArray[0][1] == 'O' && gameArray[1][1] == ' ') {
                gameArray[1][1] = 'X';
                cpuChoicePrint(5);
            }
            else if (gameArray[2][0] == 'X' && gameArray[2][1] == 'O' && gameArray[2][2] == 'X' && gameArray[1][2] == 'O' && gameArray[1][1] == ' ') {
                gameArray[1][1] = 'X';
                cpuChoicePrint(5);
            }
                       
            //If all other scenarios
            else {
                if (gameArray[1][1] == ' ') {
                    gameArray[1][1] = 'X';
                    cpuChoicePrint(5);
                }
                else if (gameArray[0][0] == ' ') {
                    gameArray[0][0] = 'X';
                    cpuChoicePrint(1);
                }
                else if (gameArray[0][2] == ' ') {
                    gameArray[0][2] = 'X';
                    cpuChoicePrint(3);
                }
                else if (gameArray[2][0] == ' ') {
                    gameArray[2][0] = 'X';
                    cpuChoicePrint(7);
                }
                else if (gameArray[2][2] == ' ') {
                    gameArray[2][2] = 'X';
                    cpuChoicePrint(9);
                }
                else if (gameArray[0][1] == ' ') {
                    gameArray[0][1] = 'X';
                    cpuChoicePrint(2);
                }
                else if (gameArray[1][0] == ' ') {
                    gameArray[1][0] = 'X';
                    cpuChoicePrint(4);
                }
                else if (gameArray[2][1] == ' ') {
                    gameArray[2][1] = 'X';
                    cpuChoicePrint(8);
                }
                else {
                    gameArray[1][2] = 'X';
                    cpuChoicePrint(6);
                }  //End of all other scenarios for CPU being X
                
            }
        }
    }
    
    displayUpdatedBoard(); //Display updated game grid board
    checkIfWin(playerOneSymbol, cpuSymbol, multiFlag); //Check if win occured       
    playerOneMove(playerOneSymbol, cpuSymbol, multiFlag); //Player One goes next
}

bool checkTaken(int choice)
{
    bool status = false;

    switch (choice) {
        case 1:
            if (gameArray[0][0] != ' ')
                status = true;
            break;
        case 2:
            if (gameArray[0][1] != ' ')
                status = true;
            break;
        case 3:
            if (gameArray[0][2] != ' ')
                status = true;
            break;
        case 4:
            if (gameArray[1][0] != ' ')
                status = true;
            break;
        case 5:
            if (gameArray[1][1] != ' ')
                status = true;
            break;
        case 6:
            if (gameArray[1][2] != ' ')
                status = true;
            break;
        case 7:
            if (gameArray[2][0] != ' ')
                status = true;
            break;
        case 8:
            if (gameArray[2][1] != ' ')
                status = true;
            break;
        default:
            if (gameArray[2][2] != ' ')
                status = true;
            break;
    }

    return status;
}

//Function to place player selection on board
void placePlayerSelection(int playerChoice, char playerSymbol)
{
    switch (playerChoice)
    {
    case 1:
        if (playerSymbol == 'X')
        {
            gameArray[0][0] = 'X';
            break;
        }
        else
        {
            gameArray[0][0] = 'O';
            break;
        }
    case 2:
        if (playerSymbol == 'X')
        {
            gameArray[0][1] = 'X';
            break;
        }
        else
        {
            gameArray[0][1] = 'O';
            break;
        }
    case 3:
        if (playerSymbol == 'X')
        {
            gameArray[0][2] = 'X';
            break;
        }
        else
        {
            gameArray[0][2] = 'O';
            break;
        }
    case 4:
        if (playerSymbol == 'X')
        {
            gameArray[1][0] = 'X';
            break;
        }
        else
        {
            gameArray[1][0] = 'O';
            break;
        }
    case 5:
        if (playerSymbol == 'X')
        {
            gameArray[1][1] = 'X';
            break;
        }
        else
        {
            gameArray[1][1] = 'O';
            break;
        }
    case 6:
        if (playerSymbol == 'X')
        {
            gameArray[1][2] = 'X';
            break;
        }
        else
        {
            gameArray[1][2] = 'O';
            break;
        }
    case 7:
        if (playerSymbol == 'X')
        {
            gameArray[2][0] = 'X';
            break;
        }
        else
        {
            gameArray[2][0] = 'O';
            break;
        }
    case 8:
        if (playerSymbol == 'X')
        {
            gameArray[2][1] = 'X';
            break;
        }
        else
        {
            gameArray[2][1] = 'O';
            break;
        }
    default:
        if (playerSymbol == 'X')
        {
            gameArray[2][2] = 'X';
            break;
        }
        else
        {
            gameArray[2][2] = 'O';
            break;
        }
    }
}

//Function to output the square number chosen by the CPU
void cpuChoicePrint(int cpuChoice)
{
    cout << endl << "Computer chose square " << cpuChoice << "." << endl; 
}

//Function to display updated game grid boards
void displayUpdatedBoard()
{
    cout << endl;
    cout << "Current board: " << endl;
    cout << "     :     :     " << endl;
    cout << "  " << gameArray[0][0] << "  :  " << gameArray[0][1] << "  :  " << gameArray[0][2] << endl;
    cout << "_____:_____:_____" << endl;
    cout << "     :     :     " << endl;
    cout << "  " << gameArray[1][0] << "  :  " << gameArray[1][1] << "  :  " << gameArray[1][2] << endl;
    cout << "_____:_____:_____" << endl;
    cout << "     :     :     " << endl;
    cout << "  " << gameArray[2][0] << "  :  " << gameArray[2][1] << "  :  " << gameArray[2][2] << endl;
    cout << "     :     :     " << endl;
    cout << endl;    
}

//Function to check and declare a win/loss condition
void checkIfWin(char playerOneSymbol, char otherSymbol, bool multiFlag)
{
    bool playerOneWins = false;
    bool playerTwoWins = false;
    bool cpuWins = false;
    bool isFilled = false;
    bool tie = false;
    string winType = " ";

    if (playerOneSymbol == 'X')
    {
        if (gameArray[0][0] == 'X')
            if (gameArray[0][1] == 'X' && gameArray[0][2] == 'X') {
                playerOneWins = true;
                winType = "TR";
                displayWinningBoard(gameArray, winType);
            }
            else if (gameArray[1][0] == 'X' && gameArray[2][0] == 'X'){
                playerOneWins = true;
                winType = "LC";
                displayWinningBoard(gameArray, winType);
            }
            else if (gameArray[1][1] == 'X' && gameArray[2][2] == 'X'){
                playerOneWins = true;
                winType = "LD";
                displayWinningBoard(gameArray, winType);
            }
        if (gameArray[1][0] == 'X')
            if (gameArray[1][1] == 'X' && gameArray[1][2] == 'X'){
                playerOneWins = true;
                winType = "MR";
                displayWinningBoard(gameArray, winType);
            }
        if (gameArray[2][0] == 'X')
            if (gameArray[2][1] == 'X' && gameArray[2][2] == 'X'){
                playerOneWins = true;
                winType = "BR";
                displayWinningBoard(gameArray, winType);
            }
            else if (gameArray[1][1] == 'X' && gameArray[0][2] == 'X'){
                playerOneWins = true;
                winType = "RD";
                displayWinningBoard(gameArray, winType);
            }
        if (gameArray[0][1] == 'X')
            if (gameArray[1][1] == 'X' && gameArray[2][1] == 'X'){
                playerOneWins = true;
                winType = "MC";
                displayWinningBoard(gameArray, winType);
            }
        if (gameArray[0][2] == 'X')
            if (gameArray[1][2] == 'X' && gameArray[2][2] == 'X'){
                playerOneWins = true;
                winType = "RC";
                displayWinningBoard(gameArray, winType);
            }
    }

    else if (playerOneSymbol == 'O')
    {
        if (gameArray[0][0] == 'O')
            if (gameArray[0][1] == 'O' && gameArray[0][2] == 'O') {
                playerOneWins = true;
                winType = "TR";
                displayWinningBoard(gameArray, winType);
            }
            else if (gameArray[1][0] == 'O' && gameArray[2][0] == 'O'){
                playerOneWins = true;
                winType = "LC";
                displayWinningBoard(gameArray, winType);
            }
            else if (gameArray[1][1] == 'O' && gameArray[2][2] == 'O'){
                playerOneWins = true;
                winType = "LD";
                displayWinningBoard(gameArray, winType);
            }
        if (gameArray[1][0] == 'O')
            if (gameArray[1][1] == 'O' && gameArray[1][2] == 'O'){
                playerOneWins = true;
                winType = "MR";
                displayWinningBoard(gameArray, winType);
            }
        if (gameArray[2][0] == 'O')
            if (gameArray[2][1] == 'O' && gameArray[2][2] == 'O'){
                playerOneWins = true;
                winType = "BR";
                displayWinningBoard(gameArray, winType);
            }
            else if (gameArray[1][1] == 'O' && gameArray[0][2] == 'O'){
                playerOneWins = true;
                winType = "RD";
                displayWinningBoard(gameArray, winType);
            }
        if (gameArray[0][1] == 'O')
            if (gameArray[1][1] == 'O' && gameArray[2][1] == 'O'){
                playerOneWins = true;
                winType = "MC";
                displayWinningBoard(gameArray, winType);
            }
        if (gameArray[0][2] == 'O')
            if (gameArray[1][2] == 'O' && gameArray[2][2] == 'O'){
                playerOneWins = true;
                winType = "RC";
                displayWinningBoard(gameArray, winType);
            }
    }


    if (multiFlag == true) {

        if (otherSymbol == 'X')
        {
            if (gameArray[0][0] == 'X')
                if (gameArray[0][1] == 'X' && gameArray[0][2] == 'X') {
                    playerTwoWins = true;
                    winType = "TR";
                    displayWinningBoard(gameArray, winType);
                }
                else if (gameArray[1][0] == 'X' && gameArray[2][0] == 'X') {
                    playerTwoWins = true;
                    winType = "LC";
                    displayWinningBoard(gameArray, winType);
                }
                else if (gameArray[1][1] == 'X' && gameArray[2][2] == 'X') {
                    playerTwoWins = true;
                    winType = "LD";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[1][0] == 'X')
                if (gameArray[1][1] == 'X' && gameArray[1][2] == 'X') {
                    playerTwoWins = true;
                    winType = "MR";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[2][0] == 'X')
                if (gameArray[2][1] == 'X' && gameArray[2][2] == 'X') {
                    playerTwoWins = true;
                    winType = "BR";
                    displayWinningBoard(gameArray, winType);
                }
                else if (gameArray[1][1] == 'X' && gameArray[0][2] == 'X') {
                    playerTwoWins = true;
                    winType = "RD";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[0][1] == 'X')
                if (gameArray[1][1] == 'X' && gameArray[2][1] == 'X') {
                    playerTwoWins = true;
                    winType = "MC";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[0][2] == 'X')
                if (gameArray[1][2] == 'X' && gameArray[2][2] == 'X') {
                    playerTwoWins = true;
                    winType = "RC";
                    displayWinningBoard(gameArray, winType);
                }
        }

        else if (otherSymbol == 'O')
        {
            if (gameArray[0][0] == 'O')
                if (gameArray[0][1] == 'O' && gameArray[0][2] == 'O') {
                    playerTwoWins = true;
                    winType = "TR";
                    displayWinningBoard(gameArray, winType);
                }
                else if (gameArray[1][0] == 'O' && gameArray[2][0] == 'O') {
                    playerTwoWins = true;
                    winType = "LC";
                    displayWinningBoard(gameArray, winType);
                }
                else if (gameArray[1][1] == 'O' && gameArray[2][2] == 'O') {
                    playerTwoWins = true;
                    winType = "LD";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[1][0] == 'O')
                if (gameArray[1][1] == 'O' && gameArray[1][2] == 'O') {
                    playerTwoWins = true;
                    winType = "MR";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[2][0] == 'O')
                if (gameArray[2][1] == 'O' && gameArray[2][2] == 'O') {
                    playerTwoWins = true;
                    winType = "BR";
                    displayWinningBoard(gameArray, winType);
                }
                else if (gameArray[1][1] == 'O' && gameArray[0][2] == 'O') {
                    playerTwoWins = true;
                    winType = "RD";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[0][1] == 'O')
                if (gameArray[1][1] == 'O' && gameArray[2][1] == 'O') {
                    playerTwoWins = true;
                    winType = "MC";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[0][2] == 'O')
                if (gameArray[1][2] == 'O' && gameArray[2][2] == 'O') {
                    playerTwoWins = true;
                    winType = "RC";
                    displayWinningBoard(gameArray, winType);
                }
        }
    }
    else {
        if (otherSymbol == 'X')
        {
            if (gameArray[0][0] == 'X')
                if (gameArray[0][1] == 'X' && gameArray[0][2] == 'X') {
                    cpuWins = true;
                    winType = "TR";
                    displayWinningBoard(gameArray, winType);
                }
                else if (gameArray[1][0] == 'X' && gameArray[2][0] == 'X') {
                    cpuWins = true;
                    winType = "LC";
                    displayWinningBoard(gameArray, winType);
                }
                else if (gameArray[1][1] == 'X' && gameArray[2][2] == 'X') {
                    cpuWins = true;
                    winType = "LD";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[1][0] == 'X')
                if (gameArray[1][1] == 'X' && gameArray[1][2] == 'X') {
                    cpuWins = true;
                    winType = "MR";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[2][0] == 'X')
                if (gameArray[2][1] == 'X' && gameArray[2][2] == 'X') {
                    cpuWins = true;
                    winType = "BR";
                    displayWinningBoard(gameArray, winType);
                }
                else if (gameArray[1][1] == 'X' && gameArray[0][2] == 'X') {
                    cpuWins = true;
                    winType = "RD";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[0][1] == 'X')
                if (gameArray[1][1] == 'X' && gameArray[2][1] == 'X') {
                    cpuWins = true;
                    winType = "MC";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[0][2] == 'X')
                if (gameArray[1][2] == 'X' && gameArray[2][2] == 'X') {
                    cpuWins = true;
                    winType = "RC";
                    displayWinningBoard(gameArray, winType);
                }
        }

        else if (otherSymbol == 'O')
        {
            if (gameArray[0][0] == 'O')
                if (gameArray[0][1] == 'O' && gameArray[0][2] == 'O') {
                    cpuWins = true;
                    winType = "TR";
                    displayWinningBoard(gameArray, winType);
                }
                else if (gameArray[1][0] == 'O' && gameArray[2][0] == 'O') {
                    cpuWins = true;
                    winType = "LC";
                    displayWinningBoard(gameArray, winType);
                }
                else if (gameArray[1][1] == 'O' && gameArray[2][2] == 'O') {
                    cpuWins = true;
                    winType = "LD";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[1][0] == 'O')
                if (gameArray[1][1] == 'O' && gameArray[1][2] == 'O') {
                    cpuWins = true;
                    winType = "MR";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[2][0] == 'O')
                if (gameArray[2][1] == 'O' && gameArray[2][2] == 'O') {
                    cpuWins = true;
                    winType = "BR";
                    displayWinningBoard(gameArray, winType);
                }
                else if (gameArray[1][1] == 'O' && gameArray[0][2] == 'O') {
                    cpuWins = true;
                    winType = "RD";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[0][1] == 'O')
                if (gameArray[1][1] == 'O' && gameArray[2][1] == 'O') {
                    cpuWins = true;
                    winType = "MC";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[0][2] == 'O')
                if (gameArray[1][2] == 'O' && gameArray[2][2] == 'O') {
                    cpuWins = true;
                    winType = "RC";
                    displayWinningBoard(gameArray, winType);
                }
        }
    }

    //Check for tie
    for (int x = 0; x < ROW; x++) {
        for (int y = 0; y < COLUMN; y++) {
            if (gameArray[x][y] == ' ') {
                isFilled = false;
                tie = false;
                break;
            }
            else {
                isFilled = true;
                tie = true;
            }
        }
        if (isFilled == false && tie == false)
            break;
    }          
            
    //if player one wins
    if (playerOneWins == true)
    {
        cout << "==========================" << endl;
        cout << "Player One Wins!" << endl;
        cout << "==========================" << endl << endl;        
        cout << "Returning to main menu." << endl;
        Sleep(400);
        displayWelcome();
        displayMenu();
    }

    //If player two wins
    else if (playerTwoWins == true)
    {
        cout << "==========================" << endl;
        cout << "Player Two Wins!" << endl;
        cout << "==========================" << endl << endl;
        cout << "Returning to main menu." << endl << endl;
        Sleep(400);
        displayWelcome();
        displayMenu();
    }

    //If cpu wins
    else if (cpuWins == true)
    {
        cout << "==========================" << endl;
        cout << "CPU Wins!" << endl;
        cout << "==========================" << endl << endl;
        cout << "Returning to main menu." << endl << endl;
        Sleep(400);
        displayWelcome();
        displayMenu();
    }

    //If it's a tie
    else if (isFilled == true && tie == true)
    {
        cout << "==========================" << endl;
        cout << "Tie game!" << endl;
        cout << "==========================" << endl;
        cout << "Returning to main menu." << endl << endl;
        Sleep(400);
        displayWelcome();
        displayMenu();
    }
}

void displayWinningBoard(const char gameArray[ROW][COLUMN], string winType)
{
    if (winType == "TR") {
        cout << endl;
        cout << "Current board: " << endl;
        cout << "     |     |     " << endl;
        cout << "--" << gameArray[0][0] << "--|--" << gameArray[0][1] << "--|--" << gameArray[0][2] << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  " << gameArray[1][0] << "  |  " << gameArray[1][1] << "  |  " << gameArray[1][2] << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  " << gameArray[2][0] << "  |  " << gameArray[2][1] << "  |  " << gameArray[2][2] << endl;
        cout << "     |     |     " << endl;
        cout << endl;
    }

    else if (winType == "LC") {
        cout << endl;
        cout << "Current board: " << endl;
        cout << "  |  |     |     " << endl;
        cout << "  " << gameArray[0][0] << "  |  " << gameArray[0][1] << "  |  " << gameArray[0][2] << endl;
        cout << "__|__|_____|_____" << endl;
        cout << "  |  |     |     " << endl;
        cout << "  " << gameArray[1][0] << "  |  " << gameArray[1][1] << "  |  " << gameArray[1][2] << endl;
        cout << "__|__|_____|_____" << endl;
        cout << "  |  |     |     " << endl;
        cout << "  " << gameArray[2][0] << "  |  " << gameArray[2][1] << "  |  " << gameArray[2][2] << endl;
        cout << "  |  |     |     " << endl;
        cout << endl;
    }
    else if (winType == "LD") {
        cout << endl;
        cout << "Current board| " << endl;
        cout << "  \  |     |     " << endl;
        cout << "  " << gameArray[0][0] << "  |  " << gameArray[0][1] << "  |  " << gameArray[0][2] << endl;
        cout << "____\|_____|_____" << endl;
        cout << "     |\     |     " << endl;
        cout << "  " << gameArray[1][0] << "  |  " << gameArray[1][1] << "  |  " << gameArray[1][2] << endl;
        cout << "_____|___\_|_____" << endl;
        cout << "     |     |\    " << endl;
        cout << "  " << gameArray[2][0] << "  |  " << gameArray[2][1] << "  |  " << gameArray[2][2] << endl;
        cout << "     |     |   \ " << endl;
        cout << endl;
    }

    else if (winType == "MR") {
        cout << endl;
        cout << "Current board| " << endl;
        cout << "     |     |     " << endl;
        cout << "  " << gameArray[0][0] << "  |  " << gameArray[0][1] << "  |  " << gameArray[0][2] << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "--" << gameArray[1][0] << "--|--" << gameArray[1][1] << "--|--" << gameArray[1][2] << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  " << gameArray[2][0] << "  |  " << gameArray[2][1] << "  |  " << gameArray[2][2] << endl;
        cout << "     |     |     " << endl;
        cout << endl;
    }

    else if (winType == "BR") {
        cout << endl;
        cout << "Current board| " << endl;
        cout << "     |     |     " << endl;
        cout << "  " << gameArray[0][0] << "  |  " << gameArray[0][1] << "  |  " << gameArray[0][2] << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  " << gameArray[1][0] << "  |  " << gameArray[1][1] << "  |  " << gameArray[1][2] << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "--" << gameArray[2][0] << "--|--" << gameArray[2][1] << "--|--" << gameArray[2][2] << endl;
        cout << "     |     |     " << endl;
        cout << endl;
    }
    
    else if (winType == "RD") {
        cout << endl;
        cout << "Current board| " << endl;
        cout << "     |     |  /  " << endl;
        cout << "  " << gameArray[0][0] << "  |  " << gameArray[0][1] << "  |  " << gameArray[0][2] << endl;
        cout << "_____|_____|/____" << endl;
        cout << "     |    /|     " << endl;
        cout << "  " << gameArray[1][0] << "  |  " << gameArray[1][1] << "  |  " << gameArray[1][2] << endl;
        cout << "_____|/____|_____" << endl;
        cout << "    /|     |     " << endl;
        cout << "  " << gameArray[2][0] << "  |  " << gameArray[2][1] << "  |  " << gameArray[2][2] << endl;
        cout << "  /  |     |     " << endl;
        cout << endl;
    }

    else if (winType == "MC") {
        cout << endl;
        cout << "Current board| " << endl;
        cout << "     |  |  |     " << endl;
        cout << "  " << gameArray[0][0] << "  |  " << gameArray[0][1] << "  |  " << gameArray[0][2] << endl;
        cout << "_____|__|__|_____" << endl;
        cout << "     |  |  |     " << endl;
        cout << "  " << gameArray[1][0] << "  |  " << gameArray[1][1] << "  |  " << gameArray[1][2] << endl;
        cout << "_____|__|__|_____" << endl;
        cout << "     |  |  |     " << endl;
        cout << "  " << gameArray[2][0] << "  |  " << gameArray[2][1] << "  |  " << gameArray[2][2] << endl;
        cout << "     |  |  |     " << endl;
        cout << endl;
    }

    else if (winType == "RC") {
        cout << endl;
        cout << "Current board| " << endl;
        cout << "     |     |  |  " << endl;
        cout << "  " << gameArray[0][0] << "  |  " << gameArray[0][1] << "  |  " << gameArray[0][2] << endl;
        cout << "_____|_____|__|__" << endl;
        cout << "     |     |  |  " << endl;
        cout << "  " << gameArray[1][0] << "  |  " << gameArray[1][1] << "  |  " << gameArray[1][2] << endl;
        cout << "_____|_____|__|__" << endl;
        cout << "     |     |  |  " << endl;
        cout << "  " << gameArray[2][0] << "  |  " << gameArray[2][1] << "  |  " << gameArray[2][2] << endl;
        cout << "     |     |  |  " << endl;
        cout << endl;
    }
}