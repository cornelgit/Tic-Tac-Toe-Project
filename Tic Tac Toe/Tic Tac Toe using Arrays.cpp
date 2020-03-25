// Welcome to my Tic Tac Toe game. Game has 2 modes: Single Player (against cpu) or Multiplayer (1v1).
//
//Created by: Cornel Stoica
//Date: 12/16/19
//

#include <iostream>
#include <string>
#include <ctime>
#include "windows.h" //For sleep
#include "tictactoe.h"


int main()
{
    //Start game
    displayWelcome();
    displayMenu();

    std::cout << "\n\n"; //Extra space

    return 0;
}