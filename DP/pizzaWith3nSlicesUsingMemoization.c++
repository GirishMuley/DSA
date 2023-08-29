#include<bits/stdc++.h>
using namespace std;

int solve(int index,int endIndex,vector<int>& slices,int n,vector<vector<int>>& dp){
        //base case
        if(n == 0 || index > endIndex){
            return 0;
        }

        if(dp[index][n] != -1)
            return dp[index][n];

        int take = slices[index] + solve(index+2,endIndex,slices,n-1,dp);
        int notTake = 0 + solve(index+1,endIndex,slices,n,dp);
        return dp[index][n] = max(take,notTake);
    }
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();

        vector<vector<int>> dp1(k,vector<int> (k,-1));
        int case1 = solve(0,k-2,slices,k/3,dp1);
        vector<vector<int>> dp2(k,vector<int> (k,-1));
        int case2 = solve(1,k-1,slices,k/3,dp2);
        return max(case1,case2);
    }

int main(){
    int size;
    cout<<"Enter size"<<endl;
    cin>>size;
    
    cout<<"Enter elements"<<endl;
    vector<int> vect;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    
    cout<<"__________________"<<endl;
    
    cout<<maxSizeSlices(vect)<<endl;
    
    return 0;
}