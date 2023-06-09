#include<iostream>
using namespace std;

int main(){
    int num;
    int row = 1;
    cout<<"Enter a number"<<endl;
    cin>>num;
    while(row<=num){
        //printing a spaces
        int space = row - 1;
        while(space){
            cout<<" ";
            space--;
        }
        int col = 1;
        int value = row;
        int temp = num;
        temp = temp - row + 1;
        while(col<=temp){
            cout<<value;
            value++;
            col++;
        }
        cout<<endl;
        row++;
    }
}