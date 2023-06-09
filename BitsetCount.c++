#include <iostream>
#include <math.h>
using namespace std;

int counter(int num){
    int count = 0,i = 0,ans = 0;
    while(num != 0){
        int bit = num&1;
        if(bit == 1){
            count++;
        }
        ans = (bit * pow(10,i))+ans;
        num = num >>1;
    }
    return count;
}

int main()
{
    int num1;
    cout<<"enter a nunber"<<endl;
    cin>>num1;
    int num2;
    cout<<"enter a nunber"<<endl;
    cin>>num2;
    
    int result1 = counter(num1);
    int result2 = counter(num2);
    
    cout<<"Total number of set bit in a & b ="<<result1+result2<<endl;
    
    return 0;
}