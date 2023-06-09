#include<iostream>
using namespace std;

int main(){
    int num;
    int reverse = 0;
    int remainder;
    cout<<"Enter a number"<<endl;
    cin>>num;

    while(num!=0){
        remainder = num % 10;
        reverse = (reverse * 10) + remainder;
        num = num/10;
    }
    cout<<reverse<<endl;
    return 0;
}