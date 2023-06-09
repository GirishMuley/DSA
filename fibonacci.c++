#include<iostream>
using namespace std;

int main(){
    int num;
    cout<<"enter a number"<<endl;
    cin>>num;
    int nextNumber;
    int a = 0;
    int b = 1;
    cout<<a<<" ";
    cout<<b<<" ";
    for(int i = 0;i<=num;i++){
        nextNumber = a+b;
        cout<<nextNumber<<" ";
        a = b;
        b = nextNumber;
    }
    return 0;
}