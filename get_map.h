#ifndef GET_MAP_H
#define GET_MAP_H

// Read all data from map.log
void getMapDataAll(char map[25][100]);

// Read data at point (x, y) from map.log
char getMapDataAtPoint(int x, int y);

// Print map element with color
void printMapElement(char element);

// Get position of player
void getPlayerPosition(int& x, int& y);

#endif