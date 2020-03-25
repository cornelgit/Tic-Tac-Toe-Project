#include <iostream>
#include <string>
#include <ctime>
#include "windows.h" //For sleep
#include "tictactoe.h"

//Function to make cpu move
void cpuMove(char playerOneSymbol, char cpuSymbol, int playerOneScore, int otherScore)
{
    int randomNum = { 0 };
    bool multiFlag = false;

    std::cout << std::endl << std::endl;
    std::cout << "Please wait. Computer is thinking";
    Sleep(400);
    std::cout << ".";
    Sleep(400);
    std::cout << ".";
    Sleep(400);
    std::cout << ".";
    Sleep(400);
    std::cout << "." << std::endl;

    //Determine cpu selection based on game board analysis
    if (cpuSymbol == 'X') {

        // If board is empty and CPU goes first
        if (gameArray[0][0] == ' ' && gameArray[0][1] == ' ' && gameArray[0][2] == ' ' && gameArray[1][0] == ' '
            && gameArray[1][1] == ' ' && gameArray[1][2] == ' ' && gameArray[2][0] == ' ' && gameArray[2][1] == ' '
            && gameArray[2][2] == ' ') {

            do {
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

            //5th Turn plastd::coutg X to win a fork
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
            else if (gameArray[0][2] == 'X' && gameArray[0][0] == 'O' && gameArray[2][2] == 'X' && gameArray[1][2] == 'O' && gameArray[2][0] == ' ') {
                gameArray[2][0] = 'X';
                cpuChoicePrint(7);
            }
            else if (gameArray[0][2] == 'X' && gameArray[2][1] == 'O' && gameArray[2][2] == 'X' && gameArray[1][2] == 'O' && gameArray[1][1] == ' ') {
                gameArray[1][1] = 'X';
                cpuChoicePrint(5);
            }
            else if (gameArray[0][2] == 'X' && gameArray[2][0] == 'O' && gameArray[2][2] == 'X' && gameArray[1][2] == 'O' && gameArray[0][0] == ' ') {
                gameArray[0][0] = 'X';
                cpuChoicePrint(1);
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

            //3rd turn plastd::coutg x in a corner if 0 is in the middle - corner fork
            else if (gameArray[1][1] == 'O' && gameArray[0][0] == 'X' && gameArray[2][2] == ' ') {
                gameArray[2][2] = 'X';
                cpuChoicePrint(9);
            }
            else if (gameArray[1][1] == 'O' && gameArray[0][2] == 'X' && gameArray[2][0] == ' ') {
                gameArray[2][0] = 'X';
                cpuChoicePrint(7);
            }
            else if (gameArray[1][1] == 'O' && gameArray[2][0] == 'X' && gameArray[0][2] == ' ') {
                gameArray[0][2] = 'X';
                cpuChoicePrint(3);
            }
            else if (gameArray[1][1] == 'O' && gameArray[2][2] == 'X' && gameArray[0][0] == ' ') {
                gameArray[0][0] = 'X';
                cpuChoicePrint(1);
            } //End of corner fork

            //3rd turn plastd::coutg x diagonally if O is in a corner and X in middle
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

            //3rd turn plastd::coutg X in a corner if X starts in square 1
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

            //3rd turn plastd::coutg X in a corner if X starts in square 3
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
            else if (gameArray[0][2] == 'X' && gameArray[1][2] == 'O' && gameArray[1][1] == ' ') {
                gameArray[1][1] = 'X';
                cpuChoicePrint(5);
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

            //3rd turn plastd::coutg X in a corner if X starts in square 7
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

            //3rd turn plastd::coutg X in a corner if X starts in square 9
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

    //If CPU is O
    else
    {
        //Scenarios for when O is gonna complete a line
        // Rows 1-3
        if (gameArray[0][0] == 'O' && gameArray[0][1] == 'O' && gameArray[0][2] == ' ') {
            gameArray[0][2] = 'O';
            cpuChoicePrint(3);
        }
        else if (gameArray[0][0] == 'O' && gameArray[0][2] == 'O' && gameArray[0][1] == ' ') {
            gameArray[0][1] = 'O';
            cpuChoicePrint(2);
        }
        else if (gameArray[0][1] == 'O' && gameArray[0][2] == 'O' && gameArray[0][0] == ' ') {
            gameArray[0][0] = 'O';
            cpuChoicePrint(1);
        } //End of row 1
        else if (gameArray[1][0] == 'O' && gameArray[1][1] == 'O' && gameArray[1][2] == ' ') {
            gameArray[1][2] = 'O';
            cpuChoicePrint(6);
        }
        else if (gameArray[1][0] == 'O' && gameArray[1][2] == 'O' && gameArray[1][1] == ' ') {
            gameArray[1][1] = 'O';
            cpuChoicePrint(5);
        }
        else if (gameArray[1][1] == 'O' && gameArray[1][2] == 'O' && gameArray[1][0] == ' ') {
            gameArray[1][0] = 'O';
            cpuChoicePrint(4);
        } // End of row 2
        else if (gameArray[2][0] == 'O' && gameArray[2][1] == 'O' && gameArray[2][2] == ' ') {
            gameArray[2][2] = 'O';
            cpuChoicePrint(9);
        }
        else if (gameArray[2][0] == 'O' && gameArray[2][2] == 'O' && gameArray[2][1] == ' ') {
            gameArray[2][1] = 'O';
            cpuChoicePrint(8);
        }
        else if (gameArray[2][1] == 'O' && gameArray[2][2] == 'O' && gameArray[2][0] == ' ') {
            gameArray[2][0] = 'O';
            cpuChoicePrint(7);
        } // End of row 3

        //Columns 1-3
        else if (gameArray[0][0] == 'O' && gameArray[1][0] == 'O' && gameArray[2][0] == ' ') {
            gameArray[2][0] = 'O';
            cpuChoicePrint(7);
        }
        else if (gameArray[0][0] == 'O' && gameArray[2][0] == 'O' && gameArray[1][0] == ' ') {
            gameArray[1][0] = 'O';
            cpuChoicePrint(4);
        }
        else if (gameArray[1][0] == 'O' && gameArray[2][0] == 'O' && gameArray[0][0] == ' ') {
            gameArray[0][0] = 'O';
            cpuChoicePrint(1);
        } //End of column 1
        else if (gameArray[0][1] == 'O' && gameArray[1][1] == 'O' && gameArray[2][1] == ' ') {
            gameArray[2][1] = 'O';
            cpuChoicePrint(8);
        }
        else if (gameArray[0][1] == 'O' && gameArray[2][1] == 'O' && gameArray[1][1] == ' ') {
            gameArray[1][1] = 'O';
            cpuChoicePrint(5);
        }
        else if (gameArray[1][1] == 'O' && gameArray[2][1] == 'O' && gameArray[0][1] == ' ') {
            gameArray[0][1] = 'O';
            cpuChoicePrint(2);
        } //End of column 2
        else if (gameArray[0][2] == 'O' && gameArray[1][2] == 'O' && gameArray[2][2] == ' ') {
            gameArray[2][2] = 'O';
            cpuChoicePrint(9);
        }
        else if (gameArray[0][2] == 'O' && gameArray[2][2] == 'O' && gameArray[1][2] == ' ') {
            gameArray[1][2] = 'O';
            cpuChoicePrint(6);
        }
        else if (gameArray[1][2] == 'O' && gameArray[2][2] == 'O' && gameArray[0][2] == ' ') {
            gameArray[0][2] = 'O';
            cpuChoicePrint(3);
        } //End of column 3

        //Diagonals 1-2
        else if (gameArray[0][0] == 'O' && gameArray[1][1] == 'O' && gameArray[2][2] == ' ') {
            gameArray[2][2] = 'O';
            cpuChoicePrint(9);
        }
        else if (gameArray[0][0] == 'O' && gameArray[2][2] == 'O' && gameArray[1][1] == ' ') {
            gameArray[1][1] = 'O';
            cpuChoicePrint(5);
        }
        else if (gameArray[1][1] == 'O' && gameArray[2][2] == 'O' && gameArray[0][0] == ' ') {
            gameArray[0][0] = 'O';
            cpuChoicePrint(1);
        } //End of diagonal 1
        else if (gameArray[0][2] == 'O' && gameArray[1][1] == 'O' && gameArray[2][0] == ' ') {
            gameArray[2][0] = 'O';
            cpuChoicePrint(7);
        }
        else if (gameArray[0][2] == 'O' && gameArray[2][0] == 'O' && gameArray[1][1] == ' ') {
            gameArray[1][1] = 'O';
            cpuChoicePrint(5);
        }
        else if (gameArray[1][1] == 'O' && gameArray[2][0] == 'O' && gameArray[0][2] == ' ') {
            gameArray[0][2] = 'O';
            cpuChoicePrint(3);
        } //End of diagonal 2 (O's matching)

        //Scenarios for O countering 2nd X
        // Rows 1-3
        else if (gameArray[0][0] == 'X' && gameArray[0][1] == 'X' && gameArray[0][2] == ' ') {
            gameArray[0][2] = 'O';
            cpuChoicePrint(3);
        }
        else if (gameArray[0][0] == 'X' && gameArray[0][2] == 'X' && gameArray[0][1] == ' ') {
            gameArray[0][1] = 'O';
            cpuChoicePrint(2);
        }
        else if (gameArray[0][1] == 'X' && gameArray[0][2] == 'X' && gameArray[0][0] == ' ') {
            gameArray[0][0] = 'O';
            cpuChoicePrint(1);
        } //End of row 1
        else if (gameArray[1][0] == 'X' && gameArray[1][1] == 'X' && gameArray[1][2] == ' ') {
            gameArray[1][2] = 'O';
            cpuChoicePrint(6);
        }
        else if (gameArray[1][0] == 'X' && gameArray[1][2] == 'X' && gameArray[1][1] == ' ') {
            gameArray[1][1] = 'O';
            cpuChoicePrint(5);
        }
        else if (gameArray[1][1] == 'X' && gameArray[1][2] == 'X' && gameArray[1][0] == ' ') {
            gameArray[1][0] = 'O';
            cpuChoicePrint(4);
        } // End of row 2
        else if (gameArray[2][0] == 'X' && gameArray[2][1] == 'X' && gameArray[2][2] == ' ') {
            gameArray[2][2] = 'O';
            cpuChoicePrint(9);
        }
        else if (gameArray[2][0] == 'X' && gameArray[2][2] == 'X' && gameArray[2][1] == ' ') {
            gameArray[2][1] = 'O';
            cpuChoicePrint(8);
        }
        else if (gameArray[2][1] == 'X' && gameArray[2][2] == 'X' && gameArray[2][0] == ' ') {
            gameArray[2][0] = 'O';
            cpuChoicePrint(7);
        } // End of row 3

        //Columns 1-3
        else if (gameArray[0][0] == 'X' && gameArray[1][0] == 'X' && gameArray[2][0] == ' ') {
            gameArray[2][0] = 'O';
            cpuChoicePrint(7);
        }
        else if (gameArray[0][0] == 'X' && gameArray[2][0] == 'X' && gameArray[1][0] == ' ') {
            gameArray[1][0] = 'O';
            cpuChoicePrint(4);
        }
        else if (gameArray[1][0] == 'X' && gameArray[2][0] == 'X' && gameArray[0][0] == ' ') {
            gameArray[0][0] = 'O';
            cpuChoicePrint(1);
        } //End of column 1
        else if (gameArray[0][1] == 'X' && gameArray[1][1] == 'X' && gameArray[2][1] == ' ') {
            gameArray[2][1] = 'O';
            cpuChoicePrint(8);
        }
        else if (gameArray[0][1] == 'X' && gameArray[2][1] == 'X' && gameArray[1][1] == ' ') {
            gameArray[1][1] = 'O';
            cpuChoicePrint(5);
        }
        else if (gameArray[1][1] == 'X' && gameArray[2][1] == 'X' && gameArray[0][1] == ' ') {
            gameArray[0][1] = 'O';
            cpuChoicePrint(2);
        } //End of column 2
        else if (gameArray[0][2] == 'X' && gameArray[1][2] == 'X' && gameArray[2][2] == ' ') {
            gameArray[2][2] = 'O';
            cpuChoicePrint(9);
        }
        else if (gameArray[0][2] == 'X' && gameArray[2][2] == 'X' && gameArray[1][2] == ' ') {
            gameArray[1][2] = 'O';
            cpuChoicePrint(6);
        }
        else if (gameArray[1][2] == 'X' && gameArray[2][2] == 'X' && gameArray[0][2] == ' ') {
            gameArray[0][2] = 'O';
            cpuChoicePrint(3);
        } //End of column 3

        //Diagonals 1-2
        else if (gameArray[0][0] == 'X' && gameArray[1][1] == 'X' && gameArray[2][2] == ' ') {
            gameArray[2][2] = 'O';
            cpuChoicePrint(9);
        }
        else if (gameArray[0][0] == 'X' && gameArray[2][2] == 'X' && gameArray[1][1] == ' ') {
            gameArray[1][1] = 'O';
            cpuChoicePrint(5);
        }
        else if (gameArray[1][1] == 'X' && gameArray[2][2] == 'X' && gameArray[0][0] == ' ') {
            gameArray[0][0] = 'O';
            cpuChoicePrint(1);
        }//End of diagonal 1
        else if (gameArray[0][2] == 'X' && gameArray[1][1] == 'X' && gameArray[2][0] == ' ') {
            gameArray[2][0] = 'O';
            cpuChoicePrint(7);
        }
        else if (gameArray[0][2] == 'X' && gameArray[2][0] == 'X' && gameArray[1][1] == ' ') {
            gameArray[1][1] = 'O';
            cpuChoicePrint(5);
        }
        else if (gameArray[1][1] == 'X' && gameArray[2][0] == 'X' && gameArray[0][2] == ' ') {
            gameArray[0][2] = 'O';
            cpuChoicePrint(3);
        } //End of diagonal 2

        //4th turn O countering X corner forks with O in middle
        else if (gameArray[1][1] == 'O' && gameArray[0][0] == 'X' && gameArray[2][1] == 'X' && gameArray[2][0] == ' ') {
            gameArray[2][0] = 'O';
            cpuChoicePrint(7);
        }
        else if (gameArray[1][1] == 'O' && gameArray[0][0] == 'X' && gameArray[1][2] == 'X' && gameArray[0][2] == ' ') {
            gameArray[0][2] = 'O';
            cpuChoicePrint(3);
        }
        else if (gameArray[1][1] == 'O' && gameArray[0][2] == 'X' && gameArray[2][1] == 'X' && gameArray[2][2] == ' ') {
            gameArray[2][2] = 'O';
            cpuChoicePrint(9);
        }
        else if (gameArray[1][1] == 'O' && gameArray[0][2] == 'X' && gameArray[1][0] == 'X' && gameArray[0][0] == ' ') {
            gameArray[0][0] = 'O';
            cpuChoicePrint(1);
        }
        else if (gameArray[1][1] == 'O' && gameArray[2][0] == 'X' && gameArray[1][2] == 'X' && gameArray[2][2] == ' ') {
            gameArray[2][2] = 'O';
            cpuChoicePrint(9);
        }
        else if (gameArray[1][1] == 'O' && gameArray[2][0] == 'X' && gameArray[0][1] == 'X' && gameArray[0][0] == ' ') {
            gameArray[0][0] = 'O';
            cpuChoicePrint(1);
        }
        else if (gameArray[1][1] == 'O' && gameArray[1][0] == 'X' && gameArray[2][2] == 'X' && gameArray[2][0] == ' ') {
            gameArray[2][0] = 'O';
            cpuChoicePrint(7);
        }
        else if (gameArray[1][1] == 'O' && gameArray[0][1] == 'X' && gameArray[2][2] == 'X' && gameArray[0][2] == ' ') {
            gameArray[0][2] = 'O';
            cpuChoicePrint(3);
        }
        else if (gameArray[1][1] == 'O' && gameArray[1][2] == 'X' && gameArray[2][1] == 'X' && gameArray[2][2] == ' ') {
            gameArray[2][2] = 'O';
            cpuChoicePrint(9);
        }

        //4th Turn O countering X diagonal forks
        else if (gameArray[0][0] == 'O' && gameArray[1][1] == 'X' && gameArray[2][2] == 'X' && gameArray[2][0] == ' ') {
            gameArray[2][0] = 'O';
            cpuChoicePrint(7);
        }
        else if (gameArray[0][2] == 'O' && gameArray[1][1] == 'X' && gameArray[2][0] == 'X' && gameArray[2][2] == ' ') {
            gameArray[2][2] = 'O';
            cpuChoicePrint(9);
        }
        else if (gameArray[2][2] == 'O' && gameArray[1][1] == 'X' && gameArray[0][0] == 'X' && gameArray[2][0] == ' ') {
            gameArray[2][0] = 'O';
            cpuChoicePrint(7);
        }
        else if (gameArray[2][0] == 'O' && gameArray[1][1] == 'X' && gameArray[1][2] == 'X' && gameArray[2][2] == ' ') {
            gameArray[2][2] = 'O';
            cpuChoicePrint(9);
        }

        //4th Turn if X doesn't go in Middle, adjacent X's and adjacent O's
        else if (gameArray[0][0] == 'O' && gameArray[1][0] == 'X' && gameArray[2][0] == 'X' && gameArray[0][1] == ' ') {
            gameArray[0][1] = 'O';
            cpuChoicePrint(2);
        }
        else if (gameArray[0][0] == 'O' && gameArray[0][1] == 'X' && gameArray[0][2] == 'X' && gameArray[1][0] == ' ') {
            gameArray[1][0] = 'O';
            cpuChoicePrint(4);
        }
        else if (gameArray[2][0] == 'O' && gameArray[1][0] == 'X' && gameArray[0][0] == 'X' && gameArray[2][1] == ' ') {
            gameArray[2][1] = 'O';
            cpuChoicePrint(8);
        }
        else if (gameArray[2][0] == 'O' && gameArray[2][1] == 'X' && gameArray[2][2] == 'X' && gameArray[1][0] == ' ') {
            gameArray[1][0] = 'O';
            cpuChoicePrint(4);
        }
        else if (gameArray[2][2] == 'O' && gameArray[2][0] == 'X' && gameArray[2][1] == 'X' && gameArray[1][2] == ' ') {
            gameArray[1][2] = 'O';
            cpuChoicePrint(6);
        }
        else if (gameArray[2][2] == 'O' && gameArray[1][2] == 'X' && gameArray[0][2] == 'X' && gameArray[2][1] == ' ') {
            gameArray[2][1] = 'O';
            cpuChoicePrint(8);
        }
        else if (gameArray[0][2] == 'O' && gameArray[0][0] == 'X' && gameArray[0][1] == 'X' && gameArray[1][2] == ' ') {
            gameArray[1][2] = 'O';
            cpuChoicePrint(6);
        }
        else if (gameArray[0][2] == 'O' && gameArray[1][2] == 'X' && gameArray[2][2] == 'X' && gameArray[0][1] == ' ') {
            gameArray[0][1] = 'O';
            cpuChoicePrint(2);
        }

        //4th turn counter corner fork with O in middle
        else if (gameArray[0][0] == 'X' && gameArray[1][1] == 'O' && gameArray[2][2] == 'X' && gameArray[0][1] == ' ') {
            gameArray[0][1] = 'O';
            cpuChoicePrint(2);
        }
        else if (gameArray[2][0] == 'X' && gameArray[1][1] == 'O' && gameArray[0][2] == 'X' && gameArray[1][2] == ' ') {
            gameArray[1][2] = 'O';
            cpuChoicePrint(6);
        }

        //All other scenarios
        else
            if (gameArray[1][1] == ' ') {
                gameArray[1][1] = 'O';
                cpuChoicePrint(5);
            }
            else if (gameArray[0][0] == ' ') {
                gameArray[0][0] = 'O';
                cpuChoicePrint(1);
            }
            else if (gameArray[0][2] == ' ') {
                gameArray[0][2] = 'O';
                cpuChoicePrint(3);
            }
            else if (gameArray[2][0] == ' ') {
                gameArray[2][0] = 'O';
                cpuChoicePrint(7);
            }
            else if (gameArray[2][2] == ' ') {
                gameArray[2][2] = 'O';
                cpuChoicePrint(9);
            }
            else if (gameArray[0][1] == ' ') {
                gameArray[0][1] = 'O';
                cpuChoicePrint(2);
            }
            else if (gameArray[1][0] == ' ') {
                gameArray[1][0] = 'O';
                cpuChoicePrint(4);
            }
            else if (gameArray[1][2] == ' ') {
                gameArray[1][2] = 'O';
                cpuChoicePrint(6);
            }
            else {
                gameArray[2][1] = 'O';
                cpuChoicePrint(8);
            }
    }

    displayUpdatedBoard(); //Display updated game grid board
    checkIfWin(playerOneSymbol, cpuSymbol, multiFlag, playerOneScore, otherScore); //Check if win occured       
    playerOneMove(playerOneSymbol, cpuSymbol, multiFlag, playerOneScore, otherScore); //Player One goes next
}