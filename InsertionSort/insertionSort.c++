#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &vect,int size){
    int j;
    for(int i=1;i<size;i++){
        int temp = vect[i];
        for(j = i-1;j>=0;j--){
            if(vect[j] > temp){
                vect[j+1] = vect[j];//shif
            }else{
                break;
            }
        }
        vect[j+1] = temp;
    }
}

void printArray(vector<int> &vect,int size){
    for(int i=0;i<size;i++){
        cout<<vect.at(i)<<" ";
    }
}

int main(){
    vector<int> vect;
    int size;
    cout<<"Enter the size of array :"<<endl;
    cin>>size;
    cout<<"Enter element of the array :"<<endl;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }

    insertionSort(vect,size);
    cout<<"Sorted array : "<<endl;
    printArray(vect,size);

    return 0;
}