#include<iostream>
using namespace std;

void intersectElements(int firstArray[],int secondArray[],int size){
    cout<<"Intersect elements are :"<<endl;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(firstArray[i] == secondArray[j]){
                cout<<firstArray[i]<<" ";
            }
        }
    }
}

int main(){
    int firstArray[100];
    int secondArray[100];
    int size;
    cout<<"Enter number of element in first array"<<endl;
    cin>>size;
    cout<<"Enter elements :"<<endl;
    for(int i=0;i<size;i++){
        cin>>firstArray[i];
    }

    cout<<"Enter number of element in second array"<<endl;
    cin>>size;
    cout<<"Enter elements :"<<endl;
    for(int i=0;i<size;i++){
        cin>>secondArray[i];
    }

    intersectElements(firstArray,secondArray,size);

    return 0;
}