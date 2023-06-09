#include<iostream>
using namespace std;

int gcd(int a,int b){

     if(b == 0)
        return a;
        return gcd(b,a % b);
}


int main(){
    int a,b;
    cout<<"Enter the value of a and b"<<endl;
    cin>>a>>b;

    int ans = gcd(a,b);

    cout<<"the GCD of "<<a<<" & "<<b<<" is: "<<ans<<endl;

    return 0;
}