#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int add(int a,int b){
    return (a%MOD + b%MOD)%MOD;
}

int mul(int a,int b){
    return ((a%MOD) * (b%MOD))%MOD;
}

int solve(int n,int k,vector<int> &dp){
    //base case
    if(n == 1)
        return k;
    if(n == 2)
        return add(k,mul(k,k-1));
    if(dp[n] != -1)
        return dp[n];
    dp[n] = add(mul(solve(n-2,k,dp),k-1),mul(solve(n-1,k,dp),k-1));
    return dp[n];
}
int numberOfWays(int n, int k) {
    vector<int> dp(n+1,-1);
    return solve(n,k,dp);
}



int main(){
    int n,k;
    cout<<"Enter no of posts and fence"<<endl;
    cin>>n>>k;
    
    cout<<numberOfWays(n,k)<<endl;
    
    return 0;
}