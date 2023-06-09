#include<iostream>
using namespace std;

void tripletSum(int array[],int size,int value){
    cout<<"Triplet present are :"<<endl;
    for(int i=0;i<size-2;i++){
        for(int j=i+1;j<size-1;j++){
            for(int k=j+1;k<size;k++){
                if(array[i]+array[j]+array[k] == value){
                    cout<<array[i]<<" "<<array[j]<<" "<<array[k]<<endl;
                }
            }
        }
    }
}

int main(){
    int array[100];
    int size,value;

    cout<<"Enter number of element  in array :"<<endl;
    cin>>size;

    cout<<"Enter element :"<<endl;
    for(int i=0;i<size;i++){
        cin>>array[i];
    }

    cout<<"Enter value :"<<endl;
    cin>> value;

    tripletSum(array,size,value);

    return 0;

}