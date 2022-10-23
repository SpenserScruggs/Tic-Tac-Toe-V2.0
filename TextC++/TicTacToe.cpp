#include<iostream>
#include<limits>
#define NOMINMAX
#include<Windows.h>
#include"MyFunction.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

string grid[5][5] = { {" ", "|", " ", "|", " "}, {"-----"}, {" ", "|", " ", "|", " "}, {"-----"}, {" ", "|", " ", "|", " "}};
bool game = true;
string player = "X";

int main()
{
    cout << " --- Welcome to TicTacToe! --- \n\n";
    while (game) {
        int x = 0;
        while ((cout << "Enter a position from 1 to 9: ") && !(cin >> x) || x < 1 || x > 9) {
            cout << "\nThat was not an integer from 1 to 9\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        cout << endl;
        position(grid, x, player);
        display(grid);
        player = turn(player);
        game = gameLogic(grid, game);
    }
}


