#include<iostream>
using namespace std;

int fibonacci(int n){
    int first = 0;
    int secound = 1;
    int nextNumber;
    for(int i = 0;i<n;i++){
        nextNumber = first + secound;
        first = secound;
        secound = nextNumber;
    }
    return secound;
}

int main(){
    int num;
    cout<<"enter a number"<<endl;
    cin>>num;
    cout<<fibonacci(num)<<endl;
    return 0;
}