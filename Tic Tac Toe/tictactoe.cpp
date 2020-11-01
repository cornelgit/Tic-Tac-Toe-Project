#include <iostream>
#include <string>
#include <ctime>
#include "windows.h" //For sleep
#include "tictactoe.h"

//Function to display welcome message
void displayWelcome()
{
    std::cout << "Welcome to Tic Tac Toe! See menu below for options." << std::endl << std::endl;
}

//Function to display menu
void displayMenu()
{
    int menuOption = { 0 };
    int playerOneScore = { 0 };
    int otherScore = { 0 };
    srand((unsigned int)time(NULL));

    do {
        std::cout << "Main menu." << std::endl;
        std::cout << "New Game \t\t(1)" << std::endl;
        std::cout << "Display controls \t(2)" << std::endl;
        std::cout << "Quit \t\t\t(3)" << std::endl << std::endl;

        std::cout << "Please select an option: ";

        std::cin >> menuOption;

        if (std::cout.fail() && !isdigit(menuOption))
        {
            std::cout << "Invalid choice. Please try again!" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }

        std::cout << std::endl;

    } while (menuOption != 1 && menuOption != 2 && menuOption != 3);

    if (menuOption == 1)
        gameMode(playerOneScore, otherScore);

    else if (menuOption == 2)
    {
        displayControls();
        displayMenu();
    }
    else
    {
        std::cout << "Thank you for playing. Goodbye!" << std::endl << std::endl;
        exit(0);
    }
}

//Function to display game mode
void gameMode(int playerOneScore, int otherScore)
{
    int modeChoice = { 0 };

    do {

        std::cout << "Available Game Modes. " << std::endl;
        std::cout << "Single Player (vs CPU) \t(1) " << std::endl;
        std::cout << "Two Player (vs player) \t(2) " << std::endl << std::endl;
        std::cout << "Choose a game mode: ";
        std::cin >> modeChoice;

        if (std::cout.fail() && !isdigit(modeChoice))
        {
            std::cout << "Invalid choice. Please try again!" << std::endl;
            std::cin.clear();
            std::cin.ignore();
        }

        std::cout << std::endl;

    } while (modeChoice != 1 && modeChoice != 2);

    if (modeChoice == 1)
        singlePlayer(playerOneScore, otherScore);
    else
        multiPlayer(playerOneScore, otherScore);
}


//Function to display controls
void displayControls()
{
    std::cout << std::endl;
    std::cout << "The grid is setup as follows: " << std::endl;
    std::cout << "     :     :     " << std::endl;
    std::cout << "  1  :  2  :  3  " << std::endl;
    std::cout << "_____:_____:_____" << std::endl;
    std::cout << "     :     :     " << std::endl;
    std::cout << "  4  :  5  :  6  " << std::endl;
    std::cout << "_____:_____:_____" << std::endl;
    std::cout << "     :     :     " << std::endl;
    std::cout << "  7  :  8  :  9  " << std::endl;
    std::cout << "     :     :     " << std::endl;
    std::cout << std::endl;
    std::cout << "To choose a square, simply type in the number." << std::endl;
    std::cout << "For example, to place an X or O in the middle square, type 5." << std::endl;
    std::cout << std::endl << std::endl; //Extra space
}

//Function for single player mode
void singlePlayer(int playerOneScore, int otherScore)
{
    int diceOne = { 0 };
    int diceCPU = { 0 };
    int key = { 0 };
    char playerOneSymbol = ' ';
    char cpuSymbol = ' ';
    bool multiFlag = false;

    //Reset grid squares
    for (int x = 0; x < ROW; x++) {
        for (int y = 0; y < COLUMN; y++) {
            gameArray[x][y] = ' ';
        }
    }

    //Determine who goes first/second
    do {
        diceOne = diceRoll();
        diceCPU = diceRoll();

        if (diceCPU > 1)
            diceCPU -= 1; //make it more fair for player 1 to go first

    } while (diceOne == diceCPU); //Repeat dice roll if a tie



    std::cout << "Game start!" << std::endl;
    std::cout << "Let's determine who goes first by rolling a dice." << std::endl << std::endl;
    Sleep(600);
    std::cout << "Player One rolled a " << diceOne << "." << std::endl;
    std::cout << "CPU rolled a " << diceCPU << "." << std::endl << std::endl;

    //Determine symbols based on who goes first/second
    if (diceOne > diceCPU)
    {
        playerOneSymbol = 'X';
        cpuSymbol = 'O';
        std::cout << "Player One goes first (X)." << std::endl;
        std::cout << "CPU goes second (O)." << std::endl;
    }
    else
    {
        playerOneSymbol = 'O';
        cpuSymbol = 'X';
        std::cout << "CPU goes first (X)." << std::endl;
        std::cout << "Player One goes second (O)." << std::endl;
    }

    std::cout << "Press a key then [ENTER] to continue...";
    std::cin >> key;
    std::cin.clear(); //Clear std::cout state after key press

    displayStartGrid(); //Display start grid

    if (diceOne > diceCPU)
        playerOneMove(playerOneSymbol, cpuSymbol, multiFlag, playerOneScore, otherScore); //Player one makes first move
    else
        cpuMove(playerOneSymbol, cpuSymbol, playerOneScore, otherScore); //CPU makes first move        
}

