#include<iostream>
using namespace std;

int getInvcount(int arr[],int n){
    int ivnCount = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                ivnCount++;
            }
        }
    }
    return ivnCount;
}

int main(){
    int arr[] = {1,20,6,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"Number of inversion are :"<<getInvcount(arr,n);
    return 0;
}