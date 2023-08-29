#include<bits/stdc++.h>
using namespace std;

int solveMemo(vector<int> &nums,int n,vector<int> &dp){
    //base case
    if(n < 0)
        return 0;
    if(n == 0)
        return nums[0];

    if(dp[n] != -1)
        return dp[n];

    int incl = solveMemo(nums,n-2,dp) + nums[n];
    int excl = solveMemo(nums,n-1,dp) + 0;

    dp[n] = max(incl,excl);
    return dp[n];
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,-1);
    return solveMemo(nums,n-1,dp);
}

int main(){
    int size;
    cout<<"Enter the size"<<endl;
    cin>>size;
    
    cout<<"Enter elements"<<endl;
    vector<int> vect;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    
    cout<<"__________________"<<endl;
    
    cout<<maximumNonAdjacentSum(vect)<<endl;
    
    return 0;
}