//spaces number triangle pattern
#include<iostream>
using namespace std;

int main(){
    int num;
    int row = 1;
    cout<<"Enter a number"<<endl;
    cin>>num;
    while(row<=num){
        //printing a spaces
        int space = row - 1;
        while(space){
            cout<<" ";
            space--;
        }
        int col = 1;
        int temp = num;
        temp = num - row + 1;
        while(col<=temp){
            cout<<row;
            col++;
        }
        cout<<endl;
        row++;
    }
}