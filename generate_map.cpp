#include <iostream>
#include <ctime>


using namespace std;

const int mapX = 25;
const int mapY = 100;

using CharArray2D = char[25][100];

bool needToChange[25][100] = {}; // hardcode

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

// define four direction movement
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

// check the position is inside map
bool isValid(int x, int y) {
    return x >= 0 && x < mapX && y >= 0 && y < mapY;
}

// go through all blank spaces
void dfs(int x, int y, CharArray2D map, bool visited[mapX][mapY]) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (isValid(newX, newY) && map[newX][newY] == ' ' && !visited[newX][newY]) {
            dfs(newX, newY, map, visited);
        }
    }
}

// check is blank spaces connected
bool isBlankSpaceConnected(CharArray2D& map) {

    bool visited[mapX][mapY];
    for (int i = 0; i < mapX; i++) {
        for (int j = 0; j < mapY; j++) {
            visited[i][j] = false;
        }
    }

    // find the first blank place to dfs
    int startX, startY;
    for (int i = 0; i < mapX; i++) {
        for (int j = 0; j < mapY; j++) {
            if (map[i][j] == ' ') {
                startX = i;
                startY = j;
                break;
            }
        }
    }

    dfs(startX, startY, map, visited);

    // check if all blank spaces can be visited
    for (int i = 0; i < mapX; i++) {
        for (int j = 0; j < mapY; j++) {
            if (map[i][j] == ' ' && !visited[i][j]) {
                return false;
            }
        }
    }

    return true;
}

// turn the outside walls to char 'X'
void generateWalls(CharArray2D& map) { 
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
void generateGrass(CharArray2D& map) {
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

    int propTotal = 500;
    int propMax = 7;

    for (int i = 0; i < mapX; ++i) {
        for (int j = 0; j < mapY; ++j) {
            if (blankSpace[i][j] == 1) {
                if (rand() % propTotal <= propMax)
                {
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
            }
        }
    }
}

// generate a random map
void generateRandomMap(CharArray2D& map) {
    srand(time(NULL));

    //generate blank map
    int moveableSpace = 0;
    int blankSpaceArr[25][100];
    bool isConnected = false;

    while(!isConnected || moveableSpace < 1000)
    {
        initializeMap(map, '-');
        generateBlankSpace(map);
        cleanAndGetBlankSpace(map, blankSpaceArr, moveableSpace);
        isConnected = isBlankSpaceConnected(map);
    }
        
    // generate terrain
    generateWalls(map);
    generateGrass(map);
    
    // generate objects
    generateMapElements(map, blankSpaceArr);
    generateItems(map, blankSpaceArr);
}



// int main() {
//     CharArray2D map = {}; // in outside classes also use

//     generateRandomMap(map);
//     printMap(map);

//     return 0;
// }
