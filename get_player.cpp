#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

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

       

    
       