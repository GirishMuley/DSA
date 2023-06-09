#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& vect,int size){
    for(int i=0;i<size-1;i++){
        int minIndex = i;
        for(int j=i+1;j<size;j++){
            if(vect[j] < vect[minIndex]){
                minIndex = j;
            }
        }
      swap(vect[minIndex],vect[i]);
    }
}

void printArray(vector<int>& vect,int size){
    for(int i=0;i<size;i++){
        cout<<vect.at(i)<<" ";
    }
}
int main(){
    vector<int> vect;
    int size;
    cout<<"Enter size of array "<<endl;
    cin>>size;
    cout<<"Enter element of array"<<endl;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    
    selectionSort(vect,size);
    cout<<"Sorted Array = "<<endl;
    printArray(vect,size);
   return 0;
}