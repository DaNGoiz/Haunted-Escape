#include <iostream>
#include <tuple>
#include "get_map.h"
#include "set_map.h"
//#include "set_playerdata.h"
using namespace std;
string InGamePlayerMove(char input){
bool p = true;
while (p){
    int a[2]= GetPosition();
    int x = a[0];
    int y = a[1];
    if (input == 'p'){
        return "Pause";
    }
    else if (input == 'w'){
        
        char c = getMapDataAtPoint(x,y-1);
        if (c == 'X'){
            return "InGame";
        }
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
        else if (c == '!'){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x,y-1,'@',map);
            ChangeKey(true);
            return "InGame";
        }
        else if (c == '"' | c == '\'' | c == '`' | c == ' '){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x,y-1,'@',map);
            return "InGame";
        }
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
        else if (c == '$'){
            char map[25][100];
            setMapDataAtPoint(x,y,'\0', map);
            setMapDataAtPoint(x,y-1,'@',map);
            ChangeGold(1);
            return "InGame";
        }
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

int main(){
char input;
cin >> input;
InGamePlayerMove(input);
}



