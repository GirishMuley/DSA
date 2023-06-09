#include<iostream>
using namespace std;

bool pairExists(int array[],int size,int value){
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(array[i] + array[j] == value){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int array[100];
    int size,value;

    cout<<"Enter number of element in array :"<<endl;
    cin>>size;
    cout<<"Enter element :"<<endl;
    for(int i=0;i<size;i++){
        cin>>array[i];
    }
    cout<<"Enter the value :"<<endl;
    cin>>value;
    
    if(pairExists(array,size,value)){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}