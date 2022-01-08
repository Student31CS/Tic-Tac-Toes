#include <iostream>
#include <vector>
#include <unistd.h>
#include "tic_head.hpp"


// Two players take turns playing Tic-Tac-Toe
// The winner is determined when they have three consecutive Xs or Os
// Three consecutive Xs or Os can be in a row, column, or diagonal










int main() {



    int square;
    int player1;
    int player2;





        






    // Introduction
    std::cout << "===========================\n";
    std::cout << "Welcome to TJ's Tic-Tac-Toe!\n";
    std::cout << "===========================\n";
    sleep(2);
    std::cout << "This is a two player game, so make sure you have a friend.\n";
    sleep(3);
    std::cout << "Player 1 will be 'X' and Player 2 will be 'O'.\n";
    sleep(3);
    std::cout << "Try to form a straight line by row, column, or diagonally to win the game!\n";
    sleep(3);


    // Coin Toss Determines who will go first
    srand(time(NULL));
    coin_toss();

    sleep(3);


    // Prints numbered board to example user input
    grid_example();

    sleep(2);


    // Gameplay. Loop until full board, check_win function will determine end of game
    int k = 0;
    while (k < 9) {

        if (check_win() == 1 || check_win() == 2) {
            break;
        }

        else {
        player1_turn();
        k++;
        }

        if (check_win() == 1 || check_win() == 2) {
            break;
        }
        else if (k < 9) {
            player2_turn();
            k++;
        }
        else {
            break;
        }
    }

    sleep(2);
    if (check_win() == 1) {
        player1 ++;
        std::cout << "\n\n\n\n\n===================\n";
        std::cout << "PLAYER 1 WINS!!\n";
        std::cout << "===================\n\n";
        grid();
    }
    else if (check_win() == 2) {
        player2 ++;
        std::cout << "\n\n\n\n\n===================\n";
        std::cout << "PLAYER 2 WINS!!\n";
        std::cout << "===================\n\n";
        grid();
    }
    else {
        std::cout << "\n\n\n\n\n===================\n";
        std::cout << "IT'S A TIE!!\n";
        std::cout << "===================\n\n";
        grid();
    }

return 0;
}