#pragma once
#include<cmath>

bool repeat = false;

void display(std::string grid[5][5]) {
    printf("\033c");
    if (repeat) {
        std::cout << "place is taken, try again: " << "\n\n";

    }
    for (int i = 0; i < 5; i++) {
        std::cout << "  ";
        for (int j = 0; j < 5; j++) {
            std::cout << grid[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void position(std::string grid[5][5], int x, std::string player) {
    int row = (x-1)/3 * 2;
    int col = (x-1) % 3 * 2;
    if (grid[row][col] == " ") {
        grid[row][col] = player;
    }
    else {
        repeat = true;
    }
}

std::string turn(std::string player) {
    if (player == "X" && !repeat) {
        player = "O";
    }
    else if (player == "O" && !repeat) {
        player = "X";
    }
    repeat = false;
    return player;
}

void xWin() {
    std::cout << "\n\n   X has won the game!\n\n   Thanks for playing!\n\n";
}

void oWin() {
    std::cout << "\n\n   O has won the game!\n\n   Thanks for playing!\n\n";
}

bool gameLogic(std::string grid[5][5], bool game) {
    game = true;
    for (int i = 0; i < 3; i++) {
        if ((grid[i*2][0] == grid[i*2][2] && grid[i*2][2] == grid[i*2][4] && grid[i*2][4] == "X") || 
            (grid[0][i*2] == grid[2][i*2] && grid[2][i*2] == grid[4][i*2] && grid[4][i*2] == "X")) {
            xWin();
            game = false;
        }
        if ((grid[i * 2][0] == grid[i * 2][2] && grid[i * 2][2] == grid[i * 2][4] && grid[i * 2][4] == "O") ||
            (grid[0][i * 2] == grid[2][i * 2] && grid[2][i * 2] == grid[4][i * 2] && grid[4][i * 2] == "O")) {
            oWin();
            game = false;
        }
    }
    if ((grid[0][0] == grid[2][2] && grid[2][2] == grid[4][4] && grid[4][4] == "X") ||
        (grid[4][0] == grid[2][2] && grid[2][2] == grid[4][0] && grid[4][0] == "X")) {
        xWin();
        game = false;
    }
    if ((grid[0][0] == grid[2][2] && grid[2][2] == grid[4][4] && grid[4][4] == "O") ||
        (grid[4][0] == grid[2][2] && grid[2][2] == grid[4][0] && grid[4][0] == "O")) {
        oWin();
        game = false;
    }
    return game;
}