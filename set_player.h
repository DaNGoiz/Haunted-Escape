#ifndef SETPLAYER_H
#define SETPLAYER_H

void ChangeHealth(int change);
void ChangeShield(int change);
void ChangeGold(int change);
void ChangePosition(int x, int y);
void ChangeKey(bool hasKey);
void ChangeLevel(int change);
void SetLevel(int level);
void NewPlayer();

#endif