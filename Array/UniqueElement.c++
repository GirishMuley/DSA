#include<iostream>
using namespace std;

void uniqueElement(int array[],int size){
    cout<<"Unique elements are = "<<endl;
    int j;
    for(int i=0;i<size;i++){
        for(j=0;j<i;j++){
            if(array[i] == array[j]){
                break;
            }
        }
        if(i == j){
                cout<<array[i]<<" ";
            }
    }
}

int main(){
    int array[100];
    int size;
    cout<<"Enter number of a element in array"<<endl;
    cin>>size;
    cout<<"Enter elemrnts :"<<endl;
    for(int i=0;i<size;i++){
        cin>>array[i];
    }

    uniqueElement(array,size);
    return 0;
}