//Function for single player mode
void multiPlayer(int playerOneScore, int otherScore)
{
    int diceOne = { 0 };
    int diceTwo = { 0 };
    int key = { 0 }; //For continuation purposes
    char playerOneSymbol = ' ';
    char playerTwoSymbol = ' ';
    char cpuSymbol = ' ';
    bool multiFlag = true;

    //Reset grid squares
    for (int x = 0; x < ROW; x++) {
        for (int y = 0; y < COLUMN; y++) {
            gameArray[x][y] = ' ';
        }
    }

    //Determine who goes first/second
    do {
        diceOne = diceRoll();
        diceTwo = diceRoll();
    } while (diceOne == diceTwo); //Repeat dice roll if a tie

    std::cout << "Game start!" << std::endl;
    std::cout << "Let's determine who goes first by rolling a dice." << std::endl << std::endl;
    Sleep(600);
    std::cout << "Player One rolled a " << diceOne << "." << std::endl;
    std::cout << "Player Two rolled a " << diceTwo << "." << std::endl << std::endl;

    //Determine symbols based on who goes first/second
    if (diceOne > diceTwo)
    {
        playerOneSymbol = 'X';
        playerTwoSymbol = 'O';
        std::cout << "Player One goes first (X)." << std::endl;
        std::cout << "Player Two second (O)." << std::endl;
    }
    else
    {
        playerOneSymbol = 'O';
        playerTwoSymbol = 'X';
        std::cout << "Player Two goes first (X)." << std::endl;
        std::cout << "Player One second (O)." << std::endl;
    }

    std::cout << "\nPress a key then [ENTER] to continue...";
    std::cin >> key;
    std::cin.clear();

    /////////////////////DONT NEED NOW displayStartGrid(); //Display start grid

    if (diceOne > diceTwo)
        playerOneMove(playerOneSymbol, playerTwoSymbol, multiFlag, playerOneScore, otherScore); //Player one makes first move
    else
        playerTwoMove(playerOneSymbol, playerTwoSymbol, multiFlag, playerOneScore, otherScore); //CPU makes first move
}

//Function to display start grid
void displayStartGrid()
{
    std::cout << std::endl << std::endl;
    std::cout << "Current board: " << std::endl;
    std::cout << "     :     :     " << std::endl;
    std::cout << "  1  :  2  :  3  " << std::endl;
    std::cout << "_____:_____:_____" << std::endl;
    std::cout << "     :     :     " << std::endl;
    std::cout << "  4  :  5  :  6  " << std::endl;
    std::cout << "_____:_____:_____" << std::endl;
    std::cout << "     :     :     " << std::endl;
    std::cout << "  7  :  8  :  9  " << std::endl;
    std::cout << "     :     :     " << std::endl;
    std::cout << std::endl;
}

//Function to get dice roll
int diceRoll()
{
    int result = { 0 };
    result = 1 + rand() % 6;

    return result;
}

//Function to make player move
void playerOneMove(char playerOneSymbol, char otherSymbol, bool multiFlag, int playerOneScore, int otherScore)
{
    int PlayerOneChoice = { 0 };
    bool taken = false;

    do {
        std::cout << std::endl;
        std::cout << "Player One, please make a selection (1-9): ";
        std::cin.ignore();
        std::cin >> PlayerOneChoice;

        if (!isdigit(PlayerOneChoice) && (PlayerOneChoice < 1 || PlayerOneChoice > 9))
        {
            std::cin.clear();
            std::cout << "Invalid choice. Please try again!" << std::endl;
        }
        else {
            taken = checkTaken(PlayerOneChoice);
            if (taken == true)
                std::cout << "Square already occupied. Make another selection." << std::endl;
        }

    } while ((PlayerOneChoice != 1 && PlayerOneChoice != 2 && PlayerOneChoice != 3 &&
        PlayerOneChoice != 4 && PlayerOneChoice != 5 && PlayerOneChoice != 6 &&
        PlayerOneChoice != 7 && PlayerOneChoice != 8 && PlayerOneChoice != 9) || (taken == true));

    placePlayerSelection(PlayerOneChoice, playerOneSymbol); //Place player's one selection on board
    displayUpdatedBoard(); //Display updated game grid board
    checkIfWin(playerOneSymbol, otherSymbol, multiFlag, playerOneScore, otherScore); //Check if win occured

    //Next player goes depending on multiFlag
    if (multiFlag == false)
        cpuMove(playerOneSymbol, otherSymbol, playerOneScore, otherScore); //CPU goes next (single player)
    else
        playerTwoMove(playerOneSymbol, otherSymbol, multiFlag, playerOneScore, otherScore); //Player two goes next (multiplayer)
}

