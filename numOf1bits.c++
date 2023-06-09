#include<iostream>
using namespace std;

int main()
{
    int num = 00000000000000000000000000001011;
    int count = 0;
    while(num!=0){
        if(num&1){
            count++;
        }
        num = num>>1;
    }
    cout<<count<<endl;
    return 0;
}