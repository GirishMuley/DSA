//numeric pyramid pattern
#include<iostream>
using namespace std;

int main(){
    int num;
    int row = 1;
    cout<<"Enter a number"<<endl;
    cin>>num;
    while(row<=num){
        //printing space
        int  space = num - row;
        while(space){
            cout<<" ";
            space--;
        }
        //printing 1st triangle
        int col = 1;
        while(col<=row){
            cout<<col;
            col++;
        }
        //printing 2nd triangle
        int start = row - 1;
        while(start){
            cout<<start;
            start--;
        }
        cout<<endl;
        row++;
    }
}