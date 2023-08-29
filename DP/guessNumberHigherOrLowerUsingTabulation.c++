#include<bits/stdc++.h>
using namespace std;
int solveTab(int n){
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int start = n;start>=1;start--){
            for(int end = start;end<=n;end++){
                if(start == end)
                    continue;
                else
                {
                    int maxi = INT_MAX;
                    for(int i=start;i<end;i++){
                        maxi = min(maxi,i+max(dp[start][i-1],dp[i+1][end]));
                    }
                    dp[start][end] = maxi;
                }
            }
        }
        return dp[1][n];
    }
    int getMoneyAmount(int n) {
        return solveTab(n);
    }
    
int main(){
    int num;
    cout<<"Enter number"<<endl;
    cin>>num;
    
    cout<<"_____________"<<endl;
    
    cout<<getMoneyAmount(num)<<endl;
    
    
    return 0;
}