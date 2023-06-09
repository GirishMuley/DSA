//decreasing continious character pattern
#include<iostream>
using namespace std;

int main(){
    int num;
    int row = 1;
    cout<<"Enter a number"<<endl;
    cin>>num;
    while(row<=num){
        int col = 1;
        char ch = 'A' + num - row;
        while(col<=row){
            cout<<ch;
            ch++;
            col++;
        }
        cout<<endl;
        row++;
    }
}