//combaine pattern
#include<iostream>
using namespace std;

int main(){
    int num;
    int row = 1;
    cout<<"Enter a number"<<endl;
    cin>>num;
    while(row<=num){
        int col = 1;
        int temp = num;
        temp = temp - row + 1; 
        while(col<=temp){
            cout<<col;
            col++;
        }
        int star = 2;
        int startemp = num;
        int starprint = num - startemp;
        while(star<=row){
            cout<<"*";
            star++;
            startemp--;
        }
        int star2 = 2;
        int startemp2 = num;
        int starprint2 = num - startemp2;
        while(star2<=row){
            cout<<"*";
            star2++;
            startemp2--;
        }
        int col2 = num;
        while(col2>=row){
            cout<<col2;
            col2--;
        }
        
        cout<<endl;
        row++;
        
    }
}