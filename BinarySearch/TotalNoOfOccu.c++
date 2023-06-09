#include<iostream>
using namespace std;

int firstOccurrence(int array[],int n,int key){
    int start = 0,end = n-1;
    int mid = start + (end-start)/2;
    int ans = -1;
    while(start<=end){
        if(array[mid] == key){
            ans = mid;
            end = mid - 1;
        }else if(key > array[mid]){
            start = mid + 1;
        }else if(key < array[mid]){
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int lastOccurrence(int array[],int n,int key){
    int start = 0,end = n-1;
    int mid = start + (end-start)/2;
    int ans = -1;
    while(start<=end){
        if(array[mid] == key){
            ans = mid;
            start = mid + 1;
        }else if(key > array[mid]){
            start = mid + 1;
        }else if(key < array[mid]){
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int totalNoOfOccurrence(int first,int last){
    int ans = (last - first) + 1;    
    return ans;
}

int main(){
    int array[12]={1,2,3,3,3,3,3,3,3,3,10,11};

    cout<<"First Occurrence of 3 is at Index = "<<firstOccurrence(array,12,3)<<endl;
    cout<<"Last Occurrence of 3 is at Index = "<<lastOccurrence(array,12,3)<<endl;
    cout<<"Total number of Occurrence is = "<<totalNoOfOccurrence(firstOccurrence(array,12,3),lastOccurrence(array,12,3))<<endl;
    return 0;
}