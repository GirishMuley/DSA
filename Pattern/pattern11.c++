//print alphabet til the given number in square pattern
#include<iostream>
using namespace std;

int main(){
    int num;
    int row = 1;
    char ch = 'A';
    cout<<"Enter a number"<<endl;
    cin>>num;
    while(row<=num){
        int col = 1;
        while(col<=num){
            cout<<ch;
            ch++;
            col++;
        }
        cout<<endl;
        row++;
    }
}