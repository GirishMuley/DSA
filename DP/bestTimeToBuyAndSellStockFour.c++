#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& prices,int k){
    int n = prices.size();
    vector<vector<int>> curr(2,vector<int>(k+1,0));
    vector<vector<int>> next(2,vector<int>(k+1,0));
    
    for(int index = n-1;index>=0;index--){
        for(int buy = 0;buy<=1;buy++){
            for(int limit=1;limit<=k;limit++){
                int profit = 0;
                if(buy){
                    int buyStock = -prices[index] + next[0][limit];
                    int skipStock = 0 + next[1][limit];
                    profit = max(buyStock,skipStock);
                }
                else
                {
                    int sellStock = prices[index] + next[1][limit-1];
                    int skipStock = 0 + next[0][limit];
                    profit = max(sellStock,skipStock);
        
                }
                curr[buy][limit] = profit;
            }
        }
        next = curr;
    }
    return next[1][k];
}
    int maxProfit(int k, vector<int>& prices) {
        return solve(prices,k);
    }

int main(){
    int k;
    cout<<"Enter k"<<endl;
    cin>>k;
    
    int noOfPrices;
    cout<<"Enter no of prices"<<endl;
    cin>>noOfPrices;
    
    cout<<"Enter prices"<<endl;
    vector<int> vect;
    for(int i=0;i<noOfPrices;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    
    cout<<"____________________"<<endl;
    
    cout<<maxProfit(k,vect)<<endl;
    
    return 0;
}