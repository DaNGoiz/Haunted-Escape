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
using namespace std;
// This is the only main program throughout the project.
// This program controls GAME STATUS. Make sure it is always one of the following: Start; InGame; Pause; LoadLevel; GameOver; Shop; Victory.
int main(){
    string status = "Start";
    string input;
    bool gameOn = true;
    // a while loop makes sure that the game is running unless interrupted by changing gameOn = false.
    while (gameOn){
        string input;
        cin >> input;
        if (status == "Start"){
            printStartMenu();
            // player starts, timer starts, game starts
            if (input == "s"){
                printGameMenu();
                Timer(true);
                status = "InGame";
            }
            // player chooses to end the game
            if (input == "e"){
                Timer(false);
                status = "GameOver";
            }
        }
            // In Game, we use InGamePlayerMove() to interpret the move of the user.
        else if (status == "InGame"){
            gameUInoshop();
            Timer(true);
            status = InGamePlayerMove();
        }
            // Pause: if enter "c", then continue game, else enter "r" to restart the game.
        else if (status == "Pause"){
            Timer(false);
            if (input == "c"){
            Timers(true);
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
            char map[25][100];
            newMap(map);
            status = "InGame";
        }
            // go to shop, use InShopPlayerMove to interpret the move of the user.
        else if (status == "Shop"){
            Timer(false);
            gameUIhaveshop();
            status = InShopPlayerMove();
        }
            // Gameover. Game stops. While loop stops.
        else if (status == "GameOver"){
            Timer(false);
            printEndMenu();
            gameOn = false;
        }
            // Victory. Game stops. While loop stops.
        else if (status == "Victory"){
            Timer(false);
            printVictoryMenu();
            gameOn = false;
        }
        else 
        cout << "Invalid Input" << endl;
    }
}
