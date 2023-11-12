#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;



struct good{
    string name;
    int price;
};

good g1={"Shield",2}
good g2={"Health",2}
//add goods needed


//print the information of goods on Shop.log
void printgood(g1){
    ofstream fout("Shop.log");
    if(fout.fail()){
        cout<<"Error in file opening"<<endl;
        exit(1);
    }
    fout<<g1.name<<" "<<g1.price<<endl;
    fout<<g2.name<<" "<<g2.price<<endl;
    //addition if needed

    fout.close();
}

int main(){
    string name;
    int price;
    cin<<name<<price;
    good g={name,price};
    printgood(g);
}