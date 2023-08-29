#include<bits/stdc++.h>
using namespace std;

 int solve(int index,int buy,vector<int>& prices,int limit){
        if(index == prices.size())
            return 0;
        
        if(limit == 0)
            return 0;

        int profit = 0;
        if(buy){
            int buyStock = -prices[index] + solve(index+1,0,prices,limit);
            int skipStock = 0 + solve(index+1,1,prices,limit);
            profit = max(buyStock,skipStock);
        }
        else
        {
            int sellStock = prices[index] + solve(index+1,1,prices,limit-1);
            int skipStock = 0 + solve(index+1,0,prices,limit);
            profit = max(sellStock,skipStock);

        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return solve(0,1,prices,2);
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