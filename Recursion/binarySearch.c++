#include<iostream>
using namespace std;

bool binarySearch(int *arr,int s,int e,int k){
    //base case
    //element not found
    if(s>e){
        return false;
    }
    int mid = s + (e-s)/2;
    //element found
    if(arr[mid] == k){
        return true;
    }
    if(arr[mid] < k){
        return binarySearch(arr,mid + 1,e,k);
    }else{
        return binarySearch(arr,s,mid - 1,k);
    }
}

int main(){
    int arr[6] = {2,4,6,10,14,18};
    int key = 18;

    int ans = binarySearch(arr,0,5,key);
    if(ans){
        cout<<"Present"<<endl;
    }else{
        cout<<"Absent"<<endl;
    }
    return 0;
}