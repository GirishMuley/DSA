#include<iostream>
using namespace std;

int main(){
    int num;
    cout<<"enter a number"<<endl;
    cin>>num;
    int mask = 1;
    while(mask < num)
    {
        mask = (mask<<1)+1;
    }
    int ans = mask^num;
    cout<<ans;
    return 0;
}