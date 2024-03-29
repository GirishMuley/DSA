#include<bits/stdc++.h>
using namespace std;

   int solve(int n){
        vector<int> dp(n+1,0);
        dp[0] = dp[1] = 1;

        //i -> number of nodes
        for(int i=2;i<=n;i++){
            //j-> root node
            for(int j=1;j<=i;j++){
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
    int numTrees(int n) {
        return solve(n);
    }

int main(){
    int n;
    cout<<"Emter num"<<endl;
    std::cin >> n;
    
    cout<<"____________"<<endl;
    
    cout<<numTrees(n)<<endl;
    
    return 0;
}