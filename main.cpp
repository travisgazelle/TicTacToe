//  Created by Travis Cassell on 7/25/22.

#include <iostream>
#include <cstdlib>

using namespace std;

void user_query(int);   // Save user choice in "spaces_taken" array
void print_board();     // Print the current board to console
void cpu_move();        // Logic for bot move
bool game_over(string); // Test if game has ended

struct choice {
    int space;
    string letter;
    bool occupied;
};

choice spaces_taken[9];  // Array to hold current data of playing board
string winner = "";

int main(int argc, const char * argv[]) {
    
    // Pre-fill board
    for(int x = 0; x < 9; x++) {
        choice *c = new choice();
        c->space = x + 1;
        c->letter = to_string(x + 1);
        c->occupied = false;
        spaces_taken[x] = *c;
    }

    int choice;
    bool player_won, bot_won = false;
    
    srand (time(NULL));
    
    cout << "Welcome to Trav's Tic Tac Toe! \n";
    cout << "You will be presented with a board numbered from 1 - 9 \n";
    cout << "Enter the number of the space that you would like to occupy \n";
    cout << "After your turn, the computer will choose a space to occupy \n";
    cout << "You will be \'X\' and the bot will be \'O\' \n";
    cout << "Are you smarter than a computer? \n\n";
      
    // Loop through until three "X's" or three "O's" are found in a row
    do {
        print_board();
        cout << endl;
        cout << "Select your space... ";
        cin >> choice;
        while(spaces_taken[choice - 1].occupied == true) {
            cout << "Error, space is already occupied. Select another space... ";
            cin >> choice;
        }
        user_query(choice);
        cpu_move();
        player_won = game_over("X");
        bot_won = game_over("O");
    }
    while(player_won == false && bot_won == false);
    
    if (player_won == true) {
        cout << "YOU WIN! \n";
    }
    else {
        cout << "YOU LOSE! \n";
    }
    
    return 0;
}

void user_query(int space) {
    spaces_taken[space - 1].letter = "X";
    spaces_taken[space - 1].occupied = true;
}

void print_board() {
    for(int y = 0; y < 9; y++) {
        cout << spaces_taken[y++].letter << "|" <<
        spaces_taken[y++].letter << "|" <<
        spaces_taken[y].letter << "|\n";
    }
}

void cpu_move() {
    int num;
    do {
        num = rand() % 9 + 1;
    }
    while(spaces_taken[num].occupied == true);
    
    spaces_taken[num].letter = "O";
    spaces_taken[num].occupied = true;
}

bool game_over(string letter) {
    if (spaces_taken[0].letter == letter &&
        spaces_taken[1].letter == letter &&
        spaces_taken[2].letter == letter) {
        winner = letter;
        //cout << "1";
        return true;
    }
    else if (spaces_taken[3].letter == letter &&
             spaces_taken[4].letter == letter &&
             spaces_taken[5].letter == letter) {
        winner = letter;
        //cout << "2";
        return true;
    }
    else if (spaces_taken[6].letter == letter &&
             spaces_taken[7].letter == letter &&
             spaces_taken[8].letter == letter) {
        winner = letter;
        //cout << "3";
        return true;
    }
    else if (spaces_taken[0].letter == letter &&
             spaces_taken[3].letter == letter &&
             spaces_taken[6].letter == letter) {
        winner = letter;
        //cout << "4";
        return true;
    }
    else if (spaces_taken[1].letter == letter &&
             spaces_taken[4].letter == letter &&
             spaces_taken[7].letter == letter) {
        winner = letter;
        //cout << "5";
        return true;
    }
    else if (spaces_taken[2].letter == letter &&
             spaces_taken[5].letter == letter &&
             spaces_taken[8].letter == letter) {
        winner = letter;
        //cout << "6";
        return true;
    }
    else if (spaces_taken[0].letter == letter &&
             spaces_taken[4].letter == letter &&
             spaces_taken[8].letter == letter) {
        winner = letter;
        //cout << "7";
        return true;
    }
    else if (spaces_taken[2].letter == letter &&
             spaces_taken[3].letter == letter &&
             spaces_taken[6].letter == letter) {
        winner = letter;
        //cout << "8";
        return true;    }
    else {
        return false;
    }
}
