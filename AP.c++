#include<iostream>
using namespace std;

int Ap(int n){
    return (3*n+7);
}

int main(){
    int num;
    cout<<"enter a number"<<endl;
    cin>>num;

    int result = Ap(num);
    cout<<"the result is = "<<result<<endl;
    return 0;
}