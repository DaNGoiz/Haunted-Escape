#include <iostream>
#include "get_map.h"
#include "Player.h"
using namespace std;
void gameUIhaveshop(){
        int maphigh = 26;
        int maplength = 101;
        char map[25][100];
        getMapDataAll(map);
        //print map,player status, and shop frame
        for (int i =0; i<=26; i++){ 
                for(int j =0; j<=120;j++){
                        //print upper left corner of the frame
                        if ((i==0 && j==0) || (i==0 && j==102) || (i==11 && j==102)){
                                cout<<"┏";
                        }
                        //print upper right corner of the frame
                        else if((i==0 && j==maplength) || (i==0 && j==120) || (i==11 && j==120)){
                                cout<<"┓";
                        }
                        //print bottom left corner of the frame
                        else if((i==maphigh && j==0) || (i==10 && j==102) || (i==26 && j==102)){
                                cout<<"┗";
                        }
                        //print bottom right corner of the frame
                        else if((i==maphigh && j==maplength) || (i==10 && j==120) || (i==26 && j==120)){
                                cout<<"┛";
                        }
                        //print the vertical lines on the left and right sides of the frame
                        else if (j==0 || j==maplength || j==102 || (j==120 && (i < 3 || i > 6))){
                                cout << "┃";
                        }
                        //print the horizontal lines at the top and bottom of the frame
                        else if (i==0||i==maphigh || (i==10 && j>101) || (i==11 && j>101) || i==26){
                                cout<<"━";
                        }
                        // print map
                        else if ((i >= 1 && i <= 25) && (j >= 1 && j <= 100)) {
                                printMapElement(map[i-1][j-1]);
                        }
                        // print player status
                        //print health
                        else if  (i == 3 && j == 105) {
                                int health = GetHealth();
                                cout<<"Health: ";
                                for (int a = 1;a<=health;a++){
                                    cout<<"+";    
                                }
                                for (int i = 105; i <= 120 - health - 9; i++) {
                                        cout << " ";
                                }
                                cout << "┃";
                        }
                                
                        //print sheild
                        else if (i ==4 && j==105){
                                int shield = GetShield();
                                cout<<"Shield: ";
                                for (int b = 1;b<=shield;b++){
                                        cout<<"o";
                                }
                                for (int i = 105; i <= 120 - shield - 9; i++) {
                                        cout << " ";
                                }
                                cout << "┃";
                        }
                        //print Gold number
                        else if(i==5 && j==105){
                                int gold = GetGold();
                                cout<<"Gold: ";
                                for (int c = 1;c<=gold;c++){
                                        cout<<"$";
                                }
                                for (int i = 105; i <= 120 - gold - 7; i++) {
                                        cout << " ";
                                }
                                cout << "┃";
                        }   
                        //print level     
                        else if(i==6 && j==105){
                                int level = GetLevel();
                                cout<<"Level: "<<level;
                                for (int i = 105; i <= 120 - 9; i++) {
                                        cout << " ";
                                }
                                cout << "┃";                              
                        }
                        //print shop
                        //print Product Name
                        else if(i==18 && j==105){
                                cout<<"S";                               
                        }
                        else if(i==18 && j==106){
                                cout<<"h";                               
                        }
                        else if(i==18 && j==107){
                                cout<<"i";                               
                        }             
                        else if(i==18 && j==108){
                                cout<<"e";                               
                        }       
                        else if(i==18 && j==109){
                                cout<<"l";                               
                        }                     
                        else if(i==18 && j==110){
                                cout<<"d";                               
                        }      
                        //print Product Price
                        else if(i==20 && j==105){
                                cout<<"2";
                        }
                        else if(i==20 && j==106){
                                cout<<"$";
                        } 
                        else{
                                cout<<" ";

                        }
                }
                cout << endl;

        }
        //print instruction frame
        cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
        cout << "┃         You have entered a shop! You can buy shield here to get more protection.                                      ┃" << endl;
        cout << "┃         Press 'Y' to buy. Press 'q' to return to game. Press 'p' to pause.                                            ┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
}

