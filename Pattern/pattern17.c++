//spcae start pattern
#include<iostream>
using namespace std;

int main(){
    int num;
    int row = 1;
    cout<<"Enter a number"<<endl;
    cin>>num;

    while(row<=num){
        //printing a spaces
        int space = num - row;
        while(space){
            cout<<" ";
            space = space - 1;
        }
        //printing star
        int col = 1;
        while(col<=row){
            cout<<"*";
            col++;
        }
        cout<<endl;
        row++;
    }
}