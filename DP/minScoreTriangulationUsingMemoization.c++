#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& v, int i, int j,vector<vector<int>>& dp){
        //base case
        if(i+1 == j){
            return 0;
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        for(int k=i+1;k<j;k++){
            ans = min(ans,v[i]*v[j]*v[k] + solve(v,i,k,dp) + solve(v,k,j,dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(values,0,n-1,dp);
    }

int main(){
    int values;
    cout<<"Enter No of  values"<<endl;
    cin>>values;
    
    cout<<"Enter the values"<<endl;
    vector<int> vect;
    for(int i=0;i<values;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    
    cout<<"_____________________"<<endl;
    
    cout<<minScoreTriangulation(vect);
    
    return 0;
}