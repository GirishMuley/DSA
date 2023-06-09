#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int num;
    int i = 0,ans = 0;
    cout<<"enter a binary number"<<endl;
    cin>>num;
    while(num != 0){
        int digit = num % 10;
        if(digit == 1){
            ans = (ans + pow(2,i));
        }
        num = num/10;
        i++;
    }
    cout<<"Answer is = "<<ans<<endl;
    return 0;
}