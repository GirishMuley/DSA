//charactor pattern
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
        while(col<=row){
            cout<<ch;
            col++;
        }
        cout<<endl;
        ch++;
        row++;
    }
}