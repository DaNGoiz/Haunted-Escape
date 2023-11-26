#include <iostream>
#include <ctime>

using namespace std;

const int mapX = 25;
const int mapY = 100;

bool needToChange[25][100] = {}; // hardcode

// Initialize map
void initializeMap(char map[25][100], char c) {
    for (int i = 0; i < mapX; ++i)
        for (int j = 0; j < mapY; ++j)
            map[i][j] = c;
}

// Generate map blank space
void generateBlankSpace(char map[25][100]) {
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
                    if (rand() % 50 == 0)
                    {
                        map[i][j] = '\0';
                        jZero = j;
                    }
                    else
                        if (j <= jZero)
                            if (rand() % 1 == 0)
                                map[i][j] = '\0';
                        else
                            if (rand() % 10 == 0)
                                map[i][j] = '\0';
            }
}

// Clean unnecessary obstacles
// Return number of blank spaces and array of blank space index of the map
void cleanAndGetBlankSpace(char map[25][100], int blankSpace[25][100], int& numBlank) {
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

// Define four direction movement
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

// Check if the position is inside the map
bool isValid(int x, int y, bool visited[mapX][mapY], int blankSpace[mapX][mapY]) {
    return (x >= 0 && x < mapX && y >= 0 && y < mapY && !visited[x][y] && blankSpace[x][y] == 1);
}

// Go through all blank spaces
void dfs(int x, int y, bool visited[mapX][mapY], int blankSpace[mapX][mapY], int& count) {
    visited[x][y] = true;
    count++;

    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValid(newX, newY, visited, blankSpace)) {
            dfs(newX, newY, visited, blankSpace, count);
        }
    }
}

// Test if blank space is connected
bool isBlankSpaceConnected(char map[mapX][mapY], int blankSpace[mapX][mapY]) {
    bool visited[mapX][mapY] = {};
    int totalBlankSpace = 0;
    int visitedBlankSpaceCount = 0;

    // Count the total number of blank spaces
    for (int i = 0; i < mapX; i++) {
        for (int j = 0; j < mapY; j++) {
            if (blankSpace[i][j] == 1) {
                totalBlankSpace++;
            }
        }
    }

    // Find the first blank space
    bool found = false;
    for (int i = 0; i < mapX && !found; i++) {
        for (int j = 0; j < mapY; j++) {
            if (blankSpace[i][j] == 1) {
                dfs(i, j, visited, blankSpace, visitedBlankSpaceCount);
                found = true;
                break;
            }
        }
    }

    // Compare the visited blank space count with total blank spaces
    return totalBlankSpace == visitedBlankSpaceCount;
}

// Turn the outside walls to char 'X'
void generateWalls(char map[25][100]) { 
    for (int i = 0; i < mapX; ++i)
        for (int j = 0; j < mapY; ++j)
            needToChange[i][j] = false;
            
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

// Generate grass on the ground
void generateGrass(char map[25][100]) {
    for (int i = 0; i < mapX; ++i) {
        for (int j = 0; j < mapY; ++j) {
            if (map[i][j] == '\0') {
                if (rand() % 25 == 5)
                    map[i][j] = '"';
                else if (rand() % 25 == 6)
                    map[i][j] = '\'';
                else if (rand() % 25 == 7)
                    map[i][j] = '`';
                else
                    map[i][j] = ' ';
            }
        }
    }
}

// Generate some basic elements (door and key and player)
void generateMapElements(char map[25][100], int blankSpace[25][100]) {
    // Generate door (#)
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

    // Generate key (!)
    int keyX, keyY;
    do {
        keyX = rand() % (mapX - 2) + 1;
        keyY = rand() % (mapY - 2) + 1;
    } while (blankSpace[keyX][keyY] == 0 || (keyX == doorX && keyY == doorY));

    map[keyX][keyY] = '!';
    blankSpace[keyX][keyY] = 0;

    // Generate player (@)
    int playerX, playerY;
    do {
        playerX = rand() % (mapX - 2) + 1;
        playerY = rand() % (mapY - 2) + 1;
    } while (blankSpace[playerX][playerY] == 0 || (playerX == doorX && playerY == doorY) || (playerX == keyX && playerY == keyY));

    map[playerX][playerY] = '@';
    blankSpace[playerX][playerY] = 0;
}

// Generate items inside the map (money, health, shop, spike)
void generateItems(char map[25][100], int blankSpace[25][100]) {
    int propTotal = 500;
    int propMax = 7;

    for (int i = 0; i < mapX; ++i) {
        for (int j = 0; j < mapY; ++j) {
            if (blankSpace[i][j] == 1) {
                if (rand() % propTotal <= propMax) {
                    int itemIndex = rand() % 22;
                    if (itemIndex < 7)
                        map[i][j] = '$';
                    else if (itemIndex >= 7 && itemIndex < 10)
                        map[i][j] = '+';
                    else if (itemIndex >= 10 && itemIndex < 13)
                        map[i][j] = '=';
                    else
                        map[i][j] = '^';
                }
                else if (rand() % 100 < 10)
                        map[i][j] = '^';
            }
        }
    }
}

// Generate a random map
void generateRandomMap(char map[25][100]) {
    srand(time(NULL));

    // Generate a blank map
    char localMap[25][100];
    int moveableSpace = 0;
    int blankSpaceArr[25][100];
    bool isConnected = false;

    while (!isConnected || moveableSpace < 1000) {
        initializeMap(localMap, '-');
        generateBlankSpace(localMap);
        cleanAndGetBlankSpace(localMap, blankSpaceArr, moveableSpace);
        isConnected = isBlankSpaceConnected(localMap, blankSpaceArr);
    }

    // Generate terrain and objects
    generateWalls(localMap);
    generateGrass(localMap);
    generateMapElements(localMap, blankSpaceArr);
    generateItems(localMap, blankSpaceArr);

    // Copy localMap to map
    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 100; ++j) {
            map[i][j] = localMap[i][j];
        }
    }
}



// int main() {
//     char map[25][100] = {}; // Initialize the char array.

//     generateRandomMap(map);
//     printMap(map);

//     return 0;
// }