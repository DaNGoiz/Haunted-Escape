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
    string status = "Start";
    string input;

    Player player = NewPlayer();
    SetPlayerHelper(player);

    char map[25][100];
    newMap(map);

    // printStartMenu(15,45);

    bool gameOn = true;
    // a while loop makes sure that the game is running unless interrupted by changing gameOn = false.
    while (gameOn){
        if (status == "Start"){
            printStartMenu(15,45);
            // player starts, timer starts, game starts
            if (input == "s"){
                // player = NewPlayer();
                gameUInoshop();
                Timer(true);
                status = "InGame";
            }
            // player chooses to end the game
            if (input == "e"){
                Timer(false);
                cout << "Goodbye!" << endl;
                break;
            }
        }
            // In Game, we use InGamePlayerMove() to interpret the move of the user.
        else if (status == "InGame"){
            if (input.size() > 1) continue;
            gameUInoshop();
            Timer(true);
            status = InGamePlayerMove(input[0], player);
        }
            // Pause: if enter "c", then continue game, else enter "r" to restart the game.
        else if (status == "Pause"){
            Timer(false);
            if (input == "c"){
            Timer(true);
            status = "InGame";
            }
            if (input == "r"){
            Timer(false);
            ResetTimer();
            status = "Start";
            }
        }
            // when change to new level, generate a new map.
        else if (status == "LoadLevel"){
            Timer(false);
            newMap(map);
            status = "InGame";
        }
            // go to shop, use InShopPlayerMove to interpret the move of the user.
        else if (status == "Shop"){
            if (input.size() > 1) continue;
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
        cin >> input;
    }
}
