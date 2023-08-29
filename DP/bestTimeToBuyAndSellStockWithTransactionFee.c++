#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& prices,int fee){
        int n = prices.size();

        vector<int> curr(2,0);
        vector<int> next(2,0);
        
        for(int index = n-1;index >= 0;index--){
            for(int buy = 0;buy<=1;buy++){
                int profit = 0;
                if(buy){
            int buyStock = -prices[index] + next[0];
            int skipStock = 0 + next[1];
            profit = max(buyStock,skipStock);
        }
        else
        {
            int sellStock = prices[index] + next[1] - fee;
            int skipStock = 0 + next[0];
            profit = max(sellStock,skipStock);

        }
        curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
    int maxProfit(vector<int>& prices, int fee) {
        return solve(prices,fee);
    }

int main(){
    int fee;
    cout<<"Enter fee"<<endl;
    cin>>fee;
    
    int noOfPrices;
    cout<<"Enter no of prices"<<endl;
    cin>>noOfPrices;
    
    cout<<"enter prices"<<endl;
    vector<int> vect;
    for(int i=0;i<noOfPrices;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    
    cout<<"__________________"<<endl;
    
    cout<<maxProfit(vect,fee)<<endl;
    
    return 0;
}