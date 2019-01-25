// A basic tic-tac-toe game

#include <iostream>
using namespace std;
#include "Game.h"
#include "Computer.h"
#include <string>

int main()
{
    // Ends game if true
    bool gameOver = false;
    int quit;
    int choice;

	//Class for player v player
    Game test;
	//Class for player v AI
    Computer ai;

    cout << "AI (1) or 2 player (2)" << endl;
    cin >> choice;

    if(choice == 2){

        // Sets up initial values
        test.setup();

        // Game loop
        while(quit != 99){
            cout << "Press 1 and enter to play, press 99 to quit" << endl;
            cin >> quit;
	    if(quit==99)
            	break;

            while(gameOver != true){
                test.draw();
                test.input();
                gameOver = test.testGame();
            }

            gameOver = false;
            test.reset();
        }
    }
    if (choice == 1){

        // Sets up initial values
        ai.setup();

        // Game loop
        while(quit != 99){
            cout << "Press 1 and enter to play, press 99 to quit" << endl;
            cin >> quit;
	    if(quit==99)
            	break;

            while(gameOver != true){
                ai.draw();
                ai.input();
                gameOver = ai.testGame();
            }

            gameOver = false;
            ai.reset();
        }
    }
    return 0;
}
