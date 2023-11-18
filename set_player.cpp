#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

//Player's structure
struct Player{
    int Health;
    int Shield;
    int Gold;
    int x,y;
    bool Key;
    int Level;
};

//Give the player initial data
Player p;
Player p ={5,0,0,50,25,false,1};

//Initialize the level of game
int Level=1;

//Operations on player's data
void ChangeHealth(int change){
    p.Health=p.Health+change;

}

void ChangeShield(int change){
    p.Shield=p.Shield+change;
}

void ChangeGold(int change){
    p.Gold=p.Gold+change;
}

void ChangeKey(bool hasKey){
    p.Key=hasKey;
}

void SetLevel(int level){
    Level=level;
}

void ChangeLevel() {
    Level++;
}

void NewPlayer(){
    p ={5,0,0,50,25,false,1};
}

// int main(){
//     //commend towards the change of setting
//     return 0;
// }