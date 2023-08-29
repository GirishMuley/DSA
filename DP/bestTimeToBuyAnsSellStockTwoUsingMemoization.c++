#include<bits/stdc++.h>
using namespace std;

int solve(int index,int buy,vector<int>& prices,vector<vector<int>>& dp){
        if(index == prices.size())
            return 0;
        if(dp[index][buy] != -1)
            return dp[index][buy];

        int profit = 0;
        if(buy){
            int buyStock = -prices[index] + solve(index+1,0,prices,dp);
            int skipStock = 0 + solve(index+1,1,prices,dp);
            profit = max(buyStock,skipStock);
        }
        else
        {
            int sellStock = prices[index] + solve(index+1,1,prices,dp);
            int skipStock = 0 + solve(index+1,0,prices,dp);
            profit = max(sellStock,skipStock);

        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }

int main(){
    int noOfStock;
    cout<<"Enter no of stock"<<endl;
    cin>>noOfStock;
    
    cout<<"Enter stocks"<<endl;
    vector<int> vect;
    for(int i=0;i<noOfStock;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    
    cout<<"__________________"<<endl;
    
    cout<<maxProfit(vect)<<endl;
    return 0;
}