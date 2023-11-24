#include <iostream>
#include <tuple>
#include "get_map.h"
#include "set_map.h"
#include "Player.h"
using namespace std;
// This program aims to design the simple logic of player move in GAME.
// The program receives input as 'Char' and return GAME STATUS as string.
string InGamePlayerMove(char input){
bool p = true;
// Player player = NewPlayer();
while (p){
    // get the player current position
    int* position = GetPosition();
    int x = position[0];
    int y = position[1];
    // pause if input is 'p'
    if (input == 'p'){
        return "Pause";
    }
    else if (input == 'w'){
        // check what is in the destination
        char c = getMapDataAtPoint(x,y-1);
            // if is WALL, cannot move.
        if (c == 'X'){
            return "InGame";
        }
            // if is DOOR, if have key, then go into the door. Check loadlevel or Victory.
            // if no key, cannot move.
        else if (c == '#'){
            bool p = GetKey();
            if (p){
                char map[25][100];
                setMapDataAtPoint(x,y,'\0', map);
                setMapDataAtPoint(x,y-1,'@', map);
                int n = GetLevel();
                if (n == 5){
                    return "Victory";
                }
                else
                ChangeLevel(1);
                return "LoadLevel";
                }
            else
            return "InGame";
        }
            // if is key, go to the key and have key.
        else if (c == '!'){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x,y-1,'@',map);
            ChangeKey(true);
            return "InGame";
        }
            // if is grass, go to the grass, grass vanishes.
        else if (c == '"' | c == '\'' | c == '`' | c == ' '){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x,y-1,'@',map);
            return "InGame";
        }
            // if is heal, go to the heal
            // if there is no shield and the health is not full, then health++
        else if (c == '+'){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x,y-1,'@',map);
            int n = GetShield();
            int m = GetHealth();
            if (n == 0){
                if (m < 5){
                    ChangeHealth(1);
                }
            }
            return "InGame";
        }
            // if is gold, get gold
        else if (c == '$'){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x,y-1,'@',map);
            ChangeGold(1);
            return "InGame";
        }
            // if is throne, get to throne
            // if has shield, shield-1
            // else health -1, check if dies
        else if (c == '^'){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x,y-1,'@',map);
            int n = GetShield();
            int m = GetHealth();
            if (n == 0){
                ChangeHealth(-1);
                if (m < 1){
                    return "GameOver";
                }
                else 
                return "InGame";
            }
            else {
            ChangeShield(-1);
            }
            return "InGame";
        }
            //if is shop, go to shop
        else if (c == '='){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x,y-1,'@',map);
            return "Shop";
        }
    }

    else if (input == 'a'){
        
        char c = getMapDataAtPoint(x-1,y);
        if (c == 'X'){
            return "InGame";
        }
        else if (c == '#'){
            bool p = GetKey();
            if (p){
                char map[25][100];
                setMapDataAtPoint(x,y,'\0', map);
                setMapDataAtPoint(x-1,y,'@', map);
                int n = GetLevel();
                if (n == 5){
                    return "Victory";
                }
                else
                ChangeLevel(1);
                return "LoadLevel";
                }
            else
            return "InGame";
        }
        else if (c == '!'){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x-1,y,'@',map);
            ChangeKey(true);
            return "InGame";
        }
        else if (c == '"' | c == '\'' | c == '`' | c == ' '){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x-1,y,'@',map);
            return "InGame";
        }
        else if (c == '+'){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x-1,y,'@',map);
            int n = GetShield();
            int m = GetHealth();
            if (n == 0){
                if (m < 5){
                    ChangeHealth(1);
                }
            }
            return "InGame";
        }
        else if (c == '$'){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x-1,y,'@',map);
            ChangeGold(1);
            return "InGame";
        }
        else if (c == '^'){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x-1,y,'@',map);
            int n = GetShield();
            int m = GetHealth();
            if (n == 0){
                ChangeHealth(-1);
                if (m < 1){
                    return "GameOver";
                }
                else 
                return "InGame";
            }
            else {
            ChangeShield(-1);
            }
            return "InGame";
        }
        else if (c == '='){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x-1,y,'@',map);
            return "Shop";
        }
    }

    else if (input == 's'){
        
        char c = getMapDataAtPoint(x,y+1);
        if (c == 'X'){
            return "InGame";
        }
        else if (c == '#'){
            bool p = GetKey();
            if (p){
                char map[25][100];
                setMapDataAtPoint(x,y,'\0', map);
                setMapDataAtPoint(x,y+1,'@', map);
                int n = GetLevel();
                if (n == 5){
                    return "Victory";
                }
                else
                ChangeLevel(1);
                return "LoadLevel";
                }
            else
            return "InGame";
        }
        else if (c == '!'){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x,y+1,'@',map);
            ChangeKey(true);
            return "InGame";
        }
        else if (c == '"' | c == '\'' | c == '`' | c == ' '){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x,y+1,'@',map);
            return "InGame";
        }
        else if (c == '+'){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x,y+1,'@',map);
            int n = GetShield();
            int m = GetHealth();
            if (n == 0){
                if (m < 5){
                    ChangeHealth(1);
                }
            }
            return "InGame";
        }
        else if (c == '$'){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x,y+1,'@',map);
            ChangeGold(1);
            return "InGame";
        }
        else if (c == '^'){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x,y+1,'@',map);
            int n = GetShield();
            int m = GetHealth();
            if (n == 0){
                ChangeHealth(-1);
                if (m < 1){
                    return "GameOver";
                }
                else 
                return "InGame";
            }
            else {
            ChangeShield(-1);
            }
            return "InGame";
        }
        else if (c == '='){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x,y+1,'@',map);
            return "Shop";
        }
    }

    else if (input == 'd'){
        
        char c = getMapDataAtPoint(x+1,y);
        if (c == 'X'){
            return "InGame";
        }
        else if (c == '#'){
            bool p = GetKey();
            if (p){
                char map[25][100];
                setMapDataAtPoint(x,y,'\0', map);
                setMapDataAtPoint(x+1,y,'@', map);
                int n = GetLevel();
                if (n == 5){
                    return "Victory";
                }
                else
                ChangeLevel(1);
                return "LoadLevel";
                }
            else
            return "InGame";
        }
        else if (c == '!'){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x+1,y,'@',map);
            ChangeKey(true);
            return "InGame";
        }
        else if (c == '"' | c == '\'' | c == '`' | c == ' '){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x+1,y,'@',map);
            return "InGame";
        }
        else if (c == '+'){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x+1,y,'@',map);
            int n = GetShield();
            int m = GetHealth();
            if (n == 0){
                if (m < 5){
                    ChangeHealth(1);
                }
            }
            return "InGame";
        }
        else if (c == '$'){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x+1,y,'@',map);
            ChangeGold(1);
            return "InGame";
        }
        else if (c == '^'){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x+1,y,'@',map);
            int n = GetShield();
            int m = GetHealth();
            if (n == 0){
                ChangeHealth(-1);
                if (m < 1){
                    return "GameOver";
                }
                else 
                return "InGame";
            }
            else {
            ChangeShield(-1);
            }
            return "InGame";
        }
        else if (c == '='){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x+1,y,'@',map);
            return "Shop";
        }
    }
}
}




