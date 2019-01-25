//  Class file for a basic tic-tac-toe game

#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

class Game{

// Setting up variables
private:
    bool gameOver;
    string  one,two,three,four,five,
            six,seven,eight,nine;

    int value;
    int p1Score, p2Score; // Keeps track of scores
    int boardCheck[9];    // This array keeps track of which board squares are taken
                          // (1 is taken, 0 is empty
public:
    bool testGame()
        { return gameOver; }

    // Sets game loop sentinel value to false and
    // initialize values
    void setup(){
        gameOver = false;
        one = "7";
        two = "8";
        three = "9";
        four = "4";
        five = "5";
        six = "6";
        seven = "1";
        eight = "2";
        nine = "3";
        for(int i = 0; i < 9; i++){
            boardCheck[i] = 0;
        }
        p1Score = 0;
        p2Score = 0;

        cout << "-Tic-Tac-Toe- Tips" << endl;
        cout << "*Use the number pad to select a square\n";
        cout << "*P1 is X, P2 is O" << endl << endl;
    }

    //Rest board after game has been played
    void reset(){
        one = "7";
        two = "8";
        three = "9";
        four = "4";
        five = "5";
        six = "6";
        seven = "1";
        eight = "2";
        nine = "3";

        for(int i = 0; i < 9; i++){
            boardCheck[i] = 0;
        }
    }

    //Function draws board
    void draw(){
        system("cls");
        cout << "-Tic-Tac-Toe-          Tip:" << endl;
        cout << "Score(2+ per game)     Use the number pad to select a square" << endl;
        cout << "P1 - " << p1Score << " P2 - " << p2Score << endl;
        cout << "+---+---+---+" << endl;
        cout << "| " << one << " | " << two << " | " << three  << " |" << endl;
        cout << "+---+---+---+" << endl;
        cout << "| " << four << " | " << five << " | " << six << " |" << endl;
        cout << "+---+---+---+" << endl;
        cout << "| " << seven << " | " << eight << " | " << nine << " |" << endl;
        cout << "+---+---+---+" << endl << endl;
    }

    // Logic for winning and losing and adding scores
    void logic(){
        if(one == two && two == three){
            if(!one.compare("X"))
                p1Score++;
            if (!one.compare("O"))
                p2Score = p2Score + 2;
            gameOver = true;
        }
        else if (four == five && five == six){
            if(!four.compare("X"))
                p1Score++;
            if (!four.compare("O"))
                p2Score = p2Score + 2;
            gameOver = true;
        }
        else if (seven == eight && eight == nine){
            if(!seven.compare("X"))
                p1Score++;
            if (!seven.compare("O"))
                p2Score = p2Score + 2;
            gameOver = true;
        }
        else if (one == four && four == seven){
            if(!one.compare("X"))
                p1Score++;
            if (!one.compare("O"))
                p2Score = p2Score + 2;
            gameOver = true;
        }
        else if (two == five && five == eight){
            if(!two.compare("X"))
                p1Score++;
            if (!two.compare("O"))
                p2Score = p2Score + 2;
            gameOver = true;
        }
        else if (three == six && six == nine){
            if(!three.compare("X"))
                p1Score++;
            if (!three.compare("O"))
                p2Score = p2Score + 2;
            gameOver = true;
        }
        else if (one == five && five == nine){
            if(!one.compare("X"))
                p1Score++;
            if (!one.compare("O"))
                p2Score = p2Score + 2;
            gameOver = true;
        }
        else if(three == five && five == seven){
            if(!three.compare("X"))
                p1Score++;
            if (!three.compare("O"))
                 p2Score = p2Score + 2;
            gameOver = true;
        }
        else if(one != "1" && two != "2" && three != "3"&&
               four != "4" && five != "5" && six != "6" &&
               seven != "7" && eight != "8" && nine != "9")
            { gameOver = true; }
        else
            gameOver = false;

    }
    void input(){
        // Takes P1 input and replaces board piece
        cout << "It is P1 Turn:" << endl;
        cin >> value;

        // Loop to check for taken square
        while (boardCheck[value - 1] == 1){
            cout << "Square is already taken, try again:" << endl;
            cin >> value;
        }
        switch(value){
            case 7: one = "X"; boardCheck[6] = 1; break;
            case 8: two = "X"; boardCheck[7] = 1; break;
            case 9: three = "X"; boardCheck[8] = 1; break;
            case 4: four = "X"; boardCheck[3] = 1; break;
            case 5: five = "X"; boardCheck[4] = 1; break;
            case 6: six = "X"; boardCheck[5] = 1; break;
            case 1: seven = "X"; boardCheck[0] = 1; break;
            case 2: eight = "X"; boardCheck[1] = 1; break;
            case 3: nine = "X"; boardCheck[2] = 1; break;
        }


        draw(); //Resets board after P1 turn
        logic(); // Check for P1 win / tie

        // Takes P2 input and replaces board piece
        if(!gameOver){
            cout << "P2 turn:" << endl;
            cin >> value;

        // Loop to check for taken square
        while (boardCheck[value - 1] == 1){
            cout << "Square is already taken, try again:" << endl;
            cin >> value;
        }
        switch(value){
            case 7: one = "O"; boardCheck[6] = 1; break;
            case 8: two = "O"; boardCheck[7] = 1; break;
            case 9: three = "O"; boardCheck[8] = 1; break;
            case 4: four = "O"; boardCheck[3] = 1; break;
            case 5: five = "O"; boardCheck[4] = 1; break;
            case 6: six = "O"; boardCheck[5] = 1; break;
            case 1: seven = "O"; boardCheck[0] = 1; break;
            case 2: eight = "O"; boardCheck[1] = 1; break;
            case 3: nine = "O"; boardCheck[2] = 1; break;
        }

        }
        draw(); // Resets board after P2 turn
        logic(); // Checks for P2 win / tie
    }
};
#endif // GAME_H
