#include <iostream>
#include <ctime>

using namespace std;

const int mapX = 25;
const int mapY = 100;

using CharArray2D = char[25][100];

// initialize map
void initializeMap(CharArray2D& map, char c) {
    for (int i = 0; i < mapX; ++i)
        for (int j = 0; j < mapY; ++j)
            map[i][j] = c;
}

// generate map blank space
void generateBlankSpace(CharArray2D& map) {
    bool firstGen = true;
    for (int i = 0; i < mapX; ++i)
        for (int j = 0; j < mapY; ++j)
            if ((i - 1 >= 0 && map[i - 1][j] != '-') || 
                (i + 1 < mapX && map[i + 1][j] != '-') || 
                (j - 1 >= 0 && map[i][j - 1] != '-') || 
                (j + 1 < mapY && map[i][j + 1] != '-'))
            {
                if (rand() % 11 <= 8) 
                    map[i][j] = '\0';
            }
            else
            {
                int jZero = 0;
                if (i == 0)
                    if (rand()%50 == 0)
                    {
                        map[i][j] = '\0';
                        jZero = j;
                    }
                else
                    if (j <= jZero)
                        if (rand()%1 == 0)
                            map[i][j] = '\0';
                    else
                        if (rand()%10 == 0)
                            map[i][j] = '\0';
            }
}

// clean unnecessary obstacles
// return number of blank space and array of blank space index of the map
void cleanAndGetBlankSpace(CharArray2D& map, int blankSpace[mapX][mapY], int& numBlank) {
    numBlank = 0;

    for (int i = 0; i < mapX; ++i)
        for (int j = 0; j < mapY; ++j)
            if (map[i][j] == '-' &&
                (i - 1 >= 0 && map[i - 1][j] != '-') && 
                (i + 1 < mapX && map[i + 1][j] != '-') && 
                (j - 1 >= 0 && map[i][j - 1] != '-') && 
                (j + 1 < mapY && map[i][j + 1] != '-')) {
                map[i][j] = '\0';
                blankSpace[i][j] = 1;
                numBlank++;
            } else if (map[i][j] == '\0') {
                blankSpace[i][j] = 1;
                numBlank++;
            } else
                blankSpace[i][j] = 0;
}

// prove the roads are connected
bool provePathIsConnected(CharArray2D& map) {
    bool isConnected = false; 
    
    isConnected = true; // deubg

    return isConnected;
}

// turn the outside walls to X
void generateWalls(CharArray2D& map) {
    bool needToChange[25][100] = {}; // hardcode

    for (int i = 0; i < mapX; ++i)
        for (int j = 0; j < mapY; ++j)
            if (map[i][j] == '-')
                if ((i - 1 >= 0 && map[i - 1][j] != '-') ||
                    (i + 1 < mapX && map[i + 1][j] != '-') ||
                    (j - 1 >= 0 && map[i][j - 1] != '-') ||
                    (j + 1 < mapY && map[i][j + 1] != '-'))
                    needToChange[i][j] = true;

    for (int i = 0; i < mapX; ++i) {
        for (int j = 0; j < mapY; ++j) {
            if (needToChange[i][j]) {
                map[i][j] = 'X';
            }
        }
    }
}

// generate grass
void generateGround(CharArray2D& map) {
    for (int i = 0; i < mapX; ++i)
        for (int j = 0; j < mapY; ++j)
            if (map[i][j] == '\0')
                if(rand()%25 == 5)
                    map[i][j] = '"';
                else if(rand()%25 == 6)
                    map[i][j] = '\'';
                else if(rand()%25 == 7)
                    map[i][j] = '`';
                else
                    map[i][j] = ' ';
}


void generateMapElements(CharArray2D& map, int blankSpace[mapX][mapY]) {
    // generate door (#)
    int doorX, doorY;
    do {
        int boundary = rand() % 4;
        if (boundary == 0) {
            doorX = 0;
            doorY = rand() % (mapY - 2) + 1;
        } else if (boundary == 1) {
            doorX = mapX - 1;
            doorY = rand() % (mapY - 2) + 1;
        } else if (boundary == 2) {
            doorX = rand() % (mapX - 2) + 1;
            doorY = 0;
        } else {
            doorX = rand() % (mapX - 2) + 1;
            doorY = mapY - 1;
        }
    } while (blankSpace[doorX][doorY] == 0);

    map[doorX][doorY] = '#';
    blankSpace[doorX][doorY] = 0;

    // generate key (!)
    int keyX, keyY;
    do {
        keyX = rand() % (mapX - 2) + 1;
        keyY = rand() % (mapY - 2) + 1;
    } while (blankSpace[keyX][keyY] == 0 || (keyX == doorX && keyY == doorY));

    map[keyX][keyY] = '!';
    blankSpace[keyX][keyY] = 0;

    // generate player (@)
    int playerX, playerY;
    do {
        playerX = rand() % (mapX - 2) + 1;
        playerY = rand() % (mapY - 2) + 1;
    } while (blankSpace[playerX][playerY] == 0 || (playerX == doorX && playerY == doorY) || (playerX == keyX && playerY == keyY));

    map[playerX][playerY] = '@';
    blankSpace[playerX][playerY] = 0;
}

// generate items: shop, spike, health pack etc.
void generateItems(CharArray2D& map, int blankSpace[mapX][mapY]) {

    const char items[] = {'$', '+', '▲', '▄'}; // gold, health, spike, shop

    for (int i = 0; i < mapX; ++i) {
        for (int j = 0; j < mapY; ++j) {
            if (blankSpace[i][j] == 0) {
                int itemIndex = rand() % 4; // 4 items
                map[i][j] = items[itemIndex];
            }
        }
    }
}

// generate a random map
void generateRandomMap(CharArray2D& map) {
    int moveableSpace = 0;
    int blankSpaceArr[25][100];
    bool isConnected = false;

    while(!isConnected || moveableSpace < 1000)
    {
        initializeMap(map, '-');
        generateBlankSpace(map);
        cleanAndGetBlankSpace(map, blankSpaceArr, moveableSpace);
        isConnected = provePathIsConnected(map);
    }

    for (int i = 0; i < mapX; ++i)
    {
        for (int j = 0; j < mapY; ++j)
            cout << blankSpaceArr[i][j];
        cout << endl;
    }
        
    
    generateWalls(map);
    generateGround(map);
    
    generateMapElements(map, blankSpaceArr);
    generateItems(map, blankSpaceArr);
}

// set color and print map elements
void printMapElement(char element) {
    if (element == '@' || element == '$' || element == '▄')
        cout << "\x1b[33m" << element << "\x1b[0m";
    else if (element == '\'' || element == '"' || element == '`')
        cout << "\x1b[32m" << element << "\x1b[0m";
    else if (element == '#' || element == '!')
        cout << "\x1b[46m" << element << "\x1b[0m";
    else if (element == 'X')
        cout << "\x1b[90m" << element << "\x1b[0m";
    else if (element == '+')
        cout << "\x1b[31m" << element << "\x1b[0m";
    else if (element == '▲')
        cout << "\x1b[90m" << element << "\x1b[0m";
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
    srand(time(NULL));
    
    CharArray2D map = {};

    generateRandomMap(map);
    printMap(map);

    return 0;
}
