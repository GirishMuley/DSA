#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int> &days,vector<int> &cost){
    
    vector<int> dp(n+1,INT_MAX);
    dp[n] = 0;

    for(int k = n-1; k>=0;k--){
        //1 day pas
        int option1 = cost[0] + dp[k+1];

        int i;
        //7 days pass
        for(i=k; i<n && days[i] < days[k] + 7; i++);

        int option2 = cost[1] + dp[i];

        //30 days pass 
        for(int i=k;i<n && days[i] < days[k] + 30;i++);

        int option3 = cost[2] + dp[i];

        dp[k] = min(option1,min(option2,option3));
    }
    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    return solve(n,days,cost);
}

int main(){
    int days;
    cout<<"Enter no of days"<<endl;
    cin>>days;
    
    cout<<"Enter days"<<endl;
    vector<int> vectDays;
    for(int i=0;i<days;i++){
        int data;
        cin>>data;
        vectDays.push_back(data);
    }
    
    cout<<"Enter cost"<<endl;
    vector<int> vectCost;
    for(int i=0;i<3;i++){
        int data;
        cin>>data;
        vectCost.push_back(data);
    }
    
    cout<<minimumCoins(days,vectDays,vectCost)<<endl;
    
    return  0;
}