#include "InGamePlayerMove.h"
#include "InShopPlayerMove.h"
#include <iostream>
#include <string>
#include "get_map.h"
#include "set_map.h"
#include "print_end_menu.h"
#include "print_start_menu.h"
#include "print_victory_menu.h"
#include "UpdateInGameUI.h"
#include "timer.h"
#include "Player.h"
using namespace std;

// This is the only main program throughout the project.
// This program controls GAME STATUS. Make sure it is always one of the following: Start; InGame; Pause; LoadLevel; GameOver; Shop; Victory.
int main(){
    string status = "LoadStart";
    string input;

    Player player = NewPlayer();
    SetPlayerHelper(player);

    bool gameOn = true;
    // a while loop makes sure that the game is running unless interrupted by changing gameOn = false.
    while (gameOn){
        if (status == "LoadStart"){
            ResetTimer();
            char map[25][100];
            newMap(map);
            printStartMenu(15,45);
            status = "Start";
        }
        if (status == "Start"){
            cin >> input;
            // player starts, timer starts, game starts
            if (input == "s"){
                gameUInoshop();
                Timer(true);
                status = "InGame";
            }
            // player chooses to end the game
            if (input == "e"){
                Timer(false);
                cout << "Goodbye!" << endl;
                gameOn = false;
            }
        }
            // In Game, we use InGamePlayerMove() to interpret the move of the user.
        else if (status == "InGame"){
<<<<<<< HEAD
            if (input.size() != 1) continue;
=======
            cin >> input;
            if (input.size() > 1) continue;
>>>>>>> 70970cf3f36b86190f2ee35d58193ce56756a66f
            gameUInoshop();
            Timer(true);
            status = InGamePlayerMove(input[0], player);
        }
            // Pause: if enter "c", then continue game, else enter "r" to restart the game.
        else if (status == "Pause"){
            Timer(false);
            cin >> input;
            if (input == "c"){
            Timer(true);
            status = "InGame";
            }
            if (input == "r"){
            Timer(false);
            ResetTimer();
            status = "LoadStart";
            }
        }
            // when change to new level, generate a new map.
        else if (status == "LoadLevel"){
            Timer(false);
            char map[25][100];
            newMap(map);
            status = "InGame";
        }
            // go to shop, use InShopPlayerMove to interpret the move of the user.
        else if (status == "Shop"){
<<<<<<< HEAD
            if (input.size() != 1) continue;
=======
            cin >> input;
            if (input.size() > 1) continue;
>>>>>>> 70970cf3f36b86190f2ee35d58193ce56756a66f
            Timer(false);
            gameUIhaveshop();
            status = InShopPlayerMove(input[0], player);
        }
            // Gameover. Game stops. While loop stops.
        else if (status == "GameOver"){
            Timer(false);
            printEndMenu(15,45);
            gameOn = false;
        }
            // Victory. Game stops. While loop stops.
        else if (status == "Victory"){
            Timer(false);
            printVictoryMenu(15,45);
            gameOn = false;
        }
        else 
            cout << "Invalid Input" << endl;
        cout << status << endl; // debug
    }
}