void gameUInoshop(){
        int maphigh = 26;
        int maplength = 101;
        char map[25][100];
        getMapDataAll(map);
        //print map,player status, and shop frame
        for (int i =0; i<=26; i++){ 
                for(int j =0; j<=120;j++){
                        //print upper left corner of the frame
                        if ((i==0 && j==0) || (i==0 && j==102) || (i==11 && j==102)){
                                cout<<"┏";
                        }
                        //print upper right corner of the frame
                        else if((i==0 && j==maplength) || (i==0 && j==120) || (i==11 && j==120)){
                                cout<<"┓";
                        }
                        //print bottom left corner of the frame
                        else if((i==maphigh && j==0) || (i==10 && j==102) || (i==26 && j==102)){
                                cout<<"┗";
                        }
                        //print bottom right corner of the frame
                        else if((i==maphigh && j==maplength) || (i==10 && j==120) || (i==26 && j==120)){
                                cout<<"┛";
                        }
                        //print the vertical lines on the left and right sides of the frame
                        else if (j==0 || j==maplength || j==102 || (j==120 && (i < 3 || i > 6))){
                                cout << "┃";
                        }
                        //print the horizontal lines at the top and bottom of the frame
                        else if (i==0||i==maphigh || (i==10 && j>101) || (i==11 && j>101) || i==26){
                                cout<<"━";
                        }
                        // print map
                        else if ((i >= 1 && i <= 25) && (j >= 1 && j <= 100)) {
                                printMapElement(map[i-1][j-1]);
                        }
                        // print player status
                        //print health
                        else if  (i == 3 && j == 105) {
                                int health = GetHealth();
                                cout<<"Health: ";
                                for (int a = 0;a<=health-1;a++){
                                    cout<<"+";    
                                }
                                for (int i = 105; i <= 120 - health - 9; i++) {
                                        cout << " ";
                                }
                                cout << "┃";
                        }
                                
                        //print sheild
                        else if (i ==4 && j==105){
                                int shield = GetShield();
                                cout<<"Shield: ";
                                for (int b = 0;b<=shield-1;b++){
                                        cout<<"o";
                                }
                                for (int i = 105; i <= 120 - shield - 9; i++) {
                                        cout << " ";
                                }
                                cout << "┃";
                        }
                        //print Gold number
                        else if(i==5 && j==105){
                                int gold = GetGold();
                                cout<<"Gold: ";
                                for (int c = 0;c<=gold-1;c++){
                                        cout<<"$";
                                }
                                for (int i = 105; i <= 120 - gold - 7; i++) {
                                        cout << " ";
                                }
                                cout << "┃";
                        }   
                        //print level     
                        else if(i==6 && j==105){
                                int level = GetLevel();
                                cout<<"Level: "<<level;
                                for (int i = 105; i <= 120 - 9; i++) {
                                        cout << " ";
                                }
                                cout << "┃";                              
                        }
                        else{
                                cout<<" ";
                        }

                }
                cout << endl;

        }
        //print instruction frame
        cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
        cout << "┃         Press 'w/a/s/d' to move around. "<< "\x1b[31m" << "^" << "\x1b[0m" << " is throne, deduct one health. " << "\x1b[33m" << "$" << "\x1b[0m" << " is gold, use them in shop " << "\x1b[33m" << "=" << "\x1b[0m" << ".                ┃" << endl;
        cout << "┃         Your goal is to pick the key " << "\x1b[46;30m" << "!" << "\x1b[0m" << ", then use it to open the gate " << "\x1b[46;30m" << "#" << "\x1b[0m" << ".                                               ┃" << endl;
        cout << "┃         If you want to pause the game, press 'p'.                                                                     ┃" << endl;
        cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
}
