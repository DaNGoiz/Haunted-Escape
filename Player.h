#ifndef PLAYER_H
#define PLAYER_H

// Initialize the player at the begining
struct Player {
    int Health;
    int Shield;
    int Gold;
    int x, y;
    bool Key;
    int Level;
};
Player GetPlayerHelper();
void SetPlayerHelper(Player& p);
Player GetPlayer();
int GetHealth();
int GetShield();
int GetGold();
int* GetPosition();
bool GetKey();
int GetLevel();
void ChangeHealth(Player& p, int change);
void ChangeShield(Player& p, int change);
void ChangeGold(Player& p, int change);
void ChangePosition(int x, int y);
void ChangeKey(Player& p, bool hasKey);
void ChangeLevel(Player& p, int level);
Player NewPlayer();
#endif