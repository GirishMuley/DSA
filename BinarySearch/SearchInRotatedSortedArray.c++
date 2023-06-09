#include<bits/stdc++.h>
using namespace std;

int getPivot(vector<int>& vect,int size){
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start)/2;
    while(start<end){
        if(vect[mid]>=vect[0]){
            start = mid + 1;
        }else{
            end = mid;
        }
        mid = start + (end - start)/2;
    }
    return start;
}

int binarySearch(vector<int>& vect,int s,int e,int key){
    int start = s;
    int end = e;
    int mid = start + (end - start)/2;
    while(start<=end){
        if(vect[mid] == key){
            return mid;
        }
        if(key > vect[mid]){
            start = mid + 1;
        }else{
            end = mid -1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}

int findPositon(vector<int>& vect,int n,int k){
    int pivot = getPivot(vect,n);
    if(k >= vect[pivot] && k <= vect[n-1]){
        return binarySearch(vect,pivot,n-1,k);
    }else{
        return binarySearch(vect,0,pivot-1,k);
    }
}

int main(){
    vector<int> vec{8,9,4,5};
    cout<<"Ans = "<<findPositon(vec,5,3)<<endl;
    return 0;
}