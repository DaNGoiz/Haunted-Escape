#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;
// Initialize the player at the begining
struct Player {
    int Health;
    int Shield;
    int Gold;
    int x, y;
    bool Key;
    int Level;
};
// Initialize the level of game
int Level = 1;

// Print all the data of player
Player GetPlayerHelper() {
    ifstream ifs("Player.log");
    if (ifs.fail()) {
        cout << "Error in file opening" << endl;
        exit(1);
    }
    string line;
    int id = 1;
    Player p;
    while (getline(ifs, line)) {
        stringstream ss(line);
        string part;
        int cur = 0;
        while (getline(ss, part, ':')) {
            cur++;
            if (cur != 2) {
                continue;
            }
            if (id == 1) {
                p.Health = stoi(part);
            } else if (id == 2) {
                p.Shield = stoi(part);
            } else if (id == 3) {
                p.Gold = stoi(part);
            } else if (id == 4) {
                stringstream ss2(part);
                string part2;
                int cur2 = 0;
                while (getline(ss2, part2, ',')) {
                    cur2++;
                    if (cur2 == 1) {
                        p.x = stoi(part2);
                    } else if (cur2 == 2) {
                        p.y = stoi(part2);
                    }
                }
            } else if (id == 5) {
                if (part == "true") {
                    p.Key = true;
                } else {
                    p.Key = false;
                }
            } else if (id == 6) {
                p.Level = stoi(part);
            }
            id++;
        }
    }
    ifs.close();
    return p;
}

void SetPlayerHelper(Player& p) {
    ofstream ofs("Player.log");
    if (ofs.fail()) {
        cout << "Error in file opening" << endl;
        exit(1);
    }
    ofs << "Health: " << p.Health << endl;
    ofs << "Shield: " << p.Shield << endl;
    ofs << "Gold: " << p.Gold << endl;
    ofs << "Position: " << p.x << "," << p.y << endl;
    ofs << "Key: " << p.Key << endl;
    ofs << "Level: " << p.Level << endl;
    ofs.close();
}

// Return the player
Player GetPlayer() {
    Player player = GetPlayerHelper();
    return player;
}

// Return the health of player
int GetHealth() {
    Player player = GetPlayerHelper();
    return player.Health;
}

// Return the shield of player
int GetShield() {
    Player player = GetPlayerHelper();
    return player.Shield;
}

// Return the gold of player
int GetGold() {
    Player player = GetPlayerHelper();
    return player.Gold;
}

// Return the key of player
bool GetKey() {
    Player player = GetPlayerHelper();
    return player.Key;
}

// Return the level of player
int GetLevel() {
    Player player = GetPlayerHelper();
    return player.Level;
}

// Return the position of player
int* GetPosition() {
    Player player = GetPlayerHelper();
    int* position = (int *)malloc(2 * sizeof(int));
    position[0] = player.x;
    position[1] = player.y;
    return position;
}

// Operations on player's data
void ChangeHealth(Player& p, int change) {
    p.Health = p.Health + change;
    SetPlayerHelper(p);
}

void ChangeShield(Player& p, int change) {
    p.Shield = p.Shield + change;
    SetPlayerHelper(p);
}

void ChangeGold(Player& p, int change) {
    p.Gold = p.Gold + change;
    SetPlayerHelper(p);
}

void ChangeKey(Player& p) {
    p.Key = !p.Key;
    SetPlayerHelper(p);
}

void ChangeLevel(Player& p, int level) {
    p.Level = level;
    SetPlayerHelper(p);
}

void ChangePosition(Player& p, int changeX, int changeY) {
    p.x = p.x + changeX;
    p.y = p.y + changeY;
    SetPlayerHelper(p);
}

Player NewPlayer(){
    // Give the player initial data
    Player newPlayer;
    newPlayer.Health = 5;
    newPlayer.Shield = 0;
    newPlayer.Gold = 0;
    newPlayer.x = 50;
    newPlayer.y = 25;
    newPlayer.Key = false;
    newPlayer.Level = 1;
    return newPlayer;
}
