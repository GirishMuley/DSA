#include<iostream>
using namespace std;

int peakIndexOfMountainArray(int array[],int num){
    int start = 0;
    int end = num - 1;
    int mid = start + (end - start)/2;
    while(start<end){
        if(array[mid]<array[mid+1]){
            start = mid + 1;
        }else{
            end = mid;
        }
        mid = start + (end - start)/2;
    }
    return start;
}

int main(){
    int array[4]={3,4,5,1};
    
    cout<<"Peak of mountain array is "<<peakIndexOfMountainArray(array,4)<<endl;

    return 0;
}