//complement of 10 bits integer.
#include<iostream>
using namespace std;

int main()
{
    int num;
    int mask = 1;
    cout<<"enter a number"<<endl;
    cin>>num;

    while(mask < num){
        mask = (mask<<1)+1;
    }
    int ans = mask^num;
    cout<<ans<<endl;
    return 0;
}