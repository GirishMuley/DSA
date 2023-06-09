//pyramid Continuous Character pattern
#include<iostream>
using namespace std;

int main(){
    int num;
    int row = 1;
    cout<<"Enter a number"<<endl;
    cin>>num;
    while(row<=num){
        int col = 1;
        while(col<=row){
            char ch = 'A' + row + col - 2;
            cout<<ch;
            col++;
        }
        cout<<endl;
        row++;
    }
}