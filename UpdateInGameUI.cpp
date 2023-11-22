#include <iostream>
#include "get_map.h"
#include "get_player.h"
using namespace std;
void gameUIhaveshop(){
        int maphigh = 26;
        int maplength = 101;
        int playerlength = 120;
        int playerhigh = 10;
        int shoplength = 120;
        int shophigh = 26;
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
                        else if (j==0 || j==maplength || j==102 || j==120){
                                cout << "┃";
                        }
                        //print the horizontal lines at the top and bottom of the frame
                        else if (i==0||i==maphigh || (i==10 && j>101) || (i==11 && j>101) || i==26){
                                cout<<"━";
                        }
                        // print map
                        else if ((i >= 1 && i <= 25) && (j >= 1 && j <= 100)) {
                                cout << map[i-1][j-1];
                        }
                        // print player status
                        //print health
                        else if  (i == 3 && j >= 105) {
                                int health = GetHealth();
                                cout<<"Health: ";
                                for (int a = 0;a<=health;a++){
                                    cout<<"+";    
                                }
                        }
                                cout<<endl;
                        //print sheild
                        else if (i ==4 && j>=105){
                                int shield = GetShield();
                                cout<<"Shield: ";
                                for (int b = 0;b<=shield;b++){
                                        cout<<"o";
                                }
                                cout<<endl;
                        }
                        //print Gold number
                        else if(i==5 && j>=105){
                                int gold = GetGold();
                                cout<<"Gold: ";
                                for (int c = 0;c<=gold;c++){
                                        cout<<"$";
                                }
                                cout<<endl;
                        }   
                        //print level     
                        else if(i==6 && j>=105){
                                int level = GetLevel();
                                cout<<"Level: "<<level<<endl;                               
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
        for (int i = 0;i<=5;i++){
            for (int j = 0;j<=120;j++){
                //print upper left corner of the frame
                if (i==0 && j==0){
                    cout<<"┏";
                }
                //print upper right corner of the frame
                else if((i==0 && j==120)){
                    cout<<"┓";
                }
                //print bottom left corner of the frame
                else if((i==5 && j==0)){
                    cout<<"┗";
                }
                //print bottom right corner of the frame
                else if((i==5 && j==120)){
                    cout<<"┛";
                }
                //print upper line
                else if(i==0){
                        cout<<"━";
                }
                //print instruction
                else if(i==2 && j==1){
                        cout<<"Press 's' to start. Press 'e' to end. Press 'p' to pause: press 'c' to continue; press 'r' to reset. Press 'w/a/s/d' to  ";
                }
                else if(i==3 && j==1){
                        cout<<"move around. ^is throne, deduct one health. $is gold, use them in shop. You can buy shield in shop to get more health.";
                }
                //print botton line
                else if(i==5){
                    cout<<"━";
                }
                else{
                    cout<<" ";
                }
            }
            cout<<endl;


        }
}

void gameUInoshop(){
        int maphigh = 26;
        int maplength = 101;
        int playerlength = 120;
        int playerhigh = 10;
        int shoplength = 120;
        int shophigh = 26;
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
                        else if (j==0 || j==maplength || j==102 || j==120){
                                cout << "┃";
                        }
                        //print the horizontal lines at the top and bottom of the frame
                        else if (i==0||i==maphigh || (i==10 && j>101) || (i==11 && j>101) || i==26){
                                cout<<"━";
                        }
                        // print map
                        else if ((i >= 1 && i <= 25) && (j >= 1 && j <= 100)) {
                                cout << map[i-1][j-1];
                        }
                        // print player status
                        //print health
                        else if  (i == 3 && j >= 105) {
                                int health = GetHealth();
                                cout<<"Health: ";
                                for (int a = 0;a<=health;a++){
                                    cout<<"+";    
                                }
                        }
                                cout<<endl;
                        //print sheild
                        else if (i ==4 && j>=105){
                                int shield = GetShield();
                                cout<<"Shield: ";
                                for (int b = 0;b<=shield;b++){
                                        cout<<"o";
                                }
                                cout<<endl;
                        }
                        //print Gold number
                        else if(i==5 && j>=105){
                                int gold = GetGold();
                                cout<<"Gold: ";
                                for (int c = 0;c<=gold;c++){
                                        cout<<"$";
                                }
                                cout<<endl;
                        }   
                        //print level     
                        else if(i==6 && j>=105){
                                int level = GetLevel();
                                cout<<"Level: "<<level<<endl;                               
                        }
                        else{
                                cout<<" ";
                        }
                       
                }
                cout << endl;

        }
        //print instruction frame
        for (int i = 0;i<=5;i++){
            for (int j = 0;j<=120;j++){
                //print upper left corner of the frame
                if (i==0 && j==0){
                    cout<<"┏";
                }
                //print upper right corner of the frame
                else if((i==0 && j==120)){
                    cout<<"┓";
                }
                //print bottom left corner of the frame
                else if((i==5 && j==0)){
                    cout<<"┗";
                }
                //print bottom right corner of the frame
                else if((i==5 && j==120)){
                    cout<<"┛";
                }
                //print upper line
                else if(i==0){
                        cout<<"━";
                }
                //print instruction
                else if(i==2 && j==1){
                        cout<<"Press 's' to start. Press 'e' to end. Press 'p' to pause: press 'c' to continue; press 'r' to reset. Press 'w/a/s/d' to  ";
                }
                else if(i==3 && j==1){
                        cout<<"move around. ^is throne, deduct one health. $is gold, use them in shop. You can buy shield in shop to get more health.";
                }
                //print botton line
                else if(i==5){
                    cout<<"━";
                }
                else{
                    cout<<" ";
                }
            }
            cout<<endl;


        }
}


