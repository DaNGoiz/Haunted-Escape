#include "InGamePlayerMove.h"
#include "InShopPlayerMove.h"
#include <iostream>
#include <string>
#include "get_map.h"
#include "set_map.h"
#include "print_end_menu.h"
#include "print_victory_menu.h"
#include "UpdateInGameUI.h"
#include "timer.h"
#include "Player.h"
#include "print_title_menu.h"
#include "loadlevel0.h"
#include "loadlevel1.h"
#include "loadlevel2.h"
#include "loadlevel3.h"
#include "loadlevel4.h"
#include "load_start.h"
#include "shopmenu.h"
#include "print_pause_menu.h"
using namespace std;


// This is the only main program throughout the project.
// This program controls GAME STATUS. Make sure it is always one of the following: LoadStart; Start; InGame; Pause; LoadLevel; GameOver; Shop; Victory.
int main(){
    string status = "LoadStart";
    printTitleMenu();
    string input;
    char map[25][100];
    newMap(map);
    Player player = NewPlayer();
    SetPlayerHelper(player);

    bool gameOn = true;
    // a while loop makes sure that the game is running unless interrupted by changing gameOn = false.
    while (gameOn){
        if (status == "LoadStart"){
            ResetTimer();
            newMap(map);
            int x, y;
            getPlayerPosition(x, y);
            SetPosition(player, x, y);
            loadStart();
            status = "Start";
        }
        if (status == "Start"){
            cin >> input;
            // player starts, timer starts, game starts
            if (input == "s"){
                loadLevel0();
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
            cin >> input;
            if (input.size() > 1) continue;
            Timer(true);
            status = InGamePlayerMove(input[0], player, map);
            gameUInoshop();
        }
            // Pause: if enter "c", then continue game, else enter "r" to restart the game.
        else if (status == "Pause"){
            print_pause_menu();
            Timer(false);
            cin >> input;
            if (input == "c"){
            Timer(true);
            status = "InGame";
            }
            if (input == "r"){
            clearMap(map);
            Timer(false);
            ResetTimer();
            status = "LoadStart";
            }
        }
            // when change to new level, generate a new map.
        else if (status == "LoadLevel"){
            clearMap(map);
            Timer(false);
            newMap(map);
            int x, y;
            getPlayerPosition(x, y);
            SetPosition(player, x, y);
            status = "InGame";
            if (player.Level == 2){
                loadLevel1();
                }
            else if (player.Level == 3){
                loadLevel2();
                }
            else if (player.Level == 4){
                loadLevel3();
                }   
            else if (player.Level == 5){
                loadLevel4();
                }
            }
            // go to shop, use InShopPlayerMove to interpret the move of the user.
        else if (status == "Shop"){
            shopmenu();
            cin >> input;
            if (input.size() > 1) continue;
            gameUIhaveshop();
            Timer(false);
            status = InShopPlayerMove(input[0], player);
                 
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
        else {
            cout << "Invalid Input" << endl;
            status = "InGame";
            continue;}
    }
}
