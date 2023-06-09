#include<bits/stdc++.h>
using namespace std;

void moveZeros(vector<int> &vect){
    int nonZeros = 0;
    for(int j=0;j<vect.size();j++){
        if(vect[j] != 0){
            swap(vect[j],vect[nonZeros]);
            nonZeros++;
        }
    }
}

void printArray(vector<int> &vect){
    for(int i=0;i<vect.size();i++){
        cout<<vect.at(i)<<" ";
    }
}

int main(){
    vector<int> vect;
    int size;
    cout<<"Enter the size of array :"<<endl;
    cin>>size;
    cout<<"Enter element of array : "<<endl;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    
    moveZeros(vect);
    
    cout<<"Result : "<<endl;
    
    printArray(vect);
    return 0;
}