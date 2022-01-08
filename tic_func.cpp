#include <iostream>
#include "tic_head.hpp" 
#include <vector>
#include <unistd.h>


std::string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
int choice;
int choice_check;


void player1_choice() {
    board[choice - 1] = "X";
}

void player2_choice() {
    board[choice - 1] = "0";
}

void player1_pick() {
    std::cout << "\n\nPlease pick a square:\n";
    std::cin >> choice_check;
}

void player2_pick() {
    std::cout << "\n\nPlease pick a square:\n";
    std::cin >> choice_check;
}

void player1_turn() {
    std::cout << "=================================\n";
    std::cout << "Tic-Tac-Toe    Player One's Turn!\n";
    std::cout << "=================================\n";
    sleep(2);
    grid();
    sleep(2);
    while (choice_check == choice) {
        player1_pick();
        if (board[choice_check - 1] == " ") {
            choice = choice_check;
            player1_choice();
            break;
        }
        else {
            std::cout << "You picked an invalid option.\n";
            sleep(2);
            choice_check = choice;
        }
    }

        std::cout << ".";
        sleep(1);
        std::cout << ".";
        sleep(1);
        std::cout << ".\n";
        sleep(1);
        
}

void player2_turn() {
    std::cout << "=================================\n";
    std::cout << "Tic-Tac-Toe    Player Two's Turn!\n";
    std::cout << "=================================\n";
    sleep(2);
    grid();
    sleep(2);
    while (choice_check == choice) {
        player2_pick();
        if (board[choice_check - 1] == " ") {
            choice = choice_check;
            player2_choice();
            break;
        }
        else {
            std::cout << "You picked an invalid option.\n";
            sleep(2);
            choice_check = choice;
        }
    }

        std::cout << ".";
        sleep(1);
        std::cout << ".";
        sleep(1);
        std::cout << ".\n";
        sleep(1);
        
}

int check_win() {
    int check = 0;
    if (board[0] == "X" && board[1] == "X" && board[2] == "X") {
        check = 1;
        return check;
    
    }
    else if (board[3] == "X" && board[4] == "X" && board[5] == "X") {
        check = 1;
        return check;
   
    }
    else if (board[6] == "X" && board[7] == "X" && board[8] == "X") {
        check = 1;
        return check;

    }
    else if (board[0] == "X" && board[3] == "X" && board[6] == "X") {
        check = 1;
        return check;

    }
    else if (board[1] == "X" && board[4] == "X" && board[7] == "X") {
        check = 1;
        return check;

    }
    else if (board[2] == "X" && board[5] == "X" && board[8] == "X") {
        check = 1;
        return check;

    }
    else if (board[0] == "X" && board[4] == "X" && board[8] == "X") {
        check = 1;
        return check;

    }
    else if (board[2] == "X" && board[4] == "X" && board[6] == "X") {
        check = 1;
        return check;

    }
    else if (board[0] == "O" && board[1] == "O" && board[2] == "O") {
        check = 2;
        return check;
    
    }
    else if (board[3] == "O" && board[4] == "O" && board[5] == "O") {
        check = 2;
        return check;

    }
    else if (board[6] == "O" && board[7] == "O" && board[8] == "O") {
        check = 2;
        return check;

    }
    else if (board[0] == "O" && board[3] == "O" && board[6] == "O") {
        check = 2;
        return check;

    }
    else if (board[1] == "O" && board[4] == "O" && board[7] == "O") {
        check = 2;
        return check;

    }
    else if (board[2] == "O" && board[5] == "O" && board[8] == "O") {
        check = 2;
        return check;

    }
    else if (board[0] == "O" && board[4] == "O" && board[8] == "O") {
        check = 2;
        return check;

    }
    else if (board[2] == "O" && board[4] == "O" && board[6] == "O") {
        check = 2;
        return check;

    }
    else {
        return check;

    }
}




void grid_example() {
        std::cout << "Squares will be numbered from left to right and top to bottom.\n";
        sleep(3);
        std::cout << "For example, if you wish to select the top left square, type '1', for the middle square type '5' etc...\n";
        sleep(4);

    std::cout << "     |     |      \n";
 
    std::cout << "  1 " << " |  2" << "  |  3 "  << "\n";
 
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
 
    std::cout << "  4 " << " |  5" << "  |  6 " << "\n";
 
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
 
    std::cout << "  7 "  << " |  8" << "  |  9 " << "\n";
    std::cout << "     |     |      \n";
 
    std::cout << "\n";

}

// Determines which player goes first
void coin_toss() {


    int pick;
    
    std::cout << "It's time to pick who goes first\n";
    sleep(2);
    std::cout << "Any player, please pick a number:\n";
    std::cout << "1) Heads\n";
    std::cout << "2) Tails\n";
    sleep(2);
    std::cin >> pick;

        if (pick == 1) {
            std::cout << "You picked heads.\n";
        }
        else {
            std::cout << "You picked tails.\n";
        }

    int result = rand() % 2 + 1;


    sleep(2);

    if (pick == 1 && result == 1) {
        std::cout << "Heads wins, you are Player 1\n";
    }
    else if (pick == 2 && result == 2) {
        std::cout << "Tails wins, you are Player 1\n";
    }
    else if (pick == 1 && result == 2) {
        std::cout << "Tails wins, you are Player 2\n";
    }
    else if (pick == 2 && result == 1) { 
        std::cout << "Heads wins, you are Player 2\n";
    }
    else {
        std::cout << "Something went wrong, you are Player 2\n";
    }

}

// Prints the board to users
void grid() {
 
    std::cout << "     |     |      \n";
 
    std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
 
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
 
    std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
 
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
 
    std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
    std::cout << "     |     |      \n";
 
    std::cout << "\n";
}