#include<bits/stdc++.h>
using namespace std;


 int solve(vector<int>& prices){
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    
    for(int index = n-1;index>=0;index--){
        for(int buy = 0;buy<=1;buy++){
            for(int limit=1;limit<=2;limit++){
                int profit = 0;
                if(buy){
                    int buyStock = -prices[index] + dp[index+1][0][limit];
                    int skipStock = 0 + dp[index+1][1][limit];
                    profit = max(buyStock,skipStock);
                }
                else
                {
                    int sellStock = prices[index] + dp[index+1][1][limit-1];
                    int skipStock = 0 + dp[index+1][0][limit];
                    profit = max(sellStock,skipStock);
        
                }
                dp[index][buy][limit] = profit;
            }
        }
    }
    return dp[0][1][2];
}

int maxProfit(vector<int>& prices) {
     return solve(prices);
}

int main(){
    int NoOfPrices;
    cout<<"Enter no of prices"<<endl;
    cin>>NoOfPrices;
    
    cout<<"Enter prices"<<endl;
    vector<int> vect;
    for(int i=0;i<NoOfPrices;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    
    cout<<"____________________"<<endl;
    
    cout<<maxProfit(vect)<<endl;
    
    return 0;
}