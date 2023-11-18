#include <iostream>
#include <String>
#include <get_player.h>
#include <set_player.h>
using namespace std;
// This program aims to design the simple logic of player move in SHOP.
// The program receives input as 'Char' and return GAME STATUS as string.
string InShopPlayerMove(char input){
bool p = true;
while (p){
    // if input is 'p', the shop is Paused and after entering 'c' meaning continue, Game continues.
    if (input == 'p'){
        return "Pause";
    }
    // if input is 's', the player aimed at buying SHIELD.
    else if (input == 's'){
        cout << "Are you sure to buy SHIELD?" << endl;
        char c;
        cin >> c;
        // if input is 'Y', the player confirms to buy SHIELD.
        if (c == 'Y'){
            int shield = GetShield();
            int gold = GetGold();
            // check if the player already has a shield.
            if (shield > 0){
                cout << "Are you sure to buy a NEW SHIELD?" << endl;
                char d;
                cin >> d;
                if (d == 'Y'){
                    // check whether gold is enough.
                    if (gold < 3){
                        cout << "Your have not enough GOLD!" << endl;
                        return "Shop";
                    }
                    else if (shield == 1){
                        ChangeShield(2);
                        ChangeGold(-3);
                        cout << "You have bought a new SHIELD!" << endl;
                        return "Shop";
                    }
                    else if (shield == 2){
                        ChangeShield(1);
                        ChangeGold(-3);
                        cout << "You have bought a new SHIELD!" << endl;
                        return "Shop";
                    }
                    else if (shield == 3){
                        ChangeShield(0);
                        ChangeGold(-3);
                        cout << "You have bought a new SHIELD!" << endl;
                        return "Shop";
                    }
                }
                else {
                    cout << "Purchase unsuccessful" << endl;
                    return "Shop";
                }
            }
            else {
                cout << "Are you sure to buy a SHIELD?" << endl;
                char e;
                cin >> e;
                if (e == 'Y'){
                    // check whether gold is enough.
                    if (gold < 3){
                        cout << "Your have not enough GOLD!" << endl;
                        return "Shop";
                    }
                    else {
                        cout << "You have bought a SHIELD!" << endl;
                        ChangeShield(3);
                        ChangeGold(-3);
                        return "Shop";
                    }
                }
            }
        }
        else {
            cout << "Purchase unsuccessful" << endl;
            return "Shop";
            }
    }
    // if user input is 'q', quit shop and Game continues.
    else if (input == 'q'){
        cout << "Quitting Shop" << endl;
        cout << "Back to GAME" << endl;
        return "InGame";
    }
}
}