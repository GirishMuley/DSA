#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int num;
    cout<<"enter a number"<<endl;
    cin>>num;
    int i=0;
    int ans = 0;
    
    while(num != 0){
        int bit  = num&1;
        ans = (bit * pow(10,i))+ans;
        num = num>>1;
        i++;
    }
    cout<<"Answer is = "<<ans<<endl;
    return 0;
}