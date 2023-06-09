#include<iostream>
using namespace std;

int  main(){
    int num;
    int prod = 1;
    int sum = 0;

    cout<<"Enter a number"<<endl;
    cin>>num;

    while(num!=0){
        int digit = num%10;
        prod = prod * digit;
        sum = sum + digit;
        num = num/10;
    }
    int ans = prod - sum;
    cout<<ans<<endl;

    return 0;

}