#include <iostream>

using namespace std;

void printStartMenu(int high,int length){
        high = 15;
        length = 45;
        cout<<"Please widen the window until the ui layout is correct."<<endl;
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
            else if (i==5 && j==21){
                    cout<<"S";
            }
            else if (i==5 && j==22){
                    cout<<"T";
            }
            else if (i==5 && j==23){
                    cout<<"A";
            }
            else if (i==5 && j==24){
                    cout<<"R";
            }
            else if (i==5 && j==25){
                    cout<<"T";
            }
            else if (i==8 && j==21){
                    cout<<"E";
            }
            else if (i==8 && j==22){
                    cout<<"X";
            }
            else if (i==8 && j==23){
                    cout<<"I";
            }
            else if (i==8 && j==24){
                    cout<<"T";
            }
            else{
                    cout<<" ";
            }
        }
        cout<<endl;
    
    }
    cout << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << endl;
    cout << "┃    Press 's' to start. Press 'e' to end.   ┃" << endl;
    cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << endl;
}


