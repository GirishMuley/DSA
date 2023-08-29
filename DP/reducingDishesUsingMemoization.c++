#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& satisfaction,int index,int time,vector<vector<int>>& dp){
        //base case
        if(index == satisfaction.size())
            return 0;

        if(dp[index][time] != -1)
            return dp[index][time];

        int include = satisfaction[index] * (time + 1) + solve(satisfaction,index + 1,time + 1,dp);
        int exclude = 0 + solve(satisfaction,index + 1,time,dp);
        return dp[index][time] =  max(include,exclude);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return solve(satisfaction,0,0,dp);
    }

int main(){
    int dishes;
    cout<<"Enter no of dishes"<<endl;
    cin>>dishes;
    
    cout<<"Enter dishes"<<endl;
    vector<int> vect;
    for(int i=0;i<dishes;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    
    cout<<"__________________"<<endl;
    
    cout<<maxSatisfaction(vect)<<endl;
    
    return 0;
}