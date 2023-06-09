#include<iostream>
using namespace std;
#define ELE 1,2,3

int main(){
    int arr[] = {ELE};
    cout<<"Elements of array are:"<<endl;
    for(int i=0;i<3;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}