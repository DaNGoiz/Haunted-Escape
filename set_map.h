#ifndef SET_MAP_H
#define SET_MAP_H

// Set all data in map.log
void setMapDataAll(char map[25][100]);

// Set data at point (x, y) in map.log
void setMapDataAtPoint(int x, int y, char c, char map[25][100]);

// Generate new map and set it in map.log
void newMap(char map[25][100]);

// Clear map in map.log
void clearMap(char map[25][100]);

#endif