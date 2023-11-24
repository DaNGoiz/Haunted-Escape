#include <iostream>
#include <tuple>
#include "get_map.h"
#include "set_map.h"
#include "Player.h"
using namespace std;
// This program aims to design the simple logic of player move in GAME.
// The program receives input as 'Char' and return GAME STATUS as string.
string InGamePlayerMove(char input, Player& player, char map[25][100]){
    // get the player current position
    int* position = GetPosition();
    int x = position[0];
    int y = position[1];
    // pause if input is 'p'
    if (input == 'p'){
        // cout << x << "," << y;
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
                setMapDataAtPoint(x,y,' ', map);
                setMapDataAtPoint(x,y-1,'@', map);
                ChangePosition(player,0,-1);
                int n = GetLevel();
                if (n == 5){
                    return "Victory";
                }
                else
                ChangeLevel(player,1);
                return "LoadLevel";
                }
            else
            return "InGame";
        }
            // if is key, go to the key and have key.
        else if (c == '!'){
            setMapDataAtPoint(x,y,' ', map);
            setMapDataAtPoint(x,y-1,'@',map);
            ChangePosition(player,0,-1);
            ChangeKey(player,true);
            return "InGame";
        }
            // if is grass, go to the grass, grass vanishes.
        else if (c == '"' || c == '\'' || c == '`' || c == ' '){
            setMapDataAtPoint(x,y,' ', map);
            setMapDataAtPoint(x,y-1,'@',map);
            ChangePosition(player,0,-1);
            return "InGame";
        }
            // if is heal, go to the heal
            // if there is no shield and the health is not full, then health++
        else if (c == '+'){
            setMapDataAtPoint(x,y,' ', map);
            setMapDataAtPoint(x,y-1,'@',map);
            ChangePosition(player,0,-1);
            int n = GetShield();
            int m = GetHealth();
            if (n == 0){
                if (m < 5){
                    ChangeHealth(player,1);
                }
            }
            return "InGame";
        }
            // if is gold, get gold
        else if (c == '$'){
            setMapDataAtPoint(x,y,' ', map);
            setMapDataAtPoint(x,y-1,'@',map);
            ChangePosition(player,0,-1);
            ChangeGold(player,1);
            return "InGame";
        }
            // if is throne, get to throne
            // if has shield, shield-1
            // else health -1, check if dies
        else if (c == '^'){
            setMapDataAtPoint(x,y,' ', map);
            setMapDataAtPoint(x,y-1,'@',map);
            ChangePosition(player,0,-1);
            int n = GetShield();
            int m = GetHealth();
            if (n == 0){
                ChangeHealth(player,-1);
                if (m < 1){
                    return "GameOver";
                }
                else 
                return "InGame";
            }
            else {
            ChangeShield(player,-1);
            }
            return "InGame";
        }
            //if is shop, go to shop
        else if (c == '='){
            setMapDataAtPoint(x,y,' ', map);
            setMapDataAtPoint(x,y-1,'@',map);
            ChangePosition(player,0,-1);
            return "Shop";
        }
        else{
            setMapDataAtPoint(x,y,' ',map);
            setMapDataAtPoint(x,y-1,'@',map);
            ChangePosition(player,0,-1);
            return "InGame";
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
                setMapDataAtPoint(x,y,' ', map);
                setMapDataAtPoint(x-1,y,'@', map);
                ChangePosition(player,-1,0);
                int n = GetLevel();
                if (n == 5){
                    return "Victory";
                }
                else
                ChangeLevel(player,1);
                return "LoadLevel";
                }
            else
            return "InGame";
        }
        else if (c == '!'){
            setMapDataAtPoint(x,y,' ', map);
            setMapDataAtPoint(x-1,y,'@',map);
            ChangePosition(player,-1,0);
            ChangeKey(player,true);
            return "InGame";
        }
        else if (c == '"' || c == '\'' || c == '`' || c == ' '){
            setMapDataAtPoint(x,y,' ', map);
            setMapDataAtPoint(x-1,y,'@',map);
            ChangePosition(player,-1,0);
            return "InGame";
        }
        else if (c == '+'){
            setMapDataAtPoint(x,y,' ', map);
            setMapDataAtPoint(x-1,y,'@',map);
            ChangePosition(player,-1,0);
            int n = GetShield();
            int m = GetHealth();
            if (n == 0){
                if (m < 5){
                    ChangeHealth(player,1);
                }
            }
            return "InGame";
        }
        else if (c == '$'){
            setMapDataAtPoint(x,y,' ', map);
            setMapDataAtPoint(x-1,y,'@',map);
            ChangePosition(player,-1,0);
            ChangeGold(player,1);
            return "InGame";
        }
        else if (c == '^'){
            setMapDataAtPoint(x,y,' ', map);
            setMapDataAtPoint(x-1,y,'@',map);
            ChangePosition(player,-1,0);
            int n = GetShield();
            int m = GetHealth();
            if (n == 0){
                ChangeHealth(player,-1);
                if (m < 1){
                    return "GameOver";
                }
                else 
                return "InGame";
            }
            else {
            ChangeShield(player,-1);
            }
            return "InGame";
        }
        else if (c == '='){
            setMapDataAtPoint(x,y,' ', map);
            setMapDataAtPoint(x-1,y,'@',map);
            ChangePosition(player,-1,0);
            return "Shop";
        }
        else{
            setMapDataAtPoint(x,y,' ',map);
            setMapDataAtPoint(x-1,y,'@',map);
            ChangePosition(player,-1,0);
            return "InGame";
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
                setMapDataAtPoint(x,y,' ', map);
                setMapDataAtPoint(x,y+1,'@', map);
                ChangePosition(player,0,1);
                int n = GetLevel();
                if (n == 5){
                    return "Victory";
                }
                else
                ChangeLevel(player,1);
                return "LoadLevel";
                }
            else
            return "InGame";
        }
        else if (c == '!'){
            setMapDataAtPoint(x,y,' ', map);
            setMapDataAtPoint(x,y+1,'@',map);
            ChangePosition(player,0,1);
            ChangeKey(player,true);
            return "InGame";
        }
        else if (c == '"' || c == '\'' || c == '`' || c == ' '){
            setMapDataAtPoint(x,y,' ', map);
            setMapDataAtPoint(x,y+1,'@',map);
            ChangePosition(player,0,1);
            return "InGame";
        }
        else if (c == '+'){
            setMapDataAtPoint(x,y,' ', map);
            setMapDataAtPoint(x,y+1,'@',map);
            ChangePosition(player,0,1);
            int n = GetShield();
            int m = GetHealth();
            if (n == 0){
                if (m < 5){
                    ChangeHealth(player,1);
                }
            }
            return "InGame";
        }
        else if (c == '$'){
            setMapDataAtPoint(x,y,' ', map);
            setMapDataAtPoint(x,y+1,'@',map);
            ChangePosition(player,0,1);
            ChangeGold(player,1);
            return "InGame";
        }
        else if (c == '^'){
            setMapDataAtPoint(x,y,' ', map);
            setMapDataAtPoint(x,y+1,'@',map);
            ChangePosition(player,0,1);
            int n = GetShield();
            int m = GetHealth();
            if (n == 0){
                ChangeHealth(player,-1);
                if (m < 1){
                    return "GameOver";
                }
                else 
                return "InGame";
            }
            else {
            ChangeShield(player,-1);
            }
            return "InGame";
        }
        else if (c == '='){
            setMapDataAtPoint(x,y,' ', map);
            setMapDataAtPoint(x,y+1,'@',map);
            ChangePosition(player,0,1);
            return "Shop";
        }
        else{
            setMapDataAtPoint(x,y,' ',map);
            setMapDataAtPoint(x,y+1,'@',map);
            ChangePosition(player,0,1);
            return "InGame";
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
                setMapDataAtPoint(x,y,' ', map);
                setMapDataAtPoint(x+1,y,'@', map);
                ChangePosition(player,1,0);
                int n = GetLevel();
                if (n == 5){
                    return "Victory";
                }
                else
                ChangeLevel(player,1);
                return "LoadLevel";
                }
            else
            return "InGame";
        }
        else if (c == '!'){
            setMapDataAtPoint(x,y,' ', map);
            setMapDataAtPoint(x+1,y,'@',map);
            ChangePosition(player,1,0);
            ChangeKey(player,true);
            return "InGame";
        }
        else if (c == '"' || c == '\'' || c == '`' || c == ' '){
            setMapDataAtPoint(x,y,' ', map);
            setMapDataAtPoint(x+1,y,'@',map);
            ChangePosition(player,1,0);
            return "InGame";
        }
        else if (c == '+'){
            setMapDataAtPoint(x,y,' ', map);
            setMapDataAtPoint(x+1,y,'@',map);
            ChangePosition(player,1,0);
            int n = GetShield();
            int m = GetHealth();
            if (n == 0){
                if (m < 5){
                    ChangeHealth(player,1);
                }
            }
            return "InGame";
        }
        else if (c == '$'){
            setMapDataAtPoint(x,y,' ', map);
            setMapDataAtPoint(x+1,y,'@',map);
            ChangePosition(player,1,0);
            ChangeGold(player,1);
            return "InGame";
        }
        else if (c == '^'){
            setMapDataAtPoint(x,y,' ', map);
            setMapDataAtPoint(x+1,y,'@',map);
            ChangePosition(player,1,0);
            int n = GetShield();
            int m = GetHealth();
            if (n == 0){
                ChangeHealth(player,-1);
                if (m < 1){
                    return "GameOver";
                }
                else 
                return "InGame";
            }
            else {
            ChangeShield(player,-1);
            }
            return "InGame";
        }
        else if (c == '='){
            setMapDataAtPoint(x,y,' ', map);
            setMapDataAtPoint(x+1,y,'@',map);
            ChangePosition(player,1,0);
            return "Shop";
        }
        else{
            setMapDataAtPoint(x,y,' ',map);
            setMapDataAtPoint(x+1,y,'@',map);
            ChangePosition(player,1,0);
            return "InGame";
        }
    }
}