void playerTwoMove(char playerOneSymbol, char playerTwoSymbol, bool multiFlag, int playerOneScore, int otherScore)
{
    int PlayerTwoChoice = { 0 };
    bool taken = false;

    do {

        std::cout << std::endl;
        std::cout << "Player Two, please make a selection (1-9): ";
        std::cin.ignore();
        std::cin >> PlayerTwoChoice;

        if (!isdigit(PlayerTwoChoice) && (PlayerTwoChoice < 1 || PlayerTwoChoice > 9))
        {
            std::cin.clear();
            std::cout << "Invalid choice. Please try again!" << std::endl;
        }
        else {
            taken = checkTaken(PlayerTwoChoice);
            if (taken == true)
                std::cout << "Square already occupied. Make another selection." << std::endl;
        }

    } while ((PlayerTwoChoice != 1 && PlayerTwoChoice != 2 && PlayerTwoChoice != 3 &&
        PlayerTwoChoice != 4 && PlayerTwoChoice != 5 && PlayerTwoChoice != 6 &&
        PlayerTwoChoice != 7 && PlayerTwoChoice != 8 && PlayerTwoChoice != 9) || (taken == true));

    placePlayerSelection(PlayerTwoChoice, playerTwoSymbol); //Place player two selection on board
    displayUpdatedBoard(); //Display updated game grid board
    checkIfWin(playerOneSymbol, playerTwoSymbol, multiFlag, playerOneScore, otherScore); //Check if win occured

    //Next player goes 
    playerOneMove(playerOneSymbol, playerTwoSymbol, multiFlag, playerOneScore, otherScore);
}

//Function to check if a square is taken
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
    std::cout << std::endl << "Computer chose square " << cpuChoice << "." << std::endl;
}

//Function to display updated game grid boards
void displayUpdatedBoard()
{
    std::cout << std::endl;
    std::cout << "Current board: " << std::endl;
    std::cout << "     :     :     " << std::endl;
    std::cout << "  " << gameArray[0][0] << "  :  " << gameArray[0][1] << "  :  " << gameArray[0][2] << std::endl;
    std::cout << "_____:_____:_____" << std::endl;
    std::cout << "     :     :     " << std::endl;
    std::cout << "  " << gameArray[1][0] << "  :  " << gameArray[1][1] << "  :  " << gameArray[1][2] << std::endl;
    std::cout << "_____:_____:_____" << std::endl;
    std::cout << "     :     :     " << std::endl;
    std::cout << "  " << gameArray[2][0] << "  :  " << gameArray[2][1] << "  :  " << gameArray[2][2] << std::endl;
    std::cout << "     :     :     " << std::endl;
    std::cout << std::endl;
}

