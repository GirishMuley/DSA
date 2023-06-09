//count square pattern
#include<iostream>
using namespace std;

int main(){
    int num;
    int row = 1;
    int count = 1;
    cout<<"Enter a number"<<endl;
    cin>>num;
    while(row<=num){
        int col = 1;
        while(col<=num){
            cout<<count<<" ";
            count++;
            col++;
        }
        cout<<endl;
        row++;
    }
}