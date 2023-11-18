#include <iostream>
#include "set_map.h"
#include "get_map.h"
#include "get_player.h"
using namespace std;


void gameframe(){
        int maphigh = 26;
        int maplength = 101;
        int playerlength = 120;
        int playerhigh = 10;
        int shoplength = 120;
        int shophigh = 26;
       
        // char map[25][100];
        // getMapDataAll(map);

        for (int i =0; i<=26; i++){ //map frame
                for(int j =0; j<=120;j++){
                        if ((i==0 && j==0) || (i==0 && j==102) || (i==11 && j==102)){
                                cout<<"┏";
                        }
                        else if((i==0 && j==maplength) || (i==0 && j==120) || (i==11 && j==120)){
                                cout<<"┓";
                        }
                        else if((i==maphigh && j==0) || (i==10 && j==102) || (i==26 && j==102)){
                                cout<<"┗";
                        }
                        else if((i==maphigh && j==maplength) || (i==10 && j==120) || (i==26 && j==120)){
                                cout<<"┛";
                        }
                        else if (j==0 || j==maplength || j==102 || j==120){
                                cout << "┃";
                        }
                        else if (i==0||i==maphigh || (i==10 && j>101) || (i==11 && j>101) || i==26){
                                cout<<"━";
                        }
                        // print map
                        else if ((i >= 1 && i <= 25) && (j >= 1 && j <= 100)) {
                                // cout << map[i-1][j-1];

                        }
                        // print player
                        else if  ((i >= 3 && j >= 105)) {
                                int health = 5;

                                cout << "Health: +++++";
                                cout << "Shield: oo";

                        }
                        else{
                                cout<<" ";
                        
                        }

                                
                
                }
                cout << endl;
        }


        // for (int i =0; i<=maphigh; i++){ //map frame
        //         for(int j =0; j<=maplength;j++){
        //                 if (i==0 && j==0){
        //                         cout<<"┏";
        //                 }
        //                 else if(i==0 && j==maplength){
        //                         cout<<"┓";
        //                 }
        //                 else if(i==maphigh && j==0){
        //                         cout<<"┗";
        //                 }
        //                 else if(i==maphigh && j==maplength){
        //                         cout<<"┛";
        //                 }
        //                 else if (j==0 || j==maplength){
        //                         cout << "┃";
        //                 }
        //                 else if (i==0||i==maphigh){
        //                         cout<<"━";
        //                 }
        //                 else{
        //                         cout<<" ";
                        
        //                 }

                                
                
        //         }
        //         cout << endl;
        //         for (int j = 102;j<=playerlength;j++){ //player status frame
        //                 if(i==0 &&j==102){
        //                     cout<<"┏";    
        //                 }
        //                 else if(i==0 && j==playerlength){
        //                      cout<<"┓";   
        //                 }
        //                 else if (i==playerhigh && j==102){
        //                       cout<<"┗";   
        //                 }
        //                 else if (i==playerhigh && j==playerlength){
        //                       cout<<"┛";  
        //                 }
        //                 else if (j==102 || j==playerlength){
        //                         cout << "┃";
        //                 }
        //                 else if (i==0||i==playerhigh){
        //                         cout<<"━";
        //                 }
        //                 else{
        //                         cout<<" ";
        //                 }
                        

        //         }
        //         cout<<endl;
        //         for(int j =102; j<=shoplength;j++){
        //                 if (i==11 && j==102){
        //                         cout<<"┏";
        //                 }
        //                 else if(i==11 && j==shoplength){
        //                         cout<<"┓";
        //                 }
        //                 else if(i==shophigh && j==102){
        //                         cout<<"┗";
        //                 }
        //                 else if(i==shophigh && j==shoplength){
        //                         cout<<"┛";
        //                 }
        //                 else if (j==102 || j==shoplength){
        //                         cout << "┃";
        //                 }
        //                 else if (i==11||i==shophigh){
        //                         cout<<"━";
        //                 }
        //                 else{
        //                         cout<<" ";
        //                 }
        //         }
        //         cout<<endl;


        // }
        
        // return 0;
}

int main(){
        gameframe();
        return 0;
}