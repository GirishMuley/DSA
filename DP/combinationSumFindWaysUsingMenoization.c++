#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &num,int tar,vector<int> &dp){
    //base case
    if(tar < 0)
        return 0;
    
    if(tar == 0)
        return 1;
    
    if(dp[tar] != -1)
        return dp[tar];
    
    int ans = 0;

    for(int i=0;i<num.size();i++){
        ans += solve(num,tar - num[i],dp);
    }
    dp[tar] = ans;
    return dp[tar];
}
int findWays(vector<int> &num, int tar)
{
    vector<int> dp(tar+1,-1);
    return solve(num,tar,dp);
}

int main(){
    int size;
    cout<<"Enter size of array"<<endl;
    cin>>size;
    
    cout<<"Enter elements"<<endl;
    vector<int> vect;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    
    int tar;
    cout<<"Enter target value"<<endl;
    cin>>tar;
    
    cout<<"___________________"<<endl;
    
    cout<<findWays(vect,tar)<<endl;
    
    return 0;
}