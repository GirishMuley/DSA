#include<iostream>
using namespace std;

bool Search(int array[],int size,int key){
    for(int i=0;i<size;i++){
        if(array[i] == key){
            return 1;
        }
    }
    return 0;
}

int main(){
    int nums[15] = {10,5,9,3,41,63,45,63,-9,-5,-6,-1,1,2,4};
    int key;
    cout<<"Enter element you want to search :"<<endl;
    cin>>key;

    bool found = Search(nums,15,key);

    if(found){
        cout<<"Key is present"<<endl;
    }else{
        cout<<"Key is not present"<<endl;
    }
    return 0;
}