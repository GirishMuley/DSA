#include<bits/stdc++.h>
using namespace std;

int solve(int k,vector<int>& prices){
    int n = prices.size();
    vector<int> curr(2*k+1,0);
    vector<int> next(2*k+1,0);
    
    for(int index = n-1;index>=0;index--){
        for(int operationNo=0;operationNo<2*k;operationNo++){
            int profit = 0;
            if(operationNo%2 == 0){
                //buy allowed
                int buyStock = -prices[index] + next[operationNo+1];
                int skipStock = 0 + next[operationNo];
                profit = max(buyStock,skipStock);
            }
            else
            {
                int sellStock = prices[index] + next[operationNo+1];
                int skipStock = 0 + next[operationNo];
                profit = max(sellStock,skipStock);
            }
            curr[operationNo] = profit;
        }
        next = curr;
    }
    return next[0];
}

    int maxProfit(int k, vector<int>& prices) {
        return solve(k,prices);
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