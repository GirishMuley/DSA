//180 degree reverse triangle
#include<iostream>
using namespace std;

int main(){
    int num;
    int row = 1;
    cout<<"Enter a number"<<endl;
    cin>>num;
    while(row<=num){
        int col = 1;
        int temp = num;
        temp = temp - row + 1;
        while(col<=temp){  
            cout<<"*";
            col++;
        }
        cout<<endl;
        row++;
    }
}