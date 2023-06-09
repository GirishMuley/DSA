//number count pattern
#include<iostream>
using namespace std;

int main(){
    int num;
    int count = 1;
    int row = 1;
    cout<<"Enter a number"<<endl;
    cin>>num;
    while(row<=num){
        int col = 1;
        while(col<=row){
            cout<<count;
            count++;
            col++;
        }
        cout<<endl;
        row++;
    }
}