#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &cost,int n){
       //step 1 creation of dp array
        vector<int> dp(n+1);
        //step 2 base case analyze
        dp[0] = cost[0];
        dp[1] = cost[1];

        //3rd step
        for(int i=2;i<n;i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solve(cost,n);
    }

int main(){
    int size;
    cout<<"Enter total stairs"<<endl;
    cin>>size;
    
    cout<<"__________________"<<endl;
    vector<int> vect;
    
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    
    cout<<"__________________"<<endl;
    cout<<minCostClimbingStairs(vect)<<endl;
    
    return 0;
}