#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;




//get all kinds of shop data from Shop.log
int main(){
    ifstream fin("Shop.log");

    //prevent opening error
    if(fin.fail()){
        cout<<"Error in file opening"<<endl;
        exit(1);
    }

    //print each line in the log file
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

       