#include<iostream>
using namespace std;

void swapArray(int array[],int size){
    int temp = 0;
    for(int i=0;i<size-1;i=i+2){
        temp = array[i];
        array[i] = array[i+1];
        array[i+1] = temp;
    }
}

void printArray(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
}

int main(){
      
    int array[5]={5,6,8,3,7};

    swapArray(array,5);
 
    printArray(array,5);

    return 0;
}