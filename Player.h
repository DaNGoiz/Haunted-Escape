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
Player GetPlayer();
int GetHealth();
int GetShield();
int GetGold();
int* GetPosition();
bool GetKey();
int GetLevel();
void ChangeHealth(int change);
void ChangeShield(int change);
void ChangeGold(int change);
void ChangePosition(int x, int y);
void ChangeKey(bool hasKey);
void ChangeLevel(int change);
void SetLevel(int level);
void NewPlayer();
#endif