#include <iostream>
#include <string>
#include<sstream>
using namespace std;

bool tie = false;
string n1;
string n2;
char space[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
int row, column;
char token = 'x';

void functionone() {
    cout << "   " << space[0][0] << "   " << "|" << "   " << space[0][1] << "   " << "|" << "   " << space[0][2] << "   " << endl;
    cout << "       |       |       " << endl;
    cout << "_______|_______|_______" << endl;
    cout << "       |       |       " << endl;
    cout << "   " << space[1][0] << "   " << "|" << "   " << space[1][1] << "   " << "|" << "   " << space[1][2] << "   " << endl;
    cout << "       |       |       " << endl;
    cout << "_______|_______|_______" << endl;
    cout << "       |       |       " << endl;
    cout << "   " << space[2][0] << "   " << "|" << "   " << space[2][1] << "   " << "|" << "   " << space[2][2] << "   " << endl;
    cout << "       |       |       " << endl;
    cout << "       |       |       " << endl;
}

bool isInputValid(const string& input) {
    if (input.length() != 1)
        return false;
    char ch = input[0];
    return (ch >= '1' && ch <= '9' && space[(ch - '1') / 3][(ch - '1') % 3] != 'x' && space[(ch - '1') / 3][(ch - '1') % 3] != 'o');
}

void functiontwo() {
    string input;
    do {
        if (token == 'x') {
            cout << n1 << " Please enter a valid number (1-9): ";
        }
        else {
            cout << n2 << " Please enter a valid number (1-9): ";
        }
        cin >> input;
    } while (!isInputValid(input));

    char ch = input[0];
    row = (ch - '1') / 3;
    column = (ch - '1') % 3;

    space[row][column] = token;
    token = (token == 'x') ? 'o' : 'x';
}

bool functionthree() {
    for (int i = 0; i < 3; i++) {
        if (space[i][0] == space[i][1] && space[i][1] == space[i][2]) {
            return true;
        }
        if (space[0][i] == space[1][i] && space[1][i] == space[2][i]) {
            return true;
        }
    }

    if (space[0][0] == space[1][1] && space[1][1] == space[2][2]) {
        return true;
    }
    if (space[0][2] == space[1][1] && space[1][1] == space[2][0]) {
        return true;
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (space[i][j] != 'x' && space[i][j] != 'o') {
                return false;
            }
        }
    }

    tie = true;
    return false;
}

int main() {
    char playAgain;
    do {
        cout << "Enter the name of the first player: ";
        cin >> n1;
        cout << "Enter the name of the second player: ";
        cin >> n2;
        cout << n1 << " is player 1" << endl;
        cout << n2 << " is player 2" << endl;

        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                space[i][j] = '1' + i * 3 + j;
            }
        }

        while (!functionthree()) {
            functionone();
            functiontwo();
        }

        if (tie) {
            cout << "It's a tie!" << endl;
        }
        else {
            cout << ((token == 'x') ? n2 : n1) << " wins!" << endl;
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        
        if (playAgain == 'y' || playAgain == 'Y') {
            token = 'x';
            tie = false;
        }
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
