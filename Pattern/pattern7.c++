//Numbers without reassigning
#include<iostream>
using namespace std;

int main(){
    int num;
    int row = 1;
    cout<<"Enter a number"<<endl;
    cin>>num;
    while(row<=num){
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