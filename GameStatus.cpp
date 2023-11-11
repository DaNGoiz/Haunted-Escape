// #include "InGamePlayerMove.h"
#include <iostream>
#include <string>
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
                Timer(true);
                status = "InGame";
            }
            if (input == "e"){
                Timer(false);
                status = "GameOver";
            }
        }
        else if (status == "InGame"){
            Timer(true);
            status = InGamePlayerMove();
        }
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
        else if (status == "LoadLevel"){
            Timer(false);
            char map[25][100];
            newMap(map);
            status = "InGame";
        }
        else if (status == "Shop"){
            Timer(false);
            printShopMenu();
            status = InShopPlayerMove();
        }
        else if (status == "GameOver"){
            Timer(false);
            printEndMenu();
            gameOn = false;
        }
        else if (status == "Victory"){
            Timer(false);
            printVictoryMenu();
            gameOn = false;
        }
        else 
        cout << "Invalid Input" << endl;
    }
}
