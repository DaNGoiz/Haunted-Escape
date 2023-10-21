#include <iostream>
#include <ctime>

using namespace std;

const int mapX = 25;
const int mapY = 100;

using CharArray2D = char[25][100];

// initialize map with '-'
void initializeMap(CharArray2D& map) {
    for (int i = 0; i < mapX; ++i)
        for (int j = 0; j < mapY; ++j)
            map[i][j] = '-';
}

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

void removeSingleWall(CharArray2D& map) {
    int blank = 0;
    for (int i = 0; i < mapX; ++i)
        for (int j = 0; j < mapY; ++j)
            if (map[i][j] == '-' &&
            (i - 1 >= 0 && map[i - 1][j] != '-') && 
            (i + 1 < mapX && map[i + 1][j] != '-') && 
            (j - 1 >= 0 && map[i][j - 1] != '-') && 
            (j + 1 < mapY && map[i][j + 1] != '-'))
            {
                map[i][j] = '\0';
                blank ++;
            } 
            else if (map[i][j] == '\0')
                blank ++;
    cout << "blank block count: " << blank << endl; // test
}

void provePathIsConnected(CharArray2D& map) {
    // prove the roads are connected (if no then regenerate walls)
    // blank space <= 1000 regen
}

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

void genereateItems(CharArray2D& map) {
    // items
}

void generatePlayerAndDoorAndKey(CharArray2D& map) {
    // generate random born point
    map[rand() % mapX][rand() % mapY] = '@';

    // generate a gate at map border
    int border = rand()%4 + 1;
    if(border == 1)
        map[0][rand()%(mapY - 2) + 1] = '#';
    else if(border == 2)
        map[mapX - 1][rand()%(mapY - 2) + 1] = '#';
    else if(border == 3)
        map[rand()%(mapX - 2) + 1][0] = '#';
    else if(border == 4)
        map[rand()%(mapX - 2) + 1][mapY] = '#';

    // generate the only key
    // what if not generated?
    bool hasKey = false;
    for (int i = 0; i < mapX; ++i)
        for (int j = 0; j < mapY; ++j)
            if (!hasKey)
                if (map[i][j] != '-' || map[i][j] != 'X' || map[i][j] != '@' || map[i][j] != '#')
                    if(rand()%2250 == 0)
                    {
                        map[i][j] = '!';
                        hasKey = true;
                    }
}

// generate a random map
void generateRandomMap(CharArray2D& map) {
    initializeMap(map);
    generateBlankSpace(map);
    removeSingleWall(map);
    provePathIsConnected(map);

    generateWalls(map);
    generateGround(map);
    genereateItems(map);
    
    generatePlayerAndDoorAndKey(map);
}

// set color and print map elements
void printMapElement(char element) {
    if (element == '@')
        cout << "\x1b[33m" << element << "\x1b[0m";
    else if (element == '\'' || element == '"' || element == '`')
        cout << "\x1b[32m" << element << "\x1b[0m";
    else if (element == '#' || element == '!')
        cout << "\x1b[36m" << element << "\x1b[0m";
    else if (element == 'X')
        cout << "\x1b[90m" << element << "\x1b[0m";
    else
        cout << element;
}

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
