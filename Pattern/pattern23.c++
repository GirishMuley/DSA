#include<iostream>
using namespace std;

int main(){
    int num;
    int row = 1;
    cout<<"Enter a number";
    cin>>num;
    while(row<=num){
        int temp = num;
        int space = temp - row + 1;
        while(space){
            cout<<" ";
            space--;
        }
        int col = 1;
        int value = row;
        while(col<=row){
            cout<<value;
            value++;
            col++;
        }
        cout<<endl;
        row++;
    }
}