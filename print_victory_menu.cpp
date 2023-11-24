#include <iostream>
using namespace std;

void printVictoryMenu(int high,int length){
        high = 15;
        length = 45;
    for (int i = 0; i<=high; i++){
        for(int j=0;j<=length;j++){
            if (i==0 && j==0){
                    cout<<"┏";
            }
            else if(i==0 && j==length){
                    cout<<"┓";
            }
            else if(i==high && j==0){
                    cout<<"┗";
            }
            else if(i==high && j==length){
                    cout<<"┛";
            }
            else if (j==0 || j==length){
                    cout << "┃";
            }
            else if (i==0||i==high){
                    cout<<"━";

            }
            else if (i==7 && j==18){
                    cout<<"V";
            }
            else if (i==7 && j==19){
                    cout<<"I";
            }
            else if (i==7 && j==20){
                    cout<<"C";
            }
            else if (i==7 && j==21){
                    cout<<"T";
            }
            else if (i==7 && j==22){
                    cout<<"O";
            }
            else if (i==7 && j==23){
                    cout<<"R";
            }
            else if (i==7 && j==24){
                    cout<<"Y";
            }
            else if (i==7 && j==25){
                    cout<<"!";
            }
            
            else{
                    cout<<" ";
            }
        }
        cout<<endl;
    
    }
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃         Press 's' to start. Press 'e' to end. Press 'p' to pause. Press 'c' to continue. Press 'r' to reset.          ┃" << endl;
    cout << "┃         Press 'w/a/s/d' to move around. ^is throne, deduct one health. $is gold, use them in shop.                    ┃" << endl;
    cout << "┃         You can buy shield in shop to get more health.                                                                ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
        
}

