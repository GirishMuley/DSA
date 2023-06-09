#include<iostream>
using namespace std;

void printArray(int array[],int size){
    for(int i = 0;i<size;i++){
        cout<<array[i]<<" ";
    }
}

int main(){
    int arr[5] = {10,20,30,40,50};

    printArray(arr,5);

    return 0;
    
}