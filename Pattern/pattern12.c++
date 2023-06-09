//Continuous Character pattern
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
         char  result = ch + row + col - 2;
            cout<<result;
            col++;
        }
        cout<<endl;
        row++;
    }
 }