#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;


//initialize the player at the begining
struct Player{
    int Health;
    int Shield;
    int Gold;
    int x,y;
    bool Key;
    int Level;
};
Player p;
Player p ={5,0,0,50,25,false,1};



//print all the data of player
void GetPlayer(){
    ofstream fout("Player.log");
    if(fout.fail()){
        cout<<"Error in file opening"<<endl;
        exit(1);
    }
    fout<<"Health: "<<p.Health<<"\n";
    fout<<"Shield: "<<p.Shield<<"\n";
    fout<<"Gold: "<<p.Gold<<"\n";
    fout<<"Position: "<<p.x<<","<<p.y<<"\n";
    fout<<"Key: "<<p.Key<<"\n";
    fout<<"Level: "<<p.Level<<endl;
    fout.close();
}


//print the health of player
void GetHealth(){
    ofstream fout("Player.log");
    if(fout.fail()){
        cout<<"Error in file opening"<<endl;
        exit(1);
    }
    fout<<"Health "<<p.Health<<endl;
    fout.close();
}

//print the shield of player
void getShield(){
    ofstream fout("Player.log");
    if(fout.fail()){
        cout<<"Error in file opening"<<endl;
        exit(1);
    }
    fout<<"Shield "<<p.Shield<<endl;
    fout.close();
}

//print the gold of player
void GetGold(){
    ofstream fout("Player.log");
    if(fout.fail()){
        cout<<"Error in file opening"<<endl;
        exit(1);
    }
    fout<<"Gold "<<p.Gold<<endl;
    fout.close();
}


//print the key of player
void GetKey(){
    ofstream fout("Player.log");
    if(fout.fail()){
        cout<<"Error in file opening"<<endl;
        exit(1);
    }
    fout<<"Key "<<p.Key<<endl;
    fout.close();
}


//print the level of player
void GetLevel(){
    ofstream fout("Player.log");
    if(fout.fail()){
        cout<<"Error in file opening"<<endl;
        exit(1);
    }
    fout<<"Level "<<p.Level<<endl;
    fout.close();
}







//print the position of player
void printposistion(){
    ofstream fout("Player.log");
    if(fout.fail()){
        cout<<"Error in file opening"<<endl;
        exit(1);
    }
    fout<<"Position "<<p.x<<","<<p.y<<endl;
    fout.close();
}





//get all kinds of player data from Player.log
int main(){
    ifstream fin("Player.log");
    //prevent opening error
    if(fin.fail()){
        cout<<"Error in file opening"<<endl;
        exit(1);
    }


    if(!fin.is_open()){
        return 0;
        string strline;
        while(getline(fin, strline)){
            if(strline.empty()){
                continue;
            }
            cout<<strline<<endl;
        }

    }
}

       

    
       