#include<iostream>
using namespace std;

void segregate(int array[],int size){
    int count = 0;
    //counting a zero's
    for(int i=0;i<size;i++){
        if(array[i] == 0){
            count++;
        }
    }
    //Filling array with zero's
    for(int i=0;i<count;i++){
        array[i] = 0;
    }
    //Filling remaining array with one's
    for(int i=count;i<size;i++){
        array[i] = 1;
    }
}

void print(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i];
    }
}

int main(){
    int array[] = {0,1,0,1,0,1,0,1};
    int size = sizeof(array)/sizeof(array[0]);

    print(array,size);
    segregate(array,size);
    cout<<endl;
    print(array,size);
} 