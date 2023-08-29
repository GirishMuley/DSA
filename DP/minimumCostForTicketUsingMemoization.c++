#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int> &days,vector<int> &cost,int index,vector<int> &dp){
    //base case
    if(index >= n){
        return 0;
    }

    if(dp[index] != -1){
        return dp[index];
    }

    //1 day pass
    int option1 = cost[0] + solve(n,days,cost,index + 1,dp);

    int i;
    //7 days pass
    for(i = index; i<n && days[i] <days[index] + 7; i++);

    int option2 = cost[1]  + solve(n, days, cost,i,dp);

    //30 days pass 
    for(i = index; i<n && days[i] < days[index] + 30; i++);

    int option3 = cost[2] + solve(n, days, cost,i,dp);

    dp[index] = min(option1,min(option2,option3));

    return dp[index];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n+1,-1);
    return solve(n,days,cost,0,dp);
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