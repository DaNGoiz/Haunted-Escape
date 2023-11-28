# Haunted Escape
## 1. Team members of COMP2113-Group6
Liu Xinyun (3035983665)

Wang Yifu (3036098156)

Xu Jingxiang (3036051550)

Zhou Yuhong (3036037554)

## 2. How to play
### DEMO
[![asciicast](https://asciinema.org/a/unI1fghm9PS84T3rhHCxqJI1t.svg)](https://asciinema.org/a/unI1fghm9PS84T3rhHCxqJI1t)
### Launching the game
```bash
make
```
```bash
./bin/game
```
### Player movement
Press 's' to start.

Press 'w/a/s/d' to move around.

## Description
🌟 Welcome to our thrilling text-based Haunted Escape RPG game, crafted in C++! This game offers a spine-chilling adventure where you, the player, are trapped in a haunted realm. Your mission: escape the eerie confines by navigating through randomly generated rooms, unlocking doors, and avoiding lethal traps.

🚪 Your journey begins in a mysterious room where you must find the key (!) to unlock the exit door (#). Each room brings new challenges and surprises, so stay alert!

⚔️ Beware of the deadly floor spikes! These hazards will reduce your health with each encounter. Keep an eye on your health meter; if it drops to zero, it's game over. But fear not, for there are shops scattered around that sell health potions and shields to aid your survival.

🛒 Utilize the shops wisely! Purchase health potions to restore your health and shields for added protection against the perils that lurk in the shadows.

⏱️ Race against time! Your goal is to escape in the shortest time possible. Each decision and step you take counts towards your final escape time.

👻 Haunted Escape is an immersive and challenging game that will keep you on the edge of your seat. With its blend of strategy, suspense, and survival elements, it's a must-play for fans of horror and RPG genres. Get ready to embark on a harrowing escape from the clutches of the haunted!

Enjoy the thrill and challenge of Haunted Escape, where every move is a step closer to freedom or doom! 🎲🕯️👣

## Features implemented
Generation of random game sets or events

Data structures for storing game status

<img width="416" alt="image" src="https://github.com/DaNGoiz/COMP2113-Group6/assets/122252536/9418544b-b62b-492d-b35e-d8cf56c78109">

Dynamic memory management
- We dynamically manage the memory for the information data of the player (see void ChangeXXX in Player.cpp)

File input/output

Program codes in multiple files

Proper indentation and naming styles

In-code documentation

### Non-standard libraries
Used standard libraries only.

# 3. Class description
1. UpdateInGameUI.cpp
- Print the entire game frame
- Print the map, playerstatus ,instruction and shop on the screen
  
2. print_pause_mennu.cpp
- When player press 'p', the screen will be printed 'You have paused the game'.

3. Player.cpp
- Print the information data of Player on Player.log
- Change the information data of Player on Player.log
- Get each information data of Player from Player.log
  
The Structure of a Player is like below:
```bash
struct Player {
    int Health;
    int Shield;
    int Gold;
    int x, y;
    bool Key;
    int Level;
};
```
The function to convert the Player's data into Player.log:
```bash
void SetPlayerHelper(Player& p) {
    ofstream ofs("Player.log");
    if (ofs.fail()) {
        cout << "Error in file opening" << endl;
        exit(1);
    }
    ofs << "Health: " << p.Health << endl;
    ofs << "Shield: " << p.Shield << endl;
    ofs << "Gold: " << p.Gold << endl;
    ofs << "Position: " << p.x << "," << p.y << endl;
    ofs << "Key: " << p.Key << endl;
    ofs << "Level: " << p.Level << endl;
    ofs<<"Time: "<<GetTime()<<endl;
    ofs.close();
}
```
The initial information of a Player if you want a new one:
```bash
Player NewPlayer(){
    // Give the player initial data
    Player newPlayer;
    newPlayer.Health = 5;
    newPlayer.Shield = 0;
    newPlayer.Gold = 0;
    getPlayerPosition(newPlayer.x, newPlayer.y);
    newPlayer.Key = false;
    newPlayer.Level = 1;
    return newPlayer;
}
```

4. InGamePlayerMove.cpp/InShopPlayerMove.cpp
- decide what player does according to the keyboard input
- perform map/player status change accordingly
```bash
string InGamePlayerMove(char input, Player& player, char map[25][100]){
    int* position = GetPosition();
    int x = position[0];
    int y = position[1];
    if (input == 'w'){
        char c = getMapDataAtPoint(x-1,y);
        if (x == 0){
            return "InGame";
        }
}
}
```

5. GameStatus.cpp
- Change the status of player
- the only main program of the game
```bash
while (gameOn){
        if (status == "LoadStart"){
            ResetTimer();
            newMap(map);
            int x, y;
            getPlayerPosition(x, y);
            SetPosition(player, x, y);
            loadStart();
            status = "Start";
        }
```

6.Loadlevel.cpp 
- print the ASCII grafhs when loading levels

