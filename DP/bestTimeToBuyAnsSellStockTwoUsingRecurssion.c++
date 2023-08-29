#include<bits/stdc++.h>
using namespace std;

int solve(int index,int buy,vector<int>& prices){
        if(index == prices.size())
            return 0;
        
        int profit = 0;
        if(buy){
            int buyStock = -prices[index] + solve(index+1,0,prices);
            int skipStock = 0 + solve(index+1,1,prices);
            profit = max(buyStock,skipStock);
        }
        else
        {
            int sellStock = prices[index] + solve(index+1,1,prices);
            int skipStock = 0 + solve(index+1,0,prices);
            profit = max(sellStock,skipStock);

        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        return solve(0,1,prices);
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