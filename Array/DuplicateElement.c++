#include<iostream>
using namespace std;

void duplicateElement(int array[],int size){
    cout<<"Duplicate elements :"<<endl;
    for(int i=0;i<size;i++){
        for(int j=0;j<i;j++){
            if(array[i] == array[j]){
                cout<<array[i]<<" ";
            }
        }
    }
}

int main(){
    int array[100];
    int size;
    cout<<"Enter a number of element in array :"<<endl;
    cin>>size;
    cout<<"Enter elements :"<<endl;
    for(int i=0;i<size;i++){
        cin>>array[i];
    }

    duplicateElement(array,size);
    return 0;
}