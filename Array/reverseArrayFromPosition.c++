#include<bits/stdc++.h>
using namespace std;

void reverseArrayFromPosition(vector<int> &vect,int size,int m){
    int start = m;
    int end = size - 1;

    while(start<=end){
        swap(vect[start],vect[end]);
        start++;
        end--;
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
    int m;
    cout<<"Enter the array size :"<<endl;
    cin>>size;
    cout<<"Enter element of array :"<<endl;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    cout<<"Enter the position from where you want to reverse array :"<<endl;
    cin>>m;

    reverseArrayFromPosition(vect,size,m);

    cout<<"Reverse Array is :"<<endl;

    printArray(vect,size);

    return 0;
}