//Function to check and declare a win/loss condition
void checkIfWin(char playerOneSymbol, char otherSymbol, bool multiFlag, int& playerOneScore, int& otherScore)
{
    bool playerOneWins = false;
    bool playerTwoWins = false;
    bool cpuWins = false;
    bool isFilled = false;
    bool tie = false;
    std::string winType = " ";
    char continueMatch = ' ';

    if (playerOneSymbol == 'X')
    {
        if (gameArray[0][0] == 'X')
            if (gameArray[0][1] == 'X' && gameArray[0][2] == 'X') {
                playerOneWins = true;
                playerOneScore += 1;
                winType = "TR";
                displayWinningBoard(gameArray, winType);
            }
            else if (gameArray[1][0] == 'X' && gameArray[2][0] == 'X') {
                playerOneWins = true;
                playerOneScore += 1;
                winType = "LC";
                displayWinningBoard(gameArray, winType);
            }
            else if (gameArray[1][1] == 'X' && gameArray[2][2] == 'X') {
                playerOneWins = true;
                playerOneScore += 1;
                winType = "LD";
                displayWinningBoard(gameArray, winType);
            }
        if (gameArray[1][0] == 'X')
            if (gameArray[1][1] == 'X' && gameArray[1][2] == 'X') {
                playerOneWins = true;
                playerOneScore += 1;
                winType = "MR";
                displayWinningBoard(gameArray, winType);
            }
        if (gameArray[2][0] == 'X')
            if (gameArray[2][1] == 'X' && gameArray[2][2] == 'X') {
                playerOneWins = true;
                playerOneScore += 1;
                winType = "BR";
                displayWinningBoard(gameArray, winType);
            }
            else if (gameArray[1][1] == 'X' && gameArray[0][2] == 'X') {
                playerOneWins = true;
                playerOneScore += 1;
                winType = "RD";
                displayWinningBoard(gameArray, winType);
            }
        if (gameArray[0][1] == 'X')
            if (gameArray[1][1] == 'X' && gameArray[2][1] == 'X') {
                playerOneWins = true;
                playerOneScore += 1;
                winType = "MC";
                displayWinningBoard(gameArray, winType);
            }
        if (gameArray[0][2] == 'X')
            if (gameArray[1][2] == 'X' && gameArray[2][2] == 'X') {
                playerOneWins = true;
                playerOneScore += 1;
                winType = "RC";
                displayWinningBoard(gameArray, winType);
            }
    }

    else if (playerOneSymbol == 'O')
    {
        if (gameArray[0][0] == 'O')
            if (gameArray[0][1] == 'O' && gameArray[0][2] == 'O') {
                playerOneWins = true;
                playerOneScore += 1;
                winType = "TR";
                displayWinningBoard(gameArray, winType);
            }
            else if (gameArray[1][0] == 'O' && gameArray[2][0] == 'O') {
                playerOneWins = true;
                playerOneScore += 1;
                winType = "LC";
                displayWinningBoard(gameArray, winType);
            }
            else if (gameArray[1][1] == 'O' && gameArray[2][2] == 'O') {
                playerOneWins = true;
                playerOneScore += 1;
                winType = "LD";
                displayWinningBoard(gameArray, winType);
            }
        if (gameArray[1][0] == 'O')
            if (gameArray[1][1] == 'O' && gameArray[1][2] == 'O') {
                playerOneWins = true;
                playerOneScore += 1;
                winType = "MR";
                displayWinningBoard(gameArray, winType);
            }
        if (gameArray[2][0] == 'O')
            if (gameArray[2][1] == 'O' && gameArray[2][2] == 'O') {
                playerOneWins = true;
                playerOneScore += 1;
                winType = "BR";
                displayWinningBoard(gameArray, winType);
            }
            else if (gameArray[1][1] == 'O' && gameArray[0][2] == 'O') {
                playerOneWins = true;
                playerOneScore += 1;
                winType = "RD";
                displayWinningBoard(gameArray, winType);
            }
        if (gameArray[0][1] == 'O')
            if (gameArray[1][1] == 'O' && gameArray[2][1] == 'O') {
                playerOneWins = true;
                playerOneScore += 1;
                winType = "MC";
                displayWinningBoard(gameArray, winType);
            }
        if (gameArray[0][2] == 'O')
            if (gameArray[1][2] == 'O' && gameArray[2][2] == 'O') {
                playerOneWins = true;
                playerOneScore += 1;
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
                    otherScore += 1;
                    winType = "TR";
                    displayWinningBoard(gameArray, winType);
                }
                else if (gameArray[1][0] == 'X' && gameArray[2][0] == 'X') {
                    playerTwoWins = true;
                    otherScore += 1;
                    winType = "LC";
                    displayWinningBoard(gameArray, winType);
                }
                else if (gameArray[1][1] == 'X' && gameArray[2][2] == 'X') {
                    playerTwoWins = true;
                    otherScore += 1;
                    winType = "LD";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[1][0] == 'X')
                if (gameArray[1][1] == 'X' && gameArray[1][2] == 'X') {
                    playerTwoWins = true;
                    otherScore += 1;
                    winType = "MR";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[2][0] == 'X')
                if (gameArray[2][1] == 'X' && gameArray[2][2] == 'X') {
                    playerTwoWins = true;
                    otherScore += 1;
                    winType = "BR";
                    displayWinningBoard(gameArray, winType);
                }
                else if (gameArray[1][1] == 'X' && gameArray[0][2] == 'X') {
                    playerTwoWins = true;
                    otherScore += 1;
                    winType = "RD";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[0][1] == 'X')
                if (gameArray[1][1] == 'X' && gameArray[2][1] == 'X') {
                    playerTwoWins = true;
                    otherScore += 1;
                    winType = "MC";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[0][2] == 'X')
                if (gameArray[1][2] == 'X' && gameArray[2][2] == 'X') {
                    playerTwoWins = true;
                    otherScore += 1;
                    winType = "RC";
                    displayWinningBoard(gameArray, winType);
                }
        }

        else if (otherSymbol == 'O')
        {
            if (gameArray[0][0] == 'O')
                if (gameArray[0][1] == 'O' && gameArray[0][2] == 'O') {
                    playerTwoWins = true;
                    otherScore += 1;
                    winType = "TR";
                    displayWinningBoard(gameArray, winType);
                }
                else if (gameArray[1][0] == 'O' && gameArray[2][0] == 'O') {
                    playerTwoWins = true;
                    otherScore += 1;
                    winType = "LC";
                    displayWinningBoard(gameArray, winType);
                }
                else if (gameArray[1][1] == 'O' && gameArray[2][2] == 'O') {
                    playerTwoWins = true;
                    otherScore += 1;
                    winType = "LD";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[1][0] == 'O')
                if (gameArray[1][1] == 'O' && gameArray[1][2] == 'O') {
                    playerTwoWins = true;
                    otherScore += 1;
                    winType = "MR";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[2][0] == 'O')
                if (gameArray[2][1] == 'O' && gameArray[2][2] == 'O') {
                    playerTwoWins = true;
                    otherScore += 1;
                    winType = "BR";
                    displayWinningBoard(gameArray, winType);
                }
                else if (gameArray[1][1] == 'O' && gameArray[0][2] == 'O') {
                    playerTwoWins = true;
                    otherScore += 1;
                    winType = "RD";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[0][1] == 'O')
                if (gameArray[1][1] == 'O' && gameArray[2][1] == 'O') {
                    playerTwoWins = true;
                    otherScore += 1;
                    winType = "MC";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[0][2] == 'O')
                if (gameArray[1][2] == 'O' && gameArray[2][2] == 'O') {
                    playerTwoWins = true;
                    otherScore += 1;
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
                    otherScore += 1;
                    winType = "TR";
                    displayWinningBoard(gameArray, winType);
                }
                else if (gameArray[1][0] == 'X' && gameArray[2][0] == 'X') {
                    cpuWins = true;
                    otherScore += 1;
                    winType = "LC";
                    displayWinningBoard(gameArray, winType);
                }
                else if (gameArray[1][1] == 'X' && gameArray[2][2] == 'X') {
                    cpuWins = true;
                    otherScore += 1;
                    winType = "LD";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[1][0] == 'X')
                if (gameArray[1][1] == 'X' && gameArray[1][2] == 'X') {
                    cpuWins = true;
                    otherScore += 1;
                    winType = "MR";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[2][0] == 'X')
                if (gameArray[2][1] == 'X' && gameArray[2][2] == 'X') {
                    cpuWins = true;
                    otherScore += 1;
                    winType = "BR";
                    displayWinningBoard(gameArray, winType);
                }
                else if (gameArray[1][1] == 'X' && gameArray[0][2] == 'X') {
                    cpuWins = true;
                    otherScore += 1;
                    winType = "RD";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[0][1] == 'X')
                if (gameArray[1][1] == 'X' && gameArray[2][1] == 'X') {
                    cpuWins = true;
                    otherScore += 1;
                    winType = "MC";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[0][2] == 'X')
                if (gameArray[1][2] == 'X' && gameArray[2][2] == 'X') {
                    cpuWins = true;
                    otherScore += 1;
                    winType = "RC";
                    displayWinningBoard(gameArray, winType);
                }
        }

        else if (otherSymbol == 'O')
        {
            if (gameArray[0][0] == 'O')
                if (gameArray[0][1] == 'O' && gameArray[0][2] == 'O') {
                    cpuWins = true;
                    otherScore += 1;
                    winType = "TR";
                    displayWinningBoard(gameArray, winType);
                }
                else if (gameArray[1][0] == 'O' && gameArray[2][0] == 'O') {
                    cpuWins = true;
                    otherScore += 1;
                    winType = "LC";
                    displayWinningBoard(gameArray, winType);
                }
                else if (gameArray[1][1] == 'O' && gameArray[2][2] == 'O') {
                    cpuWins = true;
                    otherScore += 1;
                    winType = "LD";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[1][0] == 'O')
                if (gameArray[1][1] == 'O' && gameArray[1][2] == 'O') {
                    cpuWins = true;
                    otherScore += 1;
                    winType = "MR";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[2][0] == 'O')
                if (gameArray[2][1] == 'O' && gameArray[2][2] == 'O') {
                    cpuWins = true;
                    otherScore += 1;
                    winType = "BR";
                    displayWinningBoard(gameArray, winType);
                }
                else if (gameArray[1][1] == 'O' && gameArray[0][2] == 'O') {
                    cpuWins = true;
                    otherScore += 1;
                    winType = "RD";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[0][1] == 'O')
                if (gameArray[1][1] == 'O' && gameArray[2][1] == 'O') {
                    cpuWins = true;
                    otherScore += 1;
                    winType = "MC";
                    displayWinningBoard(gameArray, winType);
                }
            if (gameArray[0][2] == 'O')
                if (gameArray[1][2] == 'O' && gameArray[2][2] == 'O') {
                    cpuWins = true;
                    otherScore += 1;
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

        if (isFilled == false)// && tie == false)
            break;
    }

    //If player one wins
    if (playerOneWins == true)
    {
        std::cout << "==========================" << std::endl;
        std::cout << "Player One Wins!" << std::endl;
        std::cout << "==========================" << std::endl << std::endl;

        displayScore(multiFlag, playerOneScore, otherScore); //Display score based on game mode

        do {
            std::cout << "Continue match (Y/N)? ";
            std::cin.ignore();
            std::cin >> continueMatch;

            if (std::cout.fail() || (toupper(continueMatch) != 'Y' && toupper(continueMatch) != 'N'))
            {
                std::cin.clear();
                std::cout << "\nInvalid choice. Please try again!" << std::endl;
            }

        } while (toupper(continueMatch) != 'Y' && toupper(continueMatch) != 'N');

        if (toupper(continueMatch) == 'Y' && multiFlag == false)
        {
            singlePlayer(playerOneScore, otherScore); //Go to next match keeping scores intact
        }

        if (toupper(continueMatch) == 'Y' && multiFlag == true)
        {
            multiPlayer(playerOneScore, otherScore); //Go to next match keeping scores intact
        }

        else
        {
            playerOneScore = 0; //Reset score to 0
            otherScore = 0; //Reset score to 0
            std::cout << "Returning to main menu." << std::endl;
            Sleep(400);
            displayWelcome();
            displayMenu();
        }
    }

    //If player two wins
    else if (playerTwoWins == true)
    {
        std::cout << "==========================" << std::endl;
        std::cout << "Player Two Wins!" << std::endl;
        std::cout << "==========================" << std::endl << std::endl;

        displayScore(multiFlag, playerOneScore, otherScore);

        do {
            std::cout << "Continue match (Y/N)? ";
            std::cin.ignore();
            std::cin >> continueMatch;

            if (std::cout.fail() || (toupper(continueMatch) != 'Y' && toupper(continueMatch) != 'N'))
            {
                std::cin.clear();
                std::cout << "\nInvalid choice. Please try again!" << std::endl;
            }

        } while (toupper(continueMatch) != 'Y' && toupper(continueMatch) != 'N');

        if (toupper(continueMatch) == 'Y')
        {
            multiPlayer(playerOneScore, otherScore);
        }

        else
        {
            playerOneScore = 0; //Reset score to 0
            otherScore = 0; //Reset score to 0
            std::cout << "Returning to main menu." << std::endl;
            Sleep(400);
            displayWelcome();
            displayMenu();
        }
    }

    //If cpu wins
    else if (cpuWins == true)
    {
        std::cout << "==========================" << std::endl;
        std::cout << "CPU Wins!" << std::endl;
        std::cout << "==========================" << std::endl << std::endl;

        displayScore(multiFlag, playerOneScore, otherScore);

        do {
            std::cout << "Continue match (Y/N)? ";
            std::cin.ignore();
            std::cin >> continueMatch;

            if (std::cout.fail() || (toupper(continueMatch) != 'Y' && toupper(continueMatch) != 'N'))
            {
                std::cin.clear();
                std::cout << "\nInvalid choice. Please try again!" << std::endl;
            }

        } while (toupper(continueMatch) != 'Y' && toupper(continueMatch) != 'N');

        if (toupper(continueMatch) == 'Y')
        {
            singlePlayer(playerOneScore, otherScore);
        }

        else
        {
            playerOneScore = 0; //Reset score to 0
            otherScore = 0; //Reset score to 0
            std::cout << "Returning to main menu." << std::endl;
            Sleep(400);
            displayWelcome();
            displayMenu();
        }
    }

    //If it's a tie
    else if (isFilled == true && tie == true)
    {
        std::cout << "==========================" << std::endl;
        std::cout << "Tie game!" << std::endl;
        std::cout << "==========================" << std::endl;

        displayScore(multiFlag, playerOneScore, otherScore);

        do {
            std::cout << "Continue match (Y/N)? ";
            std::cin.ignore();
            std::cin >> continueMatch;

            if (std::cout.fail() || (toupper(continueMatch) != 'Y' && toupper(continueMatch) != 'N'))
            {
                std::cin.clear();
                std::cout << "\nInvalid choice. Please try again!" << std::endl;
            }

        } while (toupper(continueMatch) != 'Y' && toupper(continueMatch) != 'N');

        if (toupper(continueMatch) == 'Y' && multiFlag == false)
        {
            singlePlayer(playerOneScore, otherScore);
        }

        if (toupper(continueMatch) == 'Y' && multiFlag == true)
        {
            multiPlayer(playerOneScore, otherScore);
        }

        else
        {
            playerOneScore = 0; //Reset score to 0
            otherScore = 0; //Reset score to 0
            std::cout << "Returning to main menu." << std::endl;
            Sleep(400);
            displayWelcome();
            displayMenu();
        }
    }
}

//Function to display winning board layout
void displayWinningBoard(const char gameArray[ROW][COLUMN], std::string winType)
{
    if (winType == "TR") {
        std::cout << std::endl;
        std::cout << "Current board: " << std::endl;
        std::cout << "     |     |     " << std::endl;
        std::cout << "--" << gameArray[0][0] << "--|--" << gameArray[0][1] << "--|--" << gameArray[0][2] << "--" << std::endl;
        std::cout << "_____|_____|_____" << std::endl;
        std::cout << "     |     |     " << std::endl;
        std::cout << "  " << gameArray[1][0] << "  |  " << gameArray[1][1] << "  |  " << gameArray[1][2] << std::endl;
        std::cout << "_____|_____|_____" << std::endl;
        std::cout << "     |     |     " << std::endl;
        std::cout << "  " << gameArray[2][0] << "  |  " << gameArray[2][1] << "  |  " << gameArray[2][2] << std::endl;
        std::cout << "     |     |     " << std::endl;
        std::cout << std::endl;
    }

    else if (winType == "LC") {
        std::cout << std::endl;
        std::cout << "Current board: " << std::endl;
        std::cout << "  |  |     |     " << std::endl;
        std::cout << "  " << gameArray[0][0] << "  |  " << gameArray[0][1] << "  |  " << gameArray[0][2] << std::endl;
        std::cout << "__|__|_____|_____" << std::endl;
        std::cout << "  |  |     |     " << std::endl;
        std::cout << "  " << gameArray[1][0] << "  |  " << gameArray[1][1] << "  |  " << gameArray[1][2] << std::endl;
        std::cout << "__|__|_____|_____" << std::endl;
        std::cout << "  |  |     |     " << std::endl;
        std::cout << "  " << gameArray[2][0] << "  |  " << gameArray[2][1] << "  |  " << gameArray[2][2] << std::endl;
        std::cout << "  |  |     |     " << std::endl;
        std::cout << std::endl;
    }

    else if (winType == "LD") {
        std::cout << std::endl;
        std::cout << "Current board| " << std::endl;
        std::cout << " \\   |     |     " << std::endl;
        std::cout << "  " << gameArray[0][0] << "  |  " << gameArray[0][1] << "  |  " << gameArray[0][2] << std::endl;
        std::cout << "____\\|_____|_____" << std::endl;
        std::cout << "     |\\    |     " << std::endl;
        std::cout << "  " << gameArray[1][0] << "  |  " << gameArray[1][1] << "  |  " << gameArray[1][2] << std::endl;
        std::cout << "_____|____\\|_____" << std::endl;
        std::cout << "     |     |\\    " << std::endl;
        std::cout << "  " << gameArray[2][0] << "  |  " << gameArray[2][1] << "  |  " << gameArray[2][2] << std::endl;
        std::cout << "     |     |   \\ " << std::endl;
        std::cout << std::endl;
    }

    else if (winType == "MR") {
        std::cout << std::endl;
        std::cout << "Current board| " << std::endl;
        std::cout << "     |     |     " << std::endl;
        std::cout << "  " << gameArray[0][0] << "  |  " << gameArray[0][1] << "  |  " << gameArray[0][2] << std::endl;
        std::cout << "_____|_____|_____" << std::endl;
        std::cout << "     |     |     " << std::endl;
        std::cout << "--" << gameArray[1][0] << "--|--" << gameArray[1][1] << "--|--" << gameArray[1][2] << "--" << std::endl;
        std::cout << "_____|_____|_____" << std::endl;
        std::cout << "     |     |     " << std::endl;
        std::cout << "  " << gameArray[2][0] << "  |  " << gameArray[2][1] << "  |  " << gameArray[2][2] << std::endl;
        std::cout << "     |     |     " << std::endl;
        std::cout << std::endl;
    }

    else if (winType == "BR") {
        std::cout << std::endl;
        std::cout << "Current board| " << std::endl;
        std::cout << "     |     |     " << std::endl;
        std::cout << "  " << gameArray[0][0] << "  |  " << gameArray[0][1] << "  |  " << gameArray[0][2] << std::endl;
        std::cout << "_____|_____|_____" << std::endl;
        std::cout << "     |     |     " << std::endl;
        std::cout << "  " << gameArray[1][0] << "  |  " << gameArray[1][1] << "  |  " << gameArray[1][2] << std::endl;
        std::cout << "_____|_____|_____" << std::endl;
        std::cout << "     |     |     " << std::endl;
        std::cout << "--" << gameArray[2][0] << "--|--" << gameArray[2][1] << "--|--" << gameArray[2][2] << "--" << std::endl;
        std::cout << "     |     |     " << std::endl;
        std::cout << std::endl;
    }

    else if (winType == "RD") {
        std::cout << std::endl;
        std::cout << "Current board| " << std::endl;
        std::cout << "     |     |   / " << std::endl;
        std::cout << "  " << gameArray[0][0] << "  |  " << gameArray[0][1] << "  |  " << gameArray[0][2] << std::endl;
        std::cout << "_____|_____|/____" << std::endl;
        std::cout << "     |    /|     " << std::endl;
        std::cout << "  " << gameArray[1][0] << "  |  " << gameArray[1][1] << "  |  " << gameArray[1][2] << std::endl;
        std::cout << "_____|/____|_____" << std::endl;
        std::cout << "    /|     |     " << std::endl;
        std::cout << "  " << gameArray[2][0] << "  |  " << gameArray[2][1] << "  |  " << gameArray[2][2] << std::endl;
        std::cout << " /   |     |     " << std::endl;
        std::cout << std::endl;
    }

    else if (winType == "MC") {
        std::cout << std::endl;
        std::cout << "Current board| " << std::endl;
        std::cout << "     |  |  |     " << std::endl;
        std::cout << "  " << gameArray[0][0] << "  |  " << gameArray[0][1] << "  |  " << gameArray[0][2] << std::endl;
        std::cout << "_____|__|__|_____" << std::endl;
        std::cout << "     |  |  |     " << std::endl;
        std::cout << "  " << gameArray[1][0] << "  |  " << gameArray[1][1] << "  |  " << gameArray[1][2] << std::endl;
        std::cout << "_____|__|__|_____" << std::endl;
        std::cout << "     |  |  |     " << std::endl;
        std::cout << "  " << gameArray[2][0] << "  |  " << gameArray[2][1] << "  |  " << gameArray[2][2] << std::endl;
        std::cout << "     |  |  |     " << std::endl;
        std::cout << std::endl;
    }

    else if (winType == "RC") {
        std::cout << std::endl;
        std::cout << "Current board| " << std::endl;
        std::cout << "     |     |  |  " << std::endl;
        std::cout << "  " << gameArray[0][0] << "  |  " << gameArray[0][1] << "  |  " << gameArray[0][2] << std::endl;
        std::cout << "_____|_____|__|__" << std::endl;
        std::cout << "     |     |  |  " << std::endl;
        std::cout << "  " << gameArray[1][0] << "  |  " << gameArray[1][1] << "  |  " << gameArray[1][2] << std::endl;
        std::cout << "_____|_____|__|__" << std::endl;
        std::cout << "     |     |  |  " << std::endl;
        std::cout << "  " << gameArray[2][0] << "  |  " << gameArray[2][1] << "  |  " << gameArray[2][2] << std::endl;
        std::cout << "     |     |  |  " << std::endl;
        std::cout << std::endl;
    }
}

//Function to display score based on game mode
void displayScore(bool multiFlag, const int playerOneScore, const int otherScore)
{
    if (multiFlag == false)
    {
        std::cout << "=========================================" << std::endl;
        std::cout << "Score ----> \t" << "Player One: " << playerOneScore << "\tCPU: " << otherScore << std::endl;
        std::cout << "=========================================" << std::endl << std::endl;
    }

    else
    {
        std::cout << "=========================================" << std::endl;
        std::cout << "Score ----> \t" << "Player One: " << playerOneScore << "\tPlayer Two: " << otherScore << std::endl;
        std::cout << "=========================================" << std::endl << std::endl;
    }
}