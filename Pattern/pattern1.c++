//square number pattern
#include<iostream>
using namespace std;

int main(){
    int row = 1;
    int num;
    cout<<"enter a number"<<endl;
    cin>>num;
    while(row<=num){
        int col = 1;
        while(col<=num){
            cout<<col;
            col++;
        }
        cout<<endl;
        row++;
    }

}