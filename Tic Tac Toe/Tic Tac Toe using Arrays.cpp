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
void displayStartGrid();
void playerOneMove(char, char);
bool checkTaken(int);
void cpuMove(char, char);
int diceRoll();
void placePlayerOneSelection(int, char);
void checkIfWin(char, char);
void displayUpdatedBoard(char, char);
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

        cout << "Available Game Mode. " << endl;
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
        playerOneMove(playerOneSymbol, cpuSymbol); //Player one makes first move
    else
        cpuMove(cpuSymbol, playerOneSymbol); //CPU makes first move
        
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
void playerOneMove(char playerOneSymbol, char cpuSymbol)
{
    int PlayerOneChoice = { 0 };
    bool taken = false;
    
    do {

        cout << "Player One, please make a selection (1-9): ";
        cin.ignore();
        cin >> PlayerOneChoice;


        if (!isdigit(PlayerOneChoice) && (PlayerOneChoice < 1 || PlayerOneChoice > 9))
        {
            cout << "Invalid choice. Please try again!" << endl;   
            cin.clear();
            cin.ignore();
         
        }

        cout << endl;
        taken = checkTaken(PlayerOneChoice);

    } while ((PlayerOneChoice != 1 && PlayerOneChoice != 2 && PlayerOneChoice != 3 &&
              PlayerOneChoice != 4 && PlayerOneChoice != 5 && PlayerOneChoice != 6 &&
              PlayerOneChoice != 7 && PlayerOneChoice != 8 && PlayerOneChoice != 9) && taken==true);

    placePlayerOneSelection(PlayerOneChoice, playerOneSymbol); //Place player's one selection on board
    checkIfWin(playerOneSymbol, cpuSymbol); //Check if win occured
    displayUpdatedBoard(playerOneSymbol, cpuSymbol); //Display updated game grid board 
    cpuMove(cpuSymbol, playerOneSymbol); //CPU goes next

}

//Function to make cpu move
void cpuMove(char cpuSymbol, char playerOneSymbol)
{
    int randomNum = { 0 };
    int cpuX = { 0 };
    int cpuY = { 0 }; 

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
    if (cpuSymbol == 'X')

        // If board is empty and CPU goes first
        if (gameArray[0][0] == ' ' && gameArray[0][1] == ' ' && gameArray[0][2] == ' ' && gameArray[1][0] == ' '
            && gameArray[1][1] == ' ' && gameArray[1][2] == ' ' && gameArray[2][0] == ' ' && gameArray[2][1] == ' '
            && gameArray[2][2] == ' ')
        {
            do {
                srand(time(NULL));
                randomNum = 1 + rand() % 9;
            } while (randomNum % 2 == 0); //Repeat if random number is even. We want an odd number

            if (randomNum == 1){
                gameArray[0][0] = 'X';
                cpuChoicePrint(1);
            }
            else if (randomNum == 3){
                gameArray[0][2] = 'X';
                cpuChoicePrint(3);
            }
            else if (randomNum == 5) {
                gameArray[1][1] = 'X';
                cpuChoicePrint(5);
            }
            else if (randomNum == 7){
                gameArray[2][0] = 'X';
                cpuChoicePrint(7);
            }
            else if (randomNum == 9){
                gameArray[2][2] = 'X';
                cpuChoicePrint(9);
            }
        }
        
        //If board is not empty and CPU is 'X'

        // Rows 1-3
        else if (gameArray[0][0] == 'O' && gameArray[0][1] == 'O' && gameArray[0][2] == ' '){
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




    checkIfWin(playerOneSymbol, cpuSymbol); //Check if win occured
    displayUpdatedBoard(playerOneSymbol, cpuSymbol); //Display updated game grid board   
    playerOneMove(playerOneSymbol, cpuSymbol); //Player One goes next
}

bool checkTaken(int choice)
{
    bool status = false;

    for (int x = 0; x < ROW; x++) {
        for (int y = 0; y < COLUMN; y++) {
            if (gameArray[x][y] != ' ')
                status = false;
            else
                status = true;
        }
    }
        
    return status;
}

//Function to place selection on board for player one
void placePlayerOneSelection(int PlayerOneChoice, char playerOneSymbol)
{
    switch (PlayerOneChoice)
    {
    case 1:
        if (playerOneSymbol == 'X')
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
        if (playerOneSymbol == 'X')
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
        if (playerOneSymbol == 'X')
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
        if (playerOneSymbol == 'X')
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
        if (playerOneSymbol == 'X')
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
        if (playerOneSymbol == 'X')
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
        if (playerOneSymbol == 'X')
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
        if (playerOneSymbol == 'X')
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
        if (playerOneSymbol == 'X')
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
void displayUpdatedBoard(char playerOneSymbol, char cpuSymbol)
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
void checkIfWin(char playerOneSymbol, char cpuSymbol)
{
    bool playerOneWins = false;
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

    if (cpuSymbol == 'X')
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

    else if (cpuSymbol == 'O')
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

    //If cpu wins
    else if (cpuWins == true)
    {
        cout << "==========================" << endl;
        cout << "CPU Wins!" << endl;
        cout << "==========================" << endl;
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