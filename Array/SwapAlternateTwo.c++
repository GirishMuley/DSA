#include<iostream>
using namespace std;

void swapAlternate(int array[],int size){
    for(int i=0;i<size;i+=2){
        if(i+1<size){
            swap(array[i],array[i+1]);
        }
    }
}

void print(int array[],int size){
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
}

int main(){
    int even[] = {5,2,9,4,7,6,1,0};
    int odd[] = {11,33,9,76,43};
    int sizeofeven = sizeof(even)/sizeof(even[0]);
    int sizeofodd = sizeof(odd)/sizeof(odd[0]);

    swapAlternate(even,sizeofeven);
    print(even,sizeofeven);
    cout<<endl;
    swapAlternate(odd,sizeofodd);
    print(odd,sizeofodd);

    return 0;
}