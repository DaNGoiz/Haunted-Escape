#include <iostream>
#include "generate_map.h"

using namespace std;
using CharArray2D = char[25][100];

const int mapX = 25;
const int mapY = 100;

void getMapDataAll() {

}

void getMapDataAtPoint() {
    
}


// set color and print map elements
void printMapElement(char element) {
    if (element == '@')
        cout << "\x1b[43;30m" << element << "\x1b[0m";
    else if (element == '$' || element == '=')
        cout << "\x1b[33m" << element << "\x1b[0m";
    else if (element == '\'' || element == '"' || element == '`')
        cout << "\x1b[32m" << element << "\x1b[0m";
    else if (element == '#' || element == '!')
        cout << "\x1b[46;30m" << element << "\x1b[0m";
    else if (element == 'X')
        cout << "\x1b[90m" << element << "\x1b[0m";
    else if (element == '+')
        cout << "\x1b[31m" << element << "\x1b[0m";
    else if (element == '^') // different color
        cout << "\x1b[31m" << element << "\x1b[0m";
    else
        cout << element;
}

// print the map on console
void printMap(const CharArray2D& map) {
    for (int i = 0; i < mapX; ++i) {
        for (int j = 0; j < mapY; ++j) {
            printMapElement(map[i][j]);
        }
        cout << "|" << endl;
    }
}

int main() {
    CharArray2D map = {};

    generateRandomMap(map);
    printMap(map);


    return 0;
}