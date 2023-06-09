//reverse square number pattern
#include<iostream>
using namespace std;

int main(){
    int num;
    int row = 1;
    cout<<"Enter any interger number"<<endl;
    cin>>num;
    while(row<=num){
        int col = 1;
        while(col<=num){
            cout<<num - col +1;
            col++;
        }
        cout<<endl;
        row++;
    }
}