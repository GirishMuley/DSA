#include<iostream>
using namespace std;

int getPivot(int array[],int size){
    int start = 0;
    int end = size -1;
    int mid = start + (end - start)/2;
    while(start<end){
        if(array[mid]>=array[0]){
            start = mid + 1;
        }else{
            end = mid;
        }
        mid = start + (end - start)/2;
    }
    return end;
}

int main(){
    int array[5]={3,8,10,17,1};
    
    cout<<"Pivot at index = "<<getPivot(array,5)<<endl;
    cout<<"value is = "<<array[getPivot(array,5)]<<endl;
    return 0;
}