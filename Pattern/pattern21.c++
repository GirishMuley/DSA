//spaces triangle number pattern
#include<iostream>
using namespace std;

int main(){
    int num;
    int row = 1;
    cout<<"Enter a number"<<endl;
    cin>>num;
    while(row<=num){
        //printing spaces
        int temp = num;
        int space = temp - row + 1;
        while(space){
            cout<<" ";
            space--;
        }
        int col = 1;
        while(col<=row){
        cout<<row;
        col++;
        }
        cout<<endl;
        row++;
    }

}
