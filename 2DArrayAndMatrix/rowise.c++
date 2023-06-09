#include<iostream>
using namespace std;

int main(){
    //creating 2d array
    int arr[3][4];

    //taking input row-wise
    for(int row=0;row<3;row++){
        for(int col=0;col<4;col++){
            cin>>arr[row][col];
        }
    }

    //print 2d array
    for(int row=0;row<3;row++){
        for(int col=0;col<4;col++){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
    return 0;
}