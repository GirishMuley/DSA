#include<iostream>
using namespace std;

void swap(int *a,int *b){
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int first,second;
    cout<<"Enter two number"<<endl;
    cin>>first>>second;
    cout<<"Before swapping "<<first<<" "<<second<<endl;
    swap(&first,&second);
    cout<<"Afetr swapping "<<first<<" "<<second<<endl;
    return 0;
}