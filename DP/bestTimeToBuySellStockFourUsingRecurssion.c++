#include<bits/stdc++.h>
using namespace std;

int solve(int index,int operationNo,int k,vector<int>& prices){
                if(index == prices.size())
                    return 0;
    
                if(operationNo == 2*k)
                    return 0;
    
                int profit = 0;
                if(operationNo%2 == 0){
                    //buyStock allowed
                    int buyStock = -prices[index] + solve(index+1,operationNo+1,k,prices);
                    int skipStock = 0 + solve(index+1,operationNo,k,prices);
                    profit = max(buyStock,skipStock);
                }
                else
                {
                    int sellStock = prices[index] + solve(index+1,operationNo+1,k,prices);
                    int skipStock = 0 + solve(index+1,operationNo,k,prices);
                    profit = max(sellStock,skipStock);
        
                }
                return  profit;
            }
 
    int maxProfit(int k, vector<int>& prices) {
        return solve(0,0,k,prices);
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