#include<iostream>
using namespace std;

void countPair(int array[],int size,int value){
    int count = 0;
    cout<<"Number of pair exists :"<<endl;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(array[i]+array[j] == value){
                count++;
            }
        }
    }
    cout<<count<<endl;
}

int main(){
    int array[100];
    int size,value;

    cout<<"Enter number of element in array :"<<endl;
    cin>>size;
    cout<<"Enter elements :"<<endl;
    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    cout<<"Enter the value :"<<endl;
    cin>>value;
    countPair(array,size,value);
    return 0;
}