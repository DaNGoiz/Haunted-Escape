//#include "InGamePlayerMover.h"
#include <iostream>
#include <String>
#include "get_map.h"
#include "set_map.h"
using namespace std;
int main(){
    string status = "Start";
    string input;
    bool gameOn = true;
    while (gameOn){
        string input;
        cin >> input;
        if (status == "Start"){
            printStartMenu();
            if (input == "s"){
                printGameMenu();
                status = "InGame";
            }
            if (input == "e"){
                status = "GameOver";
            }
        }
        else if (status == "InGame"){
            status = InGamePlayerMove();
        }
        else if (status == "Pause"){
            Timerstop();
            if (input == "c"){
            Timerstart();
            status = "InGame";
            }
        }
        else if (status == "LoadLevel"){
            char map[25][100];
            newMap(map);
            status = "InGame";
        }
        else if (status == "Shop"){
            printShopMenu();
            status = InShopPlayerMove();
        }
        else if (status == "GameOver"){
            printEndMenu();
            gameOn = false;
        }
        else if (status == "Victory"){
            printVictoryMenu();
            gameOn = false;
        }
        else 
        cout << "Invalid Input" << endl;
    }
}