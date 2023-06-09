//Half-Pyramid Using Numbers
#include<iostream>
using namespace std;

int main(){
    int num;
    int row = 1;
    cout<<"Enter a nuber"<<endl;
    cin>>num;
    while(row<=num){
        int col = 1;
        while(col<=row){
        cout<<(row - col) + 1;
        col++;
        }
        cout<<endl;
    row++;
    }
    
}