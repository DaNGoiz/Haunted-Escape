#include <iostream>
#include <fstream>
#include <string>

#include "generate_map.h"

using namespace std;


// set all data in map.log
void setMapDataAll(char map[25][100]) { // why not const?
    ofstream outfile("map.log");

    if (outfile.is_open()) {
        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 100; j++) {
                outfile << map[i][j];
            }
            outfile << endl;
        }

        outfile.close();
    }
}

// set data at point (x, y) in map.log
void setMapDataAtPoint(int x, int y, char c, char map[25][100]) {
    ofstream outfile("map.log");

    if (outfile.is_open()) {
        for (int i = 0; i < 25; i++) {
            for (int j = 0; j < 100; j++) {
                if (i == x && j == y) {
                    outfile << c;
                } else {
                    outfile << map[i][j];
                }
            }
            outfile << endl;
        }

        outfile.close();
    }
}

// Generate new map and set it in map.log
void newMap(char map[25][100]) {
    generateRandomMap(map);
    setMapDataAll(map);
}

// Clear map in map.log
void clearMap() {
    char emptyMap[25][100] = {};
    setMapDataAll(emptyMap);
}