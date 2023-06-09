#include<iostream>
using namespace std;

void reverseArray(int array[],int size){
    int start = 0;
    int end = size - 1;

    while(start<=end){
        swap(array[start],array[end]);
        start++;
        end--;
    }
}

void printArray(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arrayFirst[6]={10,20,30,40,50,60};
    int arraySecond[5]={70,80,90,100,110};

    reverseArray(arrayFirst,6);
    reverseArray(arraySecond,5);

    printArray(arrayFirst,6);
    printArray(arraySecond,5);

    return 0;

}