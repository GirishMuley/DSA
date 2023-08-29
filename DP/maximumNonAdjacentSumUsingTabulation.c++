#include<bits/stdc++.h>
using namespace std;


int solveTab(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,0);

    dp[0] = nums[0];

    for(int i=1;i<n;i++){
        int incl = dp[i-2] + nums[i];
        int excl = dp[i-1] + 0;
        dp[i] = max(incl,excl);
    }
    return dp[n-1];
}

int maximumNonAdjacentSum(vector<int> &nums){
    return solveTab(nums);
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