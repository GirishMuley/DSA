#include<iostream>
using namespace std;

void swap(int a,int b){
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
    cout<<"After swapping first and second number is "<<a<<" "<<b<<endl;
}

int main(){
    int first,second;
    cout<<"Enter two number"<<endl;
    cin>>first>>second;
    swap(first,second);
    return 0;
}