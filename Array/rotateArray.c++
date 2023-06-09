#include<bits/stdc++.h>
using namespace std;

void rotateArray(vector<int> &vect,int k){
    vector<int> temp(vect.size());
    for(int i=0;i<vect.size();i++){
        temp[(i+k)%vect.size()] = vect[i];
    }
    vect = temp;
}

void printArray(vector<int> &vect){
    for(int i=0;i<vect.size();i++){
        cout<<vect.at(i)<<" ";
    }
}

int main(){
    vector<int> vect;
    int size;
    int k;
    cout<<"Enter the size of array : "<<endl;
    cin>>size;
    cout<<"Enter element of array : "<<endl;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    cout<<"Enter rotation position"<<endl;
    cin>>k;

    rotateArray(vect,k);

    cout<<"Rotated array : "<<endl;

    printArray(vect);

    return 0;
}