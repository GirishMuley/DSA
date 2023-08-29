#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;
        for(int i=1;i<prices.size();i++){
            int diff = prices[i] - mini;
            profit = max(profit,diff);
            mini = min(mini,prices[i]);
        }
        return profit;
    }

int main(){
    int days;
    cout<<"Enter no of days"<<endl;
    cin>>days;
    
    cout<<"Enter prices of stock"<<endl;
    vector<int> vect;
    for(int i=0;i<days;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    
    cout<<"______________________"<<endl;
    
    cout<<maxProfit(vect)<<endl;
    
    return 0;
}