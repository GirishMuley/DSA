#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
long long int countDerangements(int n) {
    //base case
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;

    int ans = ((n-1)%MOD)*((countDerangements(n-1)%MOD) + (countDerangements(n-2)%MOD)%MOD);

    return ans;
}

int main(){
    int size;
    cout<<"Enter size of elements"<<endl;
    cin>>size;
    
    
    cout<<countDerangements(size)<<endl;
    
    
    return 0;
}