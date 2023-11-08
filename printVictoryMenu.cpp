#include <iostream>
using namespace std;

char printEndMenu(int high,int length){
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
    return ' ';
}

int main(){
    int endhigh = 15;
    int endlength = 45;
    char c =  printEndMenu(endhigh,endlength);
    return 0;
}
