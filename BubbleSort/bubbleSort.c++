#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &vect){
    int size = vect.size();
    for(int i=0;i<size-1;i++){
        bool swapped = false;
        for(int j=0;j<size-1;j++){
            if(vect[j] > vect[j+1]){
                swap(vect[j],vect[j+1]);
                swapped = true;
            }
            // cout<<"j start"<<j<<" "<<"j end"<<endl;
        }
        if(swapped ==false){
            break;
        } 
    //  cout<<"i start"<<i<<" "<<"i end"<<endl;   
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
    cout<<"Enter size of an Array "<<endl;
    cin>>size;
    cout<<"Enter element of Array "<<endl;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    bubbleSort(vect);
    cout<<"Sorted Array "<<endl;
    printArray(vect);
    return 0;